.set LOCALID_TRICK_MASTER, 1

Route110_TrickHouseEnd_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHouseEnd_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEnd_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEnd_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEnd_OnWarp
	.byte 0

Route110_TrickHouseEnd_OnResume:
	call_if_eq VAR_TEMP_1, 1, Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	end

Route110_TrickHouseEnd_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	special SetTrickHouseNuggetFlag
	end

Route110_TrickHouseEnd_OnWarp:
	map_script_2 VAR_TEMP_2, 0, Route110_TrickHouseEnd_EventScript_SetTrickMasterPos
	.2byte 0

Route110_TrickHouseEnd_EventScript_SetTrickMasterPos::
	addobject LOCALID_TRICK_MASTER
	showobjectat LOCALID_TRICK_MASTER, MAP_ROUTE110_TRICK_HOUSE_END
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
	end

Route110_TrickHouseEnd_OnFrame:
	map_script_2 VAR_TEMP_1, 0, Route110_TrickHouseEnd_EventScript_CloseDoor
	.2byte 0

Route110_TrickHouseEnd_EventScript_CloseDoor::
	setvar VAR_TEMP_1, 1
	call Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	special DrawWholeMapView
	end

Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile::
	setmetatile 10, 1, METATILE_GenericBuilding_TrickHouse_Door_Closed, TRUE
	return

Route110_TrickHouseEnd_EventScript_TrickMaster::
	lock
	faceplayer
	msgbox Route110_TrickHouseEnd_Text_YouveMadeItToMe, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEnd_EventScript_CompletedPuzzle1
	case 1, Route110_TrickHouseEnd_EventScript_CompletedPuzzle2
	case 2, Route110_TrickHouseEnd_EventScript_CompletedPuzzle3
	case 3, Route110_TrickHouseEnd_EventScript_CompletedPuzzle4
	case 4, Route110_TrickHouseEnd_EventScript_CompletedPuzzle5
	case 5, Route110_TrickHouseEnd_EventScript_CompletedPuzzle6
	case 6, Route110_TrickHouseEnd_EventScript_CompletedPuzzle7
	case 7, Route110_TrickHouseEnd_EventScript_CompletedPuzzle8
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle1::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPlantTrees, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_RARE_CANDY
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle2::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMaze, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TIMER_BALL
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle3::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPreparePanels, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_HARD_STONE
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle4::
	msgbox Route110_TrickHouseEnd_Text_AllNightToShoveBoulders, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_SMOKE_BALL
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle5::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TM_TAUNT
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle6::
	msgbox Route110_TrickHouseEnd_Text_AllNightToInstallDoors, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_MAGNET
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle7::
	msgbox Route110_TrickHouseEnd_Text_AllNightSettingUpArrows, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_PP_MAX
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle8::
	msgbox Route110_TrickHouseEnd_Text_AllNightPolishingFloors, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_SOUTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth
	call_if_eq VAR_FACING, DIR_NORTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth
	call_if_eq VAR_FACING, DIR_WEST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest
	call_if_eq VAR_FACING, DIR_EAST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast
	delay 30
	msgbox Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
	waitmovement 0
	delay 30
	msgbox Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	call Route110_TrickHouseEnd_EventScript_ChooseTent
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_NoRoomForTent
	msgbox Route110_TrickHouseEnd_Text_LeavingOnJourney, MSGBOX_DEFAULT
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	special ResetTrickHouseNuggetFlag
	release
	end

Route110_TrickHouseEnd_EventScript_ChooseTent::
	multichoice 0, 0, MULTI_TENT, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHouseEnd_EventScript_GiveRedTent
	goto Route110_TrickHouseEnd_EventScript_GiveBlueTent

Route110_TrickHouseEnd_EventScript_GiveRedTent::
	givedecoration DECOR_RED_TENT
	return

Route110_TrickHouseEnd_EventScript_GiveBlueTent::
	givedecoration DECOR_BLUE_TENT
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExit::
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterSpin
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterJumpAway
	waitmovement 0
	removeobject LOCALID_TRICK_MASTER
	addvar VAR_TRICK_HOUSE_LEVEL, 1
	return

Route110_TrickHouseEnd_EventScript_BagFull::
	call Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEnd_Text_NoRoomForThis, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_NoRoomForTent::
	call Common_EventScript_NoRoomForDecor
	msgbox Route110_TrickHouseEnd_Text_NoRoomInPC, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExitTrigger::
	lockall
	turnobject LOCALID_TRICK_MASTER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_TRICK_MASTER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouseEnd_Movement_TrickMasterSurprise
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route110_TrickHouseEnd_Text_YoureIgnoringMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route110_TrickHouseEnd_Movement_KeepPlayerInRoom
	waitmovement 0
	delay 4
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
	releaseall
	end

Route110_TrickHouseEnd_Movement_KeepPlayerInRoom:
	walk_down
	step_end

Route110_TrickHouseEnd_Movement_TrickMasterSurprise:
	jump_in_place_left
	step_end

Route110_TrickHouseEnd_Text_YouveMadeItToMe:
	.string "Nola?!\n"
	.string "Niganaino iritsi zara?\l"
	.string "Hmmm… Zu bai zu bizkorra!$"

