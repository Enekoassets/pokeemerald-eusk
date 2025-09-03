SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
	.string "Aaaa! Nazka-nazka eginda nago\n"
	.string "leku erraldoi hau garbitzeaz!\p"
	.string "Borroka azkar bat egin dezagun!$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "Anaia txiki, galdu egin dut!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "GARBI-GARBI ANAIAK gara!\p"
	.string "Anaia nagusiak garbikaria botatzen du\n"
	.string "eta gazteak dena igurtzi!$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "Hau ontziaren kaskoaren behekaldea da.\n"
	.string "Leku pila bat dago.\l"
	.string "POKéMON borroka baterako nahikoa bai.$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "Anaia nagusi, galdu egin dut!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "GARBI-GARBI ANAIAK gara!\p"
	.string "Anaia nagusiak garbikaria botatzen du\n"
	.string "eta gazteak dena igurtzi!$"

