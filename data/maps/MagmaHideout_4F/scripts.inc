.set LOCALID_GROUDON, 1
.set LOCALID_GRUNT_1, 2
.set LOCALID_GRUNT_2, 3
.set LOCALID_GRUNT_3, 4
.set LOCALID_TABITHA, 5
.set LOCALID_MAXIE, 6
.set LOCALID_GROUDON_SLEEPING, 7

MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_GROUDON_SLEEPING
	addobject LOCALID_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "Nik ere GROUDON ikusi nahi dut, baina\n"
	.string "ez didate haren buztana ere erakusten…\p"
	.string "Oso zapuztuta sentitzen naiz.\p"
	.string "Ai, ene! Ez nuen GROUDONEN\n"
	.string "inguruan hitzik esan behar!$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "Irabaztea ezinezkoa da norberaren\n"
	.string "burua ez badago lasai…$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "Ba al du buztanik GROUDONEK?$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "Kar-kar-kar!\n"
	.string "Laister! Laister!\l"
	.string "Gure helburua lortuko dugu!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grrr…\n"
	.string "HOnaino iritsi naiz eta hau, orain?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "MAGNO jauna!\n"
	.string "Kanpotar bat doa zugana!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "Oraindik ez da hau bukatu!\n"
	.string "Ez didazu horren erraz irabaziko!$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "Horren erraz irabazi al didazu?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "Ea ba, beste borroka bat…$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "Kar-kar-kar!\n"
	.string "Honaino iritsi zarenez, esan egingoo dizut!\p"
	.string "Hori da!\n"
	.string "Hor aurrean, GROUDON dago lozorroan!\p"
	.string "MAGNO GROUDONENGANA joan da\n"
	.string "duela segundu gutxi!\p"
	.string "Segituan esnatuko dugu!\n"
	.string "Kar-kar! Kar-kar-kar!$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Berriz galdu dut…\n"
	.string "Kar-kar…$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "…Nirekin denbora galdu bitartean,\n"
	.string "MAGNOK esnatuko zuen jada GROUDON…$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "MAGNO: GROUDON…\p"
	.string "Ezerk ezin zintuen esnatu zure\n"
	.string "magmaz inguratutako lozorrotik esnatu…\p"
	.string "ORBE URDIN hau da nahi zenuena.\n"
	.string "Ez al da hala?\p"
	.string "ORBE URDINA ekarri dizut.\n"
	.string "Esna zaitzala bere distirak!\p"
	.string "Eta erakutsi niri…\n"
	.string "Zure botere guztia!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "MAGNO: GROUDON!\n"
	.string "Zer gertatzen zaizu?\p"
	.string "Ez al zen ORBE URDINA giltza?\p"
	.string "GROUDON!\n"
	.string "Nora joan ote zara…$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "MAGNO: Zer, zu al zinen?\p"
	.string "Ikusi zaitut hemen inguruan, inork\n"
	.string "gonbiterik eman ez badizu ere…\p"
	.string "Ulertzen dut orain!\n"
	.string "Trikimailuren bat erabili duzu!$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "Zergatik zara horren hona\n"
	.string "POKéMONEKIN?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "MAGNO: Arrazoiren baten ondorioz\n"
	.string "egin du ihes GROUDONEK…\p"
	.string "Hori da esan nahi duzuna,\n"
	.string "ez al da hala?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Ufff…\n"
	.string "Ez nekiela uste zenuen?\p"
	.string "GROUDONEK ihes eginda, ez dago arrazoirik\n"
	.string "sumendi honetan geratzeko.\p"
	.string "GROUDONEN bila joango naiz, beraz,\n"
	.string "hementxe banatuko gara elkarrengandik!$"
