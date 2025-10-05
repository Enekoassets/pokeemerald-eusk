MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "Iuju!\p"
	.string "Entzun dut jendeak ARROKA KOLPE TIPOA\n"
	.string "deitzen didala, baina ez dut atsegin.\p"
	.string "Errespetu gehixeago merezi dut,\n"
	.string "ARROKA KOLPE JAUNA, adibidez.\p"
	.string "Iuju!\p"
	.string "Berdin da, zure POKéMONEK indartsuak\n"
	.string "dirudite.\p"
	.string "Atsegin dut hori!\n"
	.string "Tori, hartu MAKINA EZKUTU hau!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "ME horrek ARROKA KOLPEA dauka barruan.\p"
	.string "Zure bidea oztopatzen duten arroka\n"
	.string "handiekin topo egiten baduzu…\p"
	.string "Beno, erabili ME hori eta birrindu\n"
	.string "itzazu bidea irekitzeko!\p"
	.string "Bai jauna! Txikitu arrokak, bai!\n"
	.string "Iuju!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "Ah, bai, arroka bat txikitzen baduzu,\n"
	.string "POKéMON bat agertu daiteke bat-batean.\p"
	.string "Iuju!$"

