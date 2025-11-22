FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Zerbait gertatzen ari da,\n"
	.string "eta ez dut gustoko!\p"
	.string "Jende arraroa ikusi dut KOZMO\n"
	.string "IRAKASLEAREN etxe inguruan…$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "Eskualde hau meteoritoengatik\n"
	.string "izan da ezaguna betidanik.\p"
	.string "Diotenez, METEORO UR-JAUZIA meteorito\n"
	.string "baten kolpearekin sortu zen aspaldi.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "Ikusi! Begira hau!\n"
	.string "Hau nire AZURILL maitea da!\p"
	.string "Leuna eta bigun-biguna!$"

FallarborTown_Text_Azurill:
	.string "AZURILL: Rooreelooo.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "Egin diozu aurre SUARI, LABARANEKO\n"
	.string "GIMNASIOKO LIDERRARI?\p"
	.string "Neskaren aitona famatua zen.\n"
	.string "POKéMON LIGAKO ELITE LAUKOTEAN\l"
	.string "egon omen zen aspaldi.\p"
	.string "Ez nintzateke batere harrituko SUA\n"
	.string "bera ere ENTRENATZAILE aparta\l"
	.string "bihurtuko balitz.$"

FallarborTown_Text_BattleTentSign:
	.string "ARREKARA HERRIKO BORROKA DENDA\n"
	.string "“Elkar daitezela talderik onenak!”$"

FallarborTown_Text_TownSign:
	.string "ARREKARA HERRIA\n"
	.string "“Lorategi txikidun baserritar herria.”$"

FallarborTown_Text_MoveTutorSign:
	.string "ERASO TUTOREAREN ETXEA\n"
	.string "“POKéMONEI eraso berriak erakusten dizkiet.”$"

