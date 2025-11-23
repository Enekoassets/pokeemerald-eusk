DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "Ei, zer moduz dago gure {PLAYER},\n"
	.string "etorkizuneko TXAPELDUNA?\p"
	.string "MARTZIALEK, IHINTZIBARREKO GIMNASIOKO\n"
	.string "LIDERRAK BORROKA motako POKéMONAK ditu.\p"
	.string "NORMAL motako POKéMONEKIN egiten badiozu\n"
	.string "aurre, ez zabiltza bide onetik.\p"
	.string "BORROKA motako POKéMONEK egurra\n"
	.string "emango die NORMAL motako POKéMONEI,\l"
	.string "kontuz ibili, beraz!\p"
	.string "Are gehiago, GIMNASIO hau ozeanoaren\n"
	.string "hondoa bezain iluna da.\p"
	.string "Baina argitzen joango da bidean aurkitzen\n"
	.string "dituzun ENTRENATZAILEAK garaitu heinean.\p"
	.string "Ea, bada, aurrera!$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "Uau! Hemen argi gehiagi dago!\p"
	.string "Zure etorkizuna ere oso argitsua da!$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "Indarra da bidea!\n"
	.string "Goazen borrokara!$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "Ez dut nahikoa indar…$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "Zure abileziak nire indarra garaitu du!\n"
	.string "ZUre teknikak ahaltsuak dira, gero!$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "Ez da beharrezkoa izango\n"
	.string "MARTZIAL gogaitzea!\p"
	.string "Nik txikituko zaitut!$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "Baina… Nola?\n"
	.string "Nola galdu dut hain erraz?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "Ez dut porrota alferrik galduko.\n"
	.string "Entrenatzeko indarra emango dit!\p"
	.string "Noizbait GIMNASIOKO LIDER izango naiz…\p"
	.string "Ez, POKéMON LIGAKO TXAPELDUN\n"
	.string "bihurtuko naiz!$"

DewfordTown_Gym_Text_LauraIntro:
	.string "Ez pentsa erraz irabaziko didazunik!\n"
	.string "Ez da nire errua negar egiten baduzu!$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "Buaaaaaaaaa!\n"
	.string "Galdu egin dut!$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "Ilunpean borrokatzen dut, nire\n"
	.string "bihotza indartzeko.\p"
	.string "Baina horren ilun dagoenez, ezin dut\n"
	.string "inoiz MARTZIALEN aurpegia ikusi…$"

DewfordTown_Gym_Text_LilithIntro:
	.string "Ufufu…\n"
	.string "Ilunpean galduta al zabiltza?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "Aizu…\n"
	.string "Nik ez zintudan ezagutu nahi!$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "Galduta jarraituko duzula espero\n"
	.string "dut, eta hasieran agertuko zarela!$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "Itsasgizon baten benetako\n"
	.string "indarra erakutsiko dizut!$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "Nola gertatu ote da hau?\n"
	.string "Nik ez dut horrela galtzen normalean!$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "Ei, txo! Gure GIMNASIOKO LIDERRA\n"
	.string "ezagutzea merezi duzu.$"

DewfordTown_Gym_Text_CristianIntro:
	.string "Hemendik pasatzeko, ni garaitu\n"
	.string "beharko nauzu lehenengo!$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "Grrrrr!\n"
	.string "Indar handiegia duzu!$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "Irabazi egin didazu!\n"
	.string "Segi DOMINAREN bila!$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "MARTZIAL naiz!\n"
	.string "IHINTZIBARREKO GIMNASIOKO LIDERRA!\p"
	.string "Hemen inguruko olatu gogorretan hazi\n"
	.string "naiz, eta kobazulo ilun-ilunean ere\l"
	.string "zaildutakoa naiz!\p"
	.string "Nire aurka borrokatu nahi al zenuen?\n"
	.string "Ikus dezagun zure borrokarako ahalmena!$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "Uau, ene bada! Espero baino askoz\n"
	.string "zapla handiagoa eman didazu!\p"
	.string "Txikitu egin nauzu!\p"
	.string "Ongi, galdu egin dut.\n"
	.string "Tori GIMNASIOKO DOMINA hau!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER}(e)k UKABIL DOMINA jaso\n"
	.string "du MARTZIALENGANDIK.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "UKABIL DOMINAREKIN, 30. mailara arteko\n"
	.string "POKéMONEK, baita trukean jaso dituzunek\l"
	.string "ere, txit esan gabe obedituko dizute.\p"
	.string "Gainera, borrokaz kanpo DISTIRA\n"
	.string "MEa erabili ahal izango duzu.\p"
	.string "Nahi baduzu, erabili MAKINA\n"
	.string "TEKNIKO hau ere.$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "MT08 horrek INDARKETA du barruan.\p"
	.string "ERASOA eta DEFENTSA, biak igotzen\n"
	.string "dituen erasoa da.\p"
	.string "… … … … … …$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "MARTZIAL, GIMNASIOKO LIDERRA\n"
	.string "erregistratu duzu POKéNAVEAN.$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "ENTRENATZAILE guztiak txundituko\n"
	.string "dituen ekaitza sortuko duzu zuk,\l"
	.string "zure indar olatuarekin!$"

DewfordTown_Gym_Text_GymStatue:
	.string "IHINTZIBAR HERRIKO POKéMON GIMNASIOA$"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "IHINTZIBAR HERRIKO POKéMON GIMNASIOA\p"
	.string "MARTZIALEK ZIURTATUTAKO ENTRENATZAILEAK:\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "MARTZIAL: Olatuek atzera egiten badute\n"
	.string "ere, beti itzultzen dira urertzera.\p"
	.string "Zu bezalako olatu erraldoi trebea…\n"
	.string "Banekien itzuliko zinela!\p"
	.string "Erakutsi nolako tamaina\n"
	.string "hartu duzun!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "Uau!\n"
	.string "Berriro txikitu nauzu!$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "MARTZIAL: Borrokatzea sakona eta zabala da.\n"
	.string "Ezin duzu hondoa non dagoen ikusi.\l"
	.string "HOENNEKO itsasoa bezalakoa da!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "MARTZIAL: Olatuek atzera egiten badute\n"
	.string "ere, beti itzultzen dira urertzera.\p"
	.string "Zu bezalako olatu erraldoi trebea…\n"
	.string "Banekien itzuliko zinela!\p"
	.string "Zer? Borrokatu dezakeen\n"
	.string "POKéMON bakarra duzu.\p"
	.string "Sentitzen dut, baina, gutxienez bi\n"
	.string "POKéMONEKIN itzuli behar duzu.$"
