.set LOCALID_MOM, 1
.set LOCALID_RIVAL_MOM, 4
.set LOCALID_RIVAL, 7

LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_MOM, 8, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_MOM, 4, 5
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_MOM, 9, 8
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVAL_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVAL_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVAL
	delay 30
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere:
	.string "AMA: Ikusten, {PLAYER}?\n"
	.string "Hau ere leku ederra da, ezta?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "Etxe-aldaketako gizonaren POKéMONEK\n"
	.string "egiten dute guztia, baita garbitu ere.\l"
	.string "Benetan dira erabilgarriak!\p"
	.string "{PLAYER}, zure gela goiko pisuan dago.\n"
	.string "Joan ikustera, laztana!\p"
	.string "AITAK erloju berri bat oparitu dizu\n"
	.string "gure etxe-aldaketa eguna gogoratzeko.\l"
	.string "Ez ahaztu ondo ezartzea!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "AMA: Eta, {PLAYER}?\p"
	.string "Ez al daukazu gogorik zure gela\n"
	.string "berria ikusteko edo?$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "AMA: {PLAYER}.\p"
	.string "Ezarri ezazu zure gelako erlojua, maitea.$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "AMA: Aizu! {PLAYER}, {PLAYER}!\n"
	.string "Azkar! Etorri bizkor!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "AMA: Begira! PETALOREKO GIMNASIOA da!\n"
	.string "Agian AITA agertuko da!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "AMA: Ene… Bukatu egin da.\p"
	.string "Uste dut AITA agertu dela, baina ez dugu\n"
	.string "Ikusi. Pena.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "Ah, bai.\n"
	.string "AITAREN lagun bat bizi da herrian.\p"
	.string "URKI DOKTOREA izena du.\p"
	.string "Alboko etxean bizi da, beraz, joan\n"
	.string "eta aurkeztu zure burua.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "AMA: Gero arte, laztana!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "AMA: Aurkeztu al diozu zure burua\n"
	.string "URKI DOKTOREARI?$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "AMA: Zer moduz zaude, {PLAYER}?\n"
	.string "Nekatu aurpegia daukazu.\p"
	.string "Pixka bat deskantsatu behar zenuke.$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "AMA: Zaindu zaitez, maitea!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "AMA: Zer? AITAK eman al dizu DOMINA hori?\p"
	.string "Beno, ba orduan tori hau AMAREN partez!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "Ez egin ahalegin gehiegi, laztana.\n"
	.string "Beti itzuli zaitezke etxera.\p"
	.string "Animo, maitea!$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "AMA: Zer da hori, laztana? POKéNAV bat?\n"
	.string "DEVONEKO norbaitek eman dizu?\p"
	.string "Beno, laztana, zer iruditzen zure\n"
	.string "ama erregistratzen baduzu?\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "AMA erregistratu\n"
	.string "duzu POKéNAVEAN.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Huggoh, uggo uggo…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "KAZETARIA: …Erreportaia hau PETALOREKO\n"
	.string "GIMNASIO aurretik ekarri dizuegu.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "Pelikula bat dago telebistan.\p"
	.string "Bi gizon ari dira dantzan piano\n"
	.string "handi baten tekletan.\p"
	.string "Hobe joatea!$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "KORRIKAKO ZAPATILEN eskuliburua\n"
	.string "da.\p"
	.string "“Sakatu B Botoia KORRIKAKO\n"
	.string "ZAPATILEKIN korrika egiteko.\p"
	.string "“Estu lotu KORRIKAKO ZAPATILAK eta\n"
	.string "abiatu korrika bidean!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "AITA: Zer?\p"
	.string "Ei, {PLAYER} da eta!\p"
	.string "Denbroa pasa da azkenengotik, baina\n"
	.string "nolabait…indartsuagoa dirudizu.\p"
	.string "Itxura hori hartzen dizut.\n"
	.string "Baina zure zaharra ez da errenditu!\p"
	.string "Ah, bai, zerbait dut zuretzako.\n"
	.string "SARDINZAR JN. izeneko norbaitek\l"
	.string "bidali dizu.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "AITA: Zer, ferryrako TIKET bat?\p"
	.string "Ondo oroitzen banaiz, ferryentzat\n"
	.string "portuak daude PORTUONDON eta UR-LILIN.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "PETALOREKO GIMNASIORA itzuli behar dut.\p"
	.string "AMA, eskerrik asko etxea zaintzeagatik\n"
	.string "kanpoan nagoen bitartean.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "AMA: Zure AITA hau…\p"
	.string "Aspaldiko partez etorri, eta POKéMONEN\n"
	.string "inguruan besterik ez du hitz egiten.\p"
	.string "Pixka bat gehiago gertu behar luke.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "AMA: Azken orduko albistea al da hori?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "Azken orduko albiste bat\n"
	.string "dakarkizuegu, ikusleok!\p"
	.string "HOENNEKO hainbat lekutan,\n"
	.string "BZZT…koloreko POKéMON bat hegan\l"
	.string "ikusi da azken orduetan.\p"
	.string "POKéMON honen identitatea\n"
	.string "ezezaguna da oraingoz.\p"
	.string "Berriro itzuliko gara ohiko\n"
	.string "programaziora.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "AMA: {PLAYER}, entzun al duzu hori?\p"
	.string "Zein koloretakoa dela esan du\n"
	.string "POKéMONA kazetariak?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "AMA: Beno, interesgarria, bai! Oraindik\n"
	.string "badaude ezagutzen ez ditugun POKéMONAK.$"
