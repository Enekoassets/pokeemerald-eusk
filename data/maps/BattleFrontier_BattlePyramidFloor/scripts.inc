BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle::
	trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_PHILLIP, 0, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "Hau probako mezua da.$"

gText_BattlePyramidConfirmRest::
	.string "Zure BORROKA PIRAMIDEKO aurrerapenak\n"
	.string "gordeko dira, partida itxi dezazun.\l"
	.string "Ados al zaude?$"

gText_BattlePyramidConfirmRetire::
	.string "Ziur zaude BORROKA PIRAMIDEKO\n"
	.string "erronka utzi nahi duzula?$"

BattlePyramid_Text_ExitHintUp1::
	.string "Solairu honetako irteera norabide\n"
	.string "honetan dago: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1::
	.string "Solairu honetako irteera norabide\n"
	.string "honetan dago: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1::
	.string "Solairu honetako irteera norabide\n"
	.string "honetan dago: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1::
	.string "Solairu honetako irteera norabide\n"
	.string "honetan dago: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2::
	.string "Solairu honetako irteera {UP_ARROW}\n"
	.string "norabidean dago.$"

BattlePyramid_Text_ExitHintLeft2::
	.string "Solairu honetako irteera {LEFT_ARROW}\n"
	.string "norabidean dago.$"

BattlePyramid_Text_ExitHintRight2::
	.string "Solairu honetako irteera {RIGHT_ARROW}\n"
	.string "norabidean dago.$"

BattlePyramid_Text_ExitHintDown2::
	.string "Solairu honetako irteera {DOWN_ARROW}\n"
	.string "norabidean dago.$"

BattlePyramid_Text_ExitHintUp3::
	.string "Irteera {UP_ARROW}\n"
	.string "norabidean dago.$"

BattlePyramid_Text_ExitHintLeft3::
	.string "Irteera {LEFT_ARROW}\n"
	.string "norabidean dago.$"

BattlePyramid_Text_ExitHintRight3::
	.string "Irteera {RIGHT_ARROW}\n"
	.string "norabidean dago.$"

BattlePyramid_Text_ExitHintDown3::
	.string "Irteera {DOWN_ARROW}\n"
	.string "norabidean dago.$"

BattlePyramid_Text_ExitHintUp4::
	.string "Solairu honetan, irteera {UP_ARROW}\n"
	.string "norabide inguruan dago.$"

BattlePyramid_Text_ExitHintLeft4::
	.string "Solairu honetan, irteera {LEFT_ARROW}\n"
	.string "norabide inguruan dago.$"

BattlePyramid_Text_ExitHintRight4::
	.string "Solairu honetan, irteera {RIGHT_ARROW}\n"
	.string "norabide inguruan dago.$"

BattlePyramid_Text_ExitHintDown4::
	.string "Solairu honetan, irteera {DOWN_ARROW}\n"
	.string "norabide inguruan dago.$"

BattlePyramid_Text_ExitHintUp5::
	.string "Irteera?\n"
	.string "{UP_ARROW} norabidean dago.$"

BattlePyramid_Text_ExitHintLeft5::
	.string "Irteera?\n"
	.string "{LEFT_ARROW} norabidean dago.$"

BattlePyramid_Text_ExitHintRight5::
	.string "Irteera?\n"
	.string "{RIGHT_ARROW} norabidean dago.$"

BattlePyramid_Text_ExitHintDown5::
	.string "Irteera?\n"
	.string "{DOWN_ARROW} norabidean dago.$"

BattlePyramid_Text_ExitHintUp6::
	.string "Irteera {UP_ARROW} norabidean\n"
	.string "dagoela dirudi.$"

BattlePyramid_Text_ExitHintLeft6::
	.string "Irteera {LEFT_ARROW} norabidean\n"
	.string "dagoela dirudi.$"

BattlePyramid_Text_ExitHintRight6::
	.string "Irteera {RIGHT_ARROW} norabidean\n"
	.string "dagoela dirudi.$"

BattlePyramid_Text_ExitHintDown6::
	.string "Irteera {DOWN_ARROW} norabidean\n"
	.string "dagoela dirudi.$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "Item bila al zabiltza?\p"
	.string "Zortzi item falta dira\n"
	.string "oraindik aurkitzeko.$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "Item bila al zabiltza?\p"
	.string "Zazpi item falta dira\n"
	.string "oraindik aurkitzeko.$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "Item bila al zabiltza?\p"
	.string "Sei item falta dira\n"
	.string "oraindik aurkitzeko.$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "Item bila al zabiltza?\p"
	.string "Bost item falta dira\n"
	.string "oraindik aurkitzeko.$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "Item bila al zabiltza?\p"
	.string "Lau item falta dira\n"
	.string "oraindik aurkitzeko.$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "Item bila al zabiltza?\p"
	.string "Hiru item falta dira\n"
	.string "oraindik aurkitzeko.$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "Item bila al zabiltza?\p"
	.string "Bi item falta dira\n"
	.string "oraindik aurkitzeko.$"

