MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "Ei, zer moduz, {PLAYER},\n"
	.string "etorkizuneko TXAPELDUNA?\p"
	.string "Hemengo GIMNASIOKO LIDERREK\n"
	.string "PSIKIKO motako POKéMONAK dituzte.\p"
	.string "BORROKA edo POZOIN motako\n"
	.string "POKéMONAK badituzu, izugarrizko\l"
	.string "kaltea eragingo dizute!\p"
	.string "gainera, eraso konbinaketa\n"
	.string "izugarriekin egingo dizute aurre.\p"
	.string "Irabazi nahi baduzu, zure POKéMONEKIN\n"
	.string "duzun konexioa erakutsi beharko\l"
	.string "duzu. Aurrera!$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "Uau, itzela zara!\n"
	.string "ENTRENATZAILE bikaina zara, gero!$"

MossdeepCity_Gym_Text_PrestonIntro:
	.string "Borrokak zure gogoaren indarraren arabera\n"
	.string "erabakitzen dira! Gogo gutxirekin, ezin irabazi!$"

MossdeepCity_Gym_Text_PrestonDefeat:
	.string "Galdu egin dut!\n"
	.string "Nire gogoa indartu behar dut!$"

MossdeepCity_Gym_Text_PrestonPostBattle:
	.string "Zalantzatiek galdu egiten dute.\n"
	.string "Hori da nire abisua.$"

MossdeepCity_Gym_Text_VirgilIntro:
	.string "Ikus dezagun zure talentua!$"

MossdeepCity_Gym_Text_VirgilDefeat:
	.string "Talentu harrigarria daukazu!$"

MossdeepCity_Gym_Text_VirgilPostBattle:
	.string "Prodijioak existitzen badira, gure\n"
	.string "GIMNASIOKO LIDERRAK halakoak dira!\p"
	.string "Hala ere, agian beraiek baino\n"
	.string "talntu handiagoa duzu zuk…$"

MossdeepCity_Gym_Text_BlakeIntro:
	.string "Fufufufu… Begira nola aireratzen dudan\n"
	.string "POKé BALLA telekinesiarekin!\p"
	.string "Rooooooooaaaar!\n"
	.string "… … … … … … …\p"
	.string "Batzuetan, ezin dut sinkronizatu…$"

MossdeepCity_Gym_Text_BlakeDefeat:
	.string "POKéMONEKIN borroka egiteko abilezia\n"
	.string "ere ezin dut sinkronizatu!$"

MossdeepCity_Gym_Text_BlakePostBattle:
	.string "POKé BALLA pisutsuegia zen fisikoki\n"
	.string "altxatzeko. Baina hauts maluta hau…\p"
	.string "Ffffuuuu!\n"
	.string "… … … … … …\p"
	.string "Ez, ez naiz tranpatan ari!\n"
	.string "Ez dut putz egin! Benetan!$"

MossdeepCity_Gym_Text_HannahIntro:
	.string "Nire aurka galtzen duzunean,\n"
	.string "ez jarri tristeegi.\p"
	.string "Ez da ahula zarela,\n"
	.string "ni indartsuegia naiz!$"

MossdeepCity_Gym_Text_HannahDefeat:
	.string "Indartsuegia zara!$"

MossdeepCity_Gym_Text_HannahPostBattle:
	.string "Ez naiz triste jarriko galdu dudalako.\n"
	.string "Gogorrago entrenatu behar dut.\p"
	.string "Positiboki pentsatzea, hori da\n"
	.string "kontua!$"

MossdeepCity_Gym_Text_SamanthaIntro:
	.string "Ikusi dezaket…\n"
	.string "Zure etorkizun hurbila…\p"
	.string "Irabazten badidazu, zure\n"
	.string "etorkizuna kontatuko dizut!$"

MossdeepCity_Gym_Text_SamanthaDefeat:
	.string "Errenditu egin naiz!$"

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.string "GIMNASIOKO LIDERREN aurka borroka\n"
	.string "izugarria izango duzu…\p"
	.string "Garailea…\n"
	.string "Hori ez dizut nik esango!$"

