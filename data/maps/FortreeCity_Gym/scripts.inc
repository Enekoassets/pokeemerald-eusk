FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "Ei, zer moduz dago gure {PLAYER},\n"
	.string "etorkizuneko TXAPELDUNA?\p"
	.string "HAIZEA, ZUHAITZAGAKO GIMNASIOKO\n"
	.string "LIDERRAK POKéMON HEGALARIAK ditu.\p"
	.string "GIMNASIO honen amaieran dago zain,\n"
	.string "ate birakarien atzean.\p"
	.string "Aireratu nahi duten erronkari\n"
	.string "berrien zain dago!\p"
	.string "Ongi, segi aurrera!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "Lortu duzu!\n"
	.string "Aireratzea lortu duzu!$"

FortreeCity_Gym_Text_JaredIntro:
	.string "Ikusi TXORI POKéMONEN borroka\n"
	.string "estilo dotorea!$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "Zu…\n"
	.string "Indartsua zara, gero…$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "ENTRENATZAILEAK azkarrak izan behar\n"
	.string "dira espero ez denari aurre egiteko.\p"
	.string "Nahikoa azkarra al zara zu gure\n"
	.string "LIDERRARENGANAINO iristeko?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "TXORI POKéMONAK maite dituztenek\n"
	.string "GIMNASIO honen parte izan nahi dute.\p"
	.string "ZUHAITZAGAKO GIMNASIOKO partaide\n"
	.string "naizenez, ezin dut galdu!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "Karga handiegia izan da\n"
	.string "niretzako…$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "Mundua erraldoia da eta ENTRENATZAILE\n"
	.string "indartsu piloa dago.\p"
	.string "Entrenatzen jarraituko dut eta\n"
	.string "indartsuagoa izango naiz.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "Ez da beharrezkoa, HAIZEA, gure\n"
	.string "LIDERRA, zutaz arduratzea!\p"
	.string "Nahikoa naiz ni horretarako!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "HAIZEA, nik…\n"
	.string "Galdu egin dut!$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "HAIZEA polita da, eta indartsua.\n"
	.string "LIDER onena da!\p"
	.string "Lotsagorritu egin naiz…$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "HAIZEAK berak erakutsi zidan niri!\n"
	.string "Ez didazu erraz irabaziko!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "Garaitu egin naute…$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "HAIZEARI esker, ZUHAITZAGAKO\n"
	.string "jendea beldurrik gabe bizi da.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "HAIZEA borrokan ari denean, aurpegiak\n"
	.string "determinazioz egiten dio distira…\p"
	.string "Ez dizut utziko zuri halako\n"
	.string "gauza ederra ikusten!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "Uf!\n"
	.string "Ez dut lortu zu gelditzea.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "Kontuz ibili beharko duzu!\n"
	.string "Ez galdu arreta HAIZEARI begira\l"
	.string "edo txikitu egingo zaitu!$"

FortreeCity_Gym_Text_DariusIntro:
	.string "Hobe duzu mota askotako TXORI\n"
	.string "POKéMONAK daudela jakitea.\p"
	.string "Badakizu hori, ezta?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "Badakizu, bai!$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "Ados, garaitu egin nauzu, bai.\n"
	.string "Baina kontuz ibili! HAIZEAREN, gure\l"
	.string "LIDERRAREN POKéMONAK ikaragarriak dira.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "HAIZEA naiz. ZUHAITZAGAKO POKéMON\n"
	.string "GIMNASIOKO LIDERRA.\p"
	.string "TXORI POKéMONEKIN bat eginda,\n"
	.string "zeruak zeharkatu ditut…\p"
	.string "Borroka beldurgarrietan ere,\n"
	.string "beti atera gara garaile…\p"
	.string "Nire TXORI POKéMONEN koreografia\n"
	.string "dotorearen lekukoa izango zara!$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "Ez dut inoiz ikusi ENTRENATZAILE\n"
	.string "bat ni baino dotorezia handiagoz\l"
	.string "POKéMONAK gidatzen\p"
	.string "Zure trebeziaren sari gisan,\n"
	.string "har ezazu GIMNASIOKO DOMINA hau.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER}(e)k LUMA DOMINA jaso du\n"
	.string "HAIZEARENGANDIK.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "LUMA DOMINAREKIN, 70. mailara arteko\n"
	.string "POKéMONEK, baita trukean jaso dituzunek\l"
	.string "ere, zure aginduak beteko dituzte.\p"
	.string "Gainera, HEGALDIA Makina Ezkutua\n"
	.string "borrokatik kanpo erabili dezakezu.\p"
	.string "Eta hau…\n"
	.string "Opari bat da, nire partez.$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "MT40ek AIRE KOLPEA du barruan.\p"
	.string "Eraso honen abiadura…\n"
	.string "Ez dago saihestu dezakeen POKéMONIK.\p"
	.string "… … … … … …$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "HAIZEA GIMNASIOKO LIDERRA\n"
	.string "erregistratu duzu POKéNAVEAN.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Zure aurka galduta ere, TXORI\n"
	.string "POKéMONEI emanda jarraituko dut.$"

FortreeCity_Gym_Text_GymStatue:
	.string "ZUHAITZAGA HIRIKO POKéMON GIMNASIOA$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "ZUHAITZAGA HIRIKO POKéMON GIMNASIOA\p"
	.string "HAIZEAK ZIURTATUTAKO ENTRENATZAILEAK:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "HAIZEA: Gizakiok ezin diogu grabitatearen\n"
	.string "indarrari ihes egin.\p"
	.string "Baina bikaintasunaren bila arituz,\n"
	.string "aireratzea lor dezakegu!\p"
	.string "Zu goraino iritsi zara,\n"
	.string "TXAPELDUN goren bezala.\p"
	.string "Mesedez, utz iezadazu zure boterea\n"
	.string "ikusten hegan egin bitartean!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "Ez dut lortu zure altuerara iristea…$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "HAIZEA: Galdu badut ere, nire\n"
	.string "bihotzaren hegoak ez dira hautsi.\p"
	.string "Berriro altxa eta aireratuko\n"
	.string "naiz.\p"
	.string "Guztiz ziur nago!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "HAIZEA: Gizakiok ezin diogu grabitatearen\n"
	.string "indarrari ihes egin.\p"
	.string "Baina bikaintasunaren bila arituz,\n"
	.string "aireratzea lor dezakegu!\p"
	.string "Zu goraino iritsi zara,\n"
	.string "TXAPELDUN goren bezala.\p"
	.string "Mesedez, utz iezadazu zure boterea\n"
	.string "ikusten hegan egin bitartean!\p"
	.string "Ai, ene… POKéMON bakarra al\n"
	.string "duzu aldean?\p"
	.string "Mesedez, itzuli gutxienez bi\n"
	.string "POKéMONEKIN.$"
