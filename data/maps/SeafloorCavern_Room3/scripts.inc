SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "kar-kar-kar!\p"
	.string "Nola iritsi zara honaino\n"
	.string "urpekorik gabe?\l"
	.string "Zu bai gazte harrigarria!\p"
	.string "But… Ez da komeni zu hemen\n"
	.string "bueltaka egotea.\p"
	.string "Gainera, EGURALDI INSTITUTUAN\n"
	.string "gertatutakoa ordainaraziko dizut…\p"
	.string "Mina zer den erakutsiko dizut!\n"
	.string "Errenditu zaitez!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "Kar-kar-kar!\p"
	.string "Autx!$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "Kar-kar-kar!\n"
	.string "Izugarri indartsua zara.\p"
	.string "Pena handia da ez zarela AQUA\n"
	.string "TALDEKOA.\p"
	.string "Gure NAGUSIAK agindu digun mundu\n"
	.string "zoragarria ikusiko zenuke, taldeko\l"
	.string "kide izanda…$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "Baina gure ametsa egia bihurtzeko,\n"
	.string "POKéMON baten boterea behar dugu.\p"
	.string "Baina zu bezalako umemokoek POKéMONEN\n"
	.string "boterea gure aurka egiteko erabiltzen\l"
	.string "duzue, baita hau bezalako leku batean ere!\p"
	.string "Bizitzak ez du funtzionatzen\n"
	.string "guk behar dugun moduan!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Buaf!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "Badakizu zer? Ez dugu inoiz gure\n"
	.string "nagusiaren zioa zalantzan jartzen.\p"
	.string "Baina hemen zaude, umemoko bat,\n"
	.string "gure NAGUSIAREN aurka.\p"
	.string "Agian…\n"
	.string "Norbait garrantzitsua izango zara…$"

