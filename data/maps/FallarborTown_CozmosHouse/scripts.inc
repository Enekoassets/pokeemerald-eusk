FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "KOZMO DOKT.: Ene…\n"
	.string "Ez nintzen kikildu behar eta MAGMA\l"
	.string "TALDEKOEI METEORITOAK non dauden\l"
	.string "esan…\p"
	.string "METEORO UR-JAUZIKO METEORITOA…\n"
	.string "Ez da inoiz nirea izango…$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.string "Ene!\n"
	.string "Nola?\p"
	.string "Item hori…\p"
	.string "Ez al da izango…\p"
	.string "MAGMA TALDEAK METEORO UR-JAUZIETAN\n"
	.string "hartutako METEORITOA al da?\p"
	.string "Mesedez, emango zenidake?\p"
	.string "Ez dizut doan eskatuko, noski.\n"
	.string "Zer iruditzen trukean MT hau ematen badizut?$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "KOZMO DOKT.: MT honekin nire esker\n"
	.string "ona adierazi nahi nizuke.\l"
	.string "Erabili, mesedez!$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "KOZMO DOKT.: Ene, ezin dut sinetsi.\n"
	.string "Hau izugarria da, izugarria!\p"
	.string "Honek asko lagunduko dit nire ikerketan!$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "KOZMO DOKT.: Beno, baina…\n"
	.string "A zer nolako desengainua…$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "KOZMO DOKT.: Mesedez, emango al\n"
	.string "zenidake METEORITO hori?\p"
	.string "Ez dizut doan eskatuko, noski.\n"
	.string "Zer iruditzen trukean MT hau ematen badizut?$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "KOZMO DOKTOREA 114. ERRUTARA joan da\n"
	.string "MAGMA TALDEKO pertsona batzuekin\l"
	.string "batera.$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "KOZMO gaixoa…\n"
	.string "Deprimituta dago… Pena handia ematen dit.$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "Ikusi KOZMO DOKTOREA…\n"
	.string "Oso pozik dago! Zeinen ongi.$"

