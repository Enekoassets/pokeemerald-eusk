DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "Gozatu zure begiak honi begiratuz!\p"
	.string "ZETAZKO ZAPI Bat da. Moda-modan\n"
	.string "dagoen jantzia da, bai!\p"
	.string "Ene, zur ebegien distira ikus dezaket!\n"
	.string "Nire estilo distiratsua atsegin duzu!\p"
	.string "Ene, zu bai zu jatorra!\n"
	.string "Tori. Zuretzat har dezazun nahi dut!$"

DewfordTown_House2_Text_NoRoom:
	.string "Zer, ez daukazula lekurik?\p"
	.string "Aizu, entzun iezadazu: ZAPI hau derrigor\n"
	.string "eduki beharrekoa da! Nire item guztiak\l"
	.string "salduko nituzke lortzeko!$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "ZETAZKO ZAPIAK mota NORMALEKO\n"
	.string "erasoen indarra igotzen du.\p"
	.string "Ia POKéMON guztiei ondo geratzen\n"
	.string "zaien ZAPI miragarria da!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Uau, itsasoa zeharkatu al duzu\n"
	.string "IHINTZIBAR bisitatzeko?\p"
	.string "MARTZIALEN inguruan zerbait entzun\n"
	.string "duzulako etorri al zara?\p"
	.string "Benetan itzela da MARTZIAL…\n"
	.string "Guztion idoloa da.$"

