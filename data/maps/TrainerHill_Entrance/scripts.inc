.set LOCALID_ATTENDANT, 1
.set LOCALID_NURSE, 2
.set LOCALID_GIRL, 4
.set LOCALID_MAN, 5

TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy OBJ_EVENT_ID_PLAYER, 9, 6
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_NURSE
	addobject LOCALID_ATTENDANT
	addobject LOCALID_MAN
	addobject LOCALID_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Expanded:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_Text_StillGettingReady:
	.string "Hau ERRONKA MUINOA da, hainbat\n"
	.string "ENTRENATZAILEREKIN borrokan gozatzeko\l"
	.string "leku paregabea.\p"
	.string "Hala ere, oraindik guztia prestatzen\n"
	.string "ari gara. Itzuli beranduago!$"

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
	.string "Ongi etorri!\p"
	.string "Hau ERRONKA MUINOA da, hainbat\n"
	.string "ENTRENATZAILEREKIN borrokan gozatzeko\l"
	.string "leku paregabea!$"

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
	.string "Zure lehenengo aldia al da?\p"
	.string "Sartu aurretik, gorde partida,\n"
	.string "mesedez.$"

TrainerHill_Entrance_Text_TrainersUpToFloorX:
	.string "Ikus dezagun…\n"
	.string "Orain dauden ENTRENATZAILEAK…\p"
	.string "{STR_VAR_1}. solairuraino daude.$"

TrainerHill_Entrance_Text_TrainersInEveryRoom:
	.string "Ikus dezagun…\n"
	.string "Orain dauden ENTRENATZAILEAK…\p"
	.string "Badirudi gela guztietan zehar\n"
	.string "daudela ENTRENATZAILEAK.$"

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
	.string "Nahi duzu itxaroten ari diren\n"
	.string "ENTRENATZAILEEI erronka bota?$"

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
	.string "Zure denbora neurtuko dut.\n"
	.string "Zorte on!\p"
	.string "Adi…\p"
	.string "Prest…\p"
	.string "Aurrera!$"

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
	.string "Etorri berriro, mesedez!$"

TrainerHill_Entrance_Text_TooBadTremendousEffort:
	.string "Pena izan da hori.\p"
	.string "Izugarrizko esfortzua egin\n"
	.string "duzu borrokan.\p"
	.string "Etorri eta saiatu berriro, mesedez!$"

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
	.string "Indar guztiz arituko zarela espero dut.$"

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
	.string "ENTRENATZAILEAK lekuz aldatzen direnean,\n"
	.string "mugimendua eromena izan daiteke.\p"
	.string "Zapalduak ez izateko, harrera\n"
	.string "gunea hona mugitu genuen.\p"
	.string "Barkatu eragozpenak.$"

TrainerHill_Entrance_Text_ThankYouForPlaying:
	.string "Eskerrik asko jolasteagatik!$"

TrainerHill_Entrance_Text_ExplainTrainerHill:
	.string "ERRONKA MUINPAN, Denbora Erasoa\n"
	.string "deituriko ekitaldi bat egiten dugu.\p"
	.string "Hemengo jaberaino iristen zenbat\n"
	.string "denbora behar duzun neurtzen dugu,\l"
	.string "hemendik hasi eta teilaturaino.\p"
	.string "Denbora onenak Denbora Taulan\n"
	.string "daude. Saiatu zure lagunekin\l"
	.string "norgehiagokan egiten.\p"
	.string "Bideko ENTRENATZAILE borroketan,\n"
	.string "ez da esperientzia edo dirurik\l"
	.string "lortzen.$"

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
	.string "Ene, barkatu, baina badirudi POKéMON\n"
	.string "bakarra daukazula taldean.\p"
	.string "Gutxienez bi POKéMON behar\n"
	.string "dituzu hemen parte hartzeko.$"

TrainerHill_Roof_Text_YouFinallyCameBravo:
	.string "Bai! Bai!\p"
	.string "Azkenean etorri zara!\n"
	.string "Bai, iritsi zara!\p"
	.string "Itxaron! Ez esan ezer!\n"
	.string "Badakit bide osoa bakarrik egin\l"
	.string "duzula honaino!\p"
	.string "Ni ikusi nahi ninduzun,\n"
	.string "ERRONKA MUINOAREN jabea…\p"
	.string "Nirekin taldea egiteko!\n"
	.string "Jai jauna!\p"
	.string "…Zer?\n"
	.string "Ezetz diozu?\p"
	.string "Berdin da, goraino iristen ikusi zaitut.\n"
	.string "Borroka itzelak! Zorionak, aizu!$"

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
	.string "Zu bezalako pertsona itzelak,\n"
	.string "opari itzela merezi du!$"

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
	.string "Ai ene, beteta zaude eta!\n"
	.string "Itzuli gero honen bila!$"

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
	.string "Ei, itxaron! Nola iritsi zara hona\n"
	.string "horren azkar, baina?\p"
	.string "Sinesgaitza! Ez zenuen presarik\n"
	.string "izan behar ni ikustera etortzeko!\p"
	.string "Zirraragarria da. Harrera guneko\n"
	.string "Denbora Taula eguneratuko dut!$"

TrainerHill_Roof_Text_YouWerentVeryQuick:
	.string "Baina, beno…\n"
	.string "Ez zara oso azkarra izan hona iristen.$"

TrainerHill_Roof_Text_ArriveZippierNextTime:
	.string "Agian hurrengoan azkarrago etorriko\n"
	.string "bazina hobe litzateke.\p"
	.string "Orduan, zurekin taldea egiteko\n"
	.string "prest egongo nintzateke!\p"
	.string "Ordura arte, lagun!$"

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
	.string "ERRONKA MUINOA eraikitzeko arrazoi\n"
	.string "bat eta bakarra nuen!\p"
	.string "Talde bat osatzeko bikote\n"
	.string "egokiena aurkitzea!$"

TrainerHill_Entrance_Text_ChallengeTime:
	.string "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} seg.$"

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
	.string "Nork jakin zein ENTRENATZAILE\n"
	.string "eta POKéMON konbo dauden aurretik?\p"
	.string "Nik dakidana da nire bidean dagoen\n"
	.string "edonor garaituko dudala!$"

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
	.string "Entzun dut ENTRENATZAILE indartsuak\n"
	.string "etorri ohi direla ERRONKA MUINORA.\p"
	.string "Ezin dut itxaron haien aurka egiteko!\p"
	.string "Nire bidean jartzen den\n"
	.string "edonor garaituko dut!$"

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.string "Ikusten al duzu horko Denbora Taula?\p"
	.string "Nire lagunak eta ni gora lehenago\n"
	.string "nor iritsiko norgehiagokan ari gara.$"

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
	.string "Badakizu noiz ireki behar duten\n"
	.string "leku hau?\p"
	.string "Hemen itxaroten ari naiz, lehenengo\n"
	.string "parte hartzailea izateko!$"

TrainerHill_Elevator_Text_ReturnToReception:
	.string "Nahi duzu harrera gunera\n"
	.string "itzuli?$"
