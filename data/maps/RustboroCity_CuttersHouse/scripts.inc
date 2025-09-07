RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Begirada ausart hori…\n"
	.string "Ibilkera arin hori…\l"
	.string "Eta zure ondo entrenatutako POKéMONAK…\p"
	.string "ENTRENATZAILE trebea zara, bai!\p"
	.string "Ez, itxaron, ez esan ezer.\n"
	.string "Zu ikusita bakarrik jakin dezaket.\p"
	.string "Ziur nago MAKINA EZKUTU honi\n"
	.string "erabilera egokia emango diozula.\p"
	.string "Ez izan lotsarik.\n"
	.string "Ea ba, hartu ezazu!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "MAKINA EZKUTU hori, ME, labur\n"
	.string "esateko, EBAKIA da.\p"
	.string "ME eraso bat borrokatik kanpo ere\n"
	.string "erabili dezake POKéMON batek.\p"
	.string "EBAKIA ikasi duen POKéMON batek\n"
	.string "zuhaitzak moztu ditzake, bere\l"
	.string "ENTRENATZAILEAK HARRI DOMINA badu.\p"
	.string "Eta, MT bat ez bezala, ME bat\n"
	.string "nahi adina erabili daiteke.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "BURDINTZA HIRIA zabaltzen ari zirenean,\n"
	.string "nire aitak lagundu egin zuen.\p"
	.string "Bere POKéMONAK erabili zituen, EBAKIA\n"
	.string "erabiliz zuhaitzak mozteko.$"

