SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "Entzun, zerbait interesgarria\n"
	.string "kontatuko dizut.\p"
	.string "Hemen inguruko itsasoan antzinako\n"
	.string "hondakin batzuk omen daude.\p"
	.string "Altxorrez beteta egon daiteke,\n"
	.string "nork aurkituko, zain.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "Antzinako altxorrak…\p"
	.string "Ona litzateke existituko balira,\n"
	.string "baina hala ez balitz ere, ederra\l"
	.string "litzateke nire POKéMONEKIN ur\l"
	.string "azpian paseo bat ematea.$"

SootopolisCity_House4_Text_Azumarill:
	.string "AZUMARILL: Marurii.$"

