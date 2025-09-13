.set LOCALID_BRINEY, 1
.set LOCALID_PEEKO, 2

Route104_MrBrineysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
	.byte 0

Route104_MrBrineysHouse_OnTransition:
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
	call_if_eq VAR_BRINEY_HOUSE_STATE, 1, Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos
	call_if_set FLAG_RECEIVED_POKENAV, Route104_MrBrineysHouse_EventScript_HideRustboroRival
	end

Route104_MrBrineysHouse_EventScript_HideRustboroRival::
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	return

Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos::
	setobjectxyperm LOCALID_BRINEY, 9, 3
	setobjectmovementtype LOCALID_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
	setobjectxyperm LOCALID_PEEKO, 9, 6
	setobjectmovementtype LOCALID_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
	return

Route104_MrBrineysHouse_EventScript_Briney::
	lock
	faceplayer
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_SailingIntro
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_SailBothDeliveries
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_SailDeliverPackage
	goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
	end

Route104_MrBrineysHouse_EventScript_SailingIntro::
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	msgbox Route104_MrBrineysHouse_Text_WaitUpPeeko, MSGBOX_DEFAULT
	msgbox Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_WhereAreWeBound::
	message Route104_MrBrineysHouse_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 20, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
	switch VAR_RESULT
	case 0, Route104_MrBrineysHouse_EventScript_SailToDewford
	case 1, Route104_MrBrineysHouse_EventScript_DeclineSailing
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_DeclineSailing
	end

Route104_MrBrineysHouse_EventScript_SailBothDeliveries::
	msgbox Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_SailDeliverPackage::
	msgbox Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing::
	msgbox Route104_MrBrineysHouse_Text_DeclineDeliverySail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_DeclineSailing::
	msgbox Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_SailToDewford::
	msgbox Route104_MrBrineysHouse_Text_SetSailForDewford, MSGBOX_DEFAULT
	call EventScript_BackupMrBrineyLocation
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	warp MAP_ROUTE104, 13, 51
	waitstate
	releaseall
	end

Route104_MrBrineysHouse_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route104_MrBrineysHouse_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route104_MrBrineysHouse_Text_WaitUpPeeko:
	.string "SARDINZAR JN.: Itxaron, lagun!\n"
	.string "Aizu, itxaron, PEEKO!$"

Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford:
	.string "Nola? {PLAYER}{KUN} zara!\n"
	.string "Nire PEEKO maitea salbatu duzu!\l"
	.string "Guztia zor dizugu!\p"
	.string "Zer diozu?\n"
	.string "Nirekin nabigatu nahi duzula?\p"
	.string "Hmhm…\p"
	.string "IHINTZIBARRERAKO GUTUN bat eta\n"
	.string "PORTUONDORAKO pakete bat dituzu?\p"
	.string "Bizitza lanpetua duzu, alajaina!\p"
	.string "Baina, lasai, eskatzen ari zarena\n"
	.string "ez da arazoa niretzat.\p"
	.string "Gizon egokia aurkitu duzu!\n"
	.string "IHINTZIBARRERA abiatuko gara.$"

Route104_MrBrineysHouse_Text_SetSailForDewford:
	.string "SARDINZAR JN.: IHINTZIBARRERA,\p"
	.string "beraz! Jaso aingurak!\n"
	.string "PEEKO, bagoaz, maitea!$"

Route104_MrBrineysHouse_Text_DeclineDeliverySail:
	.string "SARDINZAR JN.: Benetan?\n"
	.string "Zure enkarguek ez dutela presarik?\p"
	.string "Zuk esan eta nahi duzunean\n"
	.string "abiatuko gara!$"

Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford:
	.string "SARDINZAR JN.: Kaixo, txo!\n"
	.string "Zehatz mehatz dakit zer esan nahi duzun!\p"
	.string "GUTUN bat duzu IHINTZIBARRERAKO eta\n"
	.string "pakete bat PORTUONDORAKO.\p"
	.string "Nigandik behar duzuna ez da inolako\n"
	.string "arazoa. Gizon egokia aukeratu duzu!\p"
	.string "Lehenengo, IHINTZIBARRERA abiatuko gara.$"

Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford:
	.string "SARDINZAR JN.: Kaixo, txo!\n"
	.string "Zehatz mehatz dakit zer esan nahi duzun!\p"
	.string "ABABOR KAPITAINARI pakete bat\n"
	.string "eraman behar diozu PORTUONDORA.\p"
	.string "Nigandik behar duzuna ez da inolako\n"
	.string "arazoa. Gizon egokia aukeratu duzu!\p"
	.string "Lehenengo, IHINTZIBARRERA abiatuko gara.$"

Route104_MrBrineysHouse_Text_WhereAreWeBound:
	.string "SARDINZAR JN.: Kaixo, txo!\n"
	.string "Zuretzat, egunero nabigatuko nuke!\p"
	.string "Esan, lagun, nora joan behar dugu?$"

Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail:
	.string "SARDINZAR JN.: Benetan?\n"
	.string "Beno, PEEKOK bizia zor dizu.\p"
	.string "Zuk esan eta nahi duzunean\n"
	.string "abiatuko gara!$"

Route104_MrBrineysHouse_Text_Peeko:
	.string "PEEKO: Pii piihyoro!$"

