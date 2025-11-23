.set LOCALID_WALLACE, 1
.set LOCALID_RIVAL, 2
.set LOCALID_BIRCH, 3

EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_BIRCH
	applymovement LOCALID_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string "UREDER: Ongi etorri, {PLAYER}{KUN}.\p"
	.string "ARREZIPOLIS HIRIAN gertatu zena…\n"
	.string "Lan izugarria egin zenuen, arazoari\l"
	.string "zuk bakarrik aurre eginez.\p"
	.string "Ups!\p"
	.string "Ez litzateke justua arazoa zuk\n"
	.string "bakarrik konpondu zenuela esatea.\p"
	.string "Zure POKéMONEKIN batera lan eginez\n"
	.string "lortu zenuen guztia bere onera itzultzea.\p"
	.string "ENTRENATZAILEOK, gure POKéMONAK itemak\n"
	.string "emanez eta borrokarako teknika berriak\l"
	.string "erakutsiz hazten ditugu.\p"
	.string "Baina guk gerorrek ere asko ikasten\n"
	.string "dugu gure POKéMONENGANDIK.\p"
	.string "Eta hementxe bertan neurtzen dira zuen\n"
	.string "garaipenak, halakoak lortu dituzten\l"
	.string "besteen garaipenen alboan.\p"
	.string "Entzun!\p"
	.string "Zeinek egin dezake dantza dotoreen\n"
	.string "bere POKéMONEKIN HOENNEN?\p"
	.string "Erakutsi iezadazu orain!$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string "Ni, TXAPELDUNA, garaitu egin naute…\p"
	.string "Lan bikaina egin duzu.\n"
	.string "Oso dotorea izan zara, benetan.\l"
	.string "Eta guztiz gorena izan da borroka!\p"
	.string "Zorionak, {PLAYER}{KUN}!\p"
	.string "Benetan zara POKéMON\n"
	.string "ENTRENATZAILE zintzoa!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string "UREDER: Borrokara bidali dituzun\n"
	.string "POKéMONAK…\p"
	.string "Batzuetan, haize freskoa bezala egin\n"
	.string "dute dantza, eta besteetan tximistaren\l"
	.string "abiaduraz egin dute eraso.\p"
	.string "Bizia izan da, baina ziurra,\n"
	.string "zure POKéMONAK gidatzeko duzun era.\p"
	.string "Ni ere txundituta geratu naiz\n"
	.string "zure goi mailako erakustaldiarekin!\p"
	.string "Azkenean, POKéMON LIGAREN\n"
	.string "tontorreraino iritsi zara.\p"
	.string "Nik izendatzen zaitut HOENN\n"
	.string "eskualdeko…$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string "MAIA: {PLAYER}{KUN}!\p"
	.string "TXAPELDUNARI aurre egin baino lehenago\n"
	.string "entzun aholku hauek…$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string "MAIA: Nola?\n"
	.string "Zer, zer, zer?\p"
	.string "{PLAYER}{KUN}…\n"
	.string "Baina, zer diozu…\l"
	.string "Jada amaitu dela?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string "BEÑAT: {PLAYER}!\p"
	.string "Nahi al duzu TXAPELDUNARI aurre egin\n"
	.string "baino lehenago aholku bat?…$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string "BEÑAT: {PLAYER}…\p"
	.string "Zer esan nahi didazu…\n"
	.string "TXAPELDUNA garaitu duzula?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string "URKI DOKT.: Ikusten?\n"
	.string "Zer esan dizut, {RIVAL}?\p"
	.string "Ez al dizut ez zenuela zertan\n"
	.string "{PLAYER}{KUN}(r)engatik kezkatu?\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER}{KUN}, lortu duzu azkenean.\p"
	.string "Zure aita PETALOREKO GIMNASIOAN\n"
	.string "garaitu zenuela entzun nuenean,\l"
	.string "agian aukera bat zenuela pentsatu nuen…\p"
	.string "Baina azkenean TXAPELDUNA izateraino\n"
	.string "heltzea ere!\p"
	.string "Ah, bai!\p"
	.string "Nola dago orain zure POKéDEXA?\n"
	.string "Ea, erakutsi.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string "URKI DOKT.: Beno,\n"
	.string "zorionak!\p"
	.string "Ea, orain segi harro azken aretora!$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
	.string "UREDER: {PLAYER}{KUN}…\p"
	.string "Ez, utzi gauzak ganora esaten.\p"
	.string "TXAPELDUN berria!\p"
	.string "Etorri zaitez nirekin.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
	.string "UREDER: Sentitzen dut, baina…\p"
	.string "Hemendik aurrera, TXAPELDUN bilakatu\n"
	.string "diren ENTRENATZAILEAK soilik pasa daitezke.\p"
	.string "URKI DOKTOREAREKIN kanpoan itxaron\n"
	.string "beharko duzu.$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
	.string "MAIA: Grrrr…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Txantxetan ari naiz! Ez da ezer gertatzen!\n"
	.string "Hori da araua!\p"
	.string "{PLAYER}{KUN}!\n"
	.string "BenetaN, zorionak!$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
	.string "BEÑAT: Zeeeer?! … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Ezin ezer egin, arraua hori bada.\p"
	.string "{PLAYER}, zu bai zu!\n"
	.string "Zorionak!$"

