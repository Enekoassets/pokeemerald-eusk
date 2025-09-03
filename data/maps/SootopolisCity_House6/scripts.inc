SootopolisCity_House6_MapScripts::
	.byte 0

SootopolisCity_House6_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WAILMER_DOLL, SootopolisCity_House6_EventScript_ReceivedWailmerDoll
	msgbox SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, SootopolisCity_House6_EventScript_DeclineWailmerDoll
	msgbox SootopolisCity_House6_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	givedecoration DECOR_WAILMER_DOLL
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_House6_EventScript_NoRoomForWailmerDoll
	setflag FLAG_RECEIVED_WAILMER_DOLL
	release
	end

SootopolisCity_House6_EventScript_DeclineWailmerDoll::
	msgbox SootopolisCity_House6_Text_DontWantThisDoll, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_ReceivedWailmerDoll::
	msgbox SootopolisCity_House6_Text_LovePlushDolls, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_NoRoomForWailmerDoll::
	bufferdecorationname STR_VAR_2, DECOR_WAILMER_DOLL
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	msgbox SootopolisCity_House6_Text_IllHoldItForYou, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll:
	.string "Kaixo! Aspaldian izan dugun lehen\n"
	.string "gonbidatua zara.\p"
	.string "Eguna alaitu didazunez, WAILMERREN\n"
	.string "PANPINA bat emango dizut.$"

SootopolisCity_House6_Text_TakeGoodCareOfIt:
	.string "Ondo zaindu, aizu!$"

SootopolisCity_House6_Text_IllHoldItForYou:
	.string "Zer, nahi duzu, baina ez oraintxe?\n"
	.string "Ongi, zuretzat gordeko dut.$"

SootopolisCity_House6_Text_DontWantThisDoll:
	.string "Ziur al zaude?\n"
	.string "Ez duzu PANPINA hau nahi?$"

SootopolisCity_House6_Text_LovePlushDolls:
	.string "Maite ditut PANPINAK!$"

