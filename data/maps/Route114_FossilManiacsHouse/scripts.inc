Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "Nire anaia nagusia FOSIL MANIAKOA da…\n"
	.string "FOSILAK maite dituen mutil jatorra da…\p"
	.string "Zuloak egitea ere atsegin du…\n"
	.string "Zulo hau berak egin zuen…\p"
	.string "Hau zuretzat, zuk ere nire anaiak\n"
	.string "bezala ZULATU ahal izateko…$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "POKéMON batek ZULAKETA erabiltzen badu\n"
	.string "koba batean, hasierara itzuliko zara…$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "Forma bereziko arrokaz beteta\n"
	.string "dago erakuslekua…$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "LURRAZALAREN GERUZAK…\n"
	.string "NOLA EURIAK LURRA LANTZEN DUEN…\l"
	.string "HARRIAK, LURRA ETA ARROKAK…\p"
	.string "Liburuz gainezka dago.$"

