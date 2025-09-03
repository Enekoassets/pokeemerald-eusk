VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "EKAITZ: Zure aurka galdu dut, {PLAYER},\n"
	.string "baina jada ez nago triste.\p"
	.string "Bizitzan helburu berri bat daukadalako.\n"
	.string "Nire RALTSEKIN batera, POKéMON\l"
	.string "GIMNASIOETAKO erronkak garaitu eta\l"
	.string "ENTRENATZAILE izugarria bihurtuko naiz.\p"
	.string "Egon zaitez adi, {PLAYER}.\n"
	.string "Zu baino indartsuagoa bihurtuko naiz.\p"
	.string "Lortzen dudanean, borroka baterako\n"
	.string "erronka botako dizut.$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "EKAITZ: Egon zaitez adi, {PLAYER}.\n"
	.string "Zu baino indartsuagoa bihurtuko naiz.\p"
	.string "Lortzen dudanean, borroka baterako\n"
	.string "erronka botako dizut.$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "OSABA: Aizu! {PLAYER}{KUN}!\n"
	.string "EKAITZ hurrengo gelan dago.\p"
	.string "Baina, ene, zerbait kontatu\n"
	.string "behar dizut.\p"
	.string "Ingurune natural hau izugarri\n"
	.string "ona da EKAITZEN osasunarentzat.\p"
	.string "Agian ez da ingurunea bakarrik.\n"
	.string "Agian POKéMONAK dira mutikoari\l"
	.string "itxaropena ematen diotenak.$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "EKAITZEK ihes egin du…\n"
	.string "Bakar-bakarrik joan da…$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "OSABA: Hala al da?\n"
	.string "EKAITZ horren urrutira iritsi da\l"
	.string "bera bakarrik…\p"
	.string "Beno, bere merezimendua aitortu behar\n"
	.string "diot, nire anaia txikiaren semea da.$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "KLARA: Zu nor zara?\n"
	.string "Ah, bai, badakit!\p"
	.string "Zu zara EKAITZEK kontatu digun\n"
	.string "{PLAYER} hori.\p"
	.string "EKAITZEN lehengusina naiz.\n"
	.string "Pozten naiz zu ezagututa!\p"
	.string "Uste dut EKAITZ askoz biziago eta\n"
	.string "osasuntsuago dagoela hona etorri ginenetik.$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "KLARA: Ez kezkatu EKAITZENGATIK.\n"
	.string "Ondo egongo da.\p"
	.string "Ezagutzen dut nire lehengusu txikia,\n"
	.string "POKéMONAK ditu berekin, gainera.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "Zuri esker, egunero ikusi\n"
	.string "dezaket nire neskalaguna.\l"
	.string "Pozik? Izugarrik pozik, bai!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "Nire alabaren mutil-laguna oso\n"
	.string "mutil sutsu eta zentratua da.\p"
	.string "Nire alaba ikusi ahal izateko, tunel\n"
	.string "bat zulatzen aritu da gelditu gabe.\p"
	.string "Nire alaba pixka bat kezkatuta dago,\n"
	.string "beraz, askotan joan da tunelera.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "Izugarria da. Nire alabaren mutil-laguna\n"
	.string "eskuarekin ari zen tunela zulatzen!\p"
	.string "Sinestezina da!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "EKAITZI zerbait gertatuko balitzaio,\n"
	.string "ez nintzateke PETALOREN bizi diren bere\l"
	.string "gurasoei aurpegira begiratzeko ere…$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "EKAITZ ITZELETAN zegoela?\p"
	.string "PETALOREN bizi diren bere gurasoak\n"
	.string "asko harrituko lirateke hori entzunda!$"

