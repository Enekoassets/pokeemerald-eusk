.set LOCALID_FAT_MAN, 1
.set LOCALID_MAN_1, 2
.set LOCALID_RICH_BOY, 3
.set LOCALID_GRUNT_1, 5
.set LOCALID_COOK, 6
.set LOCALID_OLD_WOMAN, 7
.set LOCALID_GIRL, 8
.set LOCALID_TY, 9
.set LOCALID_GABBY, 10
.set LOCALID_CAPT_STERN, 11
.set LOCALID_GRUNT_2, 18
.set LOCALID_GRUNT_3, 19
.set LOCALID_GRUNT_4, 26
.set LOCALID_GRUNT_5, 27
.set LOCALID_GRUNT_6, 28
.set LOCALID_GRUNT_7, 29
.set LOCALID_GRUNT_8, 30
.set LOCALID_GRUNT_9, 31
.set LOCALID_GRUNT_11, 33
.set LOCALID_SCOTT, 35

@ Note: LOCALID_SLATEPORT_ENERGY_GURU is a local id for this map used elsewhere. It's defined in event_objects.h

SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_COOK, 27, 16
	setobjectxyperm LOCALID_GIRL, 28, 16
	setobjectxyperm LOCALID_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_MAN_1, 31, 14
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SCOTT
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SCOTT
	setobjectxyperm LOCALID_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	pokemartlistend

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	pokemartlistend

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	pokemartlistend

SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	pokemartlistend

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_GABBY
	removeobject LOCALID_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SCOTT
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "ENERGIA GURUA naiz! Ea ba, behar\n"
	.string "duzuna salduko dizut!$"

SlateportCity_Text_OhYourPokemon:
	.string "Nola?\n"
	.string "Zure {STR_VAR_1}…$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "Izugarri saiatua da!\p"
	.string "Opari gisan, emaiozu SAIATUENEN\n"
	.string "ZINTA hau, mesedez.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER}(e)k SAIATUENEN ZINTA jaso du.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER}(e)k SAIATUENEN ZINTA\n"
	.string "{STR_VAR_1}(e)ri jarri dio.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "Gehixeago saiatu beharko duzu.\p"
	.string "Hala egiten baduzu, zure POKéMONARI\n"
	.string "zerbait bikaina emango diot.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "Ene! Zure {STR_VAR_1}, lirain\n"
	.string "dago SAIATUENEN ZINTA horrekin!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "Itsasargiaren argiak dozenaka\n"
	.string "kilometrotako irismena du.\p"
	.string "Espero dut ez dituela itsasoko\n"
	.string "POKéMONAK gogaituko.$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "Uau, ikusi hau!\p"
	.string "Hemen inguruan hazten diren algak\n"
	.string "freskoak eta bizitzaz beteak dira.\p"
	.string "Badirudi edozein momentutan esnatu\n"
	.string "eta erasotzeko prest daudela!$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "Ura garbia den lekuan, jaso daitezkeen\n"
	.string "fruitu pila bat hazten dira.\p"
	.string "Eta jendeak fruituak jasotzen baditu,\n"
	.string "merkatu bat eratu ohi da.\p"
	.string "Horrela sortu eta hazten da herri bat.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "Itsasoaren brisa arnastu bitartean\n"
	.string "erosketak egin ahal izatea…\p"
	.string "PORTUONDO leku itzela da!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "PANPINAK edo KUXINAK lurrean\n"
	.string "jarrita, zikindu egiten dira.\p"
	.string "ADREILU batzuk erosiko dituta,\n"
	.string "nire PANPINAK eta KUXINAK ez\l"
	.string "zikintzeko ipintzen ditudanean.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "Roooar! BORROKA DENDARA joango\n"
	.string "naiz erronkari aurre egitera!\p"
	.string "Baina horren aurretik, POKéMON\n"
	.string "batzuk harrapatu behar ditut!$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Ufff… Akituta nago…\p"
	.string "MALBADI HIRITIK nator oinez.\n"
	.string "Baina, benetan, hiri hau erraldoia da.\p"
	.string "Jakin izan banu BIZIKLETAZ\n"
	.string "etorriko nintzen.$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "ABABOR, MUSEOA eraiki zuen gizona,\n"
	.string "ur azpiko esplorazio talde bateko\l"
	.string "burua ere bada, dirudienez.\p"
	.string "Mundu guztiak ABABOR KAPT. deitzen dio.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "Zer da horko hori?\n"
	.string "Lerro luze hori…$"

SlateportCity_Text_VisitedMuseumOften:
	.string "Umea nintzenean, askotan\n"
	.string "joaten nintzen MUSEORA.\p"
	.string "Itsasoaren misterioen inguruan amesten\n"
	.string "nuen erakusketak ikusi ostean.$"

