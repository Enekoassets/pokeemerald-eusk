MysteryGiftScript_MysticTicket::
	setvaddress MysteryGiftScript_MysticTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_MYSTIC_TICKET, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_LUGIA, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_HO_OH, MysticTicket_Obtained
	checkitem ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, MysticTicket_Obtained
	vmessage sText_MysticTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, MysticTicket_NoBagSpace
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	vmessage sText_MysticTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_NoBagSpace:
	vmessage sText_MysticTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_Obtained:
	vmessage sText_MysticTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysticTicketForYou:
	.string "Eskerrik asko OPARI MISTERIOTSUAREN\n"
	.string "Sistema erabiltzeagatik.\p"
	.string "{PLAYER} izango zara.\n"
	.string "Tiket bat dago hemen zuretzat.$"

sText_MysticTicketUseAtPort:
	.string "UR-LILI HIRIKO portuan erabili\n"
	.string "behar dela uste dut.\p"
	.string "Zergatik ez duzu proba\n"
	.string "egiten?$"

sText_MysticTicketThankYou:
	.string "Eskerrik asko OPARI MISTERIOTSUAREN\n"
	.string "Sistema erabiltzeagatik.$"

sText_MysticTicketBagFull:
	.string "Sentitzen dut, {PLAYER}.\n"
	.string "Zure ITEM GAKOEN POLTSIKOA betea dago.\p"
	.string "Gorde zerbait zure PCan, mesedez,\n"
	.string "eta itzuli honen bila.$"
