MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "Zer, zer, zer?\p"
	.string "MAGMA TALDEKO kideak soilik\n"
	.string "egon daitezke hemen!\p"
	.string "Zuk ez daukazu MAGMA TALDEKO\n"
	.string "jantzia, ordea…\p"
	.string "Susmo txarra hartzen dizut!\n"
	.string "Borrokatu nire aurka!$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "Ai ene, ai ene…\n"
	.string "Nire MAGMA TALDEKIDE ohorea…$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "Hotzikarak izan ohi badituzu,\n"
	.string "batu MAGMA TALDERA.$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "Geldi hortxe bertan!\p"
	.string "Ez duzu usteko nire tranpa pasa eta nire\n"
	.string "albotik igarotzen utziko dizudanik, ezta?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "Ai ene!\n"
	.string "Errenditu egin naiz!$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "Agian hobe izango nuen pasatzen\n"
	.string "utzi izan banizu…$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "Aja!\n"
	.string "Kanpotar bat!$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "Graaa!$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "Jada galdu dut.\p"
	.string "Benetan jarraitu behar al dut\n"
	.string "hemen korrika bueltaka?$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "Ene, ene!\n"
	.string "Kanpotar bat!$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "Kaka…$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "Egia esan, ez naiz ona borrokan…$"

