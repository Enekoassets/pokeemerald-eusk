SootopolisCity_LotadAndSeedotHouse_MapScripts::
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother::
	special GetSeedotSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
	special CompareSeedotSize
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother::
	special GetLotadSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
	special CompareLotadSize
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord::
	special GetSeedotSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord::
	special GetLotadSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot:
	.string "Ezagutzen duzu SEEDOT POKéMONA?\n"
	.string "Gutxitan ikusten da ARREZIPOLISEN.\p"
	.string "Beno, nik SEEDOT handiak ditut gustoko.\n"
	.string "Zenbat eta handiago, orduan eta hobeto.\p"
	.string "Baina nire anaia gazteak dio LOTAD\n"
	.string "handiagoa dela.\p"
	.string "A zer txorakeria.\n"
	.string "SEEDOT handiagoa izan behar da!\p"
	.string "Zer? Ba al daukazu SEEDOT bat?\n"
	.string "M-m-mesedez, erakutsi!$"

SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad:
	.string "{STR_VAR_2} hazbete!\n"
	.string "Ene maitea, handia da gero!\p"
	.string "Nire anaiak ikusi zuen LOTAD\n"
	.string "hura baino handiagoa, ziur!\p"
	.string "Eskerrik asko erakusteagatik.\n"
	.string "Tori hau, esker onez!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1:
	.string "{PLAYER}(e)k EDABE bat jaso du.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
	.string "Nola?\n"
	.string "Zure POLTSA beteta dago.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot:
	.string "{STR_VAR_2} hazbete, ezta?\p"
	.string "Hmm… Ikusi ditut hau baino\n"
	.string "SEEDOT handiagoak.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot:
	.string "Beno, hau zerbait bada…\n"
	.string "Baina ez SEEDOT bat!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot:
	.string "Ez daukazu SEEDOT handirik?\n"
	.string "Pena…\p"
	.string "SEEDOT handi bat lortzen baduzu,\n"
	.string "etorri erakustera, mesedez.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory:
	.string "Historiako SEEDOTIK handiena!\n"
	.string "{STR_VAR_2}(r)en {STR_VAR_3} hazbeteko\p"
	.string "erraldoia! LOTAD bat baino askoz\n"
	.string "handiagoa den SEEDOTA!$"

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad:
	.string "Ezagutzen duzu LOTAD POKéMONA?\n"
	.string "Gutxitan ikusten da ARREZIPOLISEN.\p"
	.string "Izugarri gustoko ditut LOTAD handiak!\p"
	.string "Nire anaiak dio SEEDOT handiagoa\n"
	.string "dela ordea.\p"
	.string "Baina ez da egia! Mundu guztiak daki\n"
	.string "LOTAD askoz handiagoa dela.\p"
	.string "Zer? Ba al daukazu LOTAD bat?\n"
	.string "M-m-mesedez, erakutsi!$"

SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot:
	.string "{STR_VAR_2} hazbete!\n"
	.string "Ene, handia da hori!\p"
	.string "Nire anaiak ikusitako SEEDOT erraldoi\n"
	.string "hori baino handiagoa da agian.\p"
	.string "Eskerrik asko erakusteagatik!\n"
	.string "Tori, nire esker ona adierazteko!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2:
	.string "{PLAYER}(e)k EDABE bat jaso du.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
	.string "Nola?\n"
	.string "Zure POLTSA beteta dago.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad:
	.string "{STR_VAR_2} hazbete?\p"
	.string "Hmm… Ikusi ditut hau baino\n"
	.string "LOTAD handiagoak.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad:
	.string "Beno, hau zerbait bada…\n"
	.string "Baina ez LOTAD bat!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad:
	.string "Ez daukazu LOTAD handirik?\n"
	.string "A zer pena…\p"
	.string "LOTAD handi bat lortzen baduzu,\n"
	.string "erakutsi, mesedez!$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory:
	.string "Historiako LOTADIK handiena!\n"
	.string "{STR_VAR_2}(r)en {STR_VAR_3} hazbeteko\p"
	.string "kolosoa! SEEDOT bat baino askoz\n"
	.string "handiagoa den LOTADA!$"

