.set LOCALID_KYOGRE, 1
.set LOCALID_ARCHIE, 2
.set LOCALID_MAXIE, 3
.set LOCALID_GRUNT_1, 4
.set LOCALID_GRUNT_2, 5
.set LOCALID_KYOGRE_SLEEPING, 7

SeafloorCavern_Room9_MapScripts::
	.byte 0

SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre::
	lockall
	setvar VAR_0x8004, LOCALID_ARCHIE
	setvar VAR_0x8005, LOCALID_MAXIE
	setvar VAR_0x8006, LOCALID_GRUNT_1
	setvar VAR_0x8007, LOCALID_GRUNT_2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, SeafloorCavern_Room9_Movement_Delay32
	waitmovement 0
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SeafloorCavern_Room9_Text_ArchieHoldItRightThere, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8004
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieSoItWasYou, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieBeholdKyogre, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieYouMustDisappear, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHIE, SeafloorCavern_Room9_Text_ArchieDefeat
	msgbox SeafloorCavern_Room9_Text_ArchieWithThisRedOrb, MSGBOX_DEFAULT
	setweather WEATHER_NONE
	doweather
	special Script_FadeOutMapMusic
	waitstate
	msgbox SeafloorCavern_Room9_Text_RedOrbShinesByItself, MSGBOX_DEFAULT
	special WaitWeather
	waitstate
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 16, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	closemessage
	setvar VAR_RESULT, 0
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_KYOGRE_SLEEPING
	addobject LOCALID_KYOGRE
	waitstate
	delay 60
	applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
	waitmovement 0
	removeobject LOCALID_KYOGRE
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	setvar VAR_0x8004, LOCALID_ARCHIE
	setvar VAR_0x8005, LOCALID_MAXIE
	setvar VAR_0x8006, LOCALID_GRUNT_1
	setvar VAR_0x8007, LOCALID_GRUNT_2
	msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
	playse SE_PC_LOGIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
	closemessage
	playse SE_PC_OFF
	delay 20
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8005
	addobject VAR_0x8006
	addobject VAR_0x8007
	applymovement VAR_0x8007, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8006, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieArrive
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x8004, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_Delay48
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty, MSGBOX_DEFAULT
	msgbox SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieExit
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieExit
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieComeOnPlayer, MSGBOX_DEFAULT
	setvar VAR_ROUTE128_STATE, 1
	setvar VAR_SOOTOPOLIS_CITY_STATE, 1
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	clearflag FLAG_HIDE_ROUTE_128_ARCHIE
	clearflag FLAG_HIDE_ROUTE_128_MAXIE
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setvar VAR_STEVENS_HOUSE_STATE, 2
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
	setflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_ROUTE128, 38, 22
	waitstate
	releaseall
	end

SeafloorCavern_Room9_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_Unused1:
	walk_left
	walk_left
	step_end

SeafloorCavern_Room9_Movement_ArchieListenMessage:
	walk_left
	delay_16
	step_end

SeafloorCavern_Room9_Movement_Unused2:
	walk_right
	step_end

SeafloorCavern_Room9_Movement_ArchieExit:
	face_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	walk_in_place_faster_right
	step_end

SeafloorCavern_Room9_Movement_KyogreApproach:
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

SeafloorCavern_Room9_Movement_KyogreExit:
	slide_up
	slide_up
	step_end

SeafloorCavern_Room9_Movement_MaxieArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_MaxieExit:
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_MagmaGruntArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_Delay32:
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Text_ArchieHoldItRightThere:
	.string "AKILES: Geldi hor.$"

SeafloorCavern_Room9_Text_ArchieSoItWasYou:
	.string "AKILES: Fufufu…\n"
	.string "Zu zinen, azkenean.$"

SeafloorCavern_Room9_Text_ArchieBeholdKyogre:
	.string "AKILES: Begira!\p"
	.string "Kontenplatu KYOGRE, lozorroan dagoen\n"
	.string "antzinako POKéMONAREN edertasuna!\p"
	.string "Luze itxaron dut egun hau\n"
	.string "iritsi zedin…$"

