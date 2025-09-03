.set LOCALID_ATTENDANT, 1

VerdanturfTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_OnFrame
	.byte 0

VerdanturfTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 6, 5
	waitstate
	releaseall
	end

VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end


@ Leftover text from when this was a Contest Hall in R/S
@ Unused
VerdanturfTown_ContestHall_Text_WhichContestYouEntering:
	.string "Zein TXAPELKETATARA zoaz?\n"
	.string "Nahi duzu aholku bat?\p"
	.string "Edozein TXAPELKETATAN, adibidez,\n"
	.string "POLITASUN TXAPELKETAN, ez dut uste\l"
	.string "politasuna bakarrik egiratzen dutenik\p"
	.string "lehen txandan. POKéMONAK hobeto hazteko\n"
	.string "erak bilatu behar dituzu.$"

@ Unused
VerdanturfTown_ContestHall_Text_RaisedMonToBeCute:
	.string "POKéMONAK politak izateko hazi ditut.\p"
	.string "Eta jakin dut POKéMONAK POLITASUN\n"
	.string "TXAPELKETAN sar ditzakezula!\p"
	.string "Oso pozik nago nire POKéMONAK\n"
	.string "maitasunez hazi ditudalako…$"

@ Unused
VerdanturfTown_ContestHall_Text_MyMonRules:
	.string "Nire POKéMONA onena da!\p"
	.string "karismatikoa, gogorra baina ederra,\n"
	.string "polita eta azkarra. Guztiz osatua!\p"
	.string "Azkenean TXAPELKETA guztietan lehen\n"
	.string "postua lortuko dut.$"

@ Unused
VerdanturfTown_ContestHall_Text_NormalRankStage:
	.string "POKéMON TXAPELKETAK\n"
	.string "MAILA NORMALEKO ARETOA!$"

