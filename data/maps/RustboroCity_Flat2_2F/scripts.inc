RustboroCity_Flat2_2F_MapScripts::
	.byte 0

RustboroCity_Flat2_2F_EventScript_OldMan::
	msgbox RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays, MSGBOX_NPC
	end

RustboroCity_Flat2_2F_EventScript_NinjaBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_PREMIER_BALL_RUSTBORO, RustboroCity_Flat2_2F_EventScript_GavePremierBall
	msgbox RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_PREMIER_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_PREMIER_BALL_RUSTBORO
	release
	end

RustboroCity_Flat2_2F_EventScript_GavePremierBall::
	msgbox RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays:
	.string "Duela urte asko, DEVON enpresa\n"
	.string "txiki, ñimiñoa zen.$"

RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt:
	.string "Nire aitatxok KORPORAZIOAN egiten du lan.\p"
	.string "Nire aitatxok egin du hau!\n"
	.string "Baina ezin dut erabili, beraz, zuretzat.$"

RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo:
	.string "Nire aitatxok KORPORAZIOAN egiten du lan.\p"
	.string "Hazten naizenean DEVONENTZAT\n"
	.string "egingo dut lan nik ere.$"

