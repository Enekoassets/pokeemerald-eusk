PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_LittleGirl::
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman::
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy::
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes::
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No::
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
	.string "Jendeak dio POKéMON hegalari bat\n"
	.string "ikusi dutela HOENN gainetik igarotzen.\p"
	.string "Gelditu gabe ari ote da hegan?\n"
	.string "Ez al du nonbait deskantsatu behar edo?$"

PacifidlogTown_House4_Text_SkyPokemon:
	.string "Zeruko POKéMONA!\n"
	.string "Zeruko POKéMONA!$"

PacifidlogTown_House4_Text_WhereDidYouComeFrom:
	.string "Nondik etorri zara?$"

PacifidlogTown_House4_Text_YesTown:
	.string "Bai?\n"
	.string "BAI HERRIA?\p"
	.string "Ez dut horrelako lekurik ezagutzen.$"

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
	.string "Ez? Horrek ez du zentzurik.\n"
	.string "Nonbaitetik etorri behar duzu, baina.\p"
	.string "Ene! Itxaron! Ez didazu esango itsasoaren\n"
	.string "hondoan jaio zinela, ezta?$"

