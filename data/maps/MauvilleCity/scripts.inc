.set LOCALID_WALLY, 6
.set LOCALID_WALLYS_UNCLE, 7
.set LOCALID_SCOTT, 11

MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_WALLY
	removeobject LOCALID_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_SCOTT, 12, 13
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
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

MauvilleCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
	.string "OSABA: POKéMONEI esker bihurtu da\n"
	.string "alaiagoa mutila, suposatzen dut…\l"
	.string "Baina agian alaiegia bihurtu da…$"

MauvilleCity_Text_WallyWantToChallengeGym:
	.string "EKAITZ: Joo, OSABA, meseee?\p"
	.string "GIMNASIOARI aurre egin nahi diot\n"
	.string "indartsuagoa naizela ikusteko.\p"
	.string "Mesedez? Utziko, mesedez?$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "OSABA: Itxaron, EKAITZ.\p"
	.string "POKéMONEKIN bizi zarenetik, egia da\n"
	.string "askoz indartsuagoa bihurtu zarela.\p"
	.string "Baina ez al da arriskutsua bat-batean\n"
	.string "GIMNASIO bateko erronkari aurre egitea?$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "EKAITZ: Ez naiz ari gehiegikeriatan.\p"
	.string "RALTSEKIN indarrak batzen baditut,\n"
	.string "edozein garaitu dezakegu!$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "EKAITZ: Ei! Kaixo, {PLAYER}!\p"
	.string "Azkenengotik askoz indartsuagoa\n"
	.string "bilakatu naiz.\p"
	.string "{PLAYER}, zuk eta OSABAK hori\n"
	.string "ulertzea nahi dut.\p"
	.string "{PLAYER}, mesedez, egingo duzu\n"
	.string "borroka nire aurka?$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "EKAITZ: beno… Ez baduzu borrokatu nahi,\n"
	.string "{PLAYER}, OSABAK oso indartsua\l"
	.string "bihurtu naizela jakingo du.$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "OSABA: {PLAYER}{KUN}, ezta?\n"
	.string "EKAITZEN izenean, eskatu diezazuket bere\l"
	.string "aurka borrokatzea, behin bada ere?\p"
	.string "Ez dut uste inolako arrazoirik\n"
	.string "entzuteko prest dagoenik orain.$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "EKAITZ: {PLAYER}, mesedez!\n"
	.string "Borrokatu nire aurka, mesedez.$"

MauvilleCity_Text_WallyHereICome:
	.string "EKAITZ: {PLAYER}, eskerrik asko.\p"
	.string "Ongi… Banator!$"

MauvilleCity_Text_WallyDefeat:
	.string "EKAITZ: … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "Galdu egin dut…$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "EKAITZ: OSABA\n"
	.string "BERDEZELAIRA itzuliko naiz…$"

MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "{PLAYER}, eskerrik asko.\n"
	.string "ENTRENATZAILEA izatea gogorra da, ezta?\p"
	.string "Ez da nahikoa POKéMONAK eduki eta\n"
	.string "haiekin borrokatzea. Hori ez da\l"
	.string "benetako ENTRENATZAILEA izatea.$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "OSABA: EKAITZ, ez izan horren\n"
	.string "gogorra zure buruarekin.\p"
	.string "Zerk geldituko zaitu gero eta\n"
	.string "indartsuagoa izatetik?\p"
	.string "Ea bada, goazen etxera.\n"
	.string "Denak zure zain daude.$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "OSABA: {PLAYER}{KUN}, oraintxe\n"
	.string "ohartu naiz zu zarela EKAITZI\l"
	.string "lagundu zion ENTRENATZAILEA bere\l"
	.string "POKéMONA harrapatu zuenean.\p"
	.string "Zergatik ez zara noizbait\n"
	.string "BERDEZELAIRA bisitan etortzen?\l"
	.string "Ziur nago EKAITZ pozik jarriko dela.$"


MauvilleCity_Text_WallyPokenavCall:
	.string "… … … … … …\n"
	.string "… … … … … Bip!\p"
	.string "EKAITZ: Aupa, kaixo, {PLAYER}!\p"
	.string "Osabak POKéNAV bat erosi\n"
	.string "didala esateko deitu dizut!\p"
	.string "Horrela edozein momentutan dei\n"
	.string "diezazuket, {PLAYER}!\p"
	.string "… … … … … …\n"
	.string "… … … … … Klik!$"

