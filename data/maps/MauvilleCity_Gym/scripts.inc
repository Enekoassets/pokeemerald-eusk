MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	.byte 0

MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_MAUVILLE_GYM_STATE
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_Wattson::
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonDefeated::
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_BADGE03_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special MauvilleGymDeactivatePuzzle
	special DrawWholeMapView
	playse SE_UNLOCK
	call MauvilleCity_Gym_EventScript_GiveShockWave
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave2::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice:
	.string "Ei, zer moduz dago gure {PLAYER},\n"
	.string "etorkizuneko TXAPELDUNA?\p"
	.string "ERIKO, MALBADIKO GIMNASIOKO\n"
	.string "LIDERRAK POKéMON ELEKTRIKOAK ditu.\p"
	.string "UR motako POKéMONAK erabiltzen badituzu\n"
	.string "elektrifikatu egingo ditu! Bzzt!\p"
	.string "Eta etengailuekin kontrolatzen diren\n"
	.string "ateak jarri ditu GIMNASIOAN! Xelebrea!\p"
	.string "Ea ba! Aurrera!$"

MauvilleCity_Gym_Text_GymGuidePostVictory:
	.string "Uau, elektrikoa zara!\n"
	.string "Zure indarrak atea ireki du!$"

MauvilleCity_Gym_Text_KirkIntro:
	.string "Nire arima elektrikoak zure ametsak\n"
	.string "zapuztuko ditu, ua-iajaja!$"

MauvilleCity_Gym_Text_KirkDefeat:
	.string "Hori elektrikoa izan da,\n"
	.string "entxufatua eta anplifikatua!$"

MauvilleCity_Gym_Text_KirkPostBattle:
	.string "POKéMONAK eta rocka, bihotz kontua\n"
	.string "dira biak ala biak!$"

MauvilleCity_Gym_Text_ShawnIntro:
	.string "ERIKOK entrenatu nau!\n"
	.string "Ez didazu erraz irabaziko!$"

MauvilleCity_Gym_Text_ShawnDefeat:
	.string "Desentxufatuta eta itzalita…$"

MauvilleCity_Gym_Text_ShawnPostBattle:
	.string "ERIKO, gure LIDERRA, aspalditik\n"
	.string "egon da GIMNASIO honetan.\p"
	.string "Zure aitatxo jaio aurretik\n"
	.string "ere hemen zegoen jada.$"

MauvilleCity_Gym_Text_BenIntro:
	.string "GIMNASIO honetan puzleak daude!\n"
	.string "Ez al da dibertigarria?$"

MauvilleCity_Gym_Text_BenDefeat:
	.string "Ez da dibertigarria galtzea…$"

MauvilleCity_Gym_Text_BenPostBattle:
	.string "ERIKORI asko gustatzen zaio\n"
	.string "etengailuekin tranpak jartzea.$"

MauvilleCity_Gym_Text_VivianIntro:
	.string "Nire xarmarekin eta nire POKéMONEN\n"
	.string "erasoekin txundituta geratuko zara!$"

MauvilleCity_Gym_Text_VivianDefeat:
	.string "Zure indarrak txunditu nau!$"

MauvilleCity_Gym_Text_VivianPostBattle:
	.string "Entzun dut MALBADI ERIKOK\n"
	.string "sortu zuela.\p"
	.string "Gu ENTRENATZAILE izan baino\n"
	.string "askoz lehenago hasi zen bera.\l"
	.string "Pila bat gauza dakizki!$"

MauvilleCity_Gym_Text_AngeloIntro:
	.string "Gauza distiratsuak atsegin ditut!$"

MauvilleCity_Gym_Text_AngeloDefeat:
	.string "Ene…\n"
	.string "Nire begiak txundituta geratu dira…$"

MauvilleCity_Gym_Text_AngeloPostBattle:
	.string "MALBADIKO GIMNASIOKO ERIKOK kopeta\n"
	.string "distiratsua du. Pozik jartzen nau!$"