SlateportCity_Text_QuitPushing:
	.string "Ei, aizu! Ez bultza!\n"
	.string "Hau da ilara, ez al duzu ikusten?$"

SlateportCity_Text_AquaHasPolicy:
	.string "AQUA TALDEAK bildu eta\n"
	.string "sakabanatzeko politika du\l"
	.string "operazio gunean.$"

SlateportCity_Text_BossIsBrilliant:
	.string "Gure NAGUSIA bikaina da.\p"
	.string "Zer egin nahi ote du orain\n"
	.string "MUSEO batean?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "Zein ote da plan berria?\p"
	.string "NAGUSIA beldurgarria da haserretzen\n"
	.string "denean, hobe dut gauzak ondo egin…$"

SlateportCity_Text_ShouldTakeItAll:
	.string "MUSEOAN behar dugun zeozer baldin\n"
	.string "badago, guztia hartu behar genuke!$"

SlateportCity_Text_DontButtIn:
	.string "Ei, ei, aizu!\n"
	.string "Ez oztopatu!$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "Ilara luzea, ezta?\p"
	.string "Atera berri ziren jokoak erosten\n"
	.string "nitueneko garaia oroitarazten dit…$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "Zergatik ari gara itxaron eta ordaintzen?\n"
	.string "Sar gaitezen denok, eta kito!$"

SlateportCity_Text_WhatDoYouWant:
	.string "Zer?\n"
	.string "Zer nahi duzu?$"

SlateportCity_Text_IllReadSignForYou:
	.string "Kartela irakurri nahi duzu?\n"
	.string "Nik irakurriko dizut!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "Ikus dezagun…\p"
	.string "Ba… Halako zerbait dio:\n"
	.string "“itsasoko bizitza amaigabea da.”\p"
	.string "Bai, horrelako zeozer jartzen du,\n"
	.string "ziur nago.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "Kaka…\p"
	.string "Nire Game Boy Advancea ekarri\n"
	.string "behar nuen ilaran ez aspertzeko…\p"
	.string "Kaka…$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "Operazio hau amaitzen denean, ur\n"
	.string "termal batzuetara eramango zaituztet!\p"
	.string "Hori esan zigun nagusiak.\n"
	.string "Irrikan nago!$"

SlateportCity_Text_SeaIsSoWet:
	.string "Itsasoa izugarri zabala da…\p"
	.string "Ez ote da itsasoa POKéMONEN\n"
	.string "malkoek osatuta egongo?$"

SlateportCity_Text_SinkOldBoats:
	.string "Badakizu zer egiten duten nabigatzeko\n"
	.string "zaharregiak diren itsasontziekin?\p"
	.string "Itsasoan hondoratzen dituzte,\n"
	.string "POKéMONENTZAKO bizileku bilakatzeko.$"

SlateportCity_Text_BuyTooMuch:
	.string "Hona etortzen naizen bakoitzean,\n"
	.string "gehiagi galtzen dut kontrola.$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "Zure POKéMONAREN ezizena aldatu\n"
	.string "nahi baduzu, eskatu laguntza\l"
	.string "EZIZENEN INSPEKTOREARI.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "Truke batean POKéMON bat jasotzen\n"
	.string "baduzu, ezin diozu ezizena aldatu.\p"
	.string "Hasierako ENTRENATZAILEAREN maitasuna\n"
	.string "POKéMONAREN ezizenean dago eta.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "Duela gutxi, BORROKA DENDA eraiki\n"
	.string "zuten PORTUONDON.\p"
	.string "GIMNASIOAK itzelak dira, baina BORROKA\n"
	.string "DENDA izugarria da, bere eran.\p"
	.string "POKéMON indartsuak lortu behar\n"
	.string "zenituzke BORROKA DENDARAKO!$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "Pertsona famatu bat izatea espero\n"
	.string "nuen, autografoa eskatzeko.\p"
	.string "Baina zein ari dira elkarrizketatzen?\n"
	.string "Ez al da ABABOR KAPITAINA?$"

SlateportCity_Text_InterviewerSoCool:
	.string "Elkarrizketatzailea oso polita\n"
	.string "eta itzela da.\p"
	.string "Handitzen naizenean, kazetari\n"
	.string "internazionala izango naiz!$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "Itsas hondoan zerbait aurkitu\n"
	.string "zutela dio ABABOR KAPITAINAK.\p"
	.string "Zer izan daiteke?\n"
	.string "Zer izango ote da?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "Zer gertatzen da hemen?\p"
	.string "Arrain handiren bat harrapatu ote\n"
	.string "du KAPITAINAK itsas hondoan?$"

