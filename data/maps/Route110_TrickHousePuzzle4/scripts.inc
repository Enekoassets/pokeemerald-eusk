Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER}(e)k kode sekretua idatzi\n"
	.string "du atean.\p"
	.string "“TRIKIMAISUA itzela da.”\n"
	.string "… … … … … … … …\p"
	.string "Atea ireki egin da!$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "Hau guztia gehiegi da pentsatzeko.\n"
	.string "Borrokatu nahi nuen soilik!$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "Galdu badut ere, ikaragarri\n"
	.string "atsegin dut borrokatzea!$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "Ez al zaude ados? Edozein lekutara\n"
	.string "nindoake, bertan ENTRENATZAILEAK baleude.$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "Bua! Halako haitzek, hatz\n"
	.string "bakarrarekin ken ditzaket paretik!$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "Harriak bultza bai, baina ezin dut\n"
	.string "puzlea argitu…$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "Ez da nahikoa izaten indarra…\n"
	.string "Burua erabili behar da. Izan argia!$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "TRIKIMAILUEN ETXEA gero eta zailagoa\n"
	.string "bihurtzen ari da, ezta?$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "Aaak!$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "Iritsi al da inor amaierara?$"

