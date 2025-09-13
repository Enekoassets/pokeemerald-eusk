Route119_House_MapScripts::
	.byte 0

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_Text_RumorAboutCaveOfOrigin:
	.string "HASIERA KOBAZULOA izeneko koba\n"
	.string "baten inguruan entzun dut.\p"
	.string "Jendeak dio POKéMONEN arimak\n"
	.string "berpizten direla bertan. Posible\l"
	.string "al da horrelako zerbait benetan?$"

Route119_House_Text_Wingull:
	.string "WINGULL: Pihyoh!$"

