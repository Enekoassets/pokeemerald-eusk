MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "DRAGOIAK erabiltzen ditugunok\n"
	.string "hemen entrenatu ohi dugu.\p"
	.string "TXAPELDUNA ere etorri ohi da.\n"
	.string "Ikusten duzu zeinen leku berezia den?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "Kaka!\n"
	.string "Ez nuen uste horren indartsua zinenik!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "Bidea gogorra eta luzea da.\p"
	.string "Noiz bihurtuko gara onenak\n"
	.string "nire POKéMONAK eta ni?$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "Zure btoerea gehiago ezagutu nahi dut.\n"
	.string "POKéNAVEAN erregistratuko zaitut.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "Elkartu ginenetik, onena izateko\n"
	.string "izugarri entrenatu dugu.\p"
	.string "Lagundu zeinen indartsuak\n"
	.string "garen erakusten!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "Kaka!\n"
	.string "Ez nuen uste horren indartsua zinenik!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "Argi dago zure POKéMONAK\n"
	.string "entrenatzen jarraitu duzula.\p"
	.string "Zu indartsua baldin bazara, ni ere\n"
	.string "indartsuagoa egingo naiz!$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "JON: Beti borrokatu dugu\n"
	.string "POKéMONEKIN bikote moduan.\l"
	.string "Konfidantza dugu gugan.$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "JON: Ai ene.\n"
	.string "Galdu egin dugu, emazte maitea.$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "JON: Berrogeita hamar urte\n"
	.string "daramatzagu ezkonduta.\p"
	.string "Ondo pentsatuta, inoiz ez diot\n"
	.string "nire maiteari borrokan irabazi.$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "JON: Beno, beno, zu bai ENTRENATZAILE\p"
	.string "gaztea! Borrokatuko duzu gurekin? POKéMON\n"
	.string "gehiagorekin itzuli, orduan.$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "JON: ENTRENATZAILE gazte, aukera\n"
	.string "baduzu, borrokatuko dugu berriz?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "JAIONE: Berrogeita hamar urte\n"
	.string "daramatzagu ezkonduta.\p"
	.string "Gure bikote harremana ez da\n"
	.string "inoiz etengo.$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "JAIONE: Ai ene.\n"
	.string "Galdu egin dugu, senar maitea.$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "JAIONE: Berrogeita hamar urte\p"
	.string "ezkonduta… Desadostasun bat badugu,\n"
	.string "POKéMON borroka batekin ebazten dugu…$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "JAIONE: Beno, beno, zu bai\n"
	.string "ENTRENATZAILE gaztea?\p"
	.string "Gurekin borrokatzekotan, POKéMON\n"
	.string "gehiago ekarri behar dituzu.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "JON: Beti borrokatu dugu\n"
	.string "POKéMONEKIN bikote moduan.\l"
	.string "Konfidantza dugu gugan.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "JON: Ai ene.\n"
	.string "Galdu egin dugu, emazte maitea.$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "JON: Berrogeita hamar urte ezkonduta…\p"
	.string "Ondo pentsatuta, nire emazteak eta\n"
	.string "nik egunero egin ditugu borrokak…$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "JON: Beno, beno, zu bai ENTRENATZAILE\p"
	.string "gaztea! Borrokatuko duzu gurekin? POKéMON\n"
	.string "gehiagorekin itzuli, orduan.$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "JAIONE: Berrogeita hamar urte\p"
	.string "daramatzagu ezkonduta.\p"
	.string "Elkarri lagundu diogu beti.\n"
	.string "Oso indartsuak bihurtu gara.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "JAIONE: Ai ene.\n"
	.string "Galdu egin dugu, senar maitea.$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "JAIONE: Berrogeita hamar urte…\n"
	.string "Gauza asko gertatu dira.\p"
	.string "Espero dut oroitzapen alaiak\n"
	.string "sortzen jarraituko dugula elkarrekin.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "JAIONE: Beno, beno, zu bai\n"
	.string "ENTRENATZAILE gaztea?\p"
	.string "Gurekin borrokatzekotan, POKéMON\n"
	.string "gehiago ekarri behar dituzu.$"

