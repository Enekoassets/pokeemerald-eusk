BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_MEOWTH
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge6_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge6_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, BattleFrontier_Lounge6_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt, MSGBOX_DEFAULT
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
	.string "Nire POKéMONA {STR_VAR_2} bat da.\n"
	.string "Ezagutzen al duzu?\l"
	.string "Oso polita eta jatorra da.\p"
	.string "Harrotasun handiz trukatu nezake\n"
	.string "txikitxo hau!\p"
	.string "Trukatu nahi duzu {STR_VAR_1} bat\n"
	.string "nire {STR_VAR_2} honen truke?$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
	.string "Ene, oso polita da!\n"
	.string "Eskerrik asko!\l"
	.string "Ondo zainduko dut, benetan!\p"
	.string "Bai! Zuk ere nire {STR_VAR_2}\n"
	.string "ondo zainduko duzula espero dut!$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
	.string "Ene, sentitzen dut!\n"
	.string "{STR_VAR_1} baten truke soilik\l"
	.string "trukatuko nuke txikitxo hau.$"

BattleFrontier_Lounge6_Text_WellThatsFineToo:
	.string "Zer, ez al duzu nahi?\n"
	.string "Beno, hori ere ondo dago.\l"
	.string "Etorri nahi duzunean.$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
	.string "Bai!\n"
	.string "SKITTY uste nuena baino askoz ere\l"
	.string "politagoa da. A zer poza!$"
