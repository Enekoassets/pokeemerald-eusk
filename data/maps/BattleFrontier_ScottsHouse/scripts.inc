.set LOCALID_SCOTT, 1

BattleFrontier_ScottsHouse_MapScripts::
	.byte 0

BattleFrontier_ScottsHouse_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_4, BattleFrontier_ScottsHouse_EventScript_GivenBerry
	goto_if_set FLAG_TEMP_3, BattleFrontier_ScottsHouse_EventScript_GivenShield
	goto_if_set FLAG_TEMP_2, BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveItems
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveItems::
	goto_if_unset FLAG_SCOTT_GIVES_BATTLE_POINTS, BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols
	goto_if_unset FLAG_COLLECTED_ALL_GOLD_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveShield::
	goto_if_unset FLAG_RECEIVED_SILVER_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield
	goto_if_unset FLAG_RECEIVED_GOLD_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols::
	goto_if_unset FLAG_SYS_TOWER_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols, MSGBOX_DEFAULT
	giveitem ITEM_LANSAT_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_SILVER_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols::
	goto_if_unset FLAG_SYS_TOWER_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols, MSGBOX_DEFAULT
	giveitem ITEM_STARF_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_GOLD_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_BerryPocketFull::
	msgbox BattleFrontier_ScottsHouse_Text_BerryPocketStuffed, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenBerry::
	msgbox BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_RandomComment::
	random 3
	goto_if_eq VAR_RESULT, 1, BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment
	goto_if_eq VAR_RESULT, 2, BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment
	msgbox BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment::
	msgbox BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment::
	msgbox BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveSilverShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_SILVER_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_SILVER_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_NoRoomForShield::
	msgbox BattleFrontier_ScottsHouse_Text_ComeBackForThisLater, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenShield::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveGoldShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_GOLD_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_GOLD_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingGreatThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier::
	msgbox BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	closemessage
	delay 30
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest
	msgbox BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing, MSGBOX_DEFAULT
	goto_if_eq VAR_SCOTT_STATE, 13, BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 9, BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 6, BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint
	end

BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints::
	buffernumberstring STR_VAR_1, 4
	setvar VAR_0x8004, 4
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints::
	buffernumberstring STR_VAR_1, 3
	setvar VAR_0x8004, 3
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints::
	buffernumberstring STR_VAR_1, 2
	setvar VAR_0x8004, 2
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint::
	buffernumberstring STR_VAR_1, 1
	setvar VAR_0x8004, 1
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints::
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	msgbox BattleFrontier_ScottsHouse_Text_ExplainBattlePoints, MSGBOX_DEFAULT
	setflag FLAG_SCOTT_GIVES_BATTLE_POINTS
	setflag FLAG_TEMP_2
	release
	end

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth::
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth::
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast::
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest::
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier:
	.string "TRIKI: Beno, kaixo eta ongi etorri!\n"
	.string "Kar-kar… barkatu leku gutxi dagoelako.\p"
	.string "Aizu, {PLAYER}{KUN}, utzi BORROKA\n"
	.string "FRONTERA ongi etorri formala egiten.\p"
	.string "Nire ametsa bete egin da.\n"
	.string "Urteak behar izan ditut, baina azkenean\l"
	.string "nire ametsari forma egokia eman diot.$"

BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal:
	.string "Pentsatzen jarrita, izugarri bidaia\n"
	.string "luzea izan da…\p"
	.string "Bakarrik atera nintzen etxetik,\n"
	.string "ENTRENATZAILE indartsuen bila.\p"
	.string "Inork ezin du imaginatu ere egin\n"
	.string "izerdi bota dudan hau lortzeko.$"

BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing:
	.string "Baina hori jada igaro da.\n"
	.string "Ez dugu zertan atzera begiratu!\p"
	.string "Hemendik aurrera, zure bihotz guztiz\n"
	.string "hemen borroka egitea nahi nuke.\p"
	.string "{PLAYER}{KUN}, gure bideak gurutzatu\n"
	.string "diren aldi guztiak gogoratzeko, hau\l"
	.string "eman nahi nizuke.$"

BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints:
	.string "{PLAYER}(e)k {STR_VAR_1}\n"
	.string "Borroka Puntu jaso d(it)u.$"

BattleFrontier_ScottsHouse_Text_ExplainBattlePoints:
	.string "TRIKI: Zure FRONTE PASEAN begiratu\n"
	.string "dezakezu zenbat Borroka Puntu dituzun.\p"
	.string "Zenbat eta arrakasta gehiago eduki\n"
	.string "BORROKA FRONTEAN, orduan eta Borroka\l"
	.string "Puntu gehiago jasoko dituzu.\p"
	.string "Erabili Borroka Puntuak zuk nahi duzun\n"
	.string "bezala, itemen truke gastatzeko, adibidez.$"

