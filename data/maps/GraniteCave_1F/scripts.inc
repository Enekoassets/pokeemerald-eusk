GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Ei, aizu.\n"
	.string "Hemendik aurrera oso ilun dago.\l"
	.string "Zaila izango da esploratzea.\p"
	.string "Lehenago etorri den mutila…\n"
	.string "MIKEL, uste dut.\p"
	.string "Bazekien DISTIRA nola erabili, beraz,\n"
	.string "ondo egongo da, baina…\p"
	.string "Beno, TXANGOZALEONTZAT besteei laguntzea\n"
	.string "garrantzi handiko kontua da.\p"
	.string "Here you go, I'll pass this on to you.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Erakutsi iezaiozu DISTIRA\n"
	.string "POKéMON bati, eta erabili.\p"
	.string "Kobazulo ilunena ere argitzeko\n"
	.string "gai izango zara.\p"
	.string "Baina, erabiltzeko, IHINTZIBARREKO\n"
	.string "GIMNASIOKO DOMINA behar duzu.$"

