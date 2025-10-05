MtPyre_5F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro:
	.string "Maite ditut gauza beldurgarriak…\n"
	.string "Gaixotasun bat bezala da…\p"
	.string "Hemen nagoenean…\n"
	.string "Beldurrez dardarka egoten naiz…$"

MtPyre_4F_Text_TashaDefeat:
	.string "Galtzea, gorroto dut…$"

MtPyre_4F_Text_TashaPostBattle:
	.string "Gauza izugarriak ikusi nahi ditut…\n"
	.string "Ezin naiz joan…\p"
	.string "Gelditu…\n"
	.string "Ez al zara nirekin geldituko?$"