SeafloorCavern_Room9_Text_ArchieYouMustDisappear:
	.string "AKILES: Harrituta nago, ez dakit\n"
	.string "nola jarraitu nauzun honaino.\p"
	.string "Baina hori guztia amaitu da.\p"
	.string "Nire ametsa egia bihurtu dadin,\n"
	.string "desagertu egin behar zara, orain!$"

SeafloorCavern_Room9_Text_ArchieDefeat:
	.string "Zer?!\n"
	.string "Zu bezalako umemoko baten aurka galdu dut?!$"

SeafloorCavern_Room9_Text_ArchieWithThisRedOrb:
	.string "AKILES: Fufufu…\p"
	.string "Onartu beharra dut. Benetan talentu\n"
	.string "izugarria daukazu.\p"
	.string "Baina!\n"
	.string "Nirea da hau azkenean!\p"
	.string "ORBE GORRI honekin, KYOGRE…$"

SeafloorCavern_Room9_Text_RedOrbShinesByItself:
	.string "ORBE GORRIA bat-batean distira\n"
	.string "egiten hasi da!$"

SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo:
	.string "AKILES: Zer?!\p"
	.string "Ez dut ezer egin.\n"
	.string "Zergatik hasi da ORBE GORRIA…\p"
	.string "Nora joan da KYOGRE?$"

SeafloorCavern_Room9_Text_ArchieAMessageFromOutside:
	.string "AKILES: Zer? Gure kanpoko kideek\n"
	.string "mezu bat bidali didate…$"

SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard:
	.string "AKILES: Bai, esan?\p"
	.string "Hm…\n"
	.string "Zaparrada izugarria hasi dela?\p"
	.string "Ongi… Hala gertatu behar zen.\n"
	.string "Horregatik esnatu dugu KYOGRE,\l"
	.string "itsasoa handitzeko AQUA TALDEAREN\l"
	.string "ametsa egia bihurtzeko.\p"
	.string "Zer?!\p"
	.string "Espero baino askoz euri gehiago\n"
	.string "ari duela? Arriskuan al zaude?\p"
	.string "Hori ezin da izan…\n"
	.string "Ezinezkoa da…\p"
	.string "Mantendua posizioa eta joan\n"
	.string "egoera azaltzen!$"

SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear:
	.string "AKILES: Zerbait gaizki doa…\p"
	.string "ORBE GORRIAK KYOGRE esnatu\n"
	.string "eta kontrolatu behar zuen…\p"
	.string "Baina… Zergatik?\n"
	.string "Zergatik desagertu da KYOGRE?\p"
	.string "Zergatik?!$"

SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought:
	.string "MAGNO: Zer egin duzu?\p"
	.string "AKILES… KYOGRE esnatu duzu azkenean,\n"
	.string "ezta?\p"
	.string "Zer gertatuko da zaparra hau ez\n"
	.string "baldin bada inoiz gelditzen?\p"
	.string "Planetako lur guztia itsaso\n"
	.string "geldiezinean urperatuko da…$"

SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty:
	.string "AKILES: Ze-zer?!\n"
	.string "Ez zaitez harropuztu nire aurrean!\p"
	.string "Ez al zarete zuek, TEAM MAGMAKOAK,\n"
	.string "GROUDON haserretu dutenak?\p"
	.string "ORBE GORRI hau dudan bitartean,\n"
	.string "KYOGRE kontrolatzeko gai izango naiz…\p"
	.string "Kontrolatzeko gai izan behar nuke…$"

SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue:
	.string "MAGNO: Ez dugu denborarik hemen\n"
	.string "liskarrean aritzeko!\p"
	.string "Atera kanpora eta ikusi zeuk!\p"
	.string "Ikusi ea egin duzuna desiatzen\n"
	.string "genuen mundua den!$"

SeafloorCavern_Room9_Text_MaxieComeOnPlayer:
	.string "MAGNO: {PLAYER}, goazen, zuk ere\n"
	.string "hemendik atera behar duzu!$"
