MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "Mendiaren atomsfera biziak nire\n"
	.string "botere psikikoak indartu ditu!\p"
	.string "Zu bezalako ume batek…\n"
	.string "Irabazi egingo didazula uste al duzu?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "Izugarrizko pena eman dut…$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "Nire botere psikikoak asko\n"
	.string "indartu dira, baina…$"

MtPyre_3F_Text_KaylaIntro:
	.string "Kar-kar-kar!\p"
	.string "Hau ez da umeentzako leku egokia,\n"
	.string "are gutxiago zuretzako!$"

MtPyre_3F_Text_KaylaDefeat:
	.string "Horren garbi galdu dut…$"

MtPyre_3F_Text_KaylaPostBattle:
	.string "Horrek esan nahi du nire entrenamendua\n"
	.string "ez dela nahikoa izan…\p"
	.string "Gailurrera iristeko lan handia\n"
	.string "egin beharko dut…\p"
	.string "Aurrera, ni!$"

MtPyre_3F_Text_GabrielleIntro:
	.string "Zertara etorri zara hona?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "Bikaina izan da! ENTRENATZAILE\n"
	.string "berezia zara.$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "Mundu honetakoak ez diren POKéMONAK.\n"
	.string "Zurekin dauden POKéMONAK.\p"
	.string "Eta etorkizunean ezagutuko\n"
	.string "dituzun POKéMONAK…\p"
	.string "Denek merezi dute tratu bera.\n"
	.string "Gogoratu ezazu, mesedez.$"

MtPyre_3F_Text_GabrielleRegister:
	.string "Zure POKéMONAK ikusi nahiko nituzke\n"
	.string "pixka bat gehiago hazten direnean…\p"
	.string "Mesedez, utzi zure POKéNAVA.$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "Ene, zu zara eta…\p"
	.string "Zure hazitako POKéMONAK erakustera\n"
	.string "etorri al zara?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "Bikaina!\n"
	.string "Oso pertsona berezia zara.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "Mundu honetakoak ez diren POKéMONAK.\n"
	.string "Zurekin dauden POKéMONAK.\p"
	.string "Eta etorkizunean ezagutuko\n"
	.string "dituzun POKéMONAK…\p"
	.string "Denek merezi dute tratu bera.\n"
	.string "Ongi gogoratu duzu, bai.$"

