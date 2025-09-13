.set LOCALID_BRINEY, 11
.set LOCALID_WANDAS_BF_OUTSIDE, 21

Route116_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route116_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route116_OnFrame
	.byte 0

Route116_OnTransition:
	call_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_SetWandasBoyfriendPos
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH, AbnormalWeather_StartGroudonWeather
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH, AbnormalWeather_StartGroudonWeather
	end

Route116_EventScript_SetWandasBoyfriendPos::
	setobjectxyperm LOCALID_WANDAS_BF_OUTSIDE, 38, 10
	return

Route116_OnLoad:
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute116North
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute116South
	end

Route116_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route116_EventScript_WandasBoyfriend::
	lock
	faceplayer
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_BoyfriendGruntLeftTunnel
	goto_if_set FLAG_DEVON_GOODS_STOLEN, Route116_EventScript_BoyfriendGruntInTunnel
	msgbox Route116_Text_WantToDigTunnel, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_BoyfriendGruntLeftTunnel::
	msgbox Route116_Text_GoonHightailedItOutOfTunnel, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_BoyfriendGruntInTunnel::
	msgbox Route116_Text_DiggingTunnelWhenGoonOrderedMeOut, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_DevonEmployee::
	lock
	faceplayer
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, Route116_EventScript_TryGiveRepeatBallAgain
	msgbox Route116_Text_ThankYouTokenOfAppreciation, MSGBOX_DEFAULT
	goto Route116_EventScript_GiveRepeatBall
	end

Route116_EventScript_GiveRepeatBall::
	setflag FLAG_MET_DEVON_EMPLOYEE
	giveitem ITEM_REPEAT_BALL
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_NoRoomForRepeatBall
	msgbox Route116_Text_NewBallAvailableAtMart, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_DevonEmployeeExit
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_DevonEmployeeExit
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_DevonEmployeeExit
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_DevonEmployeeExitEast
	removeobject VAR_LAST_TALKED
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setflag FLAG_RECEIVED_REPEAT_BALL
	release
	end

Route116_EventScript_DevonEmployeeExit::
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExit
	waitmovement 0
	return

Route116_EventScript_DevonEmployeeExitEast::
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExitEast
	waitmovement 0
	return

Route116_EventScript_TryGiveRepeatBallAgain::
	msgbox Route116_Text_TokenOfAppreciation, MSGBOX_DEFAULT
	goto Route116_EventScript_GiveRepeatBall
	end

Route116_EventScript_NoRoomForRepeatBall::
	msgbox Route116_Text_BagIsJamPacked, MSGBOX_DEFAULT
	release
	end

Route116_Movement_DevonEmployeeExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_Movement_DevonEmployeeExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_EventScript_RouteSignRustboro::
	msgbox Route116_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route116_EventScript_RusturfTunnelSign::
	msgbox Route116_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

Route116_EventScript_TunnelersRestHouseSign::
	msgbox Route116_Text_TunnelersRestHouse, MSGBOX_SIGN
	end

Route116_EventScript_TrainerTipsBToStopEvolution::
	msgbox Route116_Text_TrainerTipsBToStopEvolution, MSGBOX_SIGN
	end

Route116_EventScript_TrainerTipsBagHasPockets::
	msgbox Route116_Text_TrainerTipsBagHasPockets, MSGBOX_SIGN
	end

Route116_EventScript_Briney::
	lock
	faceplayer
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
	setvar VAR_ROUTE116_STATE, 2
	release
	end

Route116_EventScript_BrineyTrigger::
	lockall
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFasterRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
	setvar VAR_ROUTE116_STATE, 2
	releaseall
	end

Route116_EventScript_GlassesMan::
	lock
	faceplayer
	checkitem ITEM_BLACK_GLASSES
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_PlayerHasGlasses
	specialvar VAR_RESULT, FoundBlackGlasses
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesNotOnPlayer
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_FoundGlassesNotOnPlayer::
	msgbox Route116_Text_CantFindGlassesNotHere, MSGBOX_DEFAULT
	closemessage
	goto Route116_EventScript_GlassesManExit
	end

Route116_EventScript_PlayerHasGlasses::
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
	msgbox Route116_Text_MayISeeThoseGlasses, MSGBOX_DEFAULT
	specialvar VAR_RESULT, FoundBlackGlasses
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesOnPlayer
	msgbox Route116_Text_NotWhatImLookingFor, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_FoundGlassesOnPlayer::
	msgbox Route116_Text_NotWhatImLookingForMaybeTheyArentHere, MSGBOX_DEFAULT
	closemessage
	goto Route116_EventScript_GlassesManExit
	end

Route116_EventScript_GlassesManExit::
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_GlassesManExitNormal
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_GlassesManExitNormal
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_GlassesManExitNormal
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_GlassesManExitEast
	removeobject VAR_LAST_TALKED
	release
	end

