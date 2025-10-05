MtPyre_4F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi::
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_AtsushiIntro:
	.string "Irakasle…\n"
	.string "Mesedez, ikusi nire aurrerapenak!$"

MtPyre_5F_Text_AtsushiDefeat:
	.string "Irakasle…\n"
	.string "Barkatu, mesedez!$"

MtPyre_5F_Text_AtsushiPostBattle:
	.string "Hobetzen dudan arte, nire irakaslea,\n"
	.string "hemen bego, ez da lasai egongo…$"

