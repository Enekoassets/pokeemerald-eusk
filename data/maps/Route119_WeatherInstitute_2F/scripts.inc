.set LOCALID_GRUNT_1, 1
.set LOCALID_GRUNT_2, 2
.set LOCALID_SHELLY, 3
.set LOCALID_SCIENTIST, 5
.set LOCALID_GRUNT_3, 7
.set LOCALID_GRUNT_4, 8

Route119_WeatherInstitute_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
	.byte 0

Route119_WeatherInstitute_2F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone
	call_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear
	end

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere::
	setobjectxyperm LOCALID_SCIENTIST, 1, 6
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone::
	setobjectxyperm LOCALID_SCIENTIST, 4, 6
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear::
	setobjectxyperm LOCALID_SCIENTIST, 2, 2
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_UP
	return

Route119_WeatherInstitute_2F_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_5, Route119_WeatherInstitute_2F_Text_Grunt5Intro, Route119_WeatherInstitute_2F_Text_Grunt5Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_2, Route119_WeatherInstitute_2F_Text_Grunt2Intro, Route119_WeatherInstitute_2F_Text_Grunt2Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_3, Route119_WeatherInstitute_2F_Text_Grunt3Intro, Route119_WeatherInstitute_2F_Text_Grunt3Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_WEATHER_INSTITUTE, Route119_WeatherInstitute_2F_Text_ShellyIntro, Route119_WeatherInstitute_2F_Text_ShellyDefeat, Route119_WeatherInstitute_2F_EventScript_ShellyDefeated
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_ShellyDefeated::
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_GRUNT_3
	applymovement LOCALID_GRUNT_3, Route119_WeatherInstitute_2F_Movement_GruntApproachShelly
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SHELLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SHELLY, Common_Movement_Delay48
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre, MSGBOX_DEFAULT
	closemessage
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_SHELLY
	removeobject LOCALID_GRUNT_4
	removeobject LOCALID_GRUNT_3
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_SCIENTIST, Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer
	waitmovement 0
	copyobjectxytoperm LOCALID_SCIENTIST
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastform::
	msgbox Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CASTFORM
	givemon SPECIES_CASTFORM, 25, ITEM_MYSTIC_WATER
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	end

Route119_WeatherInstitute_2F_EventScript_SendCastformToPC::
	call Common_EventScript_TransferredToPC
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM
	return

Route119_WeatherInstitute_2F_EventScript_ExplainCastform::
	msgbox Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_CASTFORM
	release
	end

Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather::
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather
	msgbox Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather::
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather  @ Both defeated
	call_if_unset FLAG_TEMP_2, Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather
	specialvar VAR_RESULT, GetAbnormalWeatherMapNameAndType
	goto_if_eq VAR_RESULT, 1, Route119_WeatherInstitute_2F_EventScript_KyogreWeather
	msgbox Route119_WeatherInstitute_2F_Text_GroudonWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_KyogreWeather::
	msgbox Route119_WeatherInstitute_2F_Text_KyogreWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather::
	special CreateAbnormalWeatherEvent
	setflag FLAG_TEMP_2
	return

Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather::
	msgbox Route119_WeatherInstitute_2F_Text_NoAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_Movement_GruntApproachShelly:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	ride_water_current_up
	walk_in_place_faster_down
	step_end

Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition:
	slide_down
	walk_in_place_faster_left
	step_end

Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer:
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_WeatherScientist::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_Text_Grunt2Intro:
	.string "INSTITUTUAK eguraldiarekin\n"
	.string "zerikusia duen POKéMON bat sortu\l"
	.string "zuen. Horien bila gatoz gu!$"

Route119_WeatherInstitute_2F_Text_Grunt2Defeat:
	.string "Gure plana ume batek zapuztu al du?$"

Route119_WeatherInstitute_2F_Text_Grunt2PostBattle:
	.string "Hemen sortutako POKéMONAK eguraldia\n"
	.string "nahi bezala alda badezake, guk,\l"
	.string "AQUA TALDEAK behar dugu, noski!$"

Route119_WeatherInstitute_2F_Text_Grunt3Intro:
	.string "AQUA TALDEA gara!\n"
	.string "Zerbait bitxia agertzen bada, hor\l"
	.string "agertuko gara gu ere!$"

Route119_WeatherInstitute_2F_Text_Grunt3Defeat:
	.string "Garaitu egin nauzu!$"

