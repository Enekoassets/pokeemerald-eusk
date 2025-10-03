PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "URREBARE eta PORTUONDO arteko itsasoan\n"
	.string "ur-laster oso bizi bat dago.\p"
	.string "SURF egitea erabakitzen baduzu, beste\n"
	.string "nonbait amaitu dezakezu.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "Begira, ez al da bikaina?\n"
	.string "Etxe hauek ur gainean daude!\p"
	.string "Hemen jaio nintzen!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "ZERUAREN ZUTABEA?\p"
	.string "…Ah, ziur hemendik aurrera jarraituta\n"
	.string "dagoen dorre altu-altu hortaz ari zarela.\p"
	.string "Ni zu banintz, ez nuke igoko.\n"
	.string "Beldurra ematen du horren gora igotzeak.\p"
	.string "URREBAREKO bizitza lasaia dut nik\n"
	.string "atsegin, itsasoaren maila berean.$"

PacifidlogTown_Text_TownSign:
	.string "URREBARE HERRIA\p"
	.string "“Goizeko eguzkiak uraren gainean\n"
	.string "irribarre egiten duen lekua.”$"