MossdeepCity_Gym_Text_MauraIntro:
	.string "Gurutzatu dituzun bideak…\n"
	.string "Izan dituzun bizipenak…\p"
	.string "Ereakutsi niri ikasi duzun\n"
	.string "guztia!$"

MossdeepCity_Gym_Text_MauraDefeat:
	.string "Bide bikaina egin duzu!$"

MossdeepCity_Gym_Text_MauraPostBattle:
	.string "Lan gogor egin dutenek etorkizun\n"
	.string "oparoa dute zain.\p"
	.string "Alferkerian egon direnei, berriz,\n"
	.string "ez zaie ezer geratuko.\p"
	.string "Ereiten dena jasotzen da…$"

MossdeepCity_Gym_Text_SylviaIntro:
	.string "Bizitza arriskatuta ere, borroka\n"
	.string "hau irabazi egingo dut!$"

MossdeepCity_Gym_Text_SylviaDefeat:
	.string "Zuk egiten duzunak…\n"
	.string "beldurtu egiten nau…$"

MossdeepCity_Gym_Text_SylviaPostBattle:
	.string "Nola ausartu zara ni garaitzen…\p"
	.string "Ez da nire errua izango zerbait\n"
	.string "izugarria gertatzen bazaizu…$"

MossdeepCity_Gym_Text_NateIntro:
	.string "Jojojo.\p"
	.string "Nik erakutsiko dizut PSIKIKO mota\n"
	.string "zeinen beldurgarria izan daitekeen.$"

MossdeepCity_Gym_Text_NateDefeat:
	.string "Ai! Ene, ene!\n"
	.string "Zure borroka estiloa itzela da!$"

MossdeepCity_Gym_Text_NatePostBattle:
	.string "Nik… Ez diot utziko porrotari ni\n"
	.string "garaitzen, benetan.$"

MossdeepCity_Gym_Text_KathleenIntro:
	.string "Utzidazu esperientzia izugarria\n"
	.string "biziarazten!$"

MossdeepCity_Gym_Text_KathleenDefeat:
	.string "E-eeeez!$"

MossdeepCity_Gym_Text_KathleenPostBattle:
	.string "Zure bizitasuna itsaskorra da!\n"
	.string "Egin alde nire ondotik, azkar!$"

MossdeepCity_Gym_Text_CliffordIntro:
	.string "Agian igaro da nire momenturik onena,\n"
	.string "baina ez harrotu horregatik, mesedez.$"

MossdeepCity_Gym_Text_CliffordDefeat:
	.string "Ene, gaztetasunaren botere\n"
	.string "izugarria duzu barnean!$"

MossdeepCity_Gym_Text_CliffordPostBattle:
	.string "Badirudi ezin izan dudala zure\n"
	.string "energia gaztea garaitu.$"

MossdeepCity_Gym_Text_MaceyIntro:
	.string "Ez zara amaieraraino iritsiko!\n"
	.string "Ez, nik geratuko zaitut eta!$"

MossdeepCity_Gym_Text_MaceyDefeat:
	.string "Nola izan zaitezke horren\n"
	.string "beldurgarriki indartsua?$"

MossdeepCity_Gym_Text_MaceyPostBattle:
	.string "Uf! Indartsua izango zara, baina ez\n"
	.string "zara egokia PSIKIKO motarentzat!\p"
	.string "Zure borrokarako era basatia da nolabait!$"

MossdeepCity_Gym_Text_NicholasIntro:
	.string "Roooar! Probatu nire POKéMON\n"
	.string "borrokalarien indar bortitza!$"

MossdeepCity_Gym_Text_NicholasDefeat:
	.string "Ene!\n"
	.string "Txikitu egin nau!$"

