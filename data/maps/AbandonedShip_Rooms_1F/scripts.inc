AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "Hau bezalako ontziak ez dira\n"
	.string "ohikoak, beraz, aztertzen ari naiz.\p"
	.string "Hm…\n"
	.string "Badirudi gela gehiago daudela…$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "Zergatik etorri zara leku honetara?\n"
	.string "Jakinmin handikoa izango zara!$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "Jakinmin handikoa eta indartsua…$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "Hurrengo gelako gizona…\p"
	.string "Turista dela dio, baina\n"
	.string "ez dakit sinetsi edo ez.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "ENTRENATZAILE indartsua zara!\n"
	.string "Utzi iezadazu zu erregistratzen!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "Zergatik itzuli zara leku honetara?\n"
	.string "Benetan zara jakinmin handikoa!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "Ez al zara indartsuegia?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "Gizon hori azpikeriatan ari da, ziur!\n"
	.string "Era arraroan jokatzen du!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "Buaa!\n"
	.string "Aurkitu egin naute! …Nola?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "Ah, zu ez zara nire ama.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "Amak errieta egin dit eta ihes\n"
	.string "egin dut. Ez esan non nagoen!$"

