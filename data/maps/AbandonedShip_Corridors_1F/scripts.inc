AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
	.string "Grazia ematen al dizu nire flotagailua\n"
	.string "ontzi barruan jantzita edukitzeak?$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.string "Ene, gehiagi izan da hau!$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.string "Ez da erraza POKé BALLAK jaurtitzea\n"
	.string "flotagailua eskuan edukita!$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "Ez al da dibertigarria hau?\n"
	.string "Gustura nago soilik hemen egonda!$"
