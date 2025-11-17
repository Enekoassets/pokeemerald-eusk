.set LOCALID_HIDEOUT_GUARD, 5

JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
	.string "TXIMINIA MENDIKO HAIZPITARTEA…\p"
	.string "Hori da mendi batean gehien\n"
	.string "gustatzen zaidana.\p"
	.string "Jauzi ero hauek…\n"
	.string "Arima pizten didate!$"

JaggedPass_Text_EricDefeat:
	.string "Bai garratza galtzea!$"

JaggedPass_Text_EricPostBattle:
	.string "Bai, galdu egin dut POKéMON borrokan…\p"
	.string "Baina mendiekiko dudan maitasunean\n"
	.string "ezin didazu irabazi!$"

JaggedPass_Text_DianaIntro:
	.string "Hau ez da paseo arrunta.\n"
	.string "Hemen ezin da piknikik egin.$"

JaggedPass_Text_DianaDefeat:
	.string "Aiiii, ez!\n"
	.string "Lurra malkartsuegia da…$"

JaggedPass_Text_DianaPostBattle:
	.string "Ba al zenekien?\p"
	.string "Badago jendea jauziz beteriko bide\n"
	.string "hau bizikletan igotzen duena.$"

JaggedPass_Text_DianaRegister:
	.string "Inoiz bueltatuko al zara hemen ingurura?\n"
	.string "Baldin bazatoz, errebantxa nahi nuke.$"

JaggedPass_Text_DianaRematchIntro:
	.string "Piknikak dibertigarriak dira beti.\n"
	.string "POKéMONAK bezala!$"

JaggedPass_Text_DianaRematchDefeat:
	.string "Lurra malkartsuegia delako galdu\n"
	.string "dut, besterik ez!$"

JaggedPass_Text_DianaPostRematch:
	.string "Galdu dudala ahaztu eta paseo\n"
	.string "malkartsu hau gozatuko dut.$"

JaggedPass_Text_EthanIntro:
	.string "HAIZPITARTEAN ibiltzea ez da erraza.\n"
	.string "Entrenatzeko leku ona da.$"

JaggedPass_Text_EthanDefeat:
	.string "Hankak non jarri erabaki baino\n"
	.string "lehenago galdu dut…$"

JaggedPass_Text_EthanPostBattle:
	.string "BIZIKLETA AKROBATIKO bat banu,\n"
	.string "jauzika igoko nuke hau.$"

JaggedPass_Text_EthanRegister:
	.string "Leku malkartsu honetara ohitzen naizenean,\n"
	.string "ziur edonori irabaziko diodala!\p"
	.string "Erregistratuko nauzu POKéNAVEAN?$"

JaggedPass_Text_EthanRematchIntro:
	.string "Ohitu naiz leku malkartsu honetara.\n"
	.string "Kantatu bitartean igotzen dut orain.$"

JaggedPass_Text_EthanRematchDefeat:
	.string "Hala ere ez da erraza leku malkartsu\n"
	.string "honetan borrokan aritzea…$"

JaggedPass_Text_EthanPostRematch:
	.string "MALBADIKO ANAKLETOREN dendatik\n"
	.string "BIZIKLETA AKROBATIKOA hartu behar nuke…$"

JaggedPass_Text_GruntIntro:
	.string "Ei!\n"
	.string "Zertan ari zara hemen?\p"
	.string "Zertan ari ote naiz ni hemen?\p"
	.string "Eta zuri zer inporta zaizu?$"

JaggedPass_Text_GruntDefeat:
	.string "Uffff…\p"
	.string "Gure EZKUTALEKUAN sartu behar\n"
	.string "nintzen segituan…$"

JaggedPass_Text_GoWhereverYouWant:
	.string "Ongi, on-gi!\n"
	.string "Onartzen dut, indartsua zara!\p"
	.string "Ez kezkatu nigatik.\n"
	.string "Nahi duzun lekura joan!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "Ene! Haitza dardarka jarri da MAGMA\n"
	.string "ENBLEMARENGATIK!$"

JaggedPass_Text_JulioIntro:
	.string "Eneeee! Oso beldurgarria da\n"
	.string "mendia zuzenean jaistea!$"

JaggedPass_Text_JulioDefeat:
	.string "Hausten ariko banintz bezala da…$"

JaggedPass_Text_JulioPostBattle:
	.string "Halako saltoak eman ditu nire bizikletak,\n"
	.string "ipurdiko min izugarria daukat…$"

JaggedPass_Text_AutumnIntro:
	.string "Egunero igotzen dut tontor hau.\n"
	.string "Konfidantza dut nire indarrean!$"

JaggedPass_Text_AutumnDefeat:
	.string "Hmm…\n"
	.string "Zer gertatu ote da?$"

JaggedPass_Text_AutumnPostBattle:
	.string "Zer da hor pixka bat gorago\n"
	.string "dagoen arroka konkor hori?$"

