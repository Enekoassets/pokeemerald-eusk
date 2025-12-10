MysteryGiftScript_AuroraTicket::
	setvaddress MysteryGiftScript_AuroraTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, AuroraTicket_Obtained
	vgoto_if_set FLAG_BATTLED_DEOXYS, AuroraTicket_Obtained
	checkitem ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, AuroraTicket_Obtained
	vmessage sText_AuroraTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, AuroraTicket_NoBagSpace
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	vmessage sText_AuroraTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace:
	vmessage sText_AuroraTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_Obtained:
	vmessage sText_AuroraTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicketForYou:
	.string "Eskerrik asko OPARI MISTERIOTSUAREN\n"
	.string "Sistema erabiltzeagatik.\p"
	.string "{PLAYER} izango zara.\n"
	.string "Tiket bat dago hemen zuretzat.$"

sText_AuroraTicketUseAtPort:
	.string "UR-LILI HIRIKO portuan erabili\n"
	.string "behar dela uste dut.\p"
	.string "Zergatik ez duzu proba\n"
	.string "egiten?$"

sText_AuroraTicketThankYou:
	.string "Eskerrik asko OPARI MISTERIOTSUAREN\n"
	.string "Sistema erabiltzeagatik.$"

sText_AuroraTicketBagFull:
	.string "Sentitzen dut, {PLAYER}.\n"
	.string "Zure ITEM GAKOEN POLTSIKOA betea dago.\p"
	.string "Gorde zerbait zure PCan, mesedez,\n"
	.string "eta itzuli honen bila.$"
