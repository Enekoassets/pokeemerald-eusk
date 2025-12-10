Roulette_EventScript_Table1::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Table2::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Play::
	special PlayRoulette
	waitstate
	end

Roulette_Text_PlayMinimumWagerIsX::
	.string "Mahai honetako gutxieneko apustua\n"
	.string "{STR_VAR_1} da. Jokatu nahi al duzu?$"

Roulette_Text_NotEnoughCoins::
	.string "Ez duzu nahikoa TXANPON.$"

Roulette_Text_SpecialRateTable::
	.string "Apustu bereziko mahaia oraintxe!$"

Roulette_Text_ControlsInstruction::
	.string "Egin apustu + Kontrol Gurutzea\n"
	.string "erabiliz, gero sakatu A Botoia.$"

Roulette_Text_ItsAHit::
	.string "Asmatu duzu!$"

Roulette_Text_Jackpot::
	.string "Zakua!$"

Roulette_Text_NothingDoing::
	.string "Kale!$"

Roulette_Text_YouveWonXCoins::
	.string "{STR_VAR_1} TXANPON lortu dituzu!$"

Roulette_Text_NoCoinsLeft::
	.string "Ez duzu TXANPONIK…$"

Roulette_Text_KeepPlaying::
	.string "Jokatzen jarraitu?$"

Roulette_Text_BoardWillBeCleared::
	.string "ERRULETAKO mahaia hustu egingo da.$"

@ Unused
Roulette_Text_YouDontHaveACoinCase::
	.string "Ez daukazu DIRU ZORRORIK.$"

Roulette_Text_CoinCaseIsFull::
	.string "Zure DIRU ZORROA beteta dago!\n"
	.string "Txanponak opari truke alda ditzakezu.$"
