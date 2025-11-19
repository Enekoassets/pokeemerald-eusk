MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "Zer egin ote dut zaintza\n"
	.string "leku hau niri tokatzeko?\p"
	.string "Ezkerreko belarria urtuko zait!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "Bero kolpe batek emango dit…$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "Arraroa iruditzen al zaizu magmaz betetako\n"
	.string "sumendi honetan txanoa jantzita izatea?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "Gure nagusiari bere helburua\n"
	.string "betetzen laguntzera etorri gara.\p"
	.string "Ez zait axola AQUA TALDEKOA zaren\n"
	.string "edo hemendik dabilen gazte soila.\p"
	.string "Inor ez da gure planak zapuzten\n"
	.string "saiatuko egurra jaso gabe!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Ai, ez!\n"
	.string "Ez zara fidatzekoa!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Entzun ongi.\n"
	.string "MAGMA TALDEA zuzen dabil!\p"
	.string "Ez entzun AQUA TALDEKOEI.\n"
	.string "Ez sinetsi haien gezurrak!$"

