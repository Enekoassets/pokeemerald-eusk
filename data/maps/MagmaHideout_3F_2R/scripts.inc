MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "Nagusiak dioen guztia ulertzen\n"
	.string "dut. Baina, badakizu zer?\p"
	.string "Antzinako POKéMON batengana joan\n"
	.string "eta norbaiten METEORITOA lapurtu\l"
	.string "izana…\p"
	.string "Uste dut pasatzen ari garela.\n"
	.string "Ez al zaude ados?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "Bai, uste dut zerbait ez garela\n"
	.string "ondo egiten ari.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "Badakizu zer? Galtzeak burua argitu dit.\p"
	.string "Nagusia ikusten dudan hurrengoan,\n"
	.string "zertan ari garen galdetuko diot.$"

