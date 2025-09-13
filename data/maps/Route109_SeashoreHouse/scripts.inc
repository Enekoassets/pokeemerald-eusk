Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
	giveitem ITEM_SODA_POP
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "ITSASERTZEKO ETXEAREN jabea naiz.\n"
	.string "ITSASO JAUNA dei diezadakezu!\p"
	.string "Gehien gustatzen zaidana POKéMON\n"
	.string "borroka beroak ikustea da.\p"
	.string "Erakutsi zure bihotza ere beroa dela!\p"
	.string "Hemengo ENTRENATZAILE guztiak garaituz\n"
	.string "gero, sari bat emango dizut.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Erakutsi borroka beroak!\p"
	.string "Arrazoi horregatik soilik daukat\n"
	.string "ITSASERTZEKO ETXEA!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Zu bai zu beroa!\n"
	.string "Borrokak ere sua bezain beroak!\l"
	.string "Oso oso pozik geratu naiz!\p"
	.string "Zure borroka estilo beroa erakutsi\n"
	.string "didazunez, hauek zuretzat dira.\p"
	.string "FRESKAGARRI dozena erdi bat!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Aizu, POLTSA goraino beteta duzu.\n"
	.string "Zuretzat gordeko ditut hauek.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Nahi al duzu FRESKAGARRIRIK?\n"
	.string "POKéMONEK oso atsegin dute!\p"
	.string "Soilik 300¥ botilako!\n"
	.string "Erosi!$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Tori!$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "Ez duzu nahikoa diru.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "Ez?\n"
	.string "Beno, pena da.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "ITSASERTZEKO ETXEAN borroka bila\n"
	.string "bazabiltza, ez duzu ni baino\l"
	.string "ENTRENATZAILE beroagorik aurkituko!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "Hori bai borroka beroa!\n"
	.string "Onartzen dut porrota!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "PORTUONDON nagoenean, borroka beroak\n"
	.string "eta FRESKAGARRI hotzak atsegin ditut!$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Borroka aspergarriek ez dute merezi.\p"
	.string "Borroka bero gogorrek ENTRENATZAILE\n"
	.string "POKéMONAK indartzen dituzte!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "Hori bai beroa!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Uf, a zer nolako egarria.\n"
	.string "FRESKAGARRI bat hartuko dut agian.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "Nire POKéMONAK zeinen itzelak diren\n"
	.string "erakutsiko dizut, baina ez egin negar!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "…Galdu egin dut, baina ez dut negar egingo…$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "Nire POKéMONETAKO batek ur gainetik\n"
	.string "bizkarrean eramateko erasoa jakingo\l"
	.string "balu, ez nuke flotagailurik behar.$"

