.set LOCALID_NURSE, 1

RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "Nire POKéMONAK izaera INOZOA du, eta nire\n"
	.string "lagunarenak izaera ALAIA.\p"
	.string "Izugarria da POKéMONEK izaera\n"
	.string "desberdinak izatea!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Pertsonen moduan, POKéMON arrak\n"
	.string "eta emeak daude.\p"
	.string "Baina inork ez daki zein desberdintasun\n"
	.string "dagoen beraien artean.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "Hurrengo etxeko gizonak ME bat eman dit!\p"
	.string "Nire POKéMONEI zuhaitz txikiak nola\n"
	.string "MOZTU irakasteko erabili dut.$"

