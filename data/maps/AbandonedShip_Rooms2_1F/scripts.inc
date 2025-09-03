AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "DANEL: Altxor bila ari eta\n"
	.string "ENTRENATZAILE bat aurkitu!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "DANEL: Batera lan eginda ere ezin\n"
	.string "izan dugu irabazi…$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "DANEL: Ezin dugu altxorrik aurkitu…\n"
	.string "Beste norbait etorri ote da lehenago?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "DANEL: Ez dituzu bi POKéMON ere.\n"
	.string "Horrela ezin diguzu erronka bota.$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "KIRA: Nola?\n"
	.string "Altxor bila ari gara. Baina\l"
	.string "ENTRENATZAILE bat aurkitu dugu!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "KIRA: Uau, zeinen indartsua!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "KIRA: Non ote daude altxorrak?\p"
	.string "Jada erabaki dut zer erosiko dudan\n"
	.string "altxorra aurkitzen dugunean!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "KIRA: Zer, ez al dituzu bi POKéMON?\n"
	.string "Beste batean borrokatu beharko dugu!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "KIRA: Oso haserre jarri nauzu!\n"
	.string "Erregistratu egingo zaitut horregatik!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "DANEL: Altxor bila aritu\n"
	.string "gara orain arte.\p"
	.string "Gure POKéMONAK ere indartu egin dira.\n"
	.string "Erakutsi egingo dizkizugu, bai?$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "DANEL: Beti bezain indartsu!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "DANEL: Ez dugu altxorrik aurkitu,\n"
	.string "POKéMON borrokan ere galdu…\p"
	.string "Etxera joan nahi dut… Baina esaten\n"
	.string "badiot, haserretu egiten zait…$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "DANEL: Ez dituzu bi POKéMON ere.\n"
	.string "Horrela ezin diguzu erronka bota.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "KIRA: Zer? Berriro etorri zara!\p"
	.string "Gu bezalaq, zu ere altxor bila ari\n"
	.string "zara oraindik, ez da hala?\p"
	.string "Zer iruditzen galtzaileak altxor\n"
	.string "bila aritzeari utzi behar badio?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "KIRA: Ene, berriz galdu dugu…$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "KIRA: Ez gara hemendik joango gure\n"
	.string "POKéMONAK gehiago hazi eta hemengo\l"
	.string "altxorrak aurkitu arte!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "KIRA: Zer, ez al dituzu bi POKéMON?\n"
	.string "Beste batean borrokatu beharko dugu!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "Ez naiz ona igerian,\n"
	.string "baina bai borrokan!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "Ups.\n"
	.string "Ez da uste bezala atera hori.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "Itsasontzi honetan oinutsik\n"
	.string "ibiltzea nazkagarria da.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "Indarra eta errukia… Horiek dira\n"
	.string "ENTRENATZAILE baten altxorrak!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "Bai, zugan dagoen zerbaitek\n"
	.string "distira egiten du.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "Ontziko gelaren batean, zerbait\n"
	.string "distiratsua ikusi nuen.$"
