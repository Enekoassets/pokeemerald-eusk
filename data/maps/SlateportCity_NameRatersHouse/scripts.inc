SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Kaixo, kaixo! EZIZEN INSPEKTOREA naiz!\n"
	.string "Izenen etorkizun igarlea, alajaina!\p"
	.string "Asko gustatuko litzaidake zure\n"
	.string "POKéMONAREN ezizena aztertzea.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Zein POKéMONEN ezizena\n"
	.string "aztertu behar nuke?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Hmmm… {STR_VAR_1}, beraz? Izen\n"
	.string "galanta, jarri diozuna.\p"
	.string "Baina! Zer iruditzen izen\n"
	.string "hobexeagoa proposatzen badizut?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Ados. Orduan, zein izango\n"
	.string "da ezizen berria?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Ongi! Hemendik aurrera, POKéMON\n"
	.string "honen izena {STR_VAR_1} izango da!\p"
	.string "Lehengoa baino izen hobea!\n"
	.string "Zu bai zorionekoa!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Ados.\n"
	.string "Etorri berriz nahi duzunean.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Ongi! Hemendik aurrera, POKéMON\n"
	.string "honen izena {STR_VAR_1} izango da!\p"
	.string "Lehengoaren berdina dirudi, eta\n"
	.string "hala ere, askoz hobea da oraingoa!\p"
	.string "Zu bai zorionekoa!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "Hmmm… {STR_VAR_1} beraz!\p"
	.string "Egundoko ezizena da hori!\n"
	.string "Ezin hobea, akatsik gabea!\p"
	.string "Hemendik aurrera zure {STR_VAR_1}\n"
	.string "goxo zaintzen jarraitu.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Aizu, aizu.\n"
	.string "Hori ARRAUTZA bat da eta!$"

