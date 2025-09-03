SlateportCity_PokemonFanClub_MapScripts::
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon::
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_eq VAR_TEMP_2, CONTEST_CATEGORIES_COUNT, SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	goto_if_eq VAR_SLATEPORT_FAN_CLUB_STATE, 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves::
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon::
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname STR_VAR_1
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf::
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions::
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf::
	checkitemspace ITEM_RED_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf::
	checkitemspace ITEM_BLUE_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf::
	checkitemspace ITEM_PINK_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf::
	checkitemspace ITEM_GREEN_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf::
	checkitemspace ITEM_YELLOW_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf::
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool::
	specialvar VAR_RESULT, CheckLeadMonCool
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool::
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty::
	specialvar VAR_RESULT, CheckLeadMonBeauty
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty::
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute::
	specialvar VAR_RESULT, CheckLeadMonCute
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute::
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart::
	specialvar VAR_RESULT, CheckLeadMonSmart
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart::
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough::
	specialvar VAR_RESULT, CheckLeadMonTough
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough::
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest::
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest::
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman::
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell::
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man::
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin::
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman:
	.string "Ejem! POKéMON FAN KLUBEKO\n"
	.string "LEHENDAKARIA naiz!\p"
	.string "LEHENDAKARIA naizenez, ni naiz\n"
	.string "garrantzitsuena, noski!\p"
	.string "Inor ez da ni bezain ona\n"
	.string "POKéMONAK hazten. Inor ez!\p"
	.string "Beno, POKéMON TXAPELKETEN\n"
	.string "inguruan hitz egingo dizut.\p"
	.string "Ekitaldi batzuk dira, bertan edonork\n"
	.string "bere POKéMONAK aurkeztu ditzake!\p"
	.string "Hala ere, urruti dauden herrietan\n"
	.string "direnez, ezin dut parte hartu normalean.\p"
	.string "Horregatik biltzen gara hemen gure\n"
	.string "POKéMONAK erakusteko eta\l"
	.string "besteek guri haienak.$"

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon:
	.string "POKéMON TXAPELKETA batean parte\n"
	.string "hartu duen norbaiten POKéMONA…\l"
	.string "Hori ikusi nahi nuke.$"

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon:
	.string "Ejem! Ikus dezaket POKéMON TXAPELKETA\n"
	.string "batean parte hartu duzula!\p"
	.string "Mesedez! Utzi zure POKéMONA nola\n"
	.string "hazi duzun aztertzen.\p"
	.string "Izugarri atsegin dut beste batzuek\n"
	.string "hazitako POKéMONAK aztertzea.\p"
	.string "Ondo zaiduta dauden POKéMONEN\n"
	.string "zoriontasun aurpegia…\p"
	.string "POKéMONA hazi duen ENTRENATZAILEAREN\n"
	.string "begirada goxoa…\p"
	.string "Pentsatzeak bakarrik alaitasunez\n"
	.string "betetzen dit bihotza.\p"
	.string "Ene! Barkatu!\n"
	.string "Gehiegi hitz egiten ari naiz!\p"
	.string "Mesedez! Utzi zure POKéMONA\n"
	.string "zenbat hazi den aztertzen!$"

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing:
	.string "Zer moduz ari da hazten zure POKéMONA?\n"
	.string "Utzi aztertzen, mesedez.$"

SlateportCity_PokemonFanClub_Text_HmHmISee:
	.string "Hm, hm…\n"
	.string "Ados…$"

SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks:
	.string "Hmmm… Ez dago gaizki, baina\n"
	.string "ezta oso ondo ere…\p"
	.string "Zuk, ENTRENATZAILEAK, gogo gehiago\n"
	.string "jarri behar duzu POKéMON hau hazten!\p"
	.string "Adibidez, zer iruditzen zaizu\n"
	.string "{POKEBLOCK} gehiago ematen badizkiozu?$"

