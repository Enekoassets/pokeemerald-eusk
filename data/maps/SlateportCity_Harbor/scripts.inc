.set LOCALID_CAPT_STERN, 4
.set LOCALID_SS_TIDAL, 5
.set LOCALID_GRUNT, 6
.set LOCALID_ARCHIE, 7
.set LOCALID_SUBMARINE, 8

SlateportCity_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
	.byte 0

SlateportCity_Harbor_OnTransition:
	setescapewarp MAP_SLATEPORT_CITY, 28, 13
	setvar VAR_TEMP_1, 0
	call_if_eq VAR_SLATEPORT_HARBOR_STATE, 1, SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_ShowSSTidal
	end

SlateportCity_Harbor_EventScript_ShowSSTidal::
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	return

SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene::
	savebgm MUS_ENCOUNTER_AQUA
	setobjectxyperm LOCALID_CAPT_STERN, 12, 13
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_LEFT
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	return

SlateportCity_Harbor_EventScript_AquaEscapeTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger3::
	lockall
	setvar VAR_0x8008, 3
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_PlayerWalkUp
	waitmovement 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeScene::
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_ARCHIE, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SUBMARINE, SlateportCity_Harbor_Movement_SubmarineExit
	waitmovement 0
	removeobject LOCALID_GRUNT
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_SUBMARINE
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
	setflag FLAG_MET_TEAM_AQUA_HARBOR
	setflag FLAG_HIDE_LILYCOVE_MOTEL_SCOTT
	call_if_eq VAR_0x8008, 0, SlateportCity_Harbor_EventScript_SternApproachPlayer0
	call_if_eq VAR_0x8008, 1, SlateportCity_Harbor_EventScript_SternApproachPlayer1
	call_if_eq VAR_0x8008, 2, SlateportCity_Harbor_EventScript_SternApproachPlayer
	call_if_eq VAR_0x8008, 3, SlateportCity_Harbor_EventScript_SternApproachPlayer
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
	copyobjectxytoperm LOCALID_CAPT_STERN
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_RIGHT
	releaseall
	end

SlateportCity_Harbor_EventScript_SternApproachPlayer0::
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer1::
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer::
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_Movement_AquaBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

@ Unused, Archie instead shares above identical movement script with Grunt
SlateportCity_Harbor_Movement_ArchieBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

SlateportCity_Harbor_Movement_SubmarineExit:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer0:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer1:
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer:
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Harbor_Movement_PlayerWalkUp:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_FerryAttendant::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_AskForTicket
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskForTicket::
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_ChooseDestination::
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier::
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_BattleFrontier
	case 2, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

@ Unused. Should be impossible for player to reach Ferry without having received SS Tidal ticket
SlateportCity_Harbor_EventScript_NoTicket::
	msgbox SlateportCity_Harbor_Text_YouMustHaveTicket, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_Lilycove::
	msgbox SlateportCity_Harbor_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_BattleFrontier::
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_ChooseNewDestination::
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_BoardFerry::
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
	call_if_eq VAR_FACING, DIR_NORTH, SlateportCity_Harbor_EventScript_BoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_Harbor_EventScript_BoardFerryEast
	delay 30
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

SlateportCity_Harbor_EventScript_CancelDestinationSelect::
	msgbox SlateportCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_BoardFerryEast::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_BoardFerryNorth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
	waitmovement 0
	return

SlateportCity_Harbor_Movement_BoardFerryEast:
	walk_right
	walk_in_place_faster_up
	step_end

SlateportCity_Harbor_Movement_BoardFerryNorth:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_Sailor::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	goto_if_eq VAR_0x8004, 2, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather  @ Defeated both
	msgbox SlateportCity_Harbor_Text_AbnormalWeather, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather::
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CountDefeatedLegendary::
	addvar VAR_0x8004, 1
	return

SlateportCity_Harbor_EventScript_FatMan::
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
	end

SlateportCity_Harbor_EventScript_CaptStern::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_NeedDive
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive
	goto_if_eq VAR_SLATEPORT_HARBOR_STATE, 2, SlateportCity_Harbor_EventScript_WhyStealSubmarine
	msgbox SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Harbor_EventScript_WhyStealSubmarine::
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive::
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
	msgbox SlateportCity_Harbor_Text_TeamAquaLeftNeedDive, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_NeedDive::
	msgbox SlateportCity_Harbor_Text_NeedDiveToCatchSub, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment::
	goto_if_eq VAR_TEMP_1, 1, SlateportCity_Harbor_EventScript_TradedScanner
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Harbor_EventScript_AskToTradeScanner
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_FerryFinished
	msgbox SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_FerryFinished::
	msgbox SlateportCity_Harbor_Text_FinishedMakingFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskToTradeScanner::
	message SlateportCity_Harbor_Text_WouldYouTradeScanner
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_ChooseScannerTrade::
	multichoice 0, 0, MULTI_STERN_DEEPSEA, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_DeepSeaTooth
	case 1, SlateportCity_Harbor_EventScript_DeepSeaScale
	case 2, SlateportCity_Harbor_EventScript_DeclineTrade
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_DeclineTrade
	end

