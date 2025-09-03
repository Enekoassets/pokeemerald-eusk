SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
	.string "PIRO MENDIA…\p"
	.string "Tontorrean bi orbe daude, bata\n"
	.string "bestearen ondoan jarrita. Bazenekien?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
	.string "Bai, bi orbe elkarren ondoan…\p"
	.string "Biak batera ikustea…\n"
	.string "Lasaigarria da, nolabait…$"

SootopolisCity_House2_Text_OughtToVisitAndSee:
	.string "Hala al da?\n"
	.string "Agian bisitatu eta ikusi behar zenuke…$"

