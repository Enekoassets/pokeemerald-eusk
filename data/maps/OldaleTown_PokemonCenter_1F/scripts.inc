.set LOCALID_NURSE, 1

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "Izkina horretako PCa edozein POKéMON\n"
	.string "ENTRENATZAILEK erabili dezake.\p"
	.string "Noski, horrek esan nahi du zuk ere\n"
	.string "erabili dezakezula.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "POKéMON ZENTROAK bikainak dira!\p"
	.string "Beraien zerbitzuak nahibeste erabili\n"
	.string "ditzakezu, doan, gainera.\l"
	.string "Ez duzu arduratu beharrik!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "Bigarren solairuko HARI GABEKO POKéMON\n"
	.string "KLUBA duela gutxi eraiki dute.\p"
	.string "Baina esan idate oraindik doikuntza\n"
	.string "batzuk egiten ari direla.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "Bigarren solairuko HARI GABEKO POKéMON\n"
	.string "KLUBA duela gutxi eraiki dute.\p"
	.string "Ziztuan trukatu ditut POKéMONAK.$"

