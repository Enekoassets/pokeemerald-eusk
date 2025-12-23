.set LOCALID_OLD_WOMAN, 2

BattleFrontier_Mart_MapScripts::
	.byte 0

BattleFrontier_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

BattleFrontier_Mart_EventScript_OldMan::
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson, MSGBOX_NPC
	end

BattleFrontier_Mart_EventScript_OldWoman::
	lock
	applymovement LOCALID_OLD_WOMAN, Common_Movement_FaceDown
	waitmovement 0
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Boy::
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems, MSGBOX_NPC
	end

BattleFrontier_Mart_Text_ChaperonGrandson:
	.string "Gure bilobari laguntzera\n"
	.string "etorri gara hona.\p"
	.string "Baina behin hemen egonda, oroigarri\n"
	.string "batzuk erostea pentsatu dugu.$"

BattleFrontier_Mart_Text_ProteinMakeNiceGift:
	.string "Maitea, zer iruditzen zaizu hau?\n"
	.string "Ez al litzateke opari polita izango?\p"
	.string "Zer da…PRO…TE…INA?\n"
	.string "Gozo-gozoa dirudi, ezta?$"

BattleFrontier_Mart_Text_FacilitiesDontAllowItems:
	.string "BORROKA FRONTEKO eraikin askotan\n"
	.string "ezin dira itemak erabili borroka\l"
	.string "egin bitartean.\p"
	.string "Arau horrek are zailagoa egiten\n"
	.string "du erronka!$"

