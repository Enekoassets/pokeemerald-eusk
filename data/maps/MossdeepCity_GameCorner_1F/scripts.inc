MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end


@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "Gaztea nintzenean, mundua zeharkatu\n"
	.string "nuen POKéMON ENTRENATZAILE bezala.\p"
	.string "Orain agure zahar bihurtu naizenez,\n"
	.string "ENTRENATZAILE gazteak borrokan ikustea\l"
	.string "soilik gustatzen zait.$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "Badirudi atea itxita dagoela.$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "{STR_VAR_1} izeneko ENTRENATZAILE\n"
	.string "bat dago nire etxean bisitan.\p"
	.string "Nahi diozu erronka bota\n"
	.string "{STR_VAR_1}(e)ri?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "Ez duzu borrokatuko? Triste jarriko\n"
	.string "naiz ezin zaitudalako borrokan ikusi…$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "Bai, ongi, ongi!\p"
	.string "Baina nire etxea ez da horren sendoa.\p"
	.string "Egin dezakezue 3 3ren aurkako\n"
	.string "borroka bat?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "Borrokatu aurretik, zure partida\n"
	.string "gorde behar zenuke.$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "Ea borroka itzel bat ikusten dudan!$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "Izugarrizko borroka izan da.\p"
	.string "Alde batek ere amore eman ez duen\n"
	.string "borroka itzela izan da!$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "Hori sinesgaitza izan da!\p"
	.string "Berriro gazte izatea bezalakoa\n"
	.string "izan da ia-ia!$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "Pena zuretzat!\p"
	.string "Baina borroka ona izan da.\n"
	.string "Ea hurrengoan irabazten duzun.$"
