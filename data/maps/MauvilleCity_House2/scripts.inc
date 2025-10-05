MauvilleCity_House2_MapScripts::
	.byte 0

MauvilleCity_House2_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_ReceivedCoinCase
	msgbox MauvilleCity_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
	checkitem ITEM_HARBOR_MAIL
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_House2_EventScript_AskToTradeForHarborMail
	release
	end

MauvilleCity_House2_EventScript_AskToTradeForHarborMail::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_House2_EventScript_AcceptTrade
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House2_EventScript_DeclineTrade
	end

MauvilleCity_House2_EventScript_AcceptTrade::
	msgbox MauvilleCity_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
	removeitem ITEM_HARBOR_MAIL
	giveitem ITEM_COIN_CASE
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
	end

MauvilleCity_House2_EventScript_ReceivedCoinCase::
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_EventScript_DeclineTrade::
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_Text_BuyHarborMailAtSlateport:
	.string "BIZIKLETA bat banu, erraz joango nintzateke\n"
	.string "PORTUONDORA erosketak egitera.\p"
	.string "PORTU GUTUN bat erosiko nuke\n"
	.string "PORTUONDOKO POKéMON DENDAN…$"

MauvilleCity_House2_Text_TradeHarborMailForCoinCase:
	.string "Nola! PORTU GUTUN bat duzu? Trukatuko\n"
	.string "al zenidake DIRU ZORRO baten truke?$"

MauvilleCity_House2_Text_IllTradeYouCoinCase:
	.string "Ene, bikain!\n"
	.string "Tori, DIRU ZORROA zuretzat!$"

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner:
	.string "DIRU ZORRO hori JOKOEN\n"
	.string "TXOKOAN erabili daiteke.$"

MauvilleCity_House2_Text_ThatsDisappointing:
	.string "Ene, pena handia da hori.\p"
	.string "DIRU ZORROA behar da JOKOEN\n"
	.string "TXOKOAN jokatu ahal izateko.$"

