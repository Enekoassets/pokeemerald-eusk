MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "Nire SKITTY maitearen memoriak…\n"
	.string "Malkotan hasten naiz pentsatzean.$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "Autx, autx… Zuloak daude lurrean\n"
	.string "han-hemen.\p"
	.string "Ez naiz konturatu eta goiko\n"
	.string "pisutik erori naiz.$"

MtPyre_2F_Text_MarkIntro:
	.string "Aizu! POKéMON bila al zabiltza?\n"
	.string "Nire atzetik etorri zara! Zakarra!$"

MtPyre_2F_Text_MarkDefeat:
	.string "Ayieeeeh!\n"
	.string "Barkatu, barkatu, mesedez!$"

MtPyre_2F_Text_MarkPostBattle:
	.string "Jendea ez da hona etortzen ia, beraz,\n"
	.string "POKéMON arraroak zeudela pentsatu nuen.$"

MtPyre_2F_Text_LukeIntro:
	.string "ARITZ: Nire ausardia erakusteko gaude\p"
	.string "hemen. Kar-kar, zeinen bikaina naizen\n"
	.string "erakutsita maiteminduko dut, ziur!\p"
	.string "Badakit! Egurra emango dizut zeinen\n"
	.string "bikaina naizen erakusteko!$"

MtPyre_2F_Text_LukeDefeat:
	.string "ARITZ: Ups!$"

MtPyre_2F_Text_LukePostBattle:
	.string "ARITZ: Beno, galdu egin dugu baina\n"
	.string "berdin da. Hemen nago zure alboan.\l"
	.string "Nire ausardia erakutsiko dizut!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "ARITZ: Nire aurka egitekotan,\n"
	.string "ekarri POKéMON gehiago.\p"
	.string "Bestela ezingo diot nire neska-lagunari\n"
	.string "zeinen bikaina naizen erakutsi!$"

MtPyre_2F_Text_DezIntro:
	.string "NAIA: Nire mutil-lagunak esan\n"
	.string "dit hona etortzeko.\p"
	.string "Beldurgarria da, baina nire mutil-\n"
	.string "lagunarekin nago. Ongi, beraz.\p"
	.string "Badakit! Nire mutila ondo geratu\n"
	.string "dadin garaituko zaitut!$"

MtPyre_2F_Text_DezDefeat:
	.string "NAIA: Buaaaa! Beldurra!$"

MtPyre_2F_Text_DezPostBattle:
	.string "NAIA: Elkar maite dugu, beraz,\n"
	.string "ez zaigu axola galtzea!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "NAIA: Gure aurka egitekotan, gutxienez\n"
	.string "POKéMON ekarri behar dituzu.\p"
	.string "Nire mutil-laguna indartsua da.\n"
	.string "POKéMON bakarrarekin ezingo duzu ezer egin.$"

MtPyre_2F_Text_LeahIntro:
	.string "Zu ez zaitut ezagutzen…\n"
	.string "Alde egin ezer txarra gertatu aurretik!$"

MtPyre_2F_Text_LeahDefeat:
	.string "Hmm…\n"
	.string "Gogorra zara gero.$"

MtPyre_2F_Text_LeahPostBattle:
	.string "Gure birramonaren garaitik\n"
	.string "ENTRENATZAILEAK gara familian…\p"
	.string "Nire betebeharra da mendi hau\n"
	.string "babestea…$"

MtPyre_2F_Text_ZanderIntro:
	.string "Uaaaaaaaa!\n"
	.string "A zer ikara!$"

MtPyre_2F_Text_ZanderDefeat:
	.string "Eeeeez!\n"
	.string "Kikildu egin naiz!$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "Beldurtu egiten naiz edozer\n"
	.string "mugitzen denean… Ez nuen\p"
	.string "hona etorri behar entrenatzera…$"

