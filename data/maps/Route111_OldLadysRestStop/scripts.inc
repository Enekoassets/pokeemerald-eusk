Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady::
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest::
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_DeclineRest::
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_RestUpHere:
	.string "Ai, maitea, maitea.\n"
	.string "Ez al daude zure POKéMONAK akituta?\p"
	.string "Nahi baduzu, deskantsatu hemen.\n"
	.string "Ideia bikaina da! Hori egin behar zenuke.$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
	.string "Hori da.\n"
	.string "Lasai hartu eta deskantsatu!$"

Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest:
	.string "Ai, maitea, maitea.\n"
	.string "Oraindik nekatuta al daude zure POKéMONAK?\p"
	.string "Berriz deskantsatu behar zenuke hemen.\n"
	.string "Ideia bikaina da. Hori egin behar zenuke.$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy:
	.string "Benetan?\n"
	.string "Ez zenuke lotsarik izan behar.$"