BattlePyramid_Text_OneItemRemaining1::
	.string "Item bila al zabiltza?\p"
	.string "Item bat falta da\n"
	.string "oraindik aurkitzeko.$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "Item bila al zabiltza?\p"
	.string "Ez da itemik geratzen\n"
	.string "aurkitzeko!$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "Irabazi duzunez, sekretu\n"
	.string "txiki bat kontatuko dizut!\p"
	.string "Zortzi item geratzen\n"
	.string "dira hemen inguruan.$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "Irabazi duzunez, sekretu\n"
	.string "txiki bat kontatuko dizut!\p"
	.string "Zortzi item geratzen\n"
	.string "dira hemen inguruan.$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "Irabazi duzunez, sekretu\n"
	.string "txiki bat kontatuko dizut!\p"
	.string "Zazpi item geratzen\n"
	.string "dira hemen inguruan.$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "Irabazi duzunez, sekretu\n"
	.string "txiki bat kontatuko dizut!\p"
	.string "Bost item geratzen\n"
	.string "dira hemen inguruan.$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "Irabazi duzunez, sekretu\n"
	.string "txiki bat kontatuko dizut!\p"
	.string "Lau item geratzen\n"
	.string "dira hemen inguruan.$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "Irabazi duzunez, sekretu\n"
	.string "txiki bat kontatuko dizut!\p"
	.string "Hiru item geratzen\n"
	.string "dira hemen inguruan.$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "Irabazi duzunez, sekretu\n"
	.string "txiki bat kontatuko dizut!\p"
	.string "Bi item geratzen\n"
	.string "dira hemen inguruan.$"

BattlePyramid_Text_OneItemRemaining2::
	.string "Irabazi duzunez, sekretu\n"
	.string "txiki bat kontatuko dizut!\p"
	.string "Item bat geratzen\n"
	.string "da hemen inguruan.$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "Irabazi duzunez, sekretu\n"
	.string "txiki bat kontatuko dizut!\p"
	.string "There isn't anything left\n"
	.string "lying around here.$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "Zer moduz dago zure item bilduma?\p"
	.string "Uste dut zortzi item falta direla\n"
	.string "solairu honetan aurkitzeko.$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "Zer moduz dago zure item bilduma?\p"
	.string "Uste dut zazpi item falta direla\n"
	.string "solairu honetan aurkitzeko.$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "Zer moduz dago zure item bilduma?\p"
	.string "Uste dut sei item falta direla\n"
	.string "solairu honetan aurkitzeko.$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "Zer moduz dago zure item bilduma?\p"
	.string "Uste dut bost item falta direla\n"
	.string "solairu honetan aurkitzeko.$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "Zer moduz dago zure item bilduma?\p"
	.string "Uste dut lau item falta direla\n"
	.string "solairu honetan aurkitzeko.$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "Zer moduz dago zure item bilduma?\p"
	.string "Uste dut hiru item falta direla\n"
	.string "solairu honetan aurkitzeko.$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "Zer moduz dago zure item bilduma?\p"
	.string "Uste dut bi item falta direla\n"
	.string "solairu honetan aurkitzeko.$"

BattlePyramid_Text_OneItemRemaining3::
	.string "Zer moduz dago zure item bilduma?\p"
	.string "Uste dut item bat falta dela\n"
	.string "solairu honetan aurkitzeko.$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "Zer moduz dago zure item bilduma?\p"
	.string "Uste dut ez dela itemik geratzen\n"
	.string "solairu honetan aurkitzeko.\l"
	.string "Zaindu zaitez!$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "Indartsua zara, pista bat\n"
	.string "merezi duzu!\p"
	.string "Lurrean zortzi item\n"
	.string "geratzen direla dirudi.$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "Indartsua zara, pista bat\n"
	.string "merezi duzu!\p"
	.string "Lurrean zazpi item\n"
	.string "geratzen direla dirudi.$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "Indartsua zara, pista bat\n"
	.string "merezi duzu!\p"
	.string "Lurrean sei item\n"
	.string "geratzen direla dirudi.$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "Indartsua zara, pista bat\n"
	.string "merezi duzu!\p"
	.string "Lurrean bost item\n"
	.string "geratzen direla dirudi.$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "Indartsua zara, pista bat\n"
	.string "merezi duzu!\p"
	.string "Lurrean lau item\n"
	.string "geratzen direla dirudi.$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "Indartsua zara, pista bat\n"
	.string "merezi duzu!\p"
	.string "Lurrean hiru item\n"
	.string "geratzen direla dirudi.$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "Indartsua zara, pista bat\n"
	.string "merezi duzu!\p"
	.string "Lurrean bi item\n"
	.string "geratzen direla dirudi.$"

