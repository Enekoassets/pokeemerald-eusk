.set LOCALID_GRUNT_1, 10
.set LOCALID_GRUNT_2, 11
.set LOCALID_GRUNT_3, 12
.set LOCALID_GRUNT_4, 13
.set LOCALID_MAXIE, 14
.set LOCALID_SCOTT, 16

MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "MIKELENTZAKO hartu dut hau, baina,\n"
	.string "ez dakit zertarako balio duen.\p"
	.string "ERREGE ARROKA deitzen zaiola uste dut.\n"
	.string "Nahi al duzu?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Zertarako nahi duzu, ordea?\n"
	.string "Arraroa zara, gero.\p"
	.string "Hartu dezakezu, baina ez kontatu\n"
	.string "MIKELI.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "MIKELEN etxea hortxe bertan dago!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Zuk ere berdina uste duzu! Zertarako\n"
	.string "behar ote du arroka arraro hau?$"

MossdeepCity_Text_WailmerWatching:
	.string "GOROLDI inguruan, WAILMER basatiak\n"
	.string "aurkitu daitezke.\p"
	.string "Nola deitzen zaio…\n"
	.string "Izena ahaztu zait…\p"
	.string "WAI, WAI, WAI…\p"
	.string "WAILMERRAK behatzea!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "Irlako ESPAZIO ZENTROTIK suziri\n"
	.string "erraldoiak botatzen aritu dira.\p"
	.string "Iskanbilaren bat egon omen da, jaso\n"
	.string "ebrri duten gutun batengatik.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "Irlako ESPAZIO ZENTROTIK suziri\n"
	.string "erraldoiak botatzen aritu dira.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "Lagun MARINEL batek esan dit AQUA\n"
	.string "TALDEA UR-LILIN negoziotan dabilela.\p"
	.string "Entzun dut, gainera, norbaitek iritsi\n"
	.string "eta izugarrizko egurra eman ziela!\p"
	.string "Baina GOROLDIRI MAGMA TALDEKOEK\n"
	.string "bota diote begia.\p"
	.string "Zertan dabiltzan jakin nahi baduzu,\n"
	.string "ESPAZIO ZENTRORA joan behar zenuke.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "MARINELA naiz, beraz, itsasoa da\n"
	.string "garrantzitsuagoa niretzat.\p"
	.string "baina, badakizu zer? Bidaia baten ostean\n"
	.string "lurrera itzultzean, lasai sentitzen naiz!$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "Ez al litzateke ederra?\p"
	.string "Lur osoa lorez eta landarez lepo egongo\n"
	.string "balitz, irla honetan bezala?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "Bizidun guztiek behar dute itsasoa,\n"
	.string "nahiz eta lurrean bizi.\p"
	.string "Bizidunak, beren bidea jarraituz, lur\n"
	.string "bihurtu eta zorura itzultzen dira.\p"
	.string "Eta itsasoa beti dago lurrera\n"
	.string "konektatuta.\p"
	.string "Bai, hemengo itsasertz honetan bezala.$"

MossdeepCity_Text_SurfExhilarating:
	.string "Ontzi batean bidaiatzea ondo dago.\p"
	.string "Baina SURFA erabiltzen duen POKéMON\n"
	.string "batekin itsasoa zeharkatzea…\p"
	.string "Hori bai bidaia suspergarria!\n"
	.string "Ados al zaude, gazte?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "Arroka hau ebrezia da ESPAZIO\n"
	.string "ZENTROKO jendearentzat.\p"
	.string "Hemen jartzen dute, beraien suziriak\n"
	.string "seguru joan daitezen.\p"
	.string "Gurari bat eskatzeko, zer erabiltzen duzu?\n"
	.string "Izar-uxoren bat?\p"
	.string "Nik gurari amuleto bat.\n"
	.string "Horixe erabiltzen dut nik.$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "Arroka zuri bat da.$"

MossdeepCity_Text_GymSign:
	.string "GOROLDI HIRIKO POKéMON GIMNASIOA\n"
	.string "LIDERRAK: JON & JONE\p"
	.string "“Konbinaketa mistikoa!”$"

MossdeepCity_Text_CitySign:
	.string "GOROLDI HIRIA\n"
	.string "“Gure eslogana: Maitatu POKéMONAK!”$"

MossdeepCity_Text_SpaceCenterSign:
	.string "GOROLDIKO ESPAZIO ZENTROA\n"
	.string "“Espaziotik hurbilen dagoen lekua.”$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "TRIKI: {PLAYER}{KUN}, ondo al zabiltza?\n"
	.string "Ni bikain nago!\p"
	.string "Entzun dut GOROLDIKO GIMNASIOKO\n"
	.string "LIDERRA indartsua dela, eta neure\l"
	.string "begiekin ikustera etorri naiz.\p"
	.string "bainaz erbait arraroa dago\n"
	.string "herri honetan.\p"
	.string "Jendea urduri dago ESPAZIO ZENTRORA\n"
	.string "iritsi den gutun batengatik…\p"
	.string "Ez dut uste nire kontua denik,\n"
	.string "hala eta guztiz ere.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "Ene… Olatuei nire oinak inguratzen\n"
	.string "uztea bikaina da…\p"
	.string "Olatuez ari garenez, ezagutzen duzu\n"
	.string "ARREZZIPOLIS izeneko irla hiria?\p"
	.string "Uste dut hango GIMNASIORA LIDER\n"
	.string "berri bat iritsi dela.\p"
	.string "Jendeak dioenez, LIDER hori\n"
	.string "UREDERREN maisua izan omen zen.$"

