MysteryGiftScript_OldSeaMap::
	setvaddress MysteryGiftScript_OldSeaMap
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_OLD_SEA_MAP, OldSeaMap_Obtained
	vgoto_if_set FLAG_CAUGHT_MEW, OldSeaMap_Obtained
	checkitem ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, TRUE, OldSeaMap_Obtained
	vmessage sText_MysteryGiftOldSeaMapForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, FALSE, OldSeaMap_NoBagSpace
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	vmessage sText_MysteryGiftOldSeaMapUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_NoBagSpace:
	vmessage sText_MysteryGiftOldSeaMapBagFull
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_Obtained:
	vmessage sText_MysteryGiftOldSeaMapThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftOldSeaMapForYou:
	.string "Eskerrik asko OPARI MISTERIOTSUAREN\n"
	.string "Sistema erabiltzeagatik.\p"
	.string "Utzi baieztatzen: {PLAYER} al zara?\p"
	.string "Zuretzako ANTZINAKO MAPA\n"
	.string "hau jaso dugu.$"

sText_MysteryGiftOldSeaMapUseAtPort:
	.string "UR-LILI HIRIKO portuan erabili\n"
	.string "behar dela uste dut.\p"
	.string "Zergatik ez duzu proba\n"
	.string "egiten?$"

sText_MysteryGiftOldSeaMapThankYou:
	.string "Eskerrik asko OPARI MISTERIOTSUAREN\n"
	.string "Sistema erabiltzeagatik.$"

sText_MysteryGiftOldSeaMapBagFull:
	.string "Sentitzen dut, {PLAYER}.\n"
	.string "Zure ITEM GAKOEN POLTSIKOA betea dago.\p"
	.string "Gorde zerbait zure PCan, mesedez,\n"
	.string "eta itzuli honen bila.$"