Route116_EventScript_GlassesManExitNormal::
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExit
	waitmovement 0
	return

Route116_EventScript_GlassesManExitEast::
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExitEast
	waitmovement 0
	return

Route116_Movement_GlassesManExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_Movement_GlassesManExitEast:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_EventScript_Joey::
	trainerbattle_single TRAINER_JOEY, Route116_Text_JoeyIntro, Route116_Text_JoeyDefeat
	msgbox Route116_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Jose::
	trainerbattle_single TRAINER_JOSE, Route116_Text_JoseIntro, Route116_Text_JoseDefeat
	msgbox Route116_Text_JosePostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Jerry::
	trainerbattle_single TRAINER_JERRY_1, Route116_Text_JerryIntro, Route116_Text_JerryDefeat, Route116_EventScript_TryRegisterJerryAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchJerry
	setvar VAR_0x8004, TRAINER_JERRY_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterJerry
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_TryRegisterJerryAfterBattle::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerryAfterBattle
	release
	end

Route116_EventScript_RegisterJerryAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route116_Text_JerryRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JERRY_1
	release
	end

Route116_EventScript_TryRegisterJerry::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerry
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_RegisterJerry::
	msgbox Route116_Text_JerryRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JERRY_1
	release
	end

Route116_EventScript_RematchJerry::
	trainerbattle_rematch TRAINER_JERRY_1, Route116_Text_JerryRematchIntro, Route116_Text_JerryRematchDefeat
	msgbox Route116_Text_JerryPostRematch, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Clark::
	trainerbattle_single TRAINER_CLARK, Route116_Text_ClarkIntro, Route116_Text_ClarkDefeat
	msgbox Route116_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Janice::
	trainerbattle_single TRAINER_JANICE, Route116_Text_JaniceIntro, Route116_Text_JaniceDefeat
	msgbox Route116_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Karen::
	trainerbattle_single TRAINER_KAREN_1, Route116_Text_KarenIntro, Route116_Text_KarenDefeat, Route116_EventScript_TryRegisterKarenAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchKaren
	setvar VAR_0x8004, TRAINER_KAREN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterKaren
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_TryRegisterKarenAfterBattle::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKarenAfterBattle
	release
	end

Route116_EventScript_RegisterKarenAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route116_Text_KarenRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_KAREN_1
	release
	end

Route116_EventScript_TryRegisterKaren::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKaren
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_RegisterKaren::
	msgbox Route116_Text_KarenRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_KAREN_1
	release
	end

Route116_EventScript_RematchKaren::
	trainerbattle_rematch TRAINER_KAREN_1, Route116_Text_KarenRematchIntro, Route116_Text_KarenRematchDefeat
	msgbox Route116_Text_KarenPostRematch, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Sarah::
	trainerbattle_single TRAINER_SARAH, Route116_Text_SarahIntro, Route116_Text_SarahDefeat
	msgbox Route116_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Dawson::
	trainerbattle_single TRAINER_DAWSON, Route116_Text_DawsonIntro, Route116_Text_DawsonDefeat
	msgbox Route116_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Devan::
	trainerbattle_single TRAINER_DEVAN, Route116_Text_DevanIntro, Route116_Text_DevanDefeat
	msgbox Route116_Text_DevanPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Johnson::
	trainerbattle_single TRAINER_JOHNSON, Route116_Text_JohnsonIntro, Route116_Text_JohnsonDefeat
	msgbox Route116_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_Text_ScoundrelMadeOffWithPeeko:
	.string "Ene, zer egingo dut?\p"
	.string "Paseoan genbiltzala, PEEKO eta ni, tipo\n"
	.string "arraro batek geratu gaituenean…\p"
	.string "Gaiztagin horrek nire PEEKO\n"
	.string "maitea eraman du!\p"
	.string "Rrrooooooaaaar! PEEKO!$"

Route116_Text_WantToDigTunnel:
	.string "Nnn… Roar!\p"
	.string "Tunel hori zulatu nahi dut!$"

Route116_Text_DiggingTunnelWhenGoonOrderedMeOut:
	.string "Nnn… Roar!\n"
	.string "Zer ari da gertatzen?\p"
	.string "Tresnarik gabe tunela zulatzen ari\n"
	.string "nintzen eta txoro batek kanpora bota nau!\p"
	.string "Tunela zarata gogorrek beldurtzen\n"
	.string "dituzten POKéMONEZ betea dago.\l"
	.string "Zalaprta izugarria egin dezakete.\p"
	.string "Horregatik utzi genion tunelak\n"
	.string "egiteko tresnak erabiltzeari…\p"
	.string "Kezkatu egiten nau txoro horrek\n"
	.string "zerbait egin eta POKéMONAK\l"
	.string "aztoratzen baditu.$"