MossdeepCity_Gym_Text_NicholasPostBattle:
	.string "Ongi! Hurrengorako POKéMON indar\n"
	.string "garaitezina garatuko dut.$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "JON: Jejeje… Harrituta, ala?\p"
	.string "JONE: Fufufu… Harrituta, ala?\p"
	.string "JON: GIMNASIOKO bi LIDER daudelako?\n"
	.string "JONE: GIMNASIOKO bi LIDER daudelako?\p"
	.string "JON: Bizkiak gara!\n"
	.string "JONE: Bizkiak gara!\p"
	.string "JON: Ez dugu zertan hitz egin…\n"
	.string "JONE: Biok dakigulako beti…\p"
	.string "JON: Zer pentsatzen duen besteak…\n"
	.string "JONE: Burua soilik erabiliz!\p"
	.string "JON: Gure konbinaketa hau…\n"
	.string "JONE: Garaitzeko gai izango al zara?$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "JON: Zer?! Gure konbinaketa…\n"
	.string "JONE: Txikitu egin du!\p"
	.string "JON: Ezin dugu ezer egin. Irabazi egin duzu…\n"
	.string "JONE: Beraz, horren erakusgarri, tori hau.$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{PLAYER}(e)K GOGO DOMINA jaso\n"
	.string "du JON eta JONERENGANDIK.$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "JON: GOGO DOMINAK POKéMONEN\n"
	.string "ER. BER. eta. DEF. BER. hobetzen ditu.\p"
	.string "JONE: Gainera, URPERAKETA MEa\n"
	.string "erabili dezakezu borrokatik kanpo.\p"
	.string "JON: Hau ere zuretzako da.$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "JON: MT04 horrek barruan…\n"
	.string "JONE: BAKE MENTALA dauka grabatuta!\p"
	.string "JON: ER. BER. igotzen du eta…\n"
	.string "JONE: DEF. BER: ere bai!\p"
	.string "JON: Eraso perfektua da…\n"
	.string "JONE: POKéMON PSIKIKOENTZAT!\p"
	.string "… … … … … …$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "JON & JONE GIMNASIOKO LIDERRAK\n"
	.string "POKéNAVEAN erregistratu dira.$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "JON: Badirudi zu eta zure POKéMONEN\n"
	.string "arteko lotura gu bikion artekoa\l"
	.string "baino indartsuagoa dela.\p"
	.string "JONE: Are indartsuagoa bihurtuko zara!\n"
	.string "Badakigu, zure aurka egin baitugu.$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "JON: Jejeje… Harrituta, ala?\p"
	.string "JONE: GIMNASIOKO bi LIDER daudelako?\p"
	.string "JON: Ups, baina POKéMON…\n"
	.string "JONE: bakarra daukazu eta.\p"
	.string "JON: horrela ezin dugu borroka egin!\p"
	.string "JONE: Gure kontra borrokatu nahi baduzu,\n"
	.string "ekarri POKéMON gehiago.$"

MossdeepCity_Gym_Text_GymStatue:
	.string "GOROLDI HIRIKO POKéMON GIMNASIOA$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "GOROLDI HIRIKO POKéMON GIMNASIOA\p"
	.string "JON ETA JONEK ZIURTATUTAKO ENTRENATZAILEAK:\n"
	.string "{PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "JON: POKéMONAK…\n"
	.string "JONE: POKéMONAK…\p"
	.string "JON: Taldea aldatuz gero…\n"
	.string "JONE: Borroka estiloa aldatzen da.\p"
	.string "JON: Baina, ni…\n"
	.string "JONE: Baina, ni…\p"
	.string "JON: Beti egongo naiz JONEREKIN!\n"
	.string "JONE: Beti egongo naiz JONEKIN!\p"
	.string "JON: Gure konbinaketa…\n"
	.string "JONE: Behin eta berrik erakutsiko dizugu!$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "JON: Zu eta zure POKéMONAK…\n"
	.string "JONE: Anai-arrebak bazinete bezala da!$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "JON: irabazi egin diezagukezu,\n"
	.string "baina ez gara inoiz errendituko!\p"
	.string "JONE: Gu biok, beti bultzatuko\n"
	.string "dugulako elkar!$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "JON: Itzuli zara berriro…\n"
	.string "JONE: Itzuli zara berriro…\p"
	.string "JON: Errebantxa baterako.\n"
	.string "JONE: Errebantxa baterako.\p"
	.string "JON: Baina…\n"
	.string "JONE: Borroka egiteko…\p"
	.string "JON: POKéMON bakarra ekarri duzu!\n"
	.string "JONE: POKéMON bakarra ekarri duzu!\p"
	.string "JON: Gutxienez, bi POKéMON…\n"
	.string "JONE: ekarri, eta, ondoren, itzuli.$"
