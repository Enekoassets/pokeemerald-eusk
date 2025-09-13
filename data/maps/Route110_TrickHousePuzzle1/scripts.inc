Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER}(e)k kode sekretua idatzi\n"
	.string "du atean.\p"
	.string "“TRIKIMAISUA primerakoa da.”\n"
	.string "… … … … … … … …\p"
	.string "Atea ireki egin da!$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.string "Ebakiz eta moztuz iritsiko naiz\n"
	.string "helmugara ikasi berri dudan EBAKIAREKIN!$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.string "Zergatik zara horren serioa?$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.string "Ez naiz inoiz nekatuko ebaki\n"
	.string "eta mozteaz!$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.string "Etxe arraro honetara iritsi naiz\n"
	.string "nahigabe…$"

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "Eta galdu egin dut…$"

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.string "Bidea galdu, borroka galdu, eta orain\n"
	.string "are galduago nago… Ezin naiz atera…$"

Route110_TrickHousePuzzle1_Text_RobinIntro:
	.string "Baina, zein da TRIKIMAISUA?$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.string "Pentsamenduetan galduta, galdu egin dut!$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.string "Indartsua zara!\n"
	.string "Baina, nor zara zu?$"

