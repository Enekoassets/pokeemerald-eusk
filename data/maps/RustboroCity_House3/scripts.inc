RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "Nire POKéMONEI, ezizen perfektuak\n"
	.string "ematen dizkiet!\p"
	.string "Nire, nola esan… Originaltasuna\n"
	.string "adierazteko era bat da!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "Baina PIKACHU bati PEKACHU izena\n"
	.string "jartzea? Ez du ez hanka ez buru.\p"
	.string "Ideia ona da ulertzeko erraza den\n"
	.string "izen bat jartzea, baina…$"

RustboroCity_House3_Text_Pekachu:
	.string "PEKACHU: Peka!$"

