MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
	.string "Hemen nagoenean…\n"
	.string "Botere arrao batek zeharkatzen nau…$"

MtPyre_6F_Text_ValerieDefeat:
	.string "Badoa botere arraroa…$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "Agian hemen lotan dauden POKéMONEN\n"
	.string "espirituen boterea da…$"

MtPyre_6F_Text_ValerieRegister:
	.string "Fufufu… Borroka galdu dut, baina…\n"
	.string "Abilezia hau daukat…\p"
	.string "Zure POKéNAVA ikutu ere\n"
	.string "egin gabe… Jiaa!$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Zure atzean…\n"
	.string "Zer dago…$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "Zerbait desagertu da…$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "Hemen dauden POKéMONAK…\n"
	.string "Batzuetan, jolastu egiten dute…$"

MtPyre_6F_Text_CedricIntro:
	.string "Galdu egin al zara?\n"
	.string "Ez beldurtu, hemen nago eta!$"

MtPyre_6F_Text_CedricDefeat:
	.string "Ez al zeunden galduta?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "Uste nuen galdutako ENTRENATZAILE\n"
	.string "bat erraz garaituko nuela.\p"
	.string "Joko zikina da, ez dut berriz egingo…$"

