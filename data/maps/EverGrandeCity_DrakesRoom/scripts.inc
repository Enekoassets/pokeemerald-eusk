EverGrandeCity_DrakesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_DrakesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_DrakesRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

EverGrandeCity_DrakesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 4, EverGrandeCity_DrakesRoom_EventScript_CloseDoor
	end

EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_DrakesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_DrakesRoom_EventScript_Drake::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_Defeated::
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_Text_IntroSpeech:
	.string "POKéMON LIGAKO ELITE LAUKOTEKO azkena\n"
	.string "naiz, DRAKOI, DRAGOI maisua!\p"
	.string "Eremu naturalean, POKéMONAK izaki\n"
	.string "basati eta bizidunak dira. Guztiz askeak.\p"
	.string "Batzuetan, oztopatu egiten gaituzte.\n"
	.string "Besteetan, lagundu egiten digute.\p"
	.string "POKéMONEKIN borroka egiten dugunontzat,\n"
	.string "ba al dakizu zer den garrantzitsua?\p"
	.string "Ba al dakizu zer den beharrezkoa?\p"
	.string "Ez baldin badakizu, ez duzu inoiz\n"
	.string "ni garaitzea lortuko!$"

EverGrandeCity_DrakesRoom_Text_Defeat:
	.string "Aparta, esan beharra dago.$"

EverGrandeCity_DrakesRoom_Text_PostBattleSpeech:
	.string "POKéMON ENTRENATZAILE gisan honaino\n"
	.string "iristeagatik zoriondu behar zaitut.\p"
	.string "Badakizu zer den behar dena, bai.\p"
	.string "Bai, ENTRENATZAILE batek behar duena\n"
	.string "bihotz onekoa izatea da.\p"
	.string "POKéMONEK ENTRENATZAILEEN bihotza\n"
	.string "ukitzen dute, ona eta txarra banatuz.\p"
	.string "ENTRENATZAILEEN bihotzak ukitzen\n"
	.string "dituzte, eta indartsu bilakatu.\p"
	.string "Segi! Segi aurrera!\n"
	.string "Zain duzu TXAPELDUNA!$"

