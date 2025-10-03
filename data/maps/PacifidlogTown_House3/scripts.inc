PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_HORSEA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PacifidlogTown_House3_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House3_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PacifidlogTown_House3_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, PacifidlogTown_House3_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou, MSGBOX_DEFAULT
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "Begira {STR_VAR_2} hau!\p"
	.string "Nire urtebetetzea ospatzeko atzo\n"
	.string "harrapatu nuen {STR_VAR_2} bat da!\p"
	.string "Ikus dezaket nahi duzula!\n"
	.string "Azken finean, oso baliotsua da!\p"
	.string "Begira, {STR_VAR_1} baten truke\n"
	.string "trukatzeko prest nago.$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "Hau al da {STR_VAR_1} bat?\p"
	.string "{STR_VAR_2} baten antza dauka,\n"
	.string "baina pixka bat desberdina da.\p"
	.string "Eskerrik asko!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "Ez, ez, ez! Ez dut {STR_VAR_1}\n"
	.string "bat besterik onartuko!$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "Beraz, ez duzu honekin jarraitu\n"
	.string "nahi?\p"
	.string "Ongi. Ez dut truke hau egiteko\n"
	.string "behar edo gogo berezirik.$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "Badakit joan naitekeela ni horrelako\n"
	.string "bat harrapatzera, baina…\p"
	.string "Baina benetan nahi nuen beste ENTRENATZAILE\n"
	.string "batek harrapatutako BAGON bat izan…$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "POKéDEX bat al da hori?\p"
	.string "Lortu al duzu POKéMON desberdin pila\n"
	.string "bat ikustea?\p"
	.string "Zu bezalakoa izan nahi nuke.$"

