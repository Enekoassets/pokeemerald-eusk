BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
	.string "Egingo al dute elkarrizketarik\n"
	.string "ENTRENATZAILE indartsuekin gaur?$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.string "Hemen jatetxe bat irekiko banu,\n"
	.string "diru asko egingo luke, ziur.$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
	.string "Ufff…\p"
	.string "Atseden hartu behar dut borroka\n"
	.string "bizi hauen ostean…\p"
	.string "Baina orain ere, estrategiak eta\n"
	.string "konboak pentsatzen jarraitu behar dut.$"

