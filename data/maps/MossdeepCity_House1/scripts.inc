MossdeepCity_House1_MapScripts::
	.byte 0

MossdeepCity_House1_EventScript_BlackBelt::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox MossdeepCity_House1_Text_HmmYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetPokeblockNameByMonNature
	goto_if_eq VAR_RESULT, 0, MossdeepCity_House1_EventScript_NeutralNature
	msgbox MossdeepCity_House1_Text_ItLikesXPokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_NeutralNature::
	msgbox MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_Woman::
	msgbox MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes, MSGBOX_NPC
	end

MossdeepCity_House1_Text_HmmYourPokemon:
	.string "Hmm!\n"
	.string "Zure {STR_VAR_1}…$"

MossdeepCity_House1_Text_ItLikesXPokeblocks:
	.string "{STR_VAR_1}AK atsegin,\n"
	.string "ditu, ezta?\p"
	.string "Ez, ziur nago! Benetan atsegin\n"
	.string "ditu {STR_VAR_1}AK!$"

MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks:
	.string "Badirudi ez duela {POKEBLOCK}IK\n"
	.string "gustuko bereziki.$"

MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes:
	.string "Nire senarrak POKéMON batek atsegin dituen\n"
	.string "{POKEBLOCK}AK jakin ditzake begirada batekin.$"

