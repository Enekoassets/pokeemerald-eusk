SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.string "Nor zara?\n"
	.string "Nondik etorri zara?$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "Galdu egin dut…$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "Ez dakit nondik atera!\p"
	.string "Ez nago beldurtuta. Ez nahastu!$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "Nor zara?\n"
	.string "Nora zoazela uste duzu?$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "Ezin izan dut irabazi!$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "Nire kideak urpekoan ahaztu\n"
	.string "du mapa!\p"
	.string "Ez du ezertarako balio!$"

