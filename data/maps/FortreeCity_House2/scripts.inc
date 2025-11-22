FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
	.string "Jendea… POKéMONAK…\p"
	.string "Beraien botere ezkutuak naturan\n"
	.string "bizita azaleratzen dira…$"

FortreeCity_House2_Text_CoinInWhichHand:
	.string "Utzi emakume zahar honi zure botere\n"
	.string "ezkutua esnatu den neurtzen…\p"
	.string "Txanpon bat daukat eskuan.\p"
	.string "Esan, bada: eskuineko eskuan jarri\n"
	.string "dut? Edo ezkerrekoan?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "Ene! Bai, zuzena da!\p"
	.string "Berriro egin dezagun.\p"
	.string "Zein eskutan daukat txanpona?\n"
	.string "Eskuinean edo ezkerrean?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "Ene! Bai, zuzena da!\p"
	.string "Berriro egin dezagun.\p"
	.string "Zein eskutan daukat txanpona?\n"
	.string "Eskuinean edo ezkerrean?$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.string "Ene! Bikain!\n"
	.string "Zure botere ezkutua esnatu da!\p"
	.string "Hortxe, tori hau eta esnarazi zure\n"
	.string "POKéMONAREN botere ezkutua.$"

FortreeCity_House2_Text_ExplainHiddenPower:
	.string "BOTERE EZKUTUA POKéMONAREN arabera\n"
	.string "aldatzen den erasoa da.$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "Ez, pena.\n"
	.string "Ez duzu asmatu.$"