Route119_WeatherInstitute_2F_Text_Grunt3PostBattle:
	.string "Ez dakizu zeren alde egiten\n"
	.string "duen borroka AQUA TALDEAK!\l"
	.string "Ken zaitez gure bidetik!$"

Route119_WeatherInstitute_2F_Text_Grunt5Intro:
	.string "Ez esan zu ere eguraldi POKéMON\n"
	.string "horren bila ari zarela!\p"
	.string "Ez, ez, hori ezinezkoa da!\n"
	.string "Gu iritsi gara lehenago!$"

Route119_WeatherInstitute_2F_Text_Grunt5Defeat:
	.string "Ene, begira nire POKéMONA!$"

Route119_WeatherInstitute_2F_Text_Grunt5PostBattle:
	.string "Aizu, orduan zer?\n"
	.string "Guk nahi duguna…\p"
	.string "Benetan nahi duguna ez dago hemen…\n"
	.string "Kar-kar-kar…$"

Route119_WeatherInstitute_2F_Text_ShellyIntro:
	.string "Kar-kar-kar!\p"
	.string "AQUA TALDEAREN kontuetan sartuko\n"
	.string "al duzu muturra?\p"
	.string "Orduan ez duzu inolako beldurrik,\n"
	.string "ignorantea zara, edo biak batera!\p"
	.string "Zu bai zu, a zer nolako nazka!\n"
	.string "Egurra emango dizut, gaztetxo!$"

Route119_WeatherInstitute_2F_Text_ShellyDefeat:
	.string "Kar-kar-kar!\n"
	.string "Nazkagarria da zure indarra!$"

Route119_WeatherInstitute_2F_Text_ShellyPostBattle:
	.string "MAGMA TALDEAREKIN nahikoa ez, eta\n"
	.string "orain zu ere tartean sartu behar!\p"
	.string "Zergatik sartzen duzu muturra gure\n"
	.string "kontuetan, ordea?$"

Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy:
	.string "Zerbait gertatu da hemen!\p"
	.string "MAGMA TALDEKO kide bat EGURALDI\n"
	.string "INSTITUTUTIK pasa da.\p"
	.string "Badirudi PIRO MENDIRANTZ\n"
	.string "doazela!$"

Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre:
	.string "Zer?!\p"
	.string "Ezin dugu denbora gehiago galdu!\n"
	.string "PIRO MENDIRA joan behar dugu!\p"
	.string "Kar-kar-kar!\n"
	.string "MAGMA TALDEA, ikusiko duzue!$"

Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon:
	.string "Eskerrik asko!\n"
	.string "Zuri esker, salbu gaude!\p"
	.string "Arraroa izan daiteke hau, baina\n"
	.string "hartu POKéMON hau esker gisa.$"

@ Unused
Route119_WeatherInstitute_2F_Text_NoRoomForPokemon:
	.string "Zer? Badirudi ez duzula lekurik\n"
	.string "POKéMON honentzat.$"

Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform:
	.string "{PLAYER}(e)k CASTFORM jaso du!$"

Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather:
	.string "POKéMON horrek forma aldatzen\n"
	.string "du eguraldiaren arabera.\p"
	.string "Asko daude INSTITUTUAN. Benetan,\n"
	.string "bat har dezakezu.$"

Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous:
	.string "Urte askoan aritu naiz euria aztertzen,\n"
	.string "baina gizakiek eguraldia aldatu\l"
	.string "dezaketela pentsatzea ergelkeria da.$"

Route119_WeatherInstitute_2F_Text_GroudonWeather:
	.string "Eguraldi patroiak aztertzen\n"
	.string "ditut HOENN eskualdean.\p"
	.string "Oraintxe, lehorte bat eman da\n"
	.string "{STR_VAR_1}(e)n.\p"
	.string "Horrek esan nahi du, {STR_VAR_1}\n"
	.string "inguruan…$"

Route119_WeatherInstitute_2F_Text_KyogreWeather:
	.string "Eguraldi patroiak aztertzen\n"
	.string "ditut HOENN eskualdean.\p"
	.string "Oraintxe, izugarrizko zaparrada\n"
	.string "erori da {STR_VAR_1}(e)n.\p"
	.string "Horrek esan nahi du, {STR_VAR_1}\n"
	.string "inguruan…$"

Route119_WeatherInstitute_2F_Text_NoAbnormalWeather:
	.string "Ez da ageri ohiz kanpoko\n"
	.string "eguraldirik.\p"
	.string "Nohizbehinkako euria oso atsegina\n"
	.string "da, egia esanda.$"

