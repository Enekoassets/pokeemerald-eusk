.set LOCALID_NURSE, 1
.set LOCALID_LANETTE, 4

FallarborTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FallarborTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

FallarborTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_Girl::
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_Lanette::
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_1F_Text_LanetteGreeting, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth::
	applymovement LOCALID_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest::
	applymovement LOCALID_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExited::
	playse SE_SLIDING_DOOR
	removeobject LOCALID_LANETTE
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Text_LanetteGreeting:
	.string "Ei, kaixo.\n"
	.string "Nor zara?\p"
	.string "Ongi, {PLAYER}{KUN}, beraz.\n"
	.string "ENTRENATZAILEA zara, argi dago.\p"
	.string "Orduan, nik garatutako POKéMONAK\n"
	.string "Gordetzeko Sistema erabiltzen duzu.\p"
	.string "Ondorio horretara iristeko, prozesu\n"
	.string "oso erraza jarraitu dut.\p"
	.string "Nirekin hitz egni duzu PC\n"
	.string "honetako zerbait behar zenuelako.\p"
	.string "Ene, barkatu. LANETTE naiz.\p"
	.string "Pozten naiz zu ezagutzeaz, bikaina\n"
	.string "da zuk Gordetzeko Sistema erabiltzea.\p"
	.string "Ahal baduzu, etorri nire etxera.\n"
	.string "114. ERRUTAN dago.$"

FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown:
	.string "Nolakoak izango ote ziren POKéMONAK\n"
	.string "antzinako garaietan?\p"
	.string "Agian herriaren amaieran bizi den\n"
	.string "FOSIL MANIAKOAK jakingo du.$"

FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees:
	.string "ARREKARAKO zelaietan, zuhaitz\n"
	.string "indartsuen haziak landatzen ditugu,\l"
	.string "errauts bolaniko artean ere hazteko.$"

