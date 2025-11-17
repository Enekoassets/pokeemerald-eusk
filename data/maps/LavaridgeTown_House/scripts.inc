LavaridgeTown_House_MapScripts::
	.byte 0

LavaridgeTown_House_EventScript_OldMan::
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LavaridgeTown_House_Text_WifeWarmingEggInHotSprings:
	.string "Nire emaztea ARRAUTZA bat epeltzen ari\n"
	.string "da ur termaletan. Horixe esan dit.\p"
	.string "Bi POKéMON utzi zituen HAZTEGIAN.\n"
	.string "Eta ARRAUTZA hori aurkitu zuten!$"

LavaridgeTown_House_Text_Zigzagoon:
	.string "ZIGZAGOON: Pshoo!$"

