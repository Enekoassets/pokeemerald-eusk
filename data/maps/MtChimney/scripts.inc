.set LOCALID_ARCHIE, 1
.set LOCALID_MAXIE, 2
.set LOCALID_TABITHA, 3
.set LOCALID_MAGMA_GRUNT_2, 22
.set LOCALID_MAGMA_GRUNT_1, 29


MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_MAGMA_GRUNT_1
	removeobject LOCALID_TABITHA
	removeobject LOCALID_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreen FADE_FROM_BLACK
	setobjectxyperm LOCALID_ARCHIE, 10, 12
	addobject LOCALID_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
	.string "The power contained in the METEORITE…\p"
	.string "By amplifying its power with this\n"
	.string "machine, MT. CHIMNEY's volcanic\l"
	.string "activity will instantly intensify…\p"
	.string "Its energy will grow deep inside\n"
	.string "the crater and…\l"
	.string "Fufufu…$"

MtChimney_Text_MaxieIntro:
	.string "MAGNO: Zer?\n"
	.string "Nor zara zu?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Entzun dut AKILES kexaka aritu dela\n"
	.string "AQUA TALDEAREN planetan muturra\l"
	.string "sartzen aritu den gazte batengatik.\p"
	.string "Zu izango zara.\p"
	.string "Zer, bada! MAGMA TALDEAREN planetan\n"
	.string "muturra satu nahi al duzu?\p"
	.string "Entzun, aizu.\n"
	.string "Aspaldi, izaki bizidunak lurrean\l"
	.string "bizi eta hazten ziren. Horregatik\p"
	.string "da lurra horren garrantzitsua!\n"
	.string "Guztien hazlekua da!\p"
	.string "Horregatik nahi du MAGMA\n"
	.string "TALDEAK lur masa hedatu.\p"
	.string "Gizadiaren eta POKéMONEN\n"
	.string "garapenerako beharrezkoa da!\p"
	.string "Horretarako, mendi honetan lo\n"
	.string "dagoena esnatu…\p"
	.string "Ene! Ez duzu zertan\n"
	.string "horrenbeste jakin.\p"
	.string "Baina, berdin dio!\n"
	.string "Gure plan gorenean muturra sartzeak\l"
	.string "dakarrena erakutsiko dizut!$"

MtChimney_Text_MaxieDefeat:
	.string "Zer?!\p"
	.string "Ni, MAGNO, garaitu egin naute?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "MAGNO: Nahikoa da.\n"
	.string "Atzera egingo dut gaurkoan.\p"
	.string "Baina ez pentsa MAGMA TALDEA\n"
	.string "ikusten duzun azken aldia denik.\p"
	.string "Fufufu…\p"
	.string "METEORITO gabe ere, ORBE hori\n"
	.string "lortzen badugu… Fufufu…$"

MtChimney_Text_TabithaIntro:
	.string "Kar-kar-kar!\p"
	.string "Honaino iritsi zara!\p"
	.string "Baina beranduegi zatoz!\n"
	.string "Jada eman diot METEORO URJAUZIKO\l"
	.string "METEORITOA NAGUSIARI!$"

MtChimney_Text_TabithaDefeat:
	.string "Kar-kar-kar…\p"
	.string "Galdu badut ere, gure nagusiak\n"
	.string "gauza hori esnatzen badu…$"

MtChimney_Text_TabithaPostBattle:
	.string "NAGUSI, azkar!\n"
	.string "Emaiozu METEORITOAREN energia!\p"
	.string "Kar-kar-kar…$"

MtChimney_Text_Grunt2Intro:
	.string "MAGMA TALDEKOOK gogor ari gara\n"
	.string "lanean, gzutien alde.\p"
	.string "Gauza horren botereak lurra hedatuko\n"
	.string "balu, bizileku gehiago egongo litzateke.\p"
	.string "Denak pozik egongo lirateke!$"

MtChimney_Text_Grunt2Defeat:
	.string "Zer?\n"
	.string "Nola galdu egin dudala?$"

MtChimney_Text_Grunt2PostBattle:
	.string "NAGUSIAK dio, “Denak pozik\n"
	.string "egongo dira.”\p"
	.string "Orduan zergatik sartzen dira\n"
	.string "guztiak gure helburuen erdian?$"

MtChimney_Text_Grunt1Intro:
	.string "Lur gehiago egongo balitz, etxe\n"
	.string "handi bat edukiko nuke!\p"
	.string "Gogortutako laban eraikiko nuke!$"

