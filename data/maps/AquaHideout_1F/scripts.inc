AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "Zer? Zer? AQUA TALDEAREKIN arazoak\n"
	.string "izan nahi al dituzu?\p"
	.string "NAGUSIA ez dago hemen! Nonbaitera joan\n"
	.string "da zeozer garrantzitsua lapurtzera!\p"
	.string "… …\n"
	.string "Nora joan den?\p"
	.string "Kar-kar-kar! Benetan uste duzu halako\n"
	.string "zerbait kontatuko nizula?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "Zer? Zer?\n"
	.string "MAGMA TALDEKO errekruta al zara?\p"
	.string "Entzun dut MAGMA TALDEA beraien\n"
	.string "EZKUTALEKUKO POKéMON itzel bat\l"
	.string "esnatzen saiatzen ari dela.\p"
	.string "Baina non ote dago EZKUTALEKUA?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "Zer? Zer? AQUA TALDEAREKIN arazoak\n"
	.string "izan nahi al dituzu?\p"
	.string "NAGUSIA ez dago hemen!\n"
	.string "Urpeko bat lapurtzera joan da!\p"
	.string "… …\n"
	.string "Nora joan den?\p"
	.string "Kar-kar-kar! Benetan uste duzu halako\n"
	.string "zerbait kontatuko nizula?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "Zer? Zer? AQUA TALDEAREKIN arazoak\n"
	.string "izan nahi al dituzu?\p"
	.string "NAGUSIA ez dago hemen! PIRO MENDIRA\n"
	.string "joan da 122. ERRUTAN!\p"
	.string "… …\n"
	.string "Zertara joan den?\p"
	.string "Kar-kar-kar! Benetan uste duzu halako\n"
	.string "zerbait kontatuko nizula?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "Zer? Zer?\n"
	.string "MAGMA TALDEKO errekruta al zara?\p"
	.string "Entzun dut MAGMA TALDEA TXIMINIA\n"
	.string "MENDIKO POKéMON baten bila ari dela.\p"
	.string "Nolakoa ote da POKéMON hori?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "Zer? Zer? AQUA TALDEAREKIN arazoak\n"
	.string "izan nahi al dituzu?\p"
	.string "NAGUSIA ez dago hemen!\n"
	.string "PORTUONDO HIRIRA joan da!\p"
	.string "… …\n"
	.string "Zertara joan den?\p"
	.string "Kar-kar-kar! Benetan uste duzu halako\n"
	.string "zerbait kontatuko nizula?$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "Aiaiaiai!\n"
	.string "Pertsona susmagarri bat!$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "Kaka…\n"
	.string "Galdu egin dut!$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "TALDEAREN partez galdu dut,\n"
	.string "baina egin dut nire lana…$"

