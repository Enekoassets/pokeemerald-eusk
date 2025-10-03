.set LOCALID_NURSE, 1

PacifidlogTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PacifidlogTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Girl::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Woman::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_OldMan::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard:
	.string "Zein koloretakoa da zure ENTRENATZAILE\n"
	.string "TXARTELA? Nire kobre kolorekoa!$"

PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola:
	.string "URREBARE HERRIA CORSOLA kolonia\n"
	.string "baten gainean dago flotatzen.\p"
	.string "Hori esango banizu, sinestuko al\n"
	.string "zenidake?$"

PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats:
	.string "URREBAREKO jendearen arbasoak\n"
	.string "ontzietan jaio, bizi eta hiltzen\l"
	.string "zirela kontatu izan didate\l"
	.string "batzuetan.\p"
	.string "Suposatzen dut hala bizi zirela\n"
	.string "zerbaiten bila aritzen zirelako\l"
	.string "edo.$"