MtChimney_Text_Grunt1Defeat:
	.string "Etxe handia izateko nire ametsa…$"

MtChimney_Text_Grunt1PostBattle:
	.string "Zu bezalako ume bat, itsasoan\n"
	.string "egon behar litzateke!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "Ditxosozko AQUA TALDE hori…\n"
	.string "Gure planak zapuztu nahi dituzte!$"

MtChimney_Text_MeteoritesPackAmazingPower:
	.string "METEORITOEK botere izugarria daukate!$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "Hobe duzu gurekin ez jolasean ibili!\p"
	.string "Gauza hori esnatu nahi dugu\n"
	.string "guztien onura lortzeko!$"

MtChimney_Text_AquasNameSimilar:
	.string "MAGMA TALDEA gara!\p"
	.string "Haiek AQUA TALDEA dira!\p"
	.string "Gurea bezalako izena erabili\n"
	.string "dute! A zer amorrua!$"

MtChimney_Text_DouseThemInFire:
	.string "Bai!\n"
	.string "Sutan bilduko ditugu!$"

MtChimney_Text_KeepMakingMoreLand:
	.string "Lurra hedatzen jarraituko dugu!$"

MtChimney_Text_Bufoh:
	.string "Bufoh!$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "AKILES: Grr, {PLAYER}!\n"
	.string "Etorriko zinela espero behar nuen!\p"
	.string "Ikusi zure begiekin zertan ari diren\n"
	.string "TEAM MAGMA TALDEKO ero horiek!\p"
	.string "Lapurtutako METEORITOAREN boterea\n"
	.string "sumendian sartu nahi dute!\p"
	.string "Halako zerbait egiteak sumendia\n"
	.string "erupzioan sartu dezake!$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "AKILES: Grrr…\p"
	.string "MAGNO geratu nahi dut,\n"
	.string "baina ezin dut!\p"
	.string "Nire eskuekin hiru etsairen\n"
	.string "aurka ari naiz aldi berean!$"

MtChimney_Text_ArchieThankYou:
	.string "AKILES: {PLAYER}!\n"
	.string "Eskerrik asko!\p"
	.string "Zure laguntzarekin, MAGMA TALDEAREN\n"
	.string "plan suntsitzailea geratu dugu!\p"
	.string "Baina… Zu…\n"
	.string "Noren alde zaude zu?\p"
	.string "Beno, berdin da.\p"
	.string "Adi jarraituko dugu, MAGMA\n"
	.string "TALDEA zelatatuz.\p"
	.string "{PLAYER}, ikusi arte!$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "Kaka… MAGMA TALDEKOAK gu baino\n"
	.string "gehiago dira! Ezin dugu guztiekin!$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "Lurra hedatzen badute, URETAKO\n"
	.string "POKéMONEK ez dute bizilekurik izango!$"

MtChimney_Text_MagmasNameSimilar:
	.string "AQUA TALDEA gara!\p"
	.string "Haiek MAGMA TALDEA dira!\p"
	.string "Haiek horrelako izen nahasgarria\n"
	.string "erabiltzeak amorratu egiten nau!$"

MtChimney_Text_Bushaa:
	.string "Bushaa!$"

MtChimney_Text_LavaCookiesJust200:
	.string "LABA GALLETAK TXIMINIA MENDIKO\n"
	.string "jaki berezi lokala dira.\p"
	.string "Probatu bat. 200¥ besterik ez da.$"

MtChimney_Text_ThankYouDear:
	.string "Eskerrik asko, maitea!$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "Ai ene. Ezin duzu ezer erosi\n"
	.string "dirurik ez baduzu.$"

MtChimney_Text_OhFineThen:
	.string "Beno, ongi orduan.$"

MtChimney_Text_MetoriteFittedOnMachine:
	.string "METEORITOA makina misteriotsu\n"
	.string "batean sartuta dago…\p"
	.string "Makina METEORITOAN energia\n"
	.string "gordetzen ari dela dirudi.$"

MtChimney_Text_RemoveTheMeteorite:
	.string "METEORITOA makina misteriotsu\n"
	.string "batean sartuta dago…\p"
	.string "METEORITOA kendu nahi al duzu?$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{PLAYER}(e)k METEORITOA kendu\n"
	.string "du makina misteriotsutik.$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{PLAYER}(e)k bere lekuan utzi\n"
	.string "du METEORITOA.$"

MtChimney_Text_MachineMakesNoResponse:
	.string "Makina misteriotsu honek…\n"
	.string "Ez du erantzuten.$"

