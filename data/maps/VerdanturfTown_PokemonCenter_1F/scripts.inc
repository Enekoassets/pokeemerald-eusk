.set LOCALID_NURSE, 1

VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon:
	.string "Ezin duzu zure burua benetako\n"
	.string "ENTRENATZAILETZAT hartu ez baduzu\l"
	.string "fedea zure POKéMONENGAN.\p"
	.string "Borrokan bere POKéMONENGAN sinesten\n"
	.string "duten horiek bakarrik dira gai\l"
	.string "amaieraraino iristeko.$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent:
	.string "BERDEZELAI bisitatzeko arrazoi\n"
	.string "bakarra…\p"
	.string "BORROKA DENDA da. Ez dago inolako\n"
	.string "dudarik.\p"
	.string "Edo norbait bisitatzera etorri\n"
	.string "zara hona?$"