SlateportCity_Text_AmIOnTV:
	.string "Ei! Begira al zaude?\n"
	.string "Telebistan al nago?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "Telebistako elkarrizketa bat! Hemen!\n"
	.string "KAPITAINA famatua da!$"

SlateportCity_Text_BigSmileForCamera:
	.string "IKER: Ongi, ABABOR KAPITAINA, egin\n"
	.string "kamerari irribarre!$"

SlateportCity_Text_MostInvaluableExperience:
	.string "AMANE: Ados, ados. Esperientzia\n"
	.string "paregabea izan duzue, beraz…$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "ABABOR KAPT.: Bai, alajaina. Oraindik\n"
	.string "esplorazioarekin jarraitzeko asmoa dugu.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "AMANE: Bikain, ABABOR KAPITAINA!\n"
	.string "Eskerrik asko denbora tarte hau\l"
	.string "guri eskaintzeagatik.\p"
	.string "Ea beste batean elkarrizketatzen\n"
	.string "zaitugun, aurkikuntza berriak egitean!$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "ABABOR KAPT.: Ufff…\p"
	.string "Nire lehen aldia izan da telebistako\n"
	.string "grabazio batean. A zer urduritasuna.$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "Ei! {PLAYER}{KUN}!\n"
	.string "Itxura ona duzu!\p"
	.string "Aurkikuntza izugarria egin genuen\n"
	.string "gure azken urpeko esplorazioan.\p"
	.string "128. ERRUTAN ur azpiko kobazulo\n"
	.string "bat aurkitu genuan.\p"
	.string "Uste dugu aspaldian desagertutako\n"
	.string "POKéMON baten bizilekua dela.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "Fufufu…\n"
	.string "ABABOR KAPITAINA, suposatzen dut.\p"
	.string "AQUA TALDEAK zure urpekoaren\n"
	.string "kontrola hartuko dugu!\p"
	.string "Zure ezezkoak ez du balio!\n"
	.string "Kooperazio osoa espero dugu!\p"
	.string "Fufufu…\n"
	.string "Ikusi eta ikasi AQUA TALDEAK\l"
	.string "prestatu duenarekin!$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "ABABOR KAPT.: Zer izan da hori?\p"
	.string "Badirudi norbait megafono bat\n"
	.string "erabiltzen ari zela…\p"
	.string "Nondik etorri da?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "KAI aldean izan da!\p"
	.string "Urpekoa!\n"
	.string "Hartzen saiatzen ari dira!$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{PLAYER}{KUN}!\n"
	.string "Etorri nirekin, mesedez!$"

SlateportCity_Text_BattleTentSign:
	.string "PORTUONDOKO BORROKA DENDA\n"
	.string "“Aurkitu! Berebiziko POKéMONA!”$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "ABABORREN ONTZIDIA\p"
	.string "“Bila gabiltza: Edozein ur lasterretan\n"
	.string "nabigatzeko gai den marinela.”$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "ABABORREN ONTZIDIA\p"
	.string "“MAREA ONTZIA ia-ia prest dago\n"
	.string "UR-LILI eta PORTUONDO artean\l"
	.string "zerbitzua ematen hasteko.”$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "ABABORREN ONTZIDIA\p"
	.string "“UR-LILI eta PORTUONDO arteko MAREA\n"
	.string "ontzira igotzeko, beharrezkoa da\l"
	.string "KAIRA joatea.”$"

SlateportCity_Text_PokemonFanClubSign:
	.string "POKéMON FAN KLUBA\n"
	.string "“POKéMONEN fan guztien etxea!”$"

SlateportCity_Text_OceanicMuseumSign:
	.string "“Itsaso amaigabea bizitza\n"
	.string "osoaren euskarria da.”\p"
	.string "MUSEO OZEANIKOA$"

SlateportCity_Text_CitySign:
	.string "PORTUONDO HIRIA\p"
	.string "“POKéMONEN eta pertsonen bideak\n"
	.string "elkartzen diren portua.”$"

SlateportCity_Text_MarketSign:
	.string "PORTUONDOKO MERKATUA\n"
	.string "“Beste inon aurkituko ez dituzun gauzak!”$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "PORTUONDOKO KAIA\p"
	.string "“MAREA ONTZI ferrya eraikitzen\n"
	.string "ari dira ONTZIDIAN.\p"
	.string "“Zerbitzua laister jarriko da\n"
	.string "martxan.”$"

SlateportCity_Text_HarborSign:
	.string "PORTUONDOKO KAIA\p"
	.string "“Gozatu bidaia eder bat\n"
	.string "MAREA ONTZI ferryan.”$"

