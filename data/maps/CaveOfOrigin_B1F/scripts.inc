.set LOCALID_WALLACE, 1

CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "Zu zara beraz {PLAYER}{KUN}?\n"
	.string "Ezagun ditut zure abenturak.\p"
	.string "Nire izena UREDER da.\p"
	.string "ARREZIPOLISEKO GIMNASIOKO LIDERRA\n"
	.string "nintzen, baina zerbait gertatu zen.\p"
	.string "Orain, nire irakasle XALANT\n"
	.string "geratu da GIMNASIOA zaintzen.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "GROUDON eta KYOGRE, sarraskia sortzen\n"
	.string "ari diren bi POKéMONAK, antzina-\l"
	.string "antzinako POKéMONAK dira.\p"
	.string "Baina ez daude bi antzinako\n"
	.string "POKéMON soilik.\p"
	.string "Beste bat dago hor nonbait.\p"
	.string "Lekuren batean, oso antzinako\n"
	.string "POKéMON bat dago, RAYQUAZA.\p"
	.string "Elezaharrak dio RAYQUAZA izan\n"
	.string "zela borrokan dauden biak lasaitu\l"
	.string "zituena, aspaldian.\p"
	.string "Baina RAYQUAZA non dagoen, hori\n"
	.string "nik ere ez dakit…$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "UREDER: {PLAYER}{KUN}, ba al dakizu\n"
	.string "non dagoen orain RAYQUAZA?\p"
	.string "Hala bada, esan, mesedez.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "UREDER: HASIERA KOBAZULOAN?\p"
	.string "Hementxe bertan dago eta!\n"
	.string "Hori baino gehiago behar dut!\p"
	.string "Mesedez, pentsatu ondo non egon\n"
	.string "daiteken RAYQUAZA oraintxe bertan.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "UREDER: PIRO MENDIAN?\p"
	.string "Baina horko emakume helduarekin hitz\n"
	.string "egin dudanean, ez du halakorik aipatu.\p"
	.string "Ez dut uste emakumean ezer ezkutatuko\n"
	.string "lidakeenik, zinez…\p"
	.string "{PLAYER}{KUN}, pentsa dezakezu kontuz\n"
	.string "non egon daitekeen?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "UREDER: Zer? Ez zarela gogoratzen?\n"
	.string "Hmm… Hori arazo latza da…\p"
	.string "Ezin duzu inolaz ere gogoratu?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "UREDER: ZERUAREN ZUTABEAN?\p"
	.string "Hori da!\n"
	.string "ZERUAREN ZUTABEAN egongo da, ziur!\p"
	.string "{PLAYER}{KUN}, ez dezagun denbora gal!\n"
	.string "ZERUAREN ZUTABERA joango gara oraintxe!$"

