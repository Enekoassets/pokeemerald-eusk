SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed:
	.string "Ohe bat da…\n"
	.string "Har dezagun atseden.$"

SSTidalRooms_Text_ColtonIntro:
	.string "Askotan joaten naiz UR-LILI HIRIRA.\p"
	.string "TXAPELKETETARA joatea oso atsegin\n"
	.string "dut, bazenekien?$"

SSTidalRooms_Text_ColtonDefeat:
	.string "Hori bai borroka dibertigarria!$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "Pozik jartzen naiz hurrengo TXAPELKETAN\n"
	.string "zein POKéMON egongo diren imajinatzen.\l"
	.string "Imajinatze horrek zirrara sortzen dit!$"

SSTidalRooms_Text_MicahIntro:
	.string "Indartsuak al dira zure lagunak?$"

SSTidalRooms_Text_MicahDefeat:
	.string "Indartsuak dira, alajaina.$"

SSTidalRooms_Text_MicahPostBattle:
	.string "Lagunek ez dute zertan gizakiak izan.\n"
	.string "Niretzat, POKéMONAK lagun bikainak dira!$"

SSTidalRooms_Text_ThomasIntro:
	.string "Gazte…\n"
	.string "Atea jo al duzu?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "Porrota onartu egin behar da,\n"
	.string "izurik eta urduritasunik gabe.$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "Inoiz ere ez haserretzea JAUN baten\n"
	.string "portaeraren parte da.$"

SSTidalRooms_Text_JedIntro:
	.string "EDGAR: Lotsa apur bat ematen dit honek, baina…\n"
	.string "gure maitasun indarra erakutsiko dizugu!$"

SSTidalRooms_Text_JedDefeat:
	.string "EDGAR: Ene…$"

SSTidalRooms_Text_JedPostBattle:
	.string "EDGAR: Lehen aldia da gure maitasun\n"
	.string "indarrak norbait garaitu ez duena!\l"
	.string "ENTRENATZAILE bikaina izango zara!$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "EDGAR: POKéMON bakarra al duzu?\n"
	.string "Ez al da bakartia hori?$"

SSTidalRooms_Text_LeaIntro:
	.string "LEA: Lotsa apur bat ematen dit honek, baina…\n"
	.string "gure maitasun indarra erakutsiko dizugu!$"

SSTidalRooms_Text_LeaDefeat:
	.string "LEA: Ai, ez!$"

SSTidalRooms_Text_LeaPostBattle:
	.string "LEA: Ezin dut sinetsi!\n"
	.string "Gure maitasun indarrak porrot egin du…\l"
	.string "ENTRENATZAILE bikaina izango zara!$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "LEA: Borrokatu nahi nuen…\n"
	.string "Baina ez dituzu bi POKéMON ere…$"

SSTidalRooms_Text_GarretIntro:
	.string "Ei, une egokian iritsi zara.\p"
	.string "Aspertuta nago.\n"
	.string "Zuk entretenituko nauzu.$"

SSTidalRooms_Text_GarretDefeat:
	.string "…Hori nahikoa izan da.$"

SSTidalRooms_Text_GarretPostBattle:
	.string "Agian Aitari niretzako yate bat\n"
	.string "erosteko eskatuko diot.\l"
	.string "Ni eta nire POKéMONENTZAKO yatea!$"

SSTidalRooms_Text_NaomiIntro:
	.string "Zu bai zu ENTRENATZAILE maitagarria.\n"
	.string "Terik nahi al duzu?\l"
	.string "Edo nahiago duzu borrokatu?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "Ikusten dut, bai.\n"
	.string "Aktiboa zara, gero.$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "Luxuzko gurutzaontzi batean bidaiatzea\n"
	.string "ederra da, dudarik gabe…\p"
	.string "Baina, esango nuke HOENN ferryan\n"
	.string "ikusteak bere xarma duela.$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "Em… Kaixo! Ni… Ez nabil azpikeriatan!\n"
	.string "Em… Tori hau, zuretzat! Doan!\p"
	.string "Nik… Egia esan ez diot inori LAPURTU!\n"
	.string "Ez nuke inolaz ere hori egingo!\l"
	.string "Benetan! Erabili dezakezu!$"

SSTidalRooms_Text_ExplainSnatch:
	.string "LAPURRETAK eraso batzuen efektu\n"
	.string "positiboak lapurtzen ditu, kide edo\l"
	.string "etsai batek erabili aurretik.$"