SlateportCity_PokemonFanClub_Text_NoSpaceForReward:
	.string "Ai ene…\p"
	.string "Zure POKéMONA nahiko ondo hazten ari da,\n"
	.string "opari bat merezi duzu, beraz.\p"
	.string "Zoritxarrez, ez duzu honentzako\n"
	.string "lekurik zure POLTSAN.$"

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis:
	.string "Zure {STR_VAR_1}, era harrigarrian\n"
	.string "hazten ari da!\l"
	.string "Hau bai POKéMON bikaina!\p"
	.string "Baina! Hau emango bazenio, are\n"
	.string "hobe haziko litzateke! Benetan!$"

SlateportCity_PokemonFanClub_Text_ExplainRedScarf:
	.string "Eman POKéMONARI ZAPI GORRI hori.\p"
	.string "Guztiek POKéMONAREN karisma\n"
	.string "nabarituko dute hori badarama!$"

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf:
	.string "Eman POKéMONARI ZAPI URDIN hori.\p"
	.string "Bere edertasuna orain baino\n"
	.string "askoz gehiago areagotuko da!$"

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf:
	.string "Eman POKéMONARI ZAPI ARROSA hori.\p"
	.string "POKéMON honen politasuna\n"
	.string "ateratzeko gai izango da!$"

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf:
	.string "Eman POKéMONARI ZAPI BERDE hori.\p"
	.string "POKéMON honen argitasuna\n"
	.string "areagotuko du!$"

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf:
	.string "Eman POKéMONARI ZAPI HORI hori.\p"
	.string "Zure POKéMONAREN gogortasuna\n"
	.string "asko handituko da!$"

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou:
	.string "Barkatu, baina ez daukat ezer\n"
	.string "gehiago zuri emateko! Ezer ere ez!\p"
	.string "Azken finean, POKéMONAK itemik\n"
	.string "erabili gabe bikain hazteko\l"
	.string "abilezia izugarria duzu!$"

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou:
	.string "Oso atsegin dut beren ENTRENATZAILEAK\n"
	.string "maite dituzten POKéMONAK ikustea.\p"
	.string "POKéMONAK oso sentikorrak dira haien\n"
	.string "ENTRENATZAILEEN sentimenduekiko.\p"
	.string "Maitasun eta kontuz zaintzen badituzu\n"
	.string "POKéMONAK, bueltan maitatuko zaituzte.\p"
	.string "Zure POKéMONAK izugarri maite zaituenean,\n"
	.string "mesedez, etorri erakustera.$"

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou:
	.string "Zure POKéMONAK benetan maite zaitu.\p"
	.string "Zuretzat, ENTRENATZAILE errukitsu\n"
	.string "hori, FAN KLUBAREN opari bat!$"

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove:
	.string "POKéMONAK oso sentikorrak dira haien\n"
	.string "ENTRENATZAILEEN sentimenduekiko.\p"
	.string "Maitasun eta kontuz zaintzen badituzu\n"
	.string "POKéMONAK, bueltan maitatuko zaituzte.$"

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting:
	.string "POKéMON bat etengabe indargabetzen\n"
	.string "bada borrokan, haserretu egingo da.\p"
	.string "Segituan, konfidantza galduko\n"
	.string "du bere ENTRENATZAILEAN.\p"
	.string "Beste era batera esanda, ez zaitu\n"
	.string "oso atsegin izango.$"

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein:
	.string "Gustatzen ote zaie POKéMONEI\n"
	.string "itemak berengan erabiltzea?\p"
	.string "Nirea asko poztu zen PROTEINA\n"
	.string "pixka bat eman nionean.$"

SlateportCity_PokemonFanClub_Text_Skitty:
	.string "SKITTY: Fffnyaaaah…$"

SlateportCity_PokemonFanClub_Text_Zigzagoon:
	.string "ZIGZAGOON: Kyuuu…$"

SlateportCity_PokemonFanClub_Text_Azumarill:
	.string "AZUMARILL: Marimari?$"

