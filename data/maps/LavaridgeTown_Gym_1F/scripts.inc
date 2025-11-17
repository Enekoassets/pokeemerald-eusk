.set LOCALID_COLE, 2
.set LOCALID_GERALD, 3
.set LOCALID_AXLE, 4
.set LOCALID_DANIELLE, 5

LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Ei, zer moduz dago gure {PLAYER},\n"
	.string "etorkizuneko TXAPELDUNA?\p"
	.string "SUAK, LABARANEKO GIMNASIOKO LIDERRAK\n"
	.string "SU motako POKéMONAK erabiltzen ditu.\p"
	.string "Bere POKéMONEKIKO pasioa sumendi\n"
	.string "bat baino beroagoa da.\p"
	.string "Ez hurbildu gehiegi, erre egingo zara!\n"
	.string "Zipriztindu ezazu urez lehenengo,\l"
	.string "eta gero lortuko duzu!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "Aizu! Hori bai borroka beroa!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "Auauauauau!\n"
	.string "Ene, oso bero dago!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "Begietako izerdiak ez dit ikusten uzten…$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "Hondar berotan lurperatuta egoteak\n"
	.string "zirkulazioa hobetzen du.\p"
	.string "Artikulazioetako mina tratatzeko\n"
	.string "era paregabea da.$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "Estresa askatu nahian nabil.\n"
	.string "Ez nazazu estresatu, aizu!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "Espero dut SUAK erreko zaituela!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Uauu… Fiuuu…\p"
	.string "Denbora gehiegi bazaude hondar berotan\n"
	.string "lurperatuta, bero kolpea eduki dezakezu…$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "Nekatuta egongo zara jada.\n"
	.string "Hondar berotan sartu nahi zenuke,\l"
	.string "ez al da hala?\p"
	.string "Baina, gogoratu, gogoa indartsu\n"
	.string "mantentzea ENTRENATZAILE guztientzat\l"
	.string "kontu garrantzitsua dela.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "Jolastu suarekin eta erre egingo zara…$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Abilezia itzela duzu…\n"
	.string "Baina gure SUA LIDERRA oso indartsua da.\p"
	.string "Ez bazara kontu handiz ibiltzen,\n"
	.string "larri erreko zaitu.$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "Zure POKéMONEK jasan al dezakete\n"
	.string "200 graduko beroa?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "Ez da nahikoa bero izan…$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "Magmaren tenperatura 200\n"
	.string "gradukoa da.\p"
	.string "Zure POKéMONAK irabazi egin dit, beraz,\n"
	.string "ziur magmari aurre egin diezaiokeela.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "Um…\n"
	.string "Ongi, borroka dezagun.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Ene, baina oso indartsua zara.$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "ENTRENATZAILE polit eta indartsua\n"
	.string "izango naiz, SUA bezala.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "Ea ba, has gaitezen!\n"
	.string "Borroka dezagun gogoa hoztu aurretik!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "Bero izugarria dago, baina\n"
	.string "bihotza izoztuta daukat…$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "Barruan duzu borrokarako grina\n"
	.string "sutsua, agian gure LIDERRARI\l"
	.string "irabazteko gai izango zara.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "Ikusten sugarren mugimendu basatia?\n"
	.string "Nire garaipena aurreikusten dutelako da!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "Zerbaitek ez du ondo funtzionatu.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "Beno, eta? Zer inporta zaizu?\n"
	.string "Ikatzetan oinutsik ibil naiteke!\p"
	.string "…Ez dakizula burutik pasa saiatzea!$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "Mendiak asko atsegin baditut ere,\n"
	.string "sumendiak ditut gogokoen.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "Beno, badirudi behin kontrola\n"
	.string "hartu gabe ere galdu dudala.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "Hemen egon ohi naiz, SUAREN\n"
	.string "indarraren fana bainaiz.\p"
	.string "Kar-kar-kar.$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Ongi etorri… Ez, itxaron.\p"
	.string "ENTRENATZAILE makala, pozten naiz\n"
	.string "honaino iritsi izana!\p"
	.string "Zure ardura da orain…\n"
	.string "Ez, itxaron.\p"
	.string "SUA naiz, hemengo GIMNASIOKO\n"
	.string "LIDERRA, alajaina!\p"
	.string "Eta…\n"
	.string "Ez nazazu gutxietsi, nahiz eta denbora\l"
	.string "gutxiz izan naizen LIDER!\p"
	.string "Nire aitonagandik jasotako trebeziari\n"
	.string "esker, nik, ee… nik erakutsiko dizut\l"
	.string "nola egiten dugun borroka leku beroetan!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Ene…\n"
	.string "Agian gehiegi saiatzen ari nintzen…\p"
	.string "Ni… Duela gutxi bilakatu naiz\n"
	.string "GIMNASIOKO LIDER.\p"
	.string "Ez nintzen norbaiten itxura\n"
	.string "egiten saiatzen ari nintzen.\p"
	.string "Nire erara egin behar ditut gauzak. Bestela,\n"
	.string "nire POKéMONAK nahastu egingo dira.\p"
	.string "Eskerrik asko hori erakusteagatik.\n"
	.string "Tori, hau merezi duzu.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER}(e)k BERO DOMINA jaso\n"
	.string "du SUARENGANDIK.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "BERO DOMINAREKIN, 50. mailara arteko\n"
	.string "POKéMONEK kasu egingo dizute, baita\l"
	.string "beste pertsonekin egindako trukeetan\l"
	.string "jaso dituzunek ere.\p"
	.string "Gainera, POKéMONEK INDARRA MEa\n"
	.string "erabili dezakete borrokatik kanpo.\p"
	.string "Hau nire esker onaren adierazle.\n"
	.string "Ez izan lotsarik, hartu!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "MT50ak BEROALDIA du barnean.\p"
	.string "Etsaiari min izugarria egiten\n"
	.string "dio eraso horrek.\p"
	.string "Baina erabiltzen duen POKéMONAREN\n"
	.string "ER. BER. asko jaisten du. Agian ez\l"
	.string "da egokia borroka luzeetarako.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "SUA GIMNASIOKO LIDERRA\n"
	.string "POKéNAVEAN erregistratu duzu.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "Zure botereak norbait gogorarazten dit…\p"
	.string "Bai! Badakit! NORMANEK bezala egiten\n"
	.string "duzu borrokan, PETALOREKO LIDERRAK bezala.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "LABARAN HERRIKO POKéMON GIMNASIOA$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "LABARAN HERRIKO POKéMON GIMNASIOA\p"
	.string "SUAK ZIURTATUTAKO ENTRENATZAILEAK:\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "SUA: Borroka bat galtzeak ez\n"
	.string "nau kikilduko.\p"
	.string "Maite ditut POKéMONAK.\n"
	.string "Maite dut borrokatzea.\l"
	.string "Eta… Maite dut GIMNASIO hau!\p"
	.string "Egin dezagun borroka super\n"
	.string "bero bat beste batean!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Ufff!\n"
	.string "Ia-ia lehertu da guztia!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "SUA: Galdu egin dut borroka,\n"
	.string "baina oso gustura geratu naiz.\p"
	.string "Ez dut askotan izaten horrelako\n"
	.string "borroka berorik.\p"
	.string "Izan dezagun halako beste borroka\n"
	.string "bat beste batean!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "SUA: Borroka bat galtzeak ez\n"
	.string "nau kikilduko.\p"
	.string "Maite ditut POKéMONAK.\n"
	.string "Maite dut borrokatzea.\l"
	.string "Eta… Maite dut GIMNASIO hau!\p"
	.string "Egin dezagun borroka super\n"
	.string "bero bat beste batean!\p"
	.string "Itxaron. Borrokatu dezakeen POKéMON\n"
	.string "bakarra al daukazu?\p"
	.string "Sentitzen dut esatea, baina niregana\n"
	.string "etortzean, ekarri bi POKéMON, gutxienez.$"
