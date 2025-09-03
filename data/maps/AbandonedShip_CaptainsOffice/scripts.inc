AbandonedShip_CaptainsOffice_MapScripts::
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide::
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner::
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus::
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner:
	.string "Itsasontzi hau aztertzen ari naiz\n"
	.string "ABABOR KAPITAINAK eskatuta.\p"
	.string "ESKANER bat aurkitzeko eskatu dit,\n"
	.string "baina ez dut ezer ikusi hemen inguruan…$"

AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner:
	.string "Ene! Hori ESKANER bat da!\p"
	.string "Entzun, eramango zenioke hori\n"
	.string "ABABOR KAPITAINARI?\p"
	.string "Itsasontzi hau aztertu nahi\n"
	.string "dut pixka bat gehiago.$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus:
	.string "Ontzi honen izena KAKTUS ONTZIA da.\n"
	.string "Beste garai batekoa dela dirudi.$"

