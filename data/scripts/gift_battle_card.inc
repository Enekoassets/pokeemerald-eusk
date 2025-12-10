MysteryGiftScript_BattleCard::
	setvaddress MysteryGiftScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryGiftScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, REQUIRED_CARD_BATTLES, MysteryGiftScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryGiftScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "Eskerrik asko OPARI MISTERIOTSUAREN\n"
	.string "Sistema erabiltzeagatik.\p"
	.string "Zure BORROKA ZENBATZEKO KARTAK\n"
	.string "zure borroken informazioa gordetzen\l"
	.string "du, TXARTEL berdina dutenen aurka.\p"
	.string "Bilatu eta borrokatu zure TXARTEL\n"
	.string "berdina duten ENTRENATZAILEEN aurka.\p"
	.string "ALBISTEAK irakurrita, sailkapen\n"
	.string "orokorra nola doan ikus dezakezu.\p"
	.string "Probatu ezazu, mesedez!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "Eskerrik asko OPARI MISTERIOTSUAREN\n"
	.string "Sistema erabiltzeagatik.\p"
	.string "Zorionak!\p"
	.string "Saria lortu duzu hiru borroka\n"
	.string "irabazteagatik!\p"
	.string "Honek borrokarako gogoa emango\n"
	.string "dizula espero dugu.$"