BattlePyramid_Text_OneItemRemaining4::
	.string "Indartsua zara, pista bat\n"
	.string "merezi duzu!\p"
	.string "Lurrean item bat\n"
	.string "geratzen dela dirudi.$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "Indartsua zara, pista bat\n"
	.string "merezi duzu!\p"
	.string "Lurrean itemik ez dela\n"
	.string "geratzen dirudi.$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "PIRAMIDEAREN solairu honetan,\n"
	.string "Zortzi item omen daude oraindik…$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "PIRAMIDEAREN solairu honetan,\n"
	.string "Zazpi item omen daude oraindik…$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "PIRAMIDEAREN solairu honetan,\n"
	.string "Sei item omen daude oraindik…$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "PIRAMIDEAREN solairu honetan,\n"
	.string "Bost item omen daude oraindik…$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "PIRAMIDEAREN solairu honetan,\n"
	.string "Lau item omen daude oraindik…$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "PIRAMIDEAREN solairu honetan,\n"
	.string "Hiru item omen daude oraindik…$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "PIRAMIDEAREN solairu honetan,\n"
	.string "Bi item omen daude oraindik…$"

BattlePyramid_Text_OneItemRemaining5::
	.string "PIRAMIDEAREN solairu honetan,\n"
	.string "Item bat omen dago oraindik…$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "PIRAMIDEAREN solairu honetan,\n"
	.string "Ez omen dago itemik…$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "Aurkitu al duzu itemik?\p"
	.string "Uste dut zortzi item geratzen\n"
	.string "direla solairu honetan.$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "Aurkitu al duzu itemik?\p"
	.string "Uste dut zazpi item geratzen\n"
	.string "direla solairu honetan.$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "Aurkitu al duzu itemik?\p"
	.string "Uste dut sei item geratzen\n"
	.string "direla solairu honetan.$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "Aurkitu al duzu itemik?\p"
	.string "Uste dut bost item geratzen\n"
	.string "direla solairu honetan.$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "Aurkitu al duzu itemik?\p"
	.string "Uste dut lau item geratzen\n"
	.string "direla solairu honetan.$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "Aurkitu al duzu itemik?\p"
	.string "Uste dut hiru item geratzen\n"
	.string "direla solairu honetan.$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "Aurkitu al duzu itemik?\p"
	.string "Uste dut bi item geratzen\n"
	.string "direla solairu honetan.$"

