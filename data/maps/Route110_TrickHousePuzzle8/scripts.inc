Route110_TrickHousePuzzle8_MapScripts::
	.byte 0

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle8_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Keira::
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Leroy::
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER}(e)k kode sekretua idatzi\n"
	.string "du atean.\p"
	.string "“TRIKIMAISUA maite dut.”\n"
	.string "… … … … … … … …\p"
	.string "Atea ireki egin da!$"

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.string "Ez dira ENTRENATZAILE asko\n"
	.string "iritsi honaino.$"

Route110_TrickHousePuzzle8_Text_VincentDefeat:
	.string "ZU ere indartsua zarela esan nahi du…$"

Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.string "POKéMON LIGAKO TXAPELDUNA garaitu\n"
	.string "duzula? Hori gehiegi da!$"

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.string "Zorte handia duzu nire aurka\n"
	.string "borrokatzeko aukera izanda!$"

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.string "Hau ezin da egia izan!\n"
	.string "Ezi dut galdu!$"

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "Mirari bat da zuk niri irabazi izana.\n"
	.string "Harro egon zaitezke horretaz.$"

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.string "TRIKIMAILU ETXEKO erronkar zehar\n"
	.string "aurrera zoaz zu ere.$"

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.string "Ikusten dut…\n"
	.string "Estilo paregabea daukazu.$"

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.string "Zu bezalako norbait ikusita pozik\n"
	.string "jarri behar litzateke TRIKIMAISUA.$"

