OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "POKéMONEK borroka egitean, mailaz igo\n"
	.string "eta indartzen joan ohi dira.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Zure POKéMONA indartsuago bihurtzen\n"
	.string "bada, hemendik urruti iristea lortuko\l"
	.string "duzu.$"

