.set LOCALID_LITTLE_BOY, 5

Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "NAGUSIAK interesa du hemen\n"
	.string "egiten ari diren ikerketan,\l"
	.string "beraz, bidali egin gaitu.\p"
	.string "Ez ezazu muturrik sartu!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "Txikituta…\n"
	.string "Umemoko batek txikitu nau…$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "NAGUSIAK dena daki.\p"
	.string "Baina ni ERREKRUTA bat naiz. Nola\n"
	.string "jakingo dut zer pentsatzen ari den?$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "Zer?\n"
	.string "Zertan ari da umemoko bat hemen?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "Zer?\n"
	.string "Galdu egin dut?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "Ai ene… Ume baten aurka galduta,\n"
	.string "errieta jasoko dut…\p"
	.string "Siesta bat bota behar nuke…$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "Lotan nengoela, mundu guztia\n"
	.string "gora joan da!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "Ene, benetan indartsua zara!\p"
	.string "Zu bezalako POKéMON ENTRENATZAILEA\n"
	.string "izan nahi nuke!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "IRAKASLEAK maite du euria.\n"
	.string "Egia da hori.\p"
	.string "Baina euriak horrela jarraitzen badu,\n"
	.string "arazoa izango da. Hori ere egia da.\p"
	.string "Horregatik, IRAKASLEA euria nola\n"
	.string "erablii aztertzen ari da.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "INSTITUTUKO 2. solairuan, HOENN\n"
	.string "eskualdeko eguraldiaren patroiak\l"
	.string "aztertzen ditugu.\p"
	.string "Leku jakin batzuetan lehorte eta\n"
	.string "uholde laburrak detektatzen ari\l"
	.string "gara azkenaldian…$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "Kaixo!\n"
	.string "Zuk egindakoak salbatu gaitu!\p"
	.string "Ulertzen ez dudana da zer nahi\n"
	.string "zuten AQUA TALDEKO horiek.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "Ohe bat da…\n"
	.string "Deskantsatu dezagun.$"

