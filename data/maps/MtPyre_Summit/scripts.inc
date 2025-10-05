.set LOCALID_ARCHIE, 2
.set LOCALID_OLD_LADY, 3
.set LOCALID_GRUNT_1, 4
.set LOCALID_GRUNT_2, 5
.set LOCALID_GRUNT_3, 6
.set LOCALID_GRUNT_4, 7
.set LOCALID_MAXIE, 8

MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MAXIE, 23, 6
	setobjectxyperm LOCALID_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "Ez! MAGMA TALDEKO horiek\n"
	.string "gure aurretik doaz!\p"
	.string "Ezin gara atzean geratu!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "Uste nuen atzera itzuli zen\n"
	.string "MAGMA TALDEKIDEA zinela…$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Bai, oso indartsua zara…\n"
	.string "Baina gutako pila bat daude!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "Kar-kar!\n"
	.string "A zer nolako pena!\p"
	.string "Lehenago etorrita, MAGMA TALDEKO kikil\n"
	.string "horien aurka soilik egin beharko zenuen.\p"
	.string "Baina orain iritsi zarenez, gu\n"
	.string "indartsuon aurka egin beharko duzu!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "Uff… MAGMA TALDEAREN aurka egiten\n"
	.string "utzi behar nizun lehenengo…$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "Ez dakizu ezer!\n"
	.string "Zergatik ari zara gure aurka orduan?$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "Zu…\n"
	.string "TXIMINIA MENDIAN ikusi zintugun.\p"
	.string "Ez zara TALDE batekoa ere,\n"
	.string "zergatik zaude hemen orduan?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "Norbaiten aurka jarri behar baduzu,\n"
	.string "MAGMA TALDEA izan dadila…$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Ez du axola!\n"
	.string "Denbora pixka bat lortu dugu!\p"
	.string "Ziur NAGUSIAK lapurtu duela\n"
	.string "behar zuena!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "Bai, badakit!\n"
	.string "MAGMA TALDERA sartu nahi zenuen,\l"
	.string "baina ez zintuzten onartu!\p"
	.string "Beno, ez pentsa AQUA TALDEAN\n"
	.string "sartzen utziko dizugunik!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "Beno, AQUA TALDEAN sartu nahi baduzu,\n"
	.string "agian utziko dizugu…$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "Partaide eta nagusiaren artean\n"
	.string "konbinazio izugarria dugu.$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "AKILES: MAGMA TALDEKO MAGNO aurreratu\n"
	.string "egin zaigu, baina lortu dugu nahi genuena.\p"
	.string "PIRO MENDIKO ORBE GORRIA…\n"
	.string "Nik, AKILESEK, daukat azkenean!\p"
	.string "Fufufu… Orain lortuko dugu gure\n"
	.string "helburu gorena betetzea!\p"
	.string "Ongi, TALDEA!\n"
	.string "Bagoaz hemendik!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "Ai ene…\n"
	.string "Hau ezin da gertatu…\p"
	.string "ORBE URDINA soilik ez,\n"
	.string "ORBE GORRIA ere hartu dute…\p"
	.string "ORBE URDINA eta ORBE GORRIA ez dira\n"
	.string "banatu behar. Batera egon behar dira.\p"
	.string "Zer egin ote nahi dute gizon horiek\n"
	.string "bi ORBEEKIN?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Oh, bai. MAGMA TALDEA izan al da lehenago\n"
	.string "iritsi eta ORBE URDINA hartu duena?\p"
	.string "Korrika eta presaka, hau\n"
	.string "ahaztu dute.\p"
	.string "Ez dakit zer izango ote den\n"
	.string "zehazki.\p"
	.string "Zuk hartzea nahi nuke.\n"
	.string "Agian zeozertarako balioko dizu.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "Gaiztagin horiek lapurtutako\n"
	.string "ORBE URDINA eta ORBE GORRIA…\p"
	.string "Ez dira inoiz banatu behar… Zerbait\n"
	.string "ikaragarria gertatuko dela uste dut…$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "Ai ene Jainkoa…\p"
	.string "GROUDON eta KYOGRE, biak\n"
	.string "esnatu direla diozu?\p"
	.string "Esaten da ORBE URDINAK eta\n"
	.string "ORBE GORRIAK bi POKéMONEN\l"
	.string "haserrea baretzen duela…\p"
	.string "Esaten da, baita ere, bi ORBEEN\n"
	.string "jabea existitzen dela oraindik.\p"
	.string "Baina inork ez daki norenak, edo\n"
	.string "zerenak, diren ORBEAK, zehazki.\p"
	.string "Gizaki batenak izan daitezke, edo\n"
	.string "POKéMON batenak, baina ez daki inork.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "ORBEAK eraman zituzten bi gizonak\n"
	.string "beren kabuz etorri ziren itzultzera.\p"
	.string "Gizon horiek…\n"
	.string "Agian ez dira horren gaiztoak azkenean…$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "Lurraren, itsasoaren eta\n"
	.string "zeruaren haragitzeak…\p"
	.string "Antzinako POKéMONAK hori\n"
	.string "direla dio elezaharrak…\p"
	.string "Gizakiok eta POKéMONAK bizirik\n"
	.string "gauden bezala, gure mundua ere\l"
	.string "bizirik dago…\p"
	.string "Hori irakatsi digute antzinako\n"
	.string "POKéMON horiek…$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "PIRO MENDIAN biltzen dira zendutako\n"
	.string "POKéMONEN espiritu lasaiak…\p"
	.string "Leku altu honetatik HOENN\n"
	.string "guztia ikus daiteke…\p"
	.string "POKéMONEN espiritu gorputzgabeek\n"
	.string "lasaitasuna aurkitzen dute hemen…\p"
	.string "Kasualitatea da zu hemen egotea…\p"
	.string "Enztungo duzu nire istorioa? Aspalditik\n"
	.string "HOENN eskualdean kontatzen dena?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "Antzina-antzina gertatu zen…\p"
	.string "Mundua itsasoko POKéMONAREN eta\n"
	.string "lurreko POKéMONAREN arteko talka\l"
	.string "basati batean suntsitu zen…\p"
	.string "Lurreko POKéMONAK mendiak altxa eta\n"
	.string "kontinenteak sortu zituen…\p"
	.string "Itsasoko POKéMONAK olatu izugarriak\n"
	.string "sortu eta ozeanoak osatu zituten…\p"
	.string "Duelu basati eta amaigabea izan zen.\p"
	.string "Mundua infernu beldurgarri eta\n"
	.string "ekaitz amaitezinek bildu zuten.\p"
	.string "ORBE URDINAK eta ORBE GORRIAK\n"
	.string "kalamitatea gelditu zuten azkenean.\p"
	.string "Argia sortu zen bi ORBEETATIK eta\n"
	.string "etsai haserretuak baretu zituen.\p"
	.string "Bikotea, behin lasaituta, itsas\n"
	.string "hondora joan zen, eta, azkenean,\l"
	.string "desagertu egin zen…$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "Ikusten dut, bai…\n"
	.string "Beno, hori ere ondo dago…$"