Route110_TrickHouseEnd_Text_AllNightToPlantTrees:
	.string "Gau osoa behar izan dut zuhaitz\n"
	.string "horiek landatzeko…\p"
	.string "Ia ni bezain itzela zara, bat, bi, hiru,\n"
	.string "lau, bost eta sei posiziorengatik!$"

Route110_TrickHouseEnd_Text_AllNightToMakeMaze:
	.string "Gau osoa behar izan dut labirintua egiteko…\p"
	.string "Ia ni bezain itzela zara, bat, bi,\n"
	.string "hiru, lau eta bost posiziorengatik!$"

Route110_TrickHouseEnd_Text_AllNightToPreparePanels:
	.string "Gau osoa behar izan dut\n"
	.string "hormetako panelak jartzeko…\p"
	.string "Ia ni bezain itzela zara, bat, bi,\n"
	.string "hiru eta lau posiziorengatik!$"

Route110_TrickHouseEnd_Text_AllNightToShoveBoulders:
	.string "Gau osoa behar izan dut harritzar\n"
	.string "horiek sartzeko…\p"
	.string "Ia ni bezain itzela zara, bat, bi\n"
	.string "eta hiru posiziorengatik!$"

Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls:
	.string "Gau osoa behar izan dut MEKAPANPINAK\n"
	.string "jartzeko eta beste bat galderentzat…\p"
	.string "Ia ni bezain itzela zara, bat eta\n"
	.string "bi posiziorengatik!$"

Route110_TrickHouseEnd_Text_AllNightToInstallDoors:
	.string "Gau osoa behar izan dut\n"
	.string "ateak jartzeko…\p"
	.string "Ia ni bezain itzela zara!$"

Route110_TrickHouseEnd_Text_AllNightSettingUpArrows:
	.string "Gau osoa behar izan dut geziak jartzeko…\p"
	.string "Ni bezain itzela zara!$"

Route110_TrickHouseEnd_Text_AllNightPolishingFloors:
	.string "Gau osoa behar izan dut lurra ezkoztatzeko…\p"
	.string "Ni baino itzelagoa zara!\n"
	.string "Ziurrenik…$"

Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry:
	.string "Ze-zer egin behar nuke?\n"
	.string "Nire ideia iturria guztiz\l"
	.string "agortu da…\p"
	.string "Agian bada garaia trikimailu\n"
	.string "berrien bila herrialdea ikusteko…$"

Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent:
	.string "Ez dut porrota onartu nahi, baina\n"
	.string "garaitu egin nauzu!\p"
	.string "Hala ere, nire karismak funtzionatu\n"
	.string "du, behin eta berriz bisitatu nauzu\l"
	.string "eta. Bai ziur horregatik izan dela!\p"
	.string "Baina horrek ez du zerikusirik\n"
	.string "nik galtzearekin!\p"
	.string "Gure arteko laguntasuna ospatzeko,\n"
	.string "zu, lehiakide ekinarena eta ni, genio\l"
	.string "biziarena, hartu oroigarri hau\l"
	.string "zuretzako!\p"
	.string "Beno, izatez bi daude aukeran:\n"
	.string "DENDA GORRIA eta DENDA URDINA.\l"
	.string "Zein duzu nahiago?$"

Route110_TrickHouseEnd_Text_NoRoomInPC:
	.string "Zer? Lekurik ez PCAN?\n"
	.string "Eta zer egin dezaket nik bada?\p"
	.string "Hori esan nahi nuke, baina jatorregia\n"
	.string "naiz, beraz, etorri beranduago bila!$"

Route110_TrickHouseEnd_Text_LeavingOnJourney:
	.string "… … … … … …\p"
	.string "Bilaketa bidaia batera noa.\n"
	.string "Trikimailu berrien bilako abenturan.\p"
	.string "Espero dut egunen batean bisitan etorri\n"
	.string "eta berriro entretenituko nauzula.\p"
	.string "Eta orain, agur!$"

Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward:
	.string "Ongi!\n"
	.string "Sari hau irabazi duzu!$"

Route110_TrickHouseEnd_Text_NoRoomForThis:
	.string "Zer? Ez duzula lekurik honentzat?\n"
	.string "Baina zenbat item dituzu, baina?\p"
	.string "Baina, ongi, niganaino iritsi zarenez,\n"
	.string "zure saria gordeko dut etorri arte.$"

Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou:
	.string "Kendu irribarre hori zure aurpegitik!\n"
	.string "Goizegi da irabazi duzula pentsatzeko!\p"
	.string "Trikimailu berriak egingo ditut, bai.\n"
	.string "Garaitzen nauzunean egingo didazu burla.\p"
	.string "Itzuli instalazio berri izugarriak\n"
	.string "jartzen ditudanean!$"

Route110_TrickHouseEnd_Text_YoureIgnoringMe:
	.string "Aizu, aizu! Ez didazu kasurik egingo?\n"
	.string "Horrek bai bihotza hautsi didala!$"

