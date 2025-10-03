PacifidlogTown_House1_MapScripts::
	.byte 0

PacifidlogTown_House1_EventScript_Man::
	msgbox PacifidlogTown_House1_Text_RegiStory, MSGBOX_NPC
	end

PacifidlogTown_House1_EventScript_Woman::
	msgbox PacifidlogTown_House1_Text_SixDotsOpenThreeDoors, MSGBOX_NPC
	end

PacifidlogTown_House1_Text_RegiStory:
	.string "HOENN eskualdean, hiru POKéMON daude,\n"
	.string "arrokaren, izotzaren eta altzairuaren\l"
	.string "boterea irudikatzen dutenak.\p"
	.string "Bakoitza kobazulo batean ezkutatuta\n"
	.string "omen dago.\p"
	.string "Hori da txikia nintzenean entzun\n"
	.string "nuen istorioa.$"

PacifidlogTown_House1_Text_SixDotsOpenThreeDoors:
	.string "“Sei puntuk hiru ate dituzte irekitzen.”\p"
	.string "Hori esan ohi zuen aitonak, baina ez\n"
	.string "dakit zer esan nahi zuen.$"

