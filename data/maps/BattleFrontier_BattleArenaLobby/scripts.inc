.set LOCALID_ATTENDANT, 1

BattleFrontier_BattleArenaLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge

BattleFrontier_BattleArenaLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 9, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena:
	.string "ENTRENATZAILEEN borrokarako gogoa\n"
	.string "jokoan jartzen den tokira!\p"
	.string "Ongi etorri BORROKA ARENARA!\p"
	.string "KO Txapelketarako zure gida izango naiz!$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
	.string "BORROKA ARENAKO erronkan izena\n"
	.string "eman nahi al duzu?$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
	.string "Beste batean etorriko zarela\n"
	.string "espero dugu!$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
	.string "BORROKA ARENAN KO Txapelketa\n"
	.string "ospatzen da.\p"
	.string "Parte hartzaileek hiru POKéMONEKO\n"
	.string "talde batekin hartu behar dute parte.\p"
	.string "Hiru POKéMONAK ondoren aterako diren\n"
	.string "ordenan aukeratu behar dira.\p"
	.string "Borrokan, POKéMONAK banaka agertuko dira,\n"
	.string "aurrez aukeratutako ordenan.\p"
	.string "Behin POKéMON bat sartu denean, hor\n"
	.string "geratu behar da emaitza jakin arte.\p"
	.string "Partidaren emaitza ez bada aukeratzen\n"
	.string "hiru txandatan, epaia hasiko da.\p"
	.string "Erronka geratu nahi baduzu, mesedez,\n"
	.string "gorde partida.\p"
	.string "Ez baduzu gordetzen, ezingo duzu\n"
	.string "erronka utzi duzun lekutik jarraitu.\p"
	.string "Zazpi ENTRENATZAILE jarraian garaitzea\n"
	.string "lortzen baldin baduzu, Borroka\l"
	.string "Puntuak irabaziko dituzu.$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave:
	.string "BORROKA ARENARA sartu aurretik, partida\n"
	.string "gorde behar duzu. Ados al zaude?$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
	.string "BORROKA ARENAN bi mailatako erronkak\n"
	.string "daude aukeran, 50. Maila eta Maila Irekia.\l"
	.string "Zein aukeratu nahi duzu?$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
	.string "Oso ongi, orain aukeratu zure\n"
	.string "hiru POKéMONAK, mesedez.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Lehiakide maitea!\p"
	.string "Ez dauzkazu parte hartzeko behar\n"
	.string "diren hiru POKéMON.\p"
	.string "Horretarako, hiru POKéMON mota\n"
	.string "desberdin ekarri behar dituzu.\p"
	.string "Gainera, ezin dute mota bereko\n"
	.string "itemik eduki.\p"
	.string "ARRAUTZAK{STR_VAR_1} ezin dira aukeratu.\p"
	.string "Prestakuntzak egiten dituzunean\n"
	.string "itzuli, mesedez.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
	.string "Lehiakide maitea!\p"
	.string "Ez dauzkazu parte hartzeko behar\n"
	.string "diren hiru POKéMON.\p"
	.string "Horretarako, hiru POKéMON mota\n"
	.string "desberdin ekarri behar dituzu.\p"
	.string "Hiru POKéMON hauek 50. Mailan\n"
	.string "edo beherago egon behar dira.\p"
	.string "Gainera, ezin dute mota bereko\n"
	.string "itemik eduki.\p"
	.string "ARRAUTZAK{STR_VAR_1} ezin dira aukeratu.\p"
	.string "Prestakuntzak egiten dituzunean\n"
	.string "itzuli, mesedez.$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
	.string "Orain BORROKA ARENA barrura\n"
	.string "gidatuko zaitut.$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
	.string "Lehiakide maitea!\p"
	.string "Ez duzu partida gorde itzali\n"
	.string "aurretik, ez da hala?\p"
	.string "Sentitzen dut, baina horren ondorioz\n"
	.string "erronkatik deskalifikatuta geratu\l"
	.string "zara.\p"
	.string "Noski, berriro hasi zaitezke\n"
	.string "hasieratik, nahi duzunean.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
	.string "Zorionak eman nahi dizkizugu zazpi\n"
	.string "ENTRENATZAILE jarraian garaitzeagatik!$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
	.string "Zure lorpena grabatu egingo da.\n"
	.string "Itxaron partida gorde bitartean, mesedez.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
	.string "In commemoration of your 7-win streak,\n"
	.string "we present you with this prize.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
	.string "Oh?\n"
	.string "Your BAG seems to be full.\p"
	.string "I urge you to clear space and\n"
	.string "return for your prize.$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
	.string "Eskerrik asko parte hartzeagatik!\p"
	.string "Itxaron partida gorde bitartean, mesedez.$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
	.string "Beste batean itzuliko zarela\n"
	.string "espero dugu!$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
	.string "Zu noiz etorriko zain egon\n"
	.string "gara.\p"
	.string "BORROKA ARENARA sartu aurretik,\n"
	.string "partida gorde behar dut.\l"
	.string "Itxaron, mesedez.$"

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
	.string "Grabatuko dut zure azken BORROKA\n"
	.string "ARENAKO partida zure FRONTE PASEAN?$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
	.string "EPAILEAREN aukeran galdu dut…\p"
	.string "Uste dut ez dela ideia ona izan\n"
	.string "beti defentsako erasoak erabiltzea…$"

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
	.string "Epaiean irabazi dut!\p"
	.string "Etengabe bestearen POKéMONEI erasoak\n"
	.string "jotzeak balio izan du!$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
	.string "Gure borroka berdinketa izan da.\p"
	.string "Denbora bukatu denean, nire\n"
	.string "POKéMONARI eta etsaiarenari BP\l"
	.string "kantitate bera gelditzen zitzaien.$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
	.string "BORROKA ARENAN, POKéMONEN ordena\n"
	.string "izugarri garrantzitsua da.\p"
	.string "Adibidez, zure lehenengo POKéMONAK\n"
	.string "mota batzuen aurka sufritzen badu,\l"
	.string "komeni da zure bigarren POKéMONAK\l"
	.string "lehenengo motaren aurka onak diren\l"
	.string "erasoak izatea.\p"
	.string "Esango nuke horrela talde egoki\n"
	.string "bat osatuko duzula.$"

BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
	.string "KO Txapelketako arauak dira.$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
	.string "Zein irakurri nahi duzu?$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
	.string "KO Txapelketak arau bereziak ditu,\n"
	.string "borroka arruntek ez bezala.\p"
	.string "Lehenik, borrokak hiru txanda\n"
	.string "besterik ez ditu irauten.\p"
	.string "Hiru txanda hauen ostean ez badago\n"
	.string "irabazlerik, epaia hasten da.\p"
	.string "EPAILEAK irabazlea aukeratuko du,\n"
	.string "POKéMONEK borrokatu duten eraren arabera.\p"
	.string "Gainera, ezin da POKéMONIK aldatu\n"
	.string "borrokaren emaitza hakin arte.$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
	.string "Epaiaren lehen faktorea “Burua” da.\n"
	.string "Borrokalarien oldarkortasuna neurtzen\l"
	.string "du faktore honek.\p"
	.string "Hemen neurtzen da ea ENTRENATZAILEEK\n"
	.string "zenbat aldiz aukeratu duten eraso\l"
	.string "ofentsiboak egitea.$"

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
	.string "Bigarren faktorea “Trebetasuna” da.\n"
	.string "Hemen POKéMONEN erasoen\l"
	.string "eraginkortasuna neurtzen da.\p"
	.string "Eraso batek funtzionatu badu,\n"
	.string "puntuazio hau igo egiten da.\p"
	.string "Ez badu jo, ordea, Trebetasunaren\n"
	.string "puntuazioa jaitsi egiten da.\p"
	.string "Erasoa ofentsiboa bazen, puntuazio hau\n"
	.string "igo egiten da erasoa “oso eraginkorra”\l"
	.string "bazen, eta jaitsi “ez oso eraginkorra”\l"
	.string "bazen.\p"
	.string "Puntuazioa ez da igoko BABESA eta\n"
	.string "DETEKZIOA bezalako erasoekin.\p"
	.string "Etsaiak BABESA edo DETEKZIOA erabili\n"
	.string "badu, eta zure POKéMONAK ez badu jo\l"
	.string "horren ondorioz, Trebetasun puntuazioa\l"
	.string "ez da jaitsiko.$"

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
	.string "Hirugarren faktorea “Gorputza” da.\n"
	.string "Faktore honek neurtzen du zenbat BP\l"
	.string "geratu diren borrokaren amaieran.\p"
	.string "Neurtzen dena da, ea POKéMON bakoitzak\n"
	.string "zenbat BP zituen borrokaren hasieran,\l"
	.string "eta zenbat geratu diren amaieran.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
	.string "ARENAKO BURUARI irabazi eta zazpi\n"
	.string "ENTRENATZAILE jarraian garaituta!\p"
	.string "Zorionak horrelako balentria\n"
	.string "bikaina lortzeagatik!$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
	.string "Lehiakide maitea, horren jarrera\n"
	.string "nekaezina izateagatik, mesedez,\l"
	.string "onartu Borroka Puntu hauek.$"
