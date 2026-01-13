.set LOCALID_GREETER, 1
.set LOCALID_GUIDE, 2
.set LOCALID_SCOTT, 4

BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_GREETER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_GUIDE, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
	.string "Zure lehenengo aldia al da hemen?\n"
	.string "Pasa hemendik, mesedez!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
	.string "Hau da POKéMON borrokaleku gorena!\n"
	.string "Ongi etorri BORROKA FRONTERA!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
	.string "Lehengo aldiz datozenei FRONTE\n"
	.string "PASEA ematen diegu.\p"
	.string "BORROKA FRONTEKO eraikinetan\n"
	.string "erabili daiteke.\p"
	.string "Tori, hementxe duzu!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.string "{PLAYER}(e)k FRONTE\n"
	.string "PASEA jaso du.$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.string "{PLAYER}(e)k ENTRENATZAILE TXARTELA\n"
	.string "FRONTE PASEAN jarri du.$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
	.string "BORROKA FRONTEAK eskaintzeko duen\n"
	.string "guztia goztuko duzula espero dugu!$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.string "???: Beno, beno, {PLAYER}{KUN} da eta!\n"
	.string "Hona etorri zara!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
	.string "GIDA: Ene! TRIKI JAUNA!\n"
	.string "Egun on, jauna!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
	.string "TRIKI: Itzela da zu hemen ikustea,\n"
	.string "benetan!\p"
	.string "Denbora hartu eta guztia esploratuko\n"
	.string "duzula espero dut.\p"
	.string "Noski, borroken esentzia ere\n"
	.string "probatuko duzula ere espero dut.\p"
	.string "Hemen dago nire lantokia, beraz,\n"
	.string "etorri bisitan, denbora baduzu.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
	.string "Zure gida izango naiz BORROKA\n"
	.string "FRONTEKO eraikinei dagokienez.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.string "Zeinen inguruan ikasi nahi duzu?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
	.string "BORROKA FRONTEKO sinbolotzat\n"
	.string "hartzen den dorre erraldoia da.\p"
	.string "Lau BORROKA GELA mota daude bertan,\n"
	.string "BANAKAKO, BINAKAKO, MULTI eta LINK\l"
	.string "MULTI BORROKAK egiteko.$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
	.string "BORROKA DOMOA arrautza erraldoi baten\n"
	.string "itxura duen eraikin handia da.\p"
	.string "Eraikin horretan, Borroka Txapelketa\n"
	.string "deritzen erronkak egiten dira.\p"
	.string "Bi motatako Borroka Txapelketak\n"
	.string "daude: BANAKAKO eta BINAKAKO BORROKAK\l"
	.string "egin daitezke.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
	.string "BORROKA JAUREGIA BORROKA FRONTEKO\n"
	.string "eskuinaldean dagoen eraikin gorria da.\p"
	.string "Bi motatako BORROKA ARETOAK daude,\n"
	.string "BANAKAKO eta BINAKAKO BORROKAK egiteko.$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
	.string "BORROKA ARENA dojo itxura duen\n"
	.string "eraikina da, BORROKA FRONTEAREN\l"
	.string "erdi-eskuinaldean dagoena.\p"
	.string "KO Txapelketa izeneko ekitaldia\n"
	.string "egiten da BORROKA ARENAN.$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
	.string "BORROKA FABRIKA gugandik hurbilen\n"
	.string "dagoen eraikin handia da.\p"
	.string "Truke Borroka izeneko ekitaldia\n"
	.string "egiten da bertan.\p"
	.string "Bi motatako Truke Borrokak daude:\n"
	.string "BANAKAKO eta BINAKAKO BORROKAK\l"
	.string "egin daitezke.$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
	.string "BORROKA SUGEA POKéMON itxura duen\n"
	.string "eraikina da, BORROKA FRONTEKO\l"
	.string "erdialdean dago, ezkerretara.\p"
	.string "Aukera Borroka izeneko ekitaldia\n"
	.string "egiten da bertan.$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
	.string "BORROKA PIRAMIDEA piramide izugarri\n"
	.string "bat da.\p"
	.string "Bilaketa Borroka izeneko ekitaldia\n"
	.string "egiten da bertan.$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
	.string "ERREKORREN ARETOA BORROKA DORREAREN\n"
	.string "inguruan dago.\p"
	.string "Bertan, BORROKA FRONTEKO erronkei\n"
	.string "aurre egin dieten ENTRENATZAILEEK\l"
	.string "egindako errekorren inguruko\l"
	.string "informazioa dago.$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
	.string "TRUKE ZERBITZUA BORROKA DORREAREN\n"
	.string "inguruan dago.\p"
	.string "BORROKA FRONTEAN lortutako Borroka\n"
	.string "Puntuak trukatu ditzakezu bertan,\l"
	.string "sari itzelen truke.$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
	.string "BORROKA FRONTEKO erronka guztietan\n"
	.string "dauden oinarrizko arauen inguruan\l"
	.string "informazioa behar baduzu, ni izango\l"
	.string "naiz zure gida.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.string "Zeren inguruan jakin nahi zenuke?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
	.string "BORROKA FRONTEKO erronka guztiak\n"
	.string "bi mailatan egin daitezke: 50.\l"
	.string "Maila eta Maila Irekia.$"

