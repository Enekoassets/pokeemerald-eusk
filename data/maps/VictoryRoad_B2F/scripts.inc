VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "Nire familia osoarekin entrenatu dut,\n"
	.string "gutako guzti-guztiekin!\l"
	.string "Ez dut inoren aurka galduko!$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "Nire familia baino hobea?!\n"
	.string "Hori posible al da?!$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "Nire familiako guztiak baino hobea\n"
	.string "nintzen. Ez nuen inoiz galdu…\p"
	.string "Konfidantza galdu dut…\n"
	.string "Agian etxera joango naiz…$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "Entzun dut gazte gogor bat dabilela\n"
	.string "hemen inguruan. Zutaz ari al dira?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "Kakanarru txikia indartsua da, gero!$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "Entzun dudanez, gaztea PETALORE\n"
	.string "HIRIKOA da jaiotzez.$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "Nekatuta egongo zara, ziurrenik.$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "Ez dirudi nekatuta zaudenik!$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "GARAIPENAREN BIDEA eta POKéMON LIGA\n"
	.string "erronka luze eta gogorrak dira.\l"
	.string "Tentuz ibili nekatu gabe!$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "Ez zenuke lasai ibili behar\n"
	.string "GIMNASIOKO DOMINA asko dituzulako.\p"
	.string "Beti egongo da zu baino hobea\n"
	.string "den norbait!$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "Ni baino hobea zara!$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "Ikusi zuk lortutako DOMINAK eta\n"
	.string "gogoratu garaitutako ENTRENATZAILEAK.$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "Honaino iritsi naiz, baina urduritasunak\n"
	.string "urdaileko min izugarria egiten dit…$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "Uf…\n"
	.string "A zer mina…$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "Oso urduri jartzen naiz POKéMON\n"
	.string "LIGARA hurbiltzen ari naizenez.\p"
	.string "Lasai itxura eman besterik ezin dut egin.$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "Kobazulo honetan onenetan onenak\n"
	.string "biltzen gara.\p"
	.string "Zer moduz zabiltza zu?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "Ez zara batere kikildu!$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "Badituzu barrenak! Gustuko dut hori!\n"
	.string "Segi horrela!$"