MauvilleCity_Text_RegisteredWally:
	.string "WALLY erregistratu\n"
	.string "da POKéNAVEAN.$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "TRIKI: Kar-kar…\n"
	.string "Borrokari begira nengoen!\p"
	.string "EKAITZ hori zure laguna da,\n"
	.string "ezta?\p"
	.string "Baina ez zara kikildu eta\n"
	.string "sekulako saraipena lortu duzu.\p"
	.string "Bai! Hori da benetako POKéMON\n"
	.string "borroka baten zentzua!\p"
	.string "Halako ENTRENATZAILEAK atsegin ditut!\p"
	.string "… … … … … …\n"
	.string "Zure alde arituko naiz hemendik aurrera!$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "ERIKO: Ei, {PLAYER}{KUN}!\n"
	.string "Ziztada ederrak ematen dituzula dirudi!\l"
	.string "Hori ona da, kar-kar-kar!\p"
	.string "Ongi! Erabaki dut!\n"
	.string "Mesede bat behar dut, {PLAYER}{KUN}!\p"
	.string "MALBADI HIRIAK azpian MALBADI\n"
	.string "BERRI izeneko sektore bat dauka.\p"
	.string "{PLAYER}{KUN}, hara joan eta\n"
	.string "SORGAILUA itzaltzea nahi nuke.\p"
	.string "SORGAILUA ez dabil oso ondo\n"
	.string "azkenaldian. Arriskutsua da.\p"
	.string "Tori, hau da MALBADI BERRIRA\n"
	.string "sartzeko GILTZA.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "ERIKO: Ez kezkatu. Zuretzat\n"
	.string "ez da arazoa izango.\p"
	.string "MALBADI BERRIRAKO sarrera 110. ERRUTAN\n"
	.string "SURF labur bat eginda dago.\p"
	.string "Hori da, bai! Nire konfidantza duzu!\n"
	.string "Kar-kar-kar!$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "ERIKO: Kar-kar-kar!\p"
	.string "Banekien, {PLAYER}{KUN}! Banekien ondo\n"
	.string "egin nuela zuri mesedea eskatuta!\p"
	.string "Hau nire esker ona adierazteko:\n"
	.string "TXIMISTA duen MTa!\p"
	.string "Hartu, merezi duzu eta!$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "ERIKO: Kar-kar-kar!\p"
	.string "Izugarri pozten nau belaunaldi\n"
	.string "berriak horren indartsu ikusteak!$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "Badakizu, POKéMON borrokak egitea\n"
	.string "oso ondo dago, bai…\p"
	.string "Baina zure POKéMONAK min hartzen\n"
	.string "badu, sendatu egin behar duzu.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "Herri honetatik iparraldera, hegoaldera,\n"
	.string "ekialdera eta mendebaldera daude bideak.\p"
	.string "Horren ondorioz, leku guztietako\n"
	.string "jendea pasa ohi da hemendik.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "Egon al zara ANAKLETOREN BIZIKLETA dendan?\p"
	.string "ANAKLETO jabea benetan gizon\n"
	.string "eskuzabala da.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "BIZIKLETAN baldin bazoaz ere,\n"
	.string "POKéMON basatiak ager daitezke.$"

MauvilleCity_Text_CitySign:
	.string "MALBADI HIRIA\n"
	.string "“Dibertsioaren hiri alai eta argia!”$"

MauvilleCity_Text_GymSign:
	.string "MALBADI HIRIKO POKéMON GIMNASIOA\n"
	.string "LIDERRA: ERIKO\l"
	.string "“Gizon alai elektrikoa!”$"

MauvilleCity_Text_BikeShopSign:
	.string "“Ibili hartxintxar artean eta\n"
	.string "garbitu zure arima!”\l"
	.string "ANAKLETOREN BIZIKLETA DENDA$"

MauvilleCity_Text_GameCornerSign:
	.string "“Guztiek jokatzeko tokia!”\n"
	.string "MALBADIKO JOKOEN TXOKOA$"

MauvilleCity_Text_ExplainTV:
	.string "Kaixo, ikusten al duzu telebista?\p"
	.string "Programa berri bikainak gehitu\n"
	.string "dituzte azkenaldian.\p"
	.string "Telebista ikaragarria da. Bat-batean\n"
	.string "nire lagunak ikusi ditut telebistan.\p"
	.string "Eta, gainera, batzuetan telebistan\n"
	.string "ateratzen zaituzte, zuri esan gabe.\p"
	.string "Nik noizbait atera nahi nuke telebistan.\p"
	.string "Horregatik esango nizuke, ahal duzunean\n"
	.string "telebistari begiratzeko.$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "Kaixo, ikusi al duzu telebista azkenean?$"
