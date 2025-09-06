SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "Ez dugu umemoko bat behar hemen!\n"
	.string "Joan zaitez etxera!$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "Etxera joan nahi dut…$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "Maila igoera bat izan nahi dut\n"
	.string "ERREKRUTEI aginduak emateko…$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "Urpeko hori… Ñimiñoa da barrutik.\n"
	.string "Mina dut leku guztietan!$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "Galtzeak min ematen dit!$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "Lapurtu genuen urpeko hori,\n"
	.string "benetan, a zer nolako ontzia.\l"
	.string "Estuegia da barrutik!$"

