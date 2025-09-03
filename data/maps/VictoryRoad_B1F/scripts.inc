VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "POKéMON LIGARA hurbiltzen ari\n"
	.string "naizela jakiteak…\p"
	.string "Beldur eszenikoa ematen dit…$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "Ezin izan dut ezer egin…$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "POKéMON LIGA urrun geratu zait\n"
	.string "berriz… A zer nolako etsipena…$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "POKéMON LIGARAINO iritsi nahi baduzu,\n"
	.string "zure POKéMONENGAN konfidantza osoa\l"
	.string "izan behar duzu.$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "Zuen arteko erlazioa konfidantza\n"
	.string "sendoan oinarrituta dago.$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "Elkarrekin egonda, ENTRENATZAILEEN eta\n"
	.string "POKéMONEN arteko konfidantza handitzen da.$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "Hau ez da helburua. POKéMON LIGARA\n"
	.string "heltzeko bidea besterik ez da.$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "Hori da bidea!$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "Ondo arituko zara, ziur!\n"
	.string "Zure POKéMONAK oso prest daude!$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "Nire POKéMONAK kosmikoki izugarri\n"
	.string "inspiratzaileak dira!$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "Ez dut inoiz zu bezalako inor ezagutu.$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "Borroka amaituta ere, zu eta zure\n"
	.string "POKéMONEK sekulako boterea\l"
	.string "transmititzen duzue.$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "Lasai, ez duzu zertan altxa!\n"
	.string "Lasaitu, ez gaitezen gehiegi neka!$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "Uau!\n"
	.string "Izugarria!$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "Bia, hau da GARAIPENAREN BIDEA.\p"
	.string "Baina ez da oso desberdina orain\n"
	.string "arteko bidearekin alderatuta.\p"
	.string "Saiatu gozatzen falta zaizun bide\n"
	.string "osoan zehar!$"

