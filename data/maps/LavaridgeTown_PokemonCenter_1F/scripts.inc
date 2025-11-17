.set LOCALID_NURSE, 1

LavaridgeTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavaridgeTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Woman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether:
	.string "Nire ustez POKéMONEN eta ENTRENATZAILEEN\n"
	.string "arteko harremana hobetzen da elkarrekin\p"
	.string "denbora pasata. Zenbat eta gehiago, hobe.\n"
	.string "Hori da nire iritzia.$"

LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate:
	.string "Ia-ia magikoa da ur-termaletan\n"
	.string "eserita egoteak ematen duen energia.\p"
	.string "Nire POKéMONEI bainatzen uztea\n"
	.string "gustatuko litzaidake.$"

LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo:
	.string "Hohoho! Aizu, gazte, ur-termaletara\n"
	.string "hemendik iritsi zaitezke.\p"
	.string "POKéMONEK deskantsatzen badute, baita\n"
	.string "haien ENTRENATZAILEEK ere.$"

