.set LOCALID_WALLY_ENTRANCE, 4

VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition:
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 2, 24
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 3, 24
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1::
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_WALLY_ENTRANCE
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer1
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2::
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_WALLY_ENTRANCE
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer2
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	copyobjectxytoperm LOCALID_WALLY_ENTRANCE
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
VictoryRoad_1F_EventScript_EntranceWally::
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

@ This Wally appears and remains at the exit after the Hall of Fame is entered
VictoryRoad_1F_EventScript_ExitWally::
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_RematchWally::
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert::
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy::
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn::
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
	.string "EKAITZ: Kaixo! {PLAYER}!\p"
	.string "Harritu egingo zinen ni hemen ikusita!\p"
	.string "Honaino iritsi naiz, eta guztia zuri\n"
	.string "esker izan da!\p"
	.string "{PLAYER}, zure aurka galdu izanak\n"
	.string "asko indartu nau!\p"
	.string "Baina ez dut gehiago galduko!\p"
	.string "Irabazi egingo dut! Niri indarra eta\n"
	.string "adorea eman zidaten POKéMONENGATIK!\p"
	.string "Ongi… Has gaitezen!$"

VictoryRoad_1F_Text_WallyEntranceDefeat:
	.string "Uau!\n"
	.string "{PLAYER}, indartsua zara, gero!$"

VictoryRoad_1F_Text_WallyPostEntranceBattle:
	.string "EKAITZ: Gaur ez dizut irabazi,\n"
	.string "{PLAYER}, baina egunen batean,\l"
	.string "harrapatu egingo zaitut!$"

VictoryRoad_1F_Text_WallyIntro:
	.string "EKAITZ: Kaixo! {PLAYER}!\p"
	.string "Azkenengotik indartu egin naiz!\n"
	.string "Erakutsi egin nahi nizuke, {PLAYER}!\p"
	.string "Ongi… Has gaitezen!$"

VictoryRoad_1F_Text_WallyDefeat:
	.string "Uau!\n"
	.string "{PLAYER}, indartsua zara, gero!$"


VictoryRoad_1F_Text_WallyPostBattle:
	.string "EKAITZ: Gaur ez dizut irabazi,\n"
	.string "{PLAYER}, baina egunen batean,\l"
	.string "harrapatu egingo zaitut…\p"
	.string "Eta POKéMON LIGARA aurkeztuko naiz!$"

VictoryRoad_1F_Text_EdgarIntro:
	.string "Pare bat aldiz iritsi naiz honaino,\n"
	.string "baina azken txanpa oso gogorra da…$"

VictoryRoad_1F_Text_EdgarDefeat:
	.string "Hemen bukatzen da nire ametsa berriro…$"

VictoryRoad_1F_Text_EdgarPostBattle:
	.string "Honaino iritsi zara. Segi horrela\n"
	.string "eta bilakatu zaitez TXAPELDUN!\l"
	.string "Norbait gai bada, zu zara!$"

VictoryRoad_1F_Text_AlbertIntro:
	.string "Ez naiz honaino iritsi orain galtzeko.\n"
	.string "Hori guztiz ezinezkoa da!$"

VictoryRoad_1F_Text_AlbertDefeat:
	.string "Ezinezkoa…\n"
	.string "Galdu egin al dut?$"

VictoryRoad_1F_Text_AlbertPostBattle:
	.string "Galdu egin dut…\p"
	.string "Horrek esan nahi du ez daukadala\n"
	.string "TXAPELDUN izateko behar dena…$"

VictoryRoad_1F_Text_HopeIntro:
	.string "Bide gogor eta itxuraz amaitezin honek\n"
	.string "zeozerrengatik du GARAIPEN izenean.$"

VictoryRoad_1F_Text_HopeDefeat:
	.string "Zure borroka estiloa izugarria da…$"

VictoryRoad_1F_Text_HopePostBattle:
	.string "TXAPELDUN bihurtzeko behar\n"
	.string "dena duzula dirudi.$"

VictoryRoad_1F_Text_QuincyIntro:
	.string "Zer da GARAIPENAREN BIDEA?\n"
	.string "Esango dizut irabazten baduzu!$"

VictoryRoad_1F_Text_QuincyDefeat:
	.string "Ongi!\n"
	.string "Ondo jokatuta!$"

VictoryRoad_1F_Text_QuincyPostBattle:
	.string "Hemendik seguru igarotzea; hori da\n"
	.string "POKéMON TXAPELDUNA izan nahi duen\l"
	.string "edozein ENTRENATZAILEREN azken erronka.\p"
	.string "Horregatik du izena GARAIPENAREN\n"
	.string "BIDEA.$"

VictoryRoad_1F_Text_KatelynnIntro:
	.string "Ez daukat ezer esateko honaino\n"
	.string "iritsi den norbaiti. Aurrera!$"

VictoryRoad_1F_Text_KatelynnDefeat:
	.string "A zer ezbeharra…$"

VictoryRoad_1F_Text_KatelynnPostBattle:
	.string "Pf, aurrera, segi bada.\n"
	.string "Ez zait axola.$"
