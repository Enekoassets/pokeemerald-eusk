Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_5
Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER}(e)k kode sekretua idatzi\n"
	.string "du atean.\p"
	.string "“TRIKIMAISUA nire bizitza da.”\n"
	.string "… … … … … … … …\p"
	.string "Atea ireki egin da!$"

Route110_TrickHousePuzzle6_Text_SophiaIntro:
	.string "Etxe bitxi bat zegoela entzun\n"
	.string "nuenean, ikustera etorri nintzen.$"

Route110_TrickHousePuzzle6_Text_SophiaDefeat:
	.string "ENTRENATZAILE indartsua aurkitu dut!$"

Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
	.string "Oso ndo ari naiz pasatzen leku\n"
	.string "honetan hara eta hona.\p"
	.string "Errepikatuko nukeen erronka da\n"
	.string "ezbairik gabe!$"

Route110_TrickHousePuzzle6_Text_BennyIntro:
	.string "Agian nire TXORI POKéMONEK hegan\n"
	.string "egin dezakete hormen gainetik…$"

Route110_TrickHousePuzzle6_Text_BennyDefeat:
	.string "Uau! Kakaztu egin dut!$"

Route110_TrickHousePuzzle6_Text_BennyPostBattle:
	.string "Beno… Tranpa egiten saiatzen ari\n"
	.string "nintzelako galduko nuen.$"

Route110_TrickHousePuzzle6_Text_SebastianIntro:
	.string "Ate birakari hauekin zorabiatzen\n"
	.string "ari naiz…$"

Route110_TrickHousePuzzle6_Text_SebastianDefeat:
	.string "Guztia jira eta bira ari da.\n"
	.string "Ezin dut gehiago…$"

Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "Zuri ez dizu batere eragiten.\n"
	.string "Edo ezkutatzen ari zara zure ondoeza?$"

