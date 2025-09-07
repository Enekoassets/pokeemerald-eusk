RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, RustboroCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox RustboroCity_House1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "Zer? Nire POKéMONA polita dela?\n"
	.string "Bai, hori banekien.\p"
	.string "Baina benetan nahi baduzu, zurekin\n"
	.string "trukatzeko prest nago.\p"
	.string "Nire {STR_VAR_2} {STR_VAR_1}\n"
	.string "baten truke emango dizut.$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Beno…\n"
	.string "Mesedez, ondo zaindu nire POKéMONA.$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Zer? Horrek ez du {STR_VAR_1}\n"
	.string "itxura, aizu.$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "Beno, ez baduzu nahi, ondo.\n"
	.string "Baina polita da nire POKéMONA, jakin ezazu…$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "Edozein POKéMON izan daiteke polita\n"
	.string "jator eta maitasunez haziz gero.$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "Leku desberdinetan, era guztietako\n"
	.string "POKéMONAK eta jendea daude.\p"
	.string "Zoragarria iruditzen zait hori, beraz,\n"
	.string "leku oso desberdinetara joaten naiz.$"

