SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Ei! Zer moduz, {PLAYER}\n"
	.string "etorkizuneko TXAPELDUNA?\p"
	.string "ARREZIPOLISEKO LIDERRA, XALANT,\n"
	.string "UR motako POKéMONETAN aditua da.\p"
	.string "Eta bereganaino iristeko, izotzezko\n"
	.string "lurrak motelduko zaitu…\p"
	.string "Sentitzen dut, baina horiek dira\n"
	.string "zuretzat ditudan aholku guztiak.\p"
	.string "Hemendik aurrera, zuk bakarrik\n"
	.string "joan behar duzu!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Aizu! XALANT ere garaitu duzu,\n"
	.string "izatez HOENN osoan onena zena!\p"
	.string "Ongi! Begiratu zure ENTRENATZAILE TXARTELA.\p"
	.string "DOMINA guztiak lortu badituzu, prest\n"
	.string "zaude POKéMON LIGAKO erronkarako!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Galdera bat.\n"
	.string "Ba al zenekien?\l"
	.string "Ai, ez nuke horren lotsatia izan behar.\p"
	.string "Nik erakutsi nion UREDERRI POKéMONEN\n"
	.string "inguruan dakien guztia.\p"
	.string "Behin, nire GIMNASIOKO LIDER\n"
	.string "postua utzi nuen.\p"
	.string "Nire lekua UREDERRI utzi nion,\n"
	.string "GIMNASIOA zaindu zezn.\p"
	.string "Hala ere, arrazoi garrantzitsu\n"
	.string "batengatik itzuli behar izan nuen.\p"
	.string "Beno, hitz egin dugu nahikoa.\n"
	.string "Has gaitezen borrokan, bai?\p"
	.string "Mesedez, ikusi ezazu gure\n"
	.string "abilezia artistikoa.\p"
	.string "Uretan zizelkatutako ilusioa\n"
	.string "nire POKéMONEK eta nik egina!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "Ahahaha, bikain!\n"
	.string "Oso ongi, zuk irabazi duzu.\p"
	.string "Guztia gainditu dezakeenaren\n"
	.string "distira argia ikusten dut zugan.\p"
	.string "Hala ere, nirekin edo UREDERREKIN\n"
	.string "alderatuta, dotorezia falta zaizu.\p"
	.string "Agian nire jantziak utzi behar\n"
	.string "nizkizuke aldi baterako?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Kar-kar-kar txantxetan ari naiz!\p"
	.string "Nire jantziak ez, honakoa eman\n"
	.string "eman behar nizuke, EURI DOMINA!$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER}(e)k EURI DOMINA jaso du\n"
	.string "XALANTENGANDIK.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "EURI DOMINA edukita, zure POKéMONEK\n"
	.string "beti obedituko zaituzte, zure\l"
	.string "agindu guztiak jarraituz.\p"
	.string "EURI DOMINAK, gainera, UR-JAUZIA\n"
	.string "HMA erailtzen utziko dizu, edozein\l"
	.string "ur-jauzi igo ahal izateko.\p"
	.string "Eta inoiz ez dezazun gure arteko\n"
	.string "borroka ahaztu, tori hau…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "Eman dizudan MAKINA TEKNIKOAK\n"
	.string "HIDROPULTSUA dakar barnean.\p"
	.string "Erabiltzean, batzuetan etsaia\n"
	.string "nahas dezake uhin ultrasonikoekin.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "XALANT, GIMNASIOKO LIDERRA\n"
	.string "erregistratu duzu POKéNAVEAN.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "HOENNEKO GIMNASIOKO DOMINA guztiak\n"
	.string "bildu dituzten ENTRENATZAILEAK\l"
	.string "azken helmugara joan behar dira.\p"
	.string "POKéMON LIGARA.\p"
	.string "Bidaiatu HOENN ekialdeko mugara,\n"
	.string "ITZELETA irlara iritsi arte.\p"
	.string "Bertan aurkituko duzu POKéMON\n"
	.string "LIGA.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "DOMINA bat geratzen zaizu\n"
	.string "oraindik HOENNEN lortzeko.\p"
	.string "POKéMON LIGARA joan nahi baduzu,\n"
	.string "ZUHAITZAGAKO GIMNASIOKO azken\l"
	.string "DOMINA lortu behar duzu.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "ARREZIPOLIS HIRIKO POKéMON GIMNASIOA$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "ARREZIPOLIS HIRIKO POKéMON GIMNASIOA\p"
	.string "XALANTEK ZIURTATUTAKO ENTRENATZAILEAK:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "XALANT: Bai, GIMNASIO honetara\n"
	.string "betiko lasaitasuna itzuli da…\p"
	.string "Baina tifoi gaztea etorri da gu\n"
	.string "berriro proban jartzera!\p"
	.string "Beno, lagun, nahi bezala!\p"
	.string "Nahi duzun guztietan egingo dut\n"
	.string "dantza zurekin!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Kar-kar-kar, zuk irabazi duzu!\n"
	.string "Berriz ere garaitu nauzu!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "XALANT: Nire ikaslea izateko esaten\n"
	.string "badizut, ezetz esango didazu, badakit.\p"
	.string "Nire jaka eman nahi nizuke,\n"
	.string "opari moduan.\p"
	.string "Baina badakit ezetz esango didazula.\n"
	.string "Hala esango nuke.\p"
	.string "Eta hori, lagun, nobleziaren\n"
	.string "seinale argia da!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "XALANT: Bai, GIMNASIO honetara\n"
	.string "betiko lasaitasuna itzuli da…\p"
	.string "Baina tifoi gaztea etorri da gu\n"
	.string "berriro proban jartzera!\p"
	.string "Beno, lagun, nahi bezala!\p"
	.string "Nahi duzun guztietan egingo dut dantza…\n"
	.string "Ai, ez, ez, ez.\n"
	.string "POKéMON bakarra daukazu eta.\p"
	.string "Mesedez, itzuli gutxienez bi\n"
	.string "POKéMON, edo, agian, gehiagorekin.$"