BattleFrontier_ScottsHouse_Text_ExpectingGreatThings:
	.string "Asko espero dut zugandik!$"

BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers:
	.string "TRIKI: ENTRENATZAILE bakoitza bakana da.\n"
	.string "Bakoitzak bere bizitza izan du.\p"
	.string "Baina borrokatzen dutenean,\n"
	.string "ez du axola nor diren.\p"
	.string "Berdinak dira denak!\p"
	.string "Borrokaren purutasuna atsegin dut,\n"
	.string "denak berdinak direlako une horretan.\p"
	.string "Horregatik joaten naiz leku guztietara\n"
	.string "borroka serio hartzen duten ENTRENATZAILEEN\l"
	.string "bila, eta hona gonbidatzen ditut.$"

BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain:
	.string "TRIKI: Ezagutu al duzu jada\n"
	.string "FRONTEKO BURURIK?\p"
	.string "Are gehiago, lortu al duzu\n"
	.string "sinbolorik haiengandik?\p"
	.string "Nik aukeratu ditut FRONTEKO BURUAK,\n"
	.string "leku guztietako ENTRENATZAILE indartsuenak.\p"
	.string "Baina zure indarra ikusita, ziur haiek\n"
	.string "ere txunditzeko gai izango zarela!$"

BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier:
	.string "TRIKI: Ez duzu borrokarako soilik\n"
	.string "entrenatzen, ezta?\p"
	.string "Uste dut POKéDEX batekin ere\n"
	.string "ari zinela lanean.\p"
	.string "Beno, ba badakizu zer?\p"
	.string "POKéMON basatiak aurki ditzakezu\n"
	.string "BORROKA FRONTEAN, nonbait…\l"
	.string "Fufufu!$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols:
	.string "TRIKI: Ondo ari al zara pasatzen\n"
	.string "BORROKA FRONTEAN?\p"
	.string "…Itxaron pixka bat…\n"
	.string "Ene!\p"
	.string "Zure FRONTE PASEA!\n"
	.string "Zilarrezko sinbolo guztiak\l"
	.string "bildu dituzu eta!\p"
	.string "Hori bai harrigarria!\n"
	.string "Indartsua zara, uste nuen bezala!\p"
	.string "Normalean, ez nuke halako ezer\n"
	.string "egingo, baina hau berezia da!\p"
	.string "Hau onartzea nahi nuke.\n"
	.string "Ziur nago erabilera egokia emango diozula.$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols:
	.string "TRIKI: BORROKA FRONTEAN ondo\n"
	.string "pasatzen ari zarela espero dut.\p"
	.string "…Itxaron pixka bat…\n"
	.string "Ene, ezin dut sinetsi!\p"
	.string "Zure FRONTE PASEA!\n"
	.string "Urrezko sinbolo guztiak\l"
	.string "bildu dituzu eta!\p"
	.string "Hori sinestezina da!\n"
	.string "Izugarria zara, uste nuen bezala!\p"
	.string "… … … … … …\p"
	.string "{PLAYER}, hau onartu behar duzu!\p"
	.string "Nire opariaren balioa ikusiko\n"
	.string "duzula espero dut!$"

BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere:
	.string "Egia esan, badakit ENTRENATZAILE on\n"
	.string "bat identifikatzen ikusita bakarrik.\p"
	.string "Asko pozten naiz zu hona ekartzea\n"
	.string "lortu izanaz!$"

BattleFrontier_ScottsHouse_Text_BerryPocketStuffed:
	.string "Zure BAIA POLTSIKOA\n"
	.string "bete-beteta dago.$"

BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow:
	.string "TRIKI: Bai, entzun ditut zure berriak!\n"
	.string "Nola garaitu duzun BORROKA DORREA!\l"
	.string "50 ENTRENATZAILE jarraian garaitu dituzu?\p"
	.string "Sinesgaitza!\n"
	.string "Hau hartzea nahi nuke!$"

BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow:
	.string "TRIKI: Ai ene! Zutaz entzun dut berriz!\n"
	.string "BORROKA DORREA txikitu omen duzu!\l"
	.string "100 ENTRENATZAILE jarraian garaitu dituzu?\p"
	.string "Hori guztiz sinestezina da!\n"
	.string "Hau hartu behar duzu!$"

BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings:
	.string "Hemendik aurrera, are gauza hobeak\n"
	.string "egingo dituzula espero dut!$"

BattleFrontier_ScottsHouse_Text_ComeBackForThisLater:
	.string "Ups, beno, gauza gehiegi badituzu\n"
	.string "aldean, etorri gero honen bila.$"