SlateportCity_Harbor_EventScript_DeepSeaTooth::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaTooth, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_TOOTH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeepSeaScale::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_SCALE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeclineTrade::
	msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_ChooseDifferentTrade::
	message SlateportCity_Harbor_Text_WhichOneDoYouWant
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_TradedScanner::
	setvar VAR_TEMP_1, 1
	msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_Text_FerryServiceUnavailable:
	.string "Barkatu?\n"
	.string "Itsasontzi baten bila al zabiltza?\p"
	.string "Sentitzen dut, baina ferry\n"
	.string "zerbitzua ezin da orain erabili…$"

SlateportCity_Harbor_Text_MayISeeYourTicket:
	.string "Kaixo, ferryarengatik al zaude hemen?\n"
	.string "Ikusi dezaket zure TICKETA?$"

SlateportCity_Harbor_Text_YouMustHaveTicket:
	.string "{PLAYER}(e)k ez dauka TIKETIK…\p"
	.string "Benetan sentitzen dut.\p"
	.string "Ferryra igotzeko TIKETA behar\n"
	.string "duzu derrigor.$"

SlateportCity_Harbor_Text_FlashedTicketWhereTo:
	.string "{PLAYER}(e)k TIKETA erakutsi du.\p"
	.string "Bikain! Erabili dezakezu ferrya!\p"
	.string "Eta nora joan nahi zenuke?$"

SlateportCity_Harbor_Text_SailAnotherTime:
	.string "Nabigatu gurekin nahi duzunean!$"

SlateportCity_Harbor_Text_LilycoveItIs:
	.string "UR-LILI HIRIRA, beraz!$"

SlateportCity_Harbor_Text_BattleFrontierItIs:
	.string "BORROKA FRONTERA, beraz!$"

SlateportCity_Harbor_Text_PleaseBoardFerry:
	.string "Mesedez, igo ferryra eta itxaron\n"
	.string "abiatu arte.$"

SlateportCity_Harbor_Text_WhereWouldYouLikeToGo:
	.string "Orduan, nora joan nahi zenuke?$"

SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday:
	.string "Bidaia bat itsas hondora…\n"
	.string "Nolakoa izango ote litzateke?\p"
	.string "Gustatuko litzaidake noizbait\n"
	.string "halako bidaia bat egitea.$"

SlateportCity_Harbor_Text_AbnormalWeather:
	.string "Ontzia era seguruan ibili dadin,\n"
	.string "ondo ezagutu behar dugu eguraldia!\p"
	.string "Eguraldiaz ari garela, entzun EGURALDI\n"
	.string "INSTITUTUKO tipo batek esan zidana.\p"
	.string "Leku askotan eguraldi arraroak\n"
	.string "izaten ari direla esan zuen!\p"
	.string "EGURALDI INSTITUTURA joan behar zenuke,\n"
	.string "zer gertatzen ari den galdetzeko!$"

SlateportCity_Harbor_Text_SubTooSmallForMe:
	.string "Ozeanoaren hondora joan nahi\n"
	.string "dut ABABOR KAPITAINAREKIN.\p"
	.string "Baina ontzia txikiegia da niretzat.\p"
	.string "Bultzaka sartuko banintz, ez litzateke\n"
	.string "lekurik egongo KAPITAINARENTZAT…$"

SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum:
	.string "ABABOR KAPT.: Jendaila hori…\p"
	.string "MUSEOAN DEVON PIEZAK lapurtzen\n"
	.string "saiatu ziren horiek dira.$"

SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove:
	.string "AKILES: Zer?\n"
	.string "Zu berriro…\p"
	.string "Adorea izan duzu guri honaino\n"
	.string "jarraitzeko, esan beharra dut.\p"
	.string "Baina orain…\n"
	.string "Inork ez gaitu geldituko! Inork ez!\p"
	.string "Edo, UR-LILIN daukagun EZKUTALEKURAINO\n"
	.string "jarraituko al diguzu?\p"
	.string "Kar-kar-kar…$"

SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine:
	.string "ABABOR KAPT.: Zergatik…\p"
	.string "Zergatik lapurtu du AQUA TALDEAK\n"
	.string "nire 1. URPEKO ESPLORATZAILEA?\p"
	.string "Ez al dira itsas hondoan lo dauden\n"
	.string "POKéMONEN bila arituko…\p"
	.string "Baina beraien atzetik joango banintz\n"
	.string "ere, ez nuke ezer egiteko aukerarik…$"

SlateportCity_Harbor_Text_TeamAquaLeftNeedDive:
	.string "ABABOR KAPT.: Aizu, {PLAYER}{KUN}…\p"
	.string "Ea… AQUA TALDEAK ihes egin du zuk\n"
	.string "gelditzeko aukera izan aurretik…\p"
	.string "Ene, ez, ez da zure errua.\n"
	.string "Ez duzu honen erantzunkizunik.\p"
	.string "Urpeko bat harrapatzea…\n"
	.string "Ezinezkoa da jende gehienarentzat.\p"
	.string "URPERATZEN dakien POKéMON\n"
	.string "bat beharko zenuke…\p"
	.string "Agian GOROLDI HIRIRA joango\n"
	.string "bazina…\p"
	.string "Urpekari asko bizi dira bertan,\n"
	.string "agian erakutsiko dizute…$"

SlateportCity_Harbor_Text_NeedDiveToCatchSub:
	.string "ABABOR KAPT.: Urpeko bat harrapatzen\n"
	.string "saiatzea… Ezinezkoa da.\p"
	.string "URPERATZEN dakien POKéMON\n"
	.string "bat beharko zenuke…\p"
	.string "Agian GOROLDI HIRIRA joango\n"
	.string "bazina…\p"
	.string "Urpekari asko bizi dira bertan,\n"
	.string "agian erakutsiko dizute…$"

SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry:
	.string "ABABOR KAPT.: Ah, bai.\n"
	.string "SARDINZAR JN. etorri zen ONTZIDIRA.\p"
	.string "Laister lortuko dugu ferrya\n"
	.string "amaitzea!$"

SlateportCity_Harbor_Text_FinishedMakingFerry:
	.string "ABABOR KAPT.: {PLAYER}{KUN}!\p"
	.string "Azkenean lortu dugu MAREA\n"
	.string "ITSASONTZIA amaitzea!\p"
	.string "Ez genuen lortuko zure lagun\n"
	.string "SARDINZAR JAUNAREN laguntzarik gabe.\p"
	.string "Egin bidaia labur bat bertan, mesedez!$"

SlateportCity_Harbor_Text_WouldYouTradeScanner:
	.string "ABABOR KAPT.: Nola?\n"
	.string "{PLAYER}{KUN}, item hori…\p"
	.string "ESKANER bat da! Asko lagunduko\n"
	.string "liguke gure esplorazioetan.\p"
	.string "{PLAYER}{KUN}, aldatuko zenidake\n"
	.string "zure ESKANERRA zerbaiten truke?\p"
	.string "Adibidez, ITSASLETAGIN edo\n"
	.string "ITSASEZKATA baten truke?$"

SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow:
	.string "ABABOR KAPT.: Ziur al zaude?\n"
	.string "Zuk ez duzu behar, {PLAYER}{KUN}…\p"
	.string "Beno, ongi, orduan. Inoiz zure ESKANERRA\n"
	.string "trukatu nahi baduzu, abisatu.$"

SlateportCity_Harbor_Text_TradeForDeepSeaTooth:
	.string "ABABOR KAPT.: Orduan nire\n"
	.string "ITSASLETAGINAREN truke nahi duzu?$"

SlateportCity_Harbor_Text_TradeForDeepSeaScale:
	.string "ABABOR KAPT.: Orduan nire\n"
	.string "ITSASEZKATAREN truke nahi duzu?$"

SlateportCity_Harbor_Text_WhichOneDoYouWant:
	.string "ABABOR KAPT.: Zein nahi duzu?$"

SlateportCity_Harbor_Text_HandedScannerToStern:
	.string "{PLAYER}(e)k ESKANERRA eman dio\n"
	.string "ABABOR KAPITAINARI.$"

SlateportCity_Harbor_Text_ThisWillHelpResearch:
	.string "ABABOR KAPT.: Eskerrik asko, {PLAYER}{KUN}!\n"
	.string "Asko lagunduko digu gure ikerketetan!$"
