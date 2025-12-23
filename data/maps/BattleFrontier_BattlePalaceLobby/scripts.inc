.set LOCALID_ATTENDANT_SINGLES, 1
.set LOCALID_ATTENDANT_DOUBLES, 6

BattleFrontier_BattlePalaceLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_OnWarp
	.byte 0

BattleFrontier_BattlePalaceLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePalaceLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge, MSGBOX_DEFAULT
	closemessage
	palace_set PALACE_DATA_WIN_STREAK, 0
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven
	msgbox BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded
	waitmessage
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	palace_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
	waitmessage
	palace_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_Attendant::
	palace_get PALACE_DATA_PRIZE
	goto_if_ne VAR_RESULT, ITEM_NONE, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_WhichChallenge
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	palace_init
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePalaceLobby_Text_FollowMe, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge::
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor
	waitdooranim
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_SINGLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_DOUBLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor::
	opendoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor::
	opendoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor::
	closedoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor::
	closedoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor:
	walk_up
	step_end

BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt::
	msgbox BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Man::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Maniac::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_RulesNature
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesNature::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle:
	.string "ENTRENATZAILEEN bihotzak jokoan\n"
	.string "jartzen diren tokira.\p"
	.string "Ongi etorri BORROKA JAUREGIRA.\p"
	.string "BANAKAKO ARETO BORROKEN erronkak\n"
	.string "egiten ditugu hemen.$"

BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge:
	.string "Nahi al diozu BANAKAKO ARETO\n"
	.string "BORROKAREN erronkari aurre egin?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge:
	.string "BORROKA JAUREGIAN, hainbat auditorio\n"
	.string "daude BANAKAKO BORROKAK EGITEKO,\l"
	.string "BANAKAKO BORROKA ARETO deritzenak.\p"
	.string "BANAKAKO BORROKAK betiko moduan egiten\n"
	.string "dira, nahiz eta derrigorrez bete"
	.string "beharreko arau berri bat dagoen.\p"
	.string "ENTRENATZAILEEK soilik beraien\n"
	.string "POKéMONAK sartu eta atera ditzakete.\p"
	.string "ENTRENATZAILEEK ezin diete bestelako\n"
	.string "agindurik eman POKéMONEI.\p"
	.string "POKéMONAK haien izaeraren arabera\n"
	.string "aritu beharko dira, bakarrik borrokatuz.\p"
	.string "Zure konfidantza haiengan jarri eta\n"
	.string "haiek ikusi besterik ezin duzu egin.\p"
	.string "Zazpi ENTRENATZAILE jarraian\n"
	.string "garaitzea lortzen baduzu,\l"
	.string "Borroka Puntuak emango dizkizugu.\p"
	.string "Erronka geratu nahi baduzu edozein\n"
	.string "unetan, partida gorde behar duzu.\p"
	.string "Ez baduzu gordetzen partida eten\n"
	.string "aurretik, deskalifikatu egingo zaitugu.$"

BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified:
	.string "Zure bihotza eta zure POKéMONAK\n"
	.string "indartzen dituzunean, itzuli.$"

BattleFrontier_BattlePalaceLobby_Text_WhichChallenge:
	.string "Bi BORROKA ARETO daude,\n"
	.string "50. Maila eta Maila Irekia.\l"
	.string "Zein da aukeratu nahi duzuna?$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50:
	.string "Ene…\p"
	.string "Ez dauzkazu erronkarako behar\n"
	.string "diren hiru POKéMONAK.\p"
	.string "Sartzeko, hiru POKéMON desberdin\n"
	.string "behar dituzu.\p"
	.string "POKéMON hauek 50. Maila edo\n"
	.string "gutxiagokoak izan behar dira.\p"
	.string "Gainera ezin dute item\n"
	.string "berdinik eduki.\p"
	.string "ARRAUTZAK ezin dira erabili.\p"
	.string "Itzuli prestakuntza guztiak\n"
	.string "egin ondoren, mesedez.$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Ene…\p"
	.string "Ez dauzkazu erronkarako behar\n"
	.string "diren hiru POKéMONAK.\p"
	.string "Sartzeko, hiru POKéMON desberdin\n"
	.string "behar dituzu.\p"
	.string "Gainera ezin dute item\n"
	.string "berdinik eduki.\p"
	.string "ARRAUTZAK ezin dira erabili.\p"
	.string "Itzuli prestakuntza guztiak\n"
	.string "egin ondoren, mesedez.$"

BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons:
	.string "Ongi. Orain, zure hiru POKéMONAK\n"
	.string "aukeratu behar dituzu.$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2:
	.string "Partida gorde behar dut BORROKA\n"
	.string "ARETOA erakutsi aurretik, ados?$"

BattleFrontier_BattlePalaceLobby_Text_FollowMe:
	.string "Ongi.\n"
	.string "Jarraitu niri, mesedez.$"

BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded:
	.string "Oso pozik nago zure POKéMONEN\n"
	.string "lorpenak ikusita.\p"
	.string "Emaitzak grabatuko ditugu.\n"
	.string "Itxaron pixka bat, mesedez.$"

BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak:
	.string "7 garaipen jarraian lortzea ere…\p"
	.string "Zure bihotza eta zure POKéMONENA\n"
	.string "lotura irmoek lotzen dute, bai.$"

BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded:
	.string "Zure lorpena grabatuko dugu.\n"
	.string "Itxaron pixka bat, mesedez.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak:
	.string "For the feat of your 7-win streak,\n"
	.string "we present you with Battle Point(s).$"

BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize:
	.string "Badirudi ez daukazula lekurik\n"
	.string "gure saria gordetzeko.\p"
	.string "Zure POLTSA antolatu eta\n"
	.string "itzuli berriro, mesedez.$"

BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting:
	.string "Zure zain egon gara…$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge:
	.string "Partida gorde behar dut BORROKA\n"
	.string "ARETOA erakutsi aurretik, ados?$"

BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge:
	.string "Ene…\p"
	.string "Aurrekoan ez zenuen partida\n"
	.string "gorde erronka eten aurretik.\p"
	.string "Ondorioz, deskalifikatua izan zara.\n"
	.string "Asko sentitzen dut.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize:
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink:
	.string "Ni bezalako tipo gogorrak,\n"
	.string "POKéMON gogorrak behar ditu.\p"
	.string "Erasoa da defentsarik onena!\n"
	.string "Eraso gupidabeari ezin zaio erantzun!\p"
	.string "Baina ez nuen horren inguruan\n"
	.string "hitz egin nahi.\p"
	.string "Batzuetan andere oso eder bat\n"
	.string "etorri ohi da hona.\p"
	.string "Dioenez, POKéMONAK zer pentsatzen\n"
	.string "ari diren irakur dezake.\p"
	.string "Ez nago oso ziur horren gainean,\n"
	.string "baina oso ederra da.\p"
	.string "Zer?\n"
	.string "Zergatik begiratzen didazu horrela?$"

BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere:
	.string "Hmm…\p"
	.string "Dirudienez POKéMONEN izaerak eta\n"
	.string "erakutsi zaizkien erasoek berebiziko\l"
	.string "garrantzi dute hemen borrokatzeko.\p"
	.string "Hobe esanda, erasoak POKéMONAREN\n"
	.string "izaerari ondo egokitzea da benetan\l"
	.string "garrantzitsua dena.\p"
	.string "Zure POKéMONAK arazoak baditu eta ezin\n"
	.string "badu bere potentzial gorena lortu,\l"
	.string "ondo aztertu behar zenuke ea erasoak\l"
	.string "egokiak diren bere izaerarentzat.$"

BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms:
	.string "Nire POKéMONA oso lasaia da berez.\p"
	.string "Baina BORROKA ARETO batean dagoenean,\n"
	.string "batzuetan eraldatu egiten dela\l"
	.string "dirudi, izugarria bilakatzen da!\p"
	.string "Benetan beldurgarria bihurtzen da.\n"
	.string "Ezin dut sinetsi.$"

BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway:
	.string "Jakin nahi nuke zein izaera den egokia\n"
	.string "POKéMON batek bere etsaia pixkanaka\l"
	.string "ahultzeko joera izan dezan. Harrituko\p"
	.string "nintzateke izaera AHULA balitz.\p"
	.string "Baina, ez, ezin da hala izan.$"

BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle:
	.string "ENTRENATZAILEEN bihotzak jokoan\n"
	.string "jartzen diren tokira.\p"
	.string "Ongi etorri BORROKA JAUREGIRA.\p"
	.string "BINAKAKO ARETO BORROKEN erronkak\n"
	.string "egiten ditugu hemen.$"

BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge:
	.string "Nahi al diozu BINAKAKO ARETO\n"
	.string "BORROKAREN erronkari aurre egin?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge:
	.string "BORROKA JAUREGIAN, hainbat auditorio\n"
	.string "daude BINAKAKO BORROKAK EGITEKO,\l"
	.string "BINAKAKO BORROKA ARETO deritzenak.\p"
	.string "BINAKAKO BORROKAK betiko moduan egiten\n"
	.string "dira, nahiz eta derrigorrez bete"
	.string "beharreko arau berri bat dagoen.\p"
	.string "ENTRENATZAILEEK soilik beraien\n"
	.string "POKéMONAK sartu eta atera ditzakete.\p"
	.string "ENTRENATZAILEEK ezin diete bestelako\n"
	.string "agindurik eman POKéMONEI.\p"
	.string "POKéMONAK haien izaeraren arabera\n"
	.string "aritu beharko dira, bakarrik borrokatuz.\p"
	.string "Zure konfidantza haiengan jarri eta\n"
	.string "haiek ikusi besterik ezin duzu egin.\p"
	.string "Zazpi ENTRENATZAILE jarraian\n"
	.string "garaitzea lortzen baduzu,\l"
	.string "Borroka Puntuak emango dizkizugu.\p"
	.string "Erronka geratu nahi baduzu edozein\n"
	.string "unetan, partida gorde behar duzu.\p"
	.string "Ez baduzu gordetzen partida eten\n"
	.string "aurretik, deskalifikatu egingo zaitugu.$"

BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers:
	.string "PALAZIOKO ADITUA eta zazpi\n"
	.string "ENTRENATZAILE jarraian garaitzea…$"

BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints:
	.string "Zu eta zure POKéMONEN arteko lotura\n"
	.string "omentzeko, Borroka Puntu hauek\l"
	.string "emango dizkizugu.$"

BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch:
	.string "Nahi al duzu zure BORROKA JAUREGIKO\n"
	.string "azken borroka zure FRONTE PASEAN\l"
	.string "grabatu?$"

BattleFrontier_BattlePalaceLobby_Text_RulesAreListed:
	.string "BORROKA ARETOKO arauak dira.$"

BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading:
	.string "Zein atal irakurri nahi duzu?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics:
	.string "Hemen, POKéMONEK bakarrik pentsatu\n"
	.string "eta borrokatu behar dute.\p"
	.string "Basatiak direnean ez bezala, pertsonekin\n"
	.string "bizi diren POKéMONEK desberdin jokatzen\l"
	.string "dute beren izaeraren arabera.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature:
	.string "Izaeraren arabera, POKéMON batek\n"
	.string "beti erasotzea nahiago izan dezake.\p"
	.string "Beste POKéMON batek nahiago izan\n"
	.string "dezake edozein minetatik babestu.\p"
	.string "Beste batek nahiago izan dezake\n"
	.string "etsaia nahastu edo gogaitu.\p"
	.string "Izaeraren arabera, POKéMON batek\n"
	.string "gehiago gustatzen zaion eraso bat\l"
	.string "edukitzea ere posible da.\p"
	.string "Eta atsegin ez dituen erasoak ere\n"
	.string "izan ditzake.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves:
	.string "Etsaiak zuzenean mintzen dituzten\n"
	.string "eraso ofentsiboak existitzen dira.\p"
	.string "Eraso defentsiboak ere bai, etsaien\n"
	.string "erasoetatik babestu edo BPak\l"
	.string "sendatzeko erabili daitezkeenak.\p"
	.string "Eraso arraroagoak ere badaude,\n"
	.string "etsaiak egoera arazoekin ahuldu\l"
	.string "ditzaketenak, pozoinarekin edo\l"
	.string "paralisiarekin, esaterako.\p"
	.string "POKéMONEK hiru mota hauetako erasoak\n"
	.string "erabiliko dituzte beti.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered:
	.string "ENTRENATZAILEAREN agindurik gabe,\n"
	.string "POKéMON batek agian ez ditu eraso\l"
	.string "batzuk era egokian erabiliko.\p"
	.string "POKéMON bat ez da ona izango atsegin\n"
	.string "ez dituen erasoak erabiltzen.\p"
	.string "POKéMON batek bere izaerari egokitzen\n"
	.string "ez zaizkion erasoak soilik badakizki,\l"
	.string "ez du bere ahalmen gorena lortuko.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger:
	.string "Izaeraren arabera, POKéMON batek bere\n"
	.string "izaerarekin bat ez datozen erasoak\l"
	.string "erabili ditzake, arriskuan badago.\p"
	.string "POKéMON bat arraro jokatzen hasten\n"
	.string "bada, arreta handiz behatu.$"

