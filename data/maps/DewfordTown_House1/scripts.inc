DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "Halako irla txiki batean POKéMONEK\n"
	.string "eta familiak inguratuta bizitzeak\l"
	.string "zeresan handia ematen du.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "PORTUONDO HIRI handitik joan nintzen\n"
	.string "senarrarekin ezkondu nintzenean.\p"
	.string "Bizitza motel doa irla txiki\n"
	.string "honetan. Baina itsasoz inguratuta\l"
	.string "egotea, hori bai dela zoriontasuna.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Guguu!$"

