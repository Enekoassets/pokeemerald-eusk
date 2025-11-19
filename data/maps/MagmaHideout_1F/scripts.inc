MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "MAGMA TALDEKO zerrenda egiten dugunean,\n"
	.string "ateratzen garen ordenan ematen\l"
	.string "dizkigute zaindari lanak.\p"
	.string "Horregatik nago izkina urrun honetan.\n"
	.string "Beti iristen naiz berandu zerrenda ordura!$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "Entrenamenduetara ere beti berandu\n"
	.string "iristen naiz! Min ematen dit\p"
	.string "esateak, baina, ezgauza naiz…$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "Ongi, hemendik aurrera gehiago\n"
	.string "saiatuko naiz…$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "Liderrak TXIMINIA MENDIAN zuloa egiteko\n"
	.string "agindu zigun, eta guk agindua bete.\p"
	.string "Zulatzen ari ginela, harri eta zur\n"
	.string "utzi gintuen zerbait aurkitu genuen!\p"
	.string "Zer aurkitu genuen jakin nahi?\p"
	.string "Kar-kar-kar!\n"
	.string "Irabaziz gero, esango dizut!$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "Kaka!\n"
	.string "Galdu egin dut!$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "Ez dizut esango, azkenean.\n"
	.string "Aurkituko duzu iristen zarenean!\p"
	.string "Hobe da sorpresa handienak\n"
	.string "amaierarako uztea, ezta?$"