BattlePyramid_Text_OneItemRemaining6::
	.string "Aurkitu al duzu itemik?\p"
	.string "Uste dut item bat geratzen\n"
	.string "dela solairu honetan.$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "Aurkitu al duzu itemik?\p"
	.string "Uste dut ez dela geratzen\n"
	.string "itemik solairu honetan.$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "Itzel aritu zara!\p"
	.string "Baina beste zazpi ENTRENATZAILE\n"
	.string "indartsu daude oraingik!$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "Itzel aritu zara!\p"
	.string "Baina beste sei ENTRENATZAILE\n"
	.string "indartsu daude oraingik!$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "Itzel aritu zara!\p"
	.string "Baina beste bost ENTRENATZAILE\n"
	.string "indartsu daude oraingik!$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "Itzel aritu zara!\p"
	.string "Baina beste lau ENTRENATZAILE\n"
	.string "indartsu daude oraingik!$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "Itzel aritu zara!\p"
	.string "Baina beste hiru ENTRENATZAILE\n"
	.string "indartsu daude oraingik!$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "Itzel aritu zara!\p"
	.string "Baina beste bi ENTRENATZAILE\n"
	.string "indartsu daude oraingik!$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "Itzel aritu zara!\p"
	.string "Baina beste ENTRENATZAILE\n"
	.string "indartsu bat dago oraingik!$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "Itzel aritu zara!\p"
	.string "Ez da garaitu zaitzakeen\n"
	.string "inor geratzen!$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "A zer amorrua!\p"
	.string "Baina zazpi ENTRENATZAILE daude oraindik!\n"
	.string "Norbaitek apalduko zaitu!$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "A zer amorrua!\p"
	.string "Baina sei ENTRENATZAILE daude oraindik!\n"
	.string "Norbaitek apalduko zaitu!$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "A zer amorrua!\p"
	.string "Baina bost ENTRENATZAILE daude oraindik!\n"
	.string "Norbaitek apalduko zaitu!$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "A zer amorrua!\p"
	.string "Baina lau ENTRENATZAILE daude oraindik!\n"
	.string "Norbaitek apalduko zaitu!$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "A zer amorrua!\p"
	.string "Baina hiru ENTRENATZAILE daude oraindik!\n"
	.string "Norbaitek apalduko zaitu!$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "A zer amorrua!\p"
	.string "Baina bi ENTRENATZAILE daude oraindik!\n"
	.string "Norbaitek apalduko zaitu!$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "A zer amorrua!\p"
	.string "Baina ENTRENATZAILE bat dago oraindik!\n"
	.string "Ziur apalduko zaituela!$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "A zer amorrua!\p"
	.string "Baina ez dago zure aurka\n"
	.string "egin dezakeen ENTRENATZAILERIK!$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "Hori izugarria izan da!\p"
	.string "Baina zazpi ENTRENATZAILE geratzen dira\n"
	.string "solairu honetan. Garaituko al dituzu?$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "Hori izugarria izan da!\p"
	.string "Baina sei ENTRENATZAILE geratzen dira\n"
	.string "solairu honetan. Garaituko al dituzu?$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "Hori izugarria izan da!\p"
	.string "Baina bost ENTRENATZAILE geratzen dira\n"
	.string "solairu honetan. Garaituko al dituzu?$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "Hori izugarria izan da!\p"
	.string "Baina lau ENTRENATZAILE geratzen dira\n"
	.string "solairu honetan. Garaituko al dituzu?$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "Hori izugarria izan da!\p"
	.string "Baina hiru ENTRENATZAILE geratzen dira\n"
	.string "solairu honetan. Garaituko al dituzu?$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "Hori izugarria izan da!\p"
	.string "Baina bi ENTRENATZAILE geratzen dira\n"
	.string "solairu honetan. Garaituko al dituzu?$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "Hori izugarria izan da!\p"
	.string "Baina ENTRENATZAILE bat geratzen da\n"
	.string "solairu honetan. Garaituko al duzu?$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "Hori izugarria izan da!\p"
	.string "Solairu honetako ENTRENATZAILE\n"
	.string "guztiak garaitu dituzu.$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "Agian garaituko dituzu solairu honetan\n"
	.string "geratzen diren zazpi ENTRENATZAILEAK.$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "Agian garaituko dituzu solairu honetan\n"
	.string "geratzen diren sei ENTRENATZAILEAK.$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "Agian garaituko dituzu solairu honetan\n"
	.string "geratzen diren bost ENTRENATZAILEAK.$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "Agian garaituko dituzu solairu honetan\n"
	.string "geratzen diren lau ENTRENATZAILEAK.$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "Agian garaituko dituzu solairu honetan\n"
	.string "geratzen diren hiru ENTRENATZAILEAK.$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "Agian garaituko dituzu solairu honetan\n"
	.string "geratzen diren bi ENTRENATZAILEAK.$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "Agian garaituko duzu solairu honetan\n"
	.string "geratzen den azken ENTRENATZAILEA.$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "Ez da geratzen garaitu zaitzakeen\n"
	.string "ENTRENATZAILERIK jada…$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "Geratzen diren zazpi ENTRENATZAILE\n"
	.string "adituak garaituko dituzu, agian.$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "Geratzen diren sei ENTRENATZAILE\n"
	.string "adituak garaituko dituzu, agian.$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "Geratzen diren bost ENTRENATZAILE\n"
	.string "adituak garaituko dituzu, agian.$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "Geratzen diren lau ENTRENATZAILE\n"
	.string "adituak garaituko dituzu, agian.$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "Geratzen diren hiru ENTRENATZAILE\n"
	.string "adituak garaituko dituzu, agian.$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "Geratzen diren bi ENTRENATZAILE\n"
	.string "adituak garaituko dituzu, agian.$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "Geratzen den azken ENTRENATZAILE\n"
	.string "aditua garaituko duzu, agian.$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "Zure trebezia izugarria da.\p"
	.string "Ez da geratzen gariatuko zaituen\n"
	.string "ENTRENATZAILERIK solairu honetan.$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "Garaituko al dituzu falta\n"
	.string "diren zazpi ENTRENATZAILEAK?$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "Garaituko al dituzu falta\n"
	.string "diren sei ENTRENATZAILEAK?$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "Garaituko al dituzu falta\n"
	.string "diren bost ENTRENATZAILEAK?$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "Garaituko al dituzu falta\n"
	.string "diren lau ENTRENATZAILEAK?$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "Garaituko al dituzu falta\n"
	.string "diren hiru ENTRENATZAILEAK?$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "Garaituko al dituzu falta\n"
	.string "diren bi ENTRENATZAILEAK?$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "Garaituko al duzu falta\n"
	.string "diren azke ENTRENATZAILEA?$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "Ez da geratzen zure aurka egingo\n"
	.string "duen ENTRENATZAILERIK jada…$"
