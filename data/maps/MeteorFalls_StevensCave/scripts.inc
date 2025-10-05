.set LOCALID_STEVEN, 1

MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "MIKEL: Oh, uau, {PLAYER}{KUN}.\n"
	.string "Harrigarria, bazenekien ni non bilatu.\p"
	.string "Zuk, beno… agian harrien maniako\n"
	.string "bat soilik naizela uste duzu?\p"
	.string "Ez, ziur ez dela hala.\p"
	.string "ARREZIPOLISEKO ESPAZIO ZENTROAN\n"
	.string "elkarrekin egin genuen borroka.\p"
	.string "Jakin behar zenuke maila altuan\n"
	.string "egiten dudala borroka.\p"
	.string "Ongi, {PLAYER}{KUN}, gogorrenerako prestatu\n"
	.string "erronka bati aurre egin behar badiozu!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Zu…\n"
	.string "Ez nekien horren indartsua bilakatuko zinenik…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "MIKEL: Ondo pentsatuta, GRANITO\n"
	.string "KOBAZULOAN elkartu ginenetik,\l"
	.string "IHINTZIBARREN, hala pentsatu nuen.\p"
	.string "Espero nuen TXAPELDUNA bilakatuko\n"
	.string "zinela azkenean. Nire\p"
	.string "iragarpenak egia bihurtu ohi dira.\p"
	.string "Eta nora joango zara hemendik?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Fufufu, hori ezin dizut nik ere esan.$"

