.set LOCALID_NURSE, 1

BattleFrontier_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BattleFrontier_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST
	end

BattleFrontier_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_SchoolKid::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Man::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Picnicker::
	msgbox BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox BattleFrontier_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon:
	.string "Inoiz ikusi gabeko POKéMON bat\n"
	.string "erabiltzen ari zen norbait lehen.\p"
	.string "ENTRENATZAILE ESKOLAN behintzat\n"
	.string "ez ziguten inoiz erakutsi.\p"
	.string "Halako POKéMONAK non harrapatzen\n"
	.string "diren jakin nahi nuke.$"

BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena:
	.string "Ongi! Hurrengo geldialdia, BORROKA\n"
	.string "ARENA! Hobe dut POKéMON egokia\l"
	.string "hartzea PC Gordailu Sistematik.$"

BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge:
	.string "Kar-kar… Txikitxo honekin bakarrik\n"
	.string "gaindituko ditut erronka guztiak!$"

BattleFrontier_PokemonCenter_1F_Text_Skitty:
	.string "SKITTY: Mia miaaah!$"

