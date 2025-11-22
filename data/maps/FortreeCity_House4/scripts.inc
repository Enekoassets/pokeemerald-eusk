.set LOCALID_WINGULL, 3

FortreeCity_House4_MapScripts::
	.byte 0

FortreeCity_House4_EventScript_Woman::
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
	end

FortreeCity_House4_EventScript_Boy::
	lockall
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, FortreeCity_House4_EventScript_WingullReturned
	goto_if_set FLAG_WINGULL_SENT_ON_ERRAND, FortreeCity_House4_EventScript_WingullOnErrand
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_WINGULL_SENT_ON_ERRAND
	clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL
	applymovement LOCALID_WINGULL, FortreeCity_House4_Movement_WingullExit
	waitmovement 0
	removeobject LOCALID_WINGULL
	releaseall
	end

FortreeCity_House4_EventScript_WingullOnErrand::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_AskedWingullToRunErrand, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_EventScript_WingullReturned::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb, MSGBOX_DEFAULT
	giveitem ITEM_MENTAL_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_ReceivedMentalHerb::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToWingull, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_Movement_WingullExit:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	delay_8
	step_end

FortreeCity_House4_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox FortreeCity_House4_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House4_Text_BringsWorldCloserTogether:
	.string "POKéMONEKIN batera egonda, jendeak\n"
	.string "gero eta lagun gehiago egiten ditu.\p"
	.string "Eta horrek mundu osoa elkartzen du.\n"
	.string "Oso ederra iruditzen zait!$"

FortreeCity_House4_Text_GoBirdPokemon:
	.string "Hortxe!\n"
	.string "Aurrera, TXORI POKéMONAK!$"

FortreeCity_House4_Text_AskedWingullToRunErrand:
	.string "Kar-kar, nire WINGULLI enkargu\n"
	.string "bat egiteko eskatu diot.$"

FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb:
	.string "Ondo!\n"
	.string "Ongi etorri berriro, WINGULL!\p"
	.string "Nola? Zer da hau?\n"
	.string "Zer dauka atzaparretan?\p"
	.string "BELAR MENTAL bat?\n"
	.string "Hor nonbait jasoko zuen.\p"
	.string "Baina ez naiz ENTRENATZAILEA, beraz,\n"
	.string "zuretzat har dezakezu.$"

FortreeCity_House4_Text_FriendsFarAwayThanksToWingull:
	.string "Nire WINGULLI esker, urruti\n"
	.string "bizi diren lagunak ditut.$"

FortreeCity_House4_Text_Wingull:
	.string "WINGULL: Pihyoh!$"