Route116_Text_GoonHightailedItOutOfTunnel:
	.string "Nnn… Roar!\p"
	.string "Txoro hori atera da azkenean tuneletik!\n"
	.string "Berriz itzuli naiteke zulatzera!$"

Route116_Text_ThankYouTokenOfAppreciation:
	.string "Ei! Zu zara!\p"
	.string "PETALORE BASOAN lagundu zenidan, eta\n"
	.string "gainera nire lapurtutako paketea\l"
	.string "itzuli eta ontasun handiz\l"
	.string "PORTUONDORA ERAMAN ZENUEN!\p"
	.string "ABABOR KAPITAINAK abisatu zigun\n"
	.string "paketea iritsi zenean, bai!\p"
	.string "Izugarri eskertzen dizut!\p"
	.string "Hodei bat izango banintz, esker\n"
	.string "onezko zaparrada bat botako nizuke\l"
	.string "eta heroi bezala goraipatu!\p"
	.string "Berri onak ditut zuretzat,\n"
	.string "ENTRENATZAILE bikaina!\p"
	.string "Duela gutxi, gure enpresak POKé\n"
	.string "BALL berri bat garatu du.\p"
	.string "Esker ona adierazteko, opari hau\n"
	.string "gure ENTRENATZAILE bikainarentzat!$"

Route116_Text_NewBallAvailableAtMart:
	.string "Gure POKé BALL berria eskuragarri\n"
	.string "dago BURDINTZAKO POKéMON DENDAN.\p"
	.string "Probatu ezazu, mesedez!\n"
	.string "Eskerrik asko eta aio-aio!$"

Route116_Text_BagIsJamPacked:
	.string "Zure POLTSA gainezka dago.\n"
	.string "Ezin dizut BERRIZ BALL hau eman.$"

Route116_Text_TokenOfAppreciation:
	.string "Gure paketea bidaltzeagatik esker\n"
	.string "onak emateko, POKé BALL mota\l"
	.string "berri bat daukat ENTRENATZAILE\l"
	.string "bikainarentzat!$"

Route116_Text_CanYouHelpMeFindGlasses:
	.string "Betaurrekoak galdu ditut…\n"
	.string "Lagunduko zenidake bilatzen?$"

Route116_Text_MayISeeThoseGlasses:
	.string "Betaurreko horiek!\n"
	.string "Erakutsiko zenizkidake, mesedez?$"

Route116_Text_NotWhatImLookingForMaybeTheyArentHere:
	.string "Hmm…\n"
	.string "Hauek EGUZKITAKO BETAURREKOAK dira.\l"
	.string "Ez naiz horrelakoen bila ari…\p"
	.string "Agian nire betaurrekoak ez daude\n"
	.string "hemen inguruan…$"

Route116_Text_CantFindGlassesNotHere:
	.string "Hmm…\n"
	.string "Ezin ditut nire betaurrekoak aurkitu…\l"
	.string "Agian ez daude hemen inguruan…$"

Route116_Text_NotWhatImLookingFor:
	.string "Hmm…\n"
	.string "Hauek EGUZKITAKO BETAURREKOAK dira.\l"
	.string "Ez naiz horrelakoen bila ari…$"

Route116_Text_RouteSignRustboro:
	.string "116. ERRUTA\n"
	.string "{LEFT_ARROW} BURDINTZA HIRIA$"

Route116_Text_RusturfTunnelSign:
	.string "BURDIZELAI TUNELA\n"
	.string "“BURDINTZA eta BERDEZELAI lotuz\p"
	.string "“Tunela egiteko proiektua bertan\n"
	.string "behera gelditu da.”$"

Route116_Text_TunnelersRestHouse:
	.string "TTUNELGILEAREN DESKANTSU ETXEA$"

Route116_Text_TrainerTipsBToStopEvolution:
	.string "ENTRENATZAILEENTZAKO PISTAK\p"
	.string "Ez baduzu nahi POKéMON bat\n"
	.string "eboluzionatzea, sakatu B botoia\l"
	.string "eboluzionatzen saiatzen ari denean.\l"
	.string "POKéMON harritua gelditu egingo da.\p"
	.string "Eboluzioa ezeztatzea deitzen zaio.$"

Route116_Text_TrainerTipsBagHasPockets:
	.string "ENTRENATZAILEENTZAKO PISTAK\p"
	.string "Zure POLTSAK hainbat POLTSIKO ditu.\p"
	.string "Lortzen dituzun itemak automatikoki\n"
	.string "jartzen dira POLTSIKO egokietan.\p"
	.string "ENTRENATZAILE bat ere ezin da\n"
	.string "bere POLTSA gabe hor zehar ibili.$"

