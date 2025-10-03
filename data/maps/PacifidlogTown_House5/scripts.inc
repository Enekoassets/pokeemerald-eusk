PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "Gaur ez dut ISPILATZE IRLA ikusten…$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "Ene! Ai ene!\n"
	.string "ISPILATZE IRLA ikus dezaket gaur!$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "ISPILATZE IRLA…\p"
	.string "Ispilatzeak sortzen dituzten eguraldiaren\n"
	.string "egoera desberdinen ondorioz agertu\l"
	.string "edo desagertuko da, ziurrenik.\p"
	.string "Edo benetan agertzen eta desagertzen\n"
	.string "ote da?$"