BattleFrontier_ReceptionGate_Text_Level50Info:
	.string "50. Mailan, gehienez 50 Mailako\n"
	.string "POKéMONEK har dezakete parte.\p"
	.string "Hala ere, kontuan izan, ez duzula\n"
	.string "aurkituko POKéMONAK 50 Maila baino\l"
	.string "beherago dituen ENTRENATZAILERIK.\p"
	.string "Maila hau BORROKA FRONTEAN hasteko\n"
	.string "maila egokiena da.\p"
	.string "Hasten zarenean, maila honetan\n"
	.string "hartu behar zenuke parte.$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
	.string "Maila Irekiak ez dio mugarik jartzen\n"
	.string "erronkan parte hartzen duten\l"
	.string "POKéMONEN mailari.\p"
	.string "Zure etsaiaren POKéMONEN maila\n"
	.string "doitu egingo da, zure POKéMONEN\l"
	.string "mailaren arabera.\p"
	.string "Hala ere, 60 Maila baino beheragoko\n"
	.string "POKéMONIK ez duzu inoiz aurkituko.$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
	.string "Ia edozein POKéMON motak har dezake\n"
	.string "parte erronka guztietan. Hala ere,\p"
	.string "ARRAUTZAK eta POKéMON mota batzuk\n"
	.string "ez daude baimenduta. Parte hartzeko\p"
	.string "beharrezko POKéMON kopurua aldatu\n"
	.string "egiten da erronkaren arabera.\p"
	.string "Toki guztietan, ordea, ez da\n"
	.string "onartzen mota bereko bi POKéMON\l"
	.string "edo gehiago erabiltzea.$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
	.string "BORROKA FRONTEKO erronka batean parte\n"
	.string "hartzerakoan, POKéMONEK ezin dute\l"
	.string "mota bereko itemik eduki.\p"
	.string "Mesedez, kontuan izan erronka batean\n"
	.string "parte hartzen duten POKéMONEK\l"
	.string "item desberdinak dauzkatela.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.string "FRONTE PASEAREN inguruko zure gida naiz.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.string "Zeren inguruan jakin nahi zenuke?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
	.string "Zazpi eraikuntza daude\n"
	.string "BORROKA FRONTEAN.\p"
	.string "Beraien abilezia erakusten duten\n"
	.string "ENTRENATZAILEEK sinbolo bat lortuko\l"
	.string "dute eraikin bakoitzean.\p"
	.string "Sinbolo bat lortzeko, ENTRENATZAILEEK\n"
	.string "garaipenak jarraian lortu behar dituzte\l"
	.string "batzuetan, eta baita erronkak behin\p"
	.string "baino gehiagotan garaitu ere. Ez da\n"
	.string "erraza sinboloak lortzea. Zorte on!$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
	.string "Borroka bat grabatu dezakezu\n"
	.string "zure FRONTE PASEAN.\p"
	.string "Lagun batekin edo gehiagorekin\n"
	.string "izandako borroka bat graba dezakezu.\p"
	.string "Edo BORROKA FRONTEAN egindako bat\n"
	.string "graba dezakezu, BORROKA SUGEAN\l"
	.string "eta BORROKA PIRAMIDEAN egindako\l"
	.string "borrokak izan ezik.\p"
	.string "Borrokaren amaieran aukera dezakezu\n"
	.string "borroka grabatu edo ez.$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
	.string "Borroka Puntuak ematen zaizkie\n"
	.string "BORROKA FRONTEAN ondo borrokatu\l"
	.string "duten ENTRENATZAILEEI.\p"
	.string "Zure Borroka Puntuak trukatu\n"
	.string "ditzakezu TRUKE ZERBITZUAN, opari\l"
	.string "bikainen truke.$"

