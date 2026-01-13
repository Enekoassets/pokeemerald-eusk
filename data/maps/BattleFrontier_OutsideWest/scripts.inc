.set LOCALID_SS_TIDAL, 2
.set LOCALID_FERRY_ATTENDANT, 3
.set LOCALID_MANIAC_1, 9
.set LOCALID_MANIAC_2, 10
.set LOCALID_GIRL, 12
.set LOCALID_CAMPER, 14
.set LOCALID_FISHERMAN_2, 18
.set LOCALID_MAN_4, 23

BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "Hau BORROKA DOMOA da! Egin\n"
	.string "superizar garaiezinarenganako bidea!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "Hau BORROKA FABRIKA da!\n"
	.string "Aurkitu POKéMON indartsuenak!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "Hau BORROKA SUGEA da!\n"
	.string "Aukeratu hiru bideetako bat!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "Hau BORROKA DORREA da.\p"
	.string "ENTRENATZAILEEK beraien POKéMON\n"
	.string "indartsuenak dakartzate borrokarako.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "Kaixo, ferryagatik etorri al zara?\n"
	.string "Ikus al dezaket zure TIKETA?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER}(e)k ez dauka TIKETIK…\p"
	.string "Asko sentitzen dut.\p"
	.string "TIKET bat behar duzu ferryra\n"
	.string "igo ahal izateko.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER}(e)k TIKETA erakutsi du.\p"
	.string "Bikain! Hori besterik ez duzu behar!\p"
	.string "Eta nora joan nahi duzu?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "PORTUONDO HIRIRA, beraz!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "UR-LILI HIRIRA, beraz!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "Nabigatu gurekin berriz, mesedez!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "Mesedez, igo ferryra eta itxaron\n"
	.string "itsasoratu arte.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "Orduan, nora joan nahi zenuke?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "Nire lagun guztien artean onena naiz.\n"
	.string "Baina, hemen…\l"
	.string "Hutsaren hurrengoa besterik ez!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "BORROKA DORRERA joan nahi dut, baina\n"
	.string "ezin dut aurkitu, nahiz eta BORROKA\l"
	.string "FRONTEAREN mapa bat daukadan.\p"
	.string "Leku hau handiegia da!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "Hona iritsi bezain laster erronka\n"
	.string "bati egin nahi nion aurre.\p"
	.string "Baina bidean zorabiatu egin naiz…\n"
	.string "Urrrrp…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "Badakizu hona ezin dela edonor\n"
	.string "etorri, ezta?\p"
	.string "Gogorrak diren ENTRENATZAILEAK\n"
	.string "soilik ekartzen dituzte hona.\p"
	.string "Horregatik, hainabt ENTRENATZAILEK\n"
	.string "ez dakite BORROKA FRONTEA zer den ere.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "Aizu, anaia…\p"
	.string "Ziur zaude erronketara joan\n"
	.string "gaitezkeela POKéMONIK ez badugu ere?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "Beno…\n"
	.string "Ziur ez dela arazorik izango.\p"
	.string "Esango nuke… Gogoratzen al duzu\p"
	.string "zer esan zigun tipo handi horrek?\n"
	.string "Esan zuen, “POKéMONAK utziko dizkizuet!”$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "Hori BORROKA FABRIKA da.\n"
	.string "POKéMON indartsuak alokatu daitezke.\p"
	.string "Baina pentsarazi egiten dit horrek.\n"
	.string "Nork hazten ditu alokatzeko POKéMONAK?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "BORROKA SUGEAK beldurra ematen dit\n"
	.string "SEVIPER itxura horrekin…\p"
	.string "B-baina honaino iritsi naiz, beraz,\n"
	.string "guztia konkistatzen saiatuko naiz!\l"
	.string "…Ai ene…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "Joka dezagun harri, orri, ar!\n"
	.string "Bat, bi eta hiru!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "Bai! Irabazi egin dut!\n"
	.string "BORROKA SUGERA joango naiz!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "Ai, ene…\n"
	.string "Galdu egin dut.\p"
	.string "Ez daukat zorte handirik gaur.\n"
	.string "Bihar joango naiz BORROKA SUGERA\l"
	.string "hobeto pentsatuta.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "Esango nuke, auskalo zergatik, borrokatu\n"
	.string "baino arrantza egin nahiago duen bakarra\l"
	.string "naizela hemen.\p"
	.string "Zer? Ezin dela ezer harrapatu hemen?\n"
	.string "Hori bai pena…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "Gaur borrokan jarraituko dut, edozer\n"
	.string "gerta ere, Sinbolo bat lortu arte.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "Zer? BORROKA DOMOKO erronkari\n"
	.string "aurre egingo diozula?\p"
	.string "Zorte ona opa dizut.\n"
	.string "Ea biok borrokak irabazi eta elkar\l"
	.string "ikusten dugun hemen inguruan.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "Aitona, hementxe!\n"
	.string "Hau da BORROKA DOMOA!\l"
	.string "Eman egurra, Aitona!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "Hemengo hau da beraz BORROKA DOMOA?\n"
	.string "Ez diet utziko JAUNEI niri irabazten!\p"
	.string "Baina non dago sarrera?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "Duela ez horrenbeste, hemen ez\n"
	.string "zegoen ezer.\p"
	.string "Baina, begira orain! Izugarria da!\n"
	.string "Ama ekarriko dut hona, hau ikus dezan.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "Azkenean, iritsi naiz BORROKA\n"
	.string "FRONTERA!\p"
	.string "Ziur zeresana emango dudala, nire\n"
	.string "itxura eta abileziarekin!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "Ñam, ñam…\p"
	.string "Dirudienez, leku hau jende indartsuz\n"
	.string "beteta dago.\p"
	.string "Ñam, ñam…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "Kraust, ñam…\p"
	.string "Duela pixka bat, neska helduago\n"
	.string "bat ezagutu nuen BORROKA SUGEAN.\p"
	.string "Bere begiak beldurgarriak ziren,\n"
	.string "eta genio txarreko begirada zuen.\p"
	.string "Kraust, ñam…\p"
	.string "Asko haserretu zen: “Utziko al\n"
	.string "diozu jateari!” Egurra eman zidan.\p"
	.string "Ileak tentetzeko moduko esperientzia\n"
	.string "beldurgarria izan zen, alajaina.\p"
	.string "Kraust, ñam…$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "Zer? Entzuten al diozu zure buruari?\n"
	.string "Hori ez da ezer!\p"
	.string "Azkenengoz animatu nuenean, elkarri\n"
	.string "begiratu eta txinpartak atera ziren!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "Zeeeeeeeeer?!\n"
	.string "Pfft!\p"
	.string "Hori zure ondoan eserita nengoelako\n"
	.string "gertatu zen soilik!\p"
	.string "DOMOKO LIDERRAK begiratu zigun, nire\n"
	.string "animoak izugarriak izan zirelako!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "Bai zera, ixo!\n"
	.string "Ez egin horrenbeste zarata!\p"
	.string "Zu bezalako fan tentelak GIMNASIOKO\n"
	.string "LIDERREN bat animatu behar luke!\p"
	.string "DOMOKO LIDERRA nirea da!\n"
	.string "Nire idolo bakarra!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "Eztabaidan ari diren horiek…\p"
	.string "Sinesgaitza da, baina ENTRENATZAILEAK\n"
	.string "izan ziren, onak, gainera.\p"
	.string "Izugarri indartsuak ziren,\n"
	.string "eta famatuak, horrez gain.\p"
	.string "Baina ENTRENATZAILE batek egurtu\n"
	.string "zituen txapelketa batean.\p"
	.string "Horrenbesteko egurra jaso zuten,\n"
	.string "ENTRENATZAILEAK erakarri egin zituen.\p"
	.string "ENTRENATZAILEAREN fanak dira orain.\n"
	.string "Egunero joaten dira BORROKA DOMORA\l"
	.string "bera animatzera.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "Entzun dut norbaitek buztan oso luzeko\n"
	.string "POKéMON bat ikusi duela, hemen\l"
	.string "nonbait, BORROKA FRONTEAN.\p"
	.string "Oso polita izango da. Ziur nago…\p"
	.string "Erronkek itxaron dezakete. Izaki\n"
	.string "bikain hau aurkitu nahi dut!$"