MauvilleCity_Gym_Text_WattsonIntro:
	.string "Hiria eraldatzeko nire planak\n"
	.string "alde batera utzi ditut.\p"
	.string "Ondorioz, nire GIMNASIOAN ate\n"
	.string "tranpak jartzen aritu naiz.\p"
	.string "Zer? Zertan ari zara hemen?\p"
	.string "Zer diozu? Nire tranpa ate guztiak\n"
	.string "gurutzatzea lortu duzula?\p"
	.string "Kar-kar-kar!\n"
	.string "Dibertigarria, benetan!\p"
	.string "Orduan, nik, ERIKOK, MALBADIKO\n"
	.string "GIMNASIOKO LIDERRAK, ziztatuko zaitut!$"

MauvilleCity_Gym_Text_WattsonDefeat:
	.string "Kar-kar-kar!\n"
	.string "Ados, galdu egin dut!\p"
	.string "Borroka zirraragarria izan da!\n"
	.string "Tori DOMINA hau!$"

MauvilleCity_Gym_Text_ReceivedDynamoBadge:
	.string "{PLAYER}(e)K DINAMO DOMINA jaso\n"
	.string "du ERIKORENGANDIK.$"

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
	.string "DINAMO DOMINAREKIN, POKéMONEK borrokaz\n"
	.string "kanpo ARROKA KOLPEA erabili dezakete.\p"
	.string "Eta zure POKéMONAK pixka bat\n"
	.string "azkarragoak izango dira.\p"
	.string "Hmm…\n"
	.string "Hau ere hartu behar zenuke!$"

MauvilleCity_Gym_Text_ExplainShockWave:
	.string "MT34ak BOLTIO UHINA dakar barnean.\p"
	.string "Huts egiten ez duen eraso\n"
	.string "fidagarria da! Erabili ezazu!\p"
	.string "… … … … … …$"

MauvilleCity_Gym_Text_RegisteredWattson:
	.string "ERIKO GIMNASIOKO LIDERRA\n"
	.string "POKéNAVEAN erregistratu da.$"

MauvilleCity_Gym_Text_WattsonPostBattle:
	.string "Baikortasunez betetzen naiz zu bezalako\n"
	.string "ENTRENATZAILE gaztea ikusita!$"

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
	.string "Kar-kar-kar!\n"
	.string "Segi aurrera, gazte!$"

MauvilleCity_Gym_Text_GymStatue:
	.string "MALBADI HIRIKO POKéMON GIMNASIOA$"

MauvilleCity_Gym_Text_GymStatueCertified:
	.string "MALBADI HIRIKO POKéMON GIMNASIOA\p"
	.string "ERIKOK ZIURTATUTAKO ENTRENATZAILEAK:\n"
	.string "{PLAYER}$"

MauvilleCity_Gym_Text_WattsonPreRematch:
	.string "ERIKO: Aja! Hemen, azkenean!\n"
	.string "Badakit zer nahi duzun.\l"
	.string "You want to battle my POKéMON!\p"
	.string "Kar-kar-kar!\p"
	.string "Txinpartek hegan egingo dute!\n"
	.string "Ez esan abisatu ez dizudanik!$"

MauvilleCity_Gym_Text_WattsonRematchDefeat:
	.string "Uf…\n"
	.string "Bateria gastatu zaigu…$"

MauvilleCity_Gym_Text_WattsonPostRematch:
	.string "ERIKO: Bateriak berriz kargatu\n"
	.string "beharko ditugu.\p"
	.string "Guztiz kargatzen garenean, pozik\n"
	.string "onartuko dugu zure erronka.\p"
	.string "Beraz, itzuli nahi duzunean,\n"
	.string "ados?$"

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
	.string "ERIKO: Aja! Hemen, azkenean!\n"
	.string "Badakit zer nahi duzun.\l"
	.string "You want to battle my POKéMON!\p"
	.string "Kar-kar-kar!\p"
	.string "Ups! Itxaron!\n"
	.string "POKéMON bakarra duzu aldean!\p"
	.string "Itzuli bi POKéMON edo gehiago\n"
	.string "dituzunean, ados?$"