MtPyre_Summit_Text_MaxieSilence:
	.string "MAGNO: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "Nire ardura da HOENNEKO elezaharrak\n"
	.string "belaunaldiz belaunaldi kontatzea.\p"
	.string "Eta ARREZIPOLISEN gertatu berri\n"
	.string "denak elezaharra berridatzi du…\p"
	.string "Ba al duzu denborarik HOENNEKO\n"
	.string "elezahar berritua entzuteko?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "Antzina-antzina gertatu zen…\p"
	.string "Mundua itsasoko POKéMONAREN eta\n"
	.string "lurreko POKéMONAREN arteko talka\l"
	.string "basati batean suntsitu zen…\p"
	.string "Lurreko POKéMONAK mendiak altxa eta\n"
	.string "kontinenteak sortu zituen…\p"
	.string "Itsasoko POKéMONAK olatu izugarriak\n"
	.string "sortu eta ozeanoak osatu zituten…\p"
	.string "Duelu basati eta amaigabea izan zen.\p"
	.string "Mundua infernu beldurgarri eta\n"
	.string "ekaitz amaitezinek bildu zuten.\p"
	.string "Orduan, zeruko POKéMONA jaitsi\n"
	.string "zen ekaitz baten erditik.\p"
	.string "POKéMONAK, kolore berde biziz inguratuta,\n"
	.string "POKéMON haserretuak lasaitu zituen.\p"
	.string "Ondoren, bere betebeharra eginda,\n"
	.string "zeru urdinera joan zen hegan POKéMONA…$"

