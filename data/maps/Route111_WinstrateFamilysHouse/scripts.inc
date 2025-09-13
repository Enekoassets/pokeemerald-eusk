.set LOCALID_VIVI, 1
.set LOCALID_VICTOR, 2
.set LOCALID_VICTORIA, 3
.set LOCALID_VICKY, 4

Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "POKéMONAK halako trebeziaz erabiltzen\n"
	.string "dituen lehen ENTRENATZAILEA zara.\p"
	.string "Baina, esan beharra dut: nire semea\n"
	.string "zu baino indartsuagoa da.\p"
	.string "POKéMON LIGAKO erronkari aurre\n"
	.string "egin zion, jakin dezazun.$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "BESOKO SENDO hau erabiltzen dugu\n"
	.string "gure POKéMONAK efektiboki\l"
	.string "entrenatzeko.\p"
	.string "Gu denok garaitu gaituzunez, agian\n"
	.string "ez duzu behar, baina gure BESOKO\l"
	.string "SENDOA eman nahi genizuke.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "POKéMON borrokez ari garenean,\n"
	.string "pasio handiz aritzen gara.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "Amatxo Aitatxo baino indartsuagoa da.\p"
	.string "Ni Amatxo baino indartsuagoa naiz.\p"
	.string "Eta Amona ni baino indartsuagoa!\p"
	.string "Baina nire anaia nagusia Amona\n"
	.string "baino are indartsuagoa da.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "Indartsua zara, ez dago dudarik.\p"
	.string "Baina nire bilobaren aurka egingo bazenu,\n"
	.string "frustrazioz negar egingo zenuke.\p"
	.string "Gure familiak ezagutzen duen edozein\n"
	.string "ENTRENATZAILE baino indartsuagoa da.\p"
	.string "POKéMON LIGAKO TXAPELDUNAREN aurka\n"
	.string "aritu beharko litzateke jada.\p"
	.string "Nire biloba ezagututa, agian bera\n"
	.string "da TXAPELDUNA jada!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "Nire biloba POKéMON LIGAKO TXAPELDUNAREN\n"
	.string "aurka aritu beharko litzateke jada.\p"
	.string "Nire biloba ezagututa, agian bera\n"
	.string "da TXAPELDUNA jada!$"

