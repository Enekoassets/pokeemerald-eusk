MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro:
	.string "Ez dut ezer berezirik zure aurka.\n"
	.string "Aginduak jarraitzen ari naiz soilik!$"

MagmaHideout_2F_2R_Text_Grunt15Defeat:
	.string "Galdu egin dut, baina…$"

MagmaHideout_2F_2R_Text_Grunt15PostBattle:
	.string "Izugarrizko zuloa egin dugu!\n"
	.string "Eta ORBE URDINA aurkitu!\p"
	.string "Orain, gure liderrak soilik…\n"
	.string "Fufufu… Uajajaja!$"

MagmaHideout_2F_2R_Text_Grunt6Intro:
	.string "Ezin dut beroa jasan. Agian AQUA\n"
	.string "TALDEKOA izan behar nintzen…$"

MagmaHideout_2F_2R_Text_Grunt6Defeat:
	.string "Bai, agian ez naiz egokiena\n"
	.string "MAGMA TALDERAKO…$"

MagmaHideout_2F_2R_Text_Grunt6PostBattle:
	.string "Ez al duzu itsasoa faltan hartzen\n"
	.string "horrelako leku batean?$"

MagmaHideout_2F_2R_Text_Grunt7Intro:
	.string "Dardarak entzun daitezke batzuetan hemen.\p"
	.string "Sumendia izango al da?\n"
	.string "Edo, agian, GROU…\p"
	.string "Ups!\n"
	.string "Ez, ez, ez da ezer!$"

MagmaHideout_2F_2R_Text_Grunt7Defeat:
	.string "Borrokalari sutsua zara.\n"
	.string "Sumendiak bezala!$"

MagmaHideout_2F_2R_Text_Grunt7PostBattle:
	.string "Zuk irabaziko zenuen gaur, bai,\n"
	.string "baina ez du axola.\p"
	.string "MAGMA TALDEAREN helburua\n"
	.string "betetzear dago!$"

MagmaHideout_2F_2R_Text_Grunt8Intro:
	.string "Gure kideetako bat urduri zegoen\n"
	.string "MAGMA ENBLEMA galdu duelako…\p"
	.string "Itxaron pixka bat!\n"
	.string "Zuk aurkitu al zenuen?$"

MagmaHideout_2F_2R_Text_Grunt8Defeat:
	.string "Ezin dut hau sinetsi…$"

MagmaHideout_2F_2R_Text_Grunt8PostBattle:
	.string "Gure plana zapuztu egingo dela\n"
	.string "nabaritzen ari naiz…$"