MtChimney_Text_RouteSign:
	.string "{DOWN_ARROW} HAIZPITARTEA\n"
	.string "LABARAN HERRIA HEMENDIK$"

MtChimney_Text_ShelbyIntro:
	.string "Ur termaletara etorri naiz\n"
	.string "hezur nekatuak deskantsatzera.\l"
	.string "Orain indartsu sentitzen naiz!$"

MtChimney_Text_ShelbyDefeat:
	.string "Ai, ene Jainkoa.\n"
	.string "Zu bai zu aparta!$"

MtChimney_Text_ShelbyPostBattle:
	.string "Beno, beno, galdu egin dut. Orain\n"
	.string "ezin dut ADITUA naizela esan, ezta?$"

MtChimney_Text_ShelbyRegister:
	.string "Eskerrik asko, ume. Dibertigarria\n"
	.string "izan da, nire bilobaren aurka ari\p"
	.string "banintz bezala. Mesedez, egin dezagun\n"
	.string "borroka berriz.$"

MtChimney_Text_ShelbyRematchIntro:
	.string "Zure POKéMONEN bihotza eta\n"
	.string "zurea elkartu baditzakezu, gauza\l"
	.string "izugarriak lor ditzakezu.$"

MtChimney_Text_ShelbyRematchDefeat:
	.string "Ai, ene Jainkoa.\n"
	.string "Zu bai zu aparta!$"

MtChimney_Text_ShelbyPostRematch:
	.string "Agian zure bihotza eta zure\n"
	.string "POKéMONENA lotuta daude.$"

MtChimney_Text_MelissaIntro:
	.string "Sua daukat nire barnean. Ezin dut\n"
	.string "gehiago! Borroka egin behar dut!$"

MtChimney_Text_MelissaDefeat:
	.string "Ene, hori bai borroka beroa!$"

MtChimney_Text_MelissaPostBattle:
	.string "TXIMINIA MENDIKO beroak nire\n"
	.string "barnea berotzen du, bai!$"

MtChimney_Text_SheilaIntro:
	.string "Azkenean iritsi naiz TXIMINIA MENDIRA.\n"
	.string "Nire POKéMONEKIN borroka egin nahi dut!$"

MtChimney_Text_SheilaDefeat:
	.string "Zure borrokarkao gaitasuna… TXIMINIA\n"
	.string "MENDIAREN erupzioa bezalakoa da!$"

MtChimney_Text_SheilaPostBattle:
	.string "Esan bezala, azkenean iritsi naiz\n"
	.string "TXIMINIA MENDIRA. Tristea litzateke\l"
	.string "ingurua ikustera soilik etortzea…\p"
	.string "Borroka batzuk egin eta GALLETAK\n"
	.string "erosi nahi ditut oroigarri gisan.$"

MtChimney_Text_ShirleyIntro:
	.string "Ur termaletan bainatu naizenez,\n"
	.string "izugarri ondo sentitzen naiz!\l"
	.string "Ziur nago irabazi egingo dudala!$"

MtChimney_Text_ShirleyDefeat:
	.string "Autx!\n"
	.string "Uretatik kanpo hoztu egin naiz.$"

MtChimney_Text_ShirleyPostBattle:
	.string "Beste bainu bat hartuko dut\n"
	.string "ur termaletan. Etorri nahi?\p"
	.string "Txantxetan ari naiz!$"

MtChimney_Text_SawyerIntro:
	.string "Hau bai mendi ederra! Jende\n"
	.string "pila bat konpainia egiteko!$"

MtChimney_Text_SawyerDefeat:
	.string "Ene, zu bai pertsona sutsua!$"

MtChimney_Text_SawyerPostBattle:
	.string "Uste dut LABARANEKO UR TERMALETAN\n"
	.string "bainatu nahi dudala bertakoekin!$"

MtChimney_Text_SawyerRegister:
	.string "Zu bezalako su bola txikiak gustoko ditut.\n"
	.string "Utzi zure POKéNAVEAN erregistratzen.$"

MtChimney_Text_SawyerRematchIntro:
	.string "Jendez inguratuta nago hemen\n"
	.string "bertan. Ez dut galduko!$"

MtChimney_Text_SawyerRematchDefeat:
	.string "Ene, lehen bezain sutsua\n"
	.string "izaten jarraitzen duzu!$"

MtChimney_Text_SawyerPostRematch:
	.string "Egia esan, bero egiten du hemen.\n"
	.string "Erropa gehiegi daukat jantzita.$"