SlateportCity_Text_NameRatersHouseSign:
	.string "EZIZENEN INSPEKTOREAREN ETXEA\n"
	.string "“POKéMONEN ezizenak aztertzen ditugu.”$"

SlateportCity_Text_ExplainBerries:
	.string "POKéMON basati batek mina hartzen badu,\n"
	.string "bere burua sendatzen du BAIAK janda.\p"
	.string "Ba al zenekien?\p"
	.string "Norbaitek hori ikusi zuen eta\n"
	.string "BAIEKIN sendagaiak egiten hasi zen.\p"
	.string "Ba al zenekien?\p"
	.string "BAIAK botika bihurtzeko, lehenengo\n"
	.string "hauts bihurty behar dira.\p"
	.string "Ba al zenekien?\p"
	.string "Badirudi BAIAK interesatzen\n"
	.string "zaizkizula!\p"
	.string "Zerbait daukat zu bezalako\n"
	.string "norbaitentzat.$"

SlateportCity_Text_ExplainBerryPowder:
	.string "Duela gutxi BAIAK txikitzeko makinak\n"
	.string "jarri ditugu POKéMON ZENTROETAN.\p"
	.string "BAIA BIRRINTZAILEAK goiko pisuan\n"
	.string "daude, ZUZENEKO TXOKOAN.\p"
	.string "Ba al zenekien?\p"
	.string "Egingo zenidake BAIA HAUTSA\n"
	.string "makina hoiek erabilita?\p"
	.string "Era guztietako sendagaiak egin\n"
	.string "ditzaket BAIA HAUTSA ekartzen badidazu.$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "Ekarri al didazu\n"
	.string "BAIA HAUTSA?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "Zer nahiko zenuke aldatu\n"
	.string "horren truke?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "Ongi, zure BAIA HAUTSA aldatu nahi\n"
	.string "duzu {STR_VAR_1} baten truke?$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "Ai ene. Ez daukazu nahikoa\n"
	.string "BAIA HAUTS.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "Hau BAIA HAUTS ona da, bai.\n"
	.string "Bikaina izango da botikak egiteko.\p"
	.string "Nahi duzu BAIA HAUTS gehiago\n"
	.string "trukatu beste zerbaiten truke?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "Ongi! BAIA HAUTS gehiago lortzen\n"
	.string "baduzu, ekarri niri, mesedez!$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Itzuli zure BAIA HAUTSA botika\n"
	.string "gehiagoren truke trukatu nahi baduzu.\p"
	.string "Beti dut bazaarra irekita.\p"
	.string "Ba al zenekien?$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "TRIKI: Nola?\n"
	.string "Ziur nago lehenago nonbait ikusi zaitudala.\p"
	.string "Zuk ezagutzen al nauzu?\n"
	.string "Bestela, nire izena TRIKI da.\p"
	.string "AQUA TALDEA ihes egiten dut oraintxe\n"
	.string "bertan, zizta egin izan balie bezala.\p"
	.string "Utzi asmatzen; zuk bidali al dituzu?$"

SlateportCity_Text_MaybeThisTrainer:
	.string "TRIKI: Hmm…\n"
	.string "Agian, agian soilik, ENTRENATZAILE hau…$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "TRIKI: Bikain! Esango nuke zu eta\n"
	.string "ni lagun onak bilakatuko garela.\p"
	.string "Erregistratu gaitezen elkarren\n"
	.string "POKéNAVETAN.\p"
	.string "… … … … … …$"

SlateportCity_Text_RegisteredScott:
	.string "TRIKI hau zure POKéNAVEAN\n"
	.string "erregistratu duzu.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "TRIKI: Zure jarraipen txiki bat egin\n"
	.string "nahiko nuke, baina beste batzuen\l"
	.string "talentua ere jarraitu nahi nuke.\p"
	.string "Horregatik, beste herri batzuetara\n"
	.string "joango naiz, jende gehiago ezagutzera.\p"
	.string "Pozten naiz zu ezagututa, {PLAYER}{KUN}!$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "TRIKI: Ei, aizu!\n"
	.string "{PLAYER}{KUN} da eta!\p"
	.string "{PLAYER}{KUN}, utzi asmatzen: BORROKA\n"
	.string "DENDAKO erronkari aurre egitera zatoz?\p"
	.string "Bai! Ideia bikaina da hori!\n"
	.string "Benetan da ideia bikaina da!\p"
	.string "Azken finean, ENTRENATZAILE indartsuak\n"
	.string "BORROKA DENDARA joan behar dira!\p"
	.string "Saiatu, ea lortzen duzun!$"
