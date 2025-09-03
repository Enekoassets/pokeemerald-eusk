.set LOCALID_MATT, 1
.set LOCALID_SUBMARINE, 4

AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_MATT
	setvar VAR_0x8009, LOCALID_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "Kar-kar-kar…\p"
	.string "Honaino iritsi zara, e?\n"
	.string "Gutxietsi egin zaitugu!\p"
	.string "Baina nahikoa da!\p"
	.string "Orain arteko ERREKRUTAK baino askoz\n"
	.string "indartsuagoa naiz ni.\p"
	.string "Ez naiz denbora irabazten ari.\n"
	.string "Txikitu egingo zaitut!$"

AquaHideout_B2F_Text_MattDefeat:
	.string "Kar-kar-kar…\n"
	.string "Nik ere galdu…$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "Kar-kar-kar!\p"
	.string "Zurekin jolasten ari nintzen bitartean,\n"
	.string "NAGUSIA guztiz prestatu da!$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "Kar-kar-kar!\p"
	.string "NAGUSIA ur azpiko kobazuloren\n"
	.string "batera bidean dago jada!\p"
	.string "Bere bila joatekotan, UR-LILI baino\n"
	.string "urrutiago dagoen itsaso handi zabalean\l"
	.string "bilatu beharko duzu.\p"
	.string "Baina aurkituko al duzu garaiz?\n"
	.string "Kar-kar-kar!$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "Buaaa, nazkatu naiz itxaroten!\n"
	.string "Borroka bat zor didazu, aizu!$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "Itxaroten nazkatuta…\n"
	.string "Galdu eta txikituta…$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "NAGUSI…\n"
	.string "Nahikoa izan ote da hau?$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "Teleportatze panelak, EZKUTALEKUKO\n"
	.string "tresna harrigarriena dira!\p"
	.string "Ez dakizu non zauden ere,\n"
	.string "ez da hala?\p"
	.string "Etsaia nekatu eta harritu, eta ondoren\n"
	.string "txikitu! Hori da gure plana!$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "Zer gertatzen zaizu?\n"
	.string "Ez zaude batere nekatuta!$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "Honek zera gogorarazi dit… Ez dakit\n"
	.string "non utzi nuen MASTER BALLA.\p"
	.string "Ez badut ondo zaintzen, NAGUSIAK\n"
	.string "txikitu egingo nau…$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "AQUA TALDERA sartu nintzenea, ikasi\n"
	.string "behar izan nuen lehen gauza panelak\l"
	.string "nola zeuden konektatuta izan zen.$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "Okupatuegi egon naiz teleportatze\n"
	.string "panelen gainean…$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "Nola borrokatu hobeto ikasi\n"
	.string "beharko dut orain…$"
