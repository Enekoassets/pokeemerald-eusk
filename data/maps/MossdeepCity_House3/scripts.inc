MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "Aizu, ENTRENATZAILE!\n"
	.string "SUPERKANABERA super itzela da!\p"
	.string "Nahi duzuna esan, baina txiki honek\n"
	.string "itsas hondotik POKéMONAK harrapatu ditzake!\p"
	.string "Zer iruditzen zaizu?\n"
	.string "Nahi duzu, ezta?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "Noski, noski! Azken finean,\n"
	.string "SUPERKANABERA super itzela da!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "Urik baldin badago, bota KANABERA\n"
	.string "eta ikusi ea zer harrapatzen duzun!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "Zer?\n"
	.string "Ez zaizu arrantza gustatzen?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "Harrapatu itsas-hondoko POKéMONAK\n"
	.string "zure SUPERKANABERAREKIN.$"

