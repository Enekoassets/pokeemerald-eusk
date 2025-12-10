.set LOCALID_DAYCARE_LADY, 1

Route117_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_EventScript_CheckOnTwoMons
	msgbox Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareEggWaiting::
	msgbox Route117_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route117_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route117_EventScript_DaycareReceiveEgg
	msgbox Route117_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareReceiveEgg::
	message Route117_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox Route117_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route117_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route117_EventScript_MonReceivedMail
	return

Route117_EventScript_MonReceivedMail::
	msgbox Route117_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route117_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_PokemonDayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_PokemonDayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_PokemonDayCare_EventScript_TwoMonsInDaycare
	msgbox Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons
	msgbox Route117_PokemonDayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route117_PokemonDayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CanRaiseOneMore
	release
	end

Route117_PokemonDayCare_EventScript_ComeAgain::
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_CanRaiseOneMore::
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_OnlyOneMon::
	msgbox Route117_PokemonDayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyOneAliveMon::
	msgbox Route117_PokemonDayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_EggWaiting::
	msgbox Route117_PokemonDayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route117_PokemonDayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route117_PokemonDayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels
	return

Route117_PokemonDayCare_EventScript_OneMonInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_TryRetrieveMon::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route117_PokemonDayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route117_PokemonDayCare_EventScript_ComeAgain
	goto Route117_PokemonDayCare_EventScript_CostPrompt
	end

Route117_PokemonDayCare_EventScript_CostPrompt::
	special GetDaycareCost
	msgbox Route117_PokemonDayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_CheckEnoughMoney
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_RetrieveMon
	msgbox Route117_PokemonDayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_RetrieveMon::
	applymovement LOCALID_DAYCARE_LADY, Route117_PokemonDayCare_Movement_RetrieveDaycareMon
	waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route117_PokemonDayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_NoRoom::
	msgbox Route117_PokemonDayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route117_PokemonDayCare_EventScript_UnusedEnd::
	end

Route117_PokemonDayCare_EventScript_TwoMonsInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

@ Unused
Route117_PokemonDayCare_EventScript_UnusedRetrieveMon::
	special ShowDaycareLevelMenu
	waitstate
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_ComeAgain
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, TakePokemonFromDaycare
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

EventScript_EggHatch::
	lockall
	msgbox Text_EggHatchHuh, MSGBOX_DEFAULT
	special EggHatch
	waitstate
	releaseall
	end

Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon:
	.string "ZAINDEGIKO GIZONA naiz.\p"
	.string "ENTRENATZAILEEN POKéMON\n"
	.string "maiteak zaintzen ditut.\p"
	.string "Zure POKéMONAK zaintze nahi baduzu,\n"
	.string "hitz egin nire emaztearekin, mesedez.$"

Route117_Text_DoYouWantEgg:
	.string "Ene, zu zara eta!\p"
	.string "Zure POKéMONA zaintzen ari ginen,\n"
	.string "eta, ene bada, harrituta geratu gara!\p"
	.string "Zure POKéMONAK ARRAUTZA bat zuen!\p"
	.string "Ez dakigu nola iritsi den horra,\n"
	.string "baina zure POKéMONAK zeukan.\p"
	.string "Nahi duzu, ezta?$"

Route117_Text_YourMonIsDoingFine:
	.string "Ene, zu zara eta! Pozten naiz zu ikusita.\n"
	.string "Zure {STR_VAR_1} ondo dago.$"

Route117_Text_IllKeepIt:
	.string "Beno, orduan, nik gordeko dut.\n"
	.string "Esker mila!$"

Route117_Text_YouHaveNoRoomForIt:
	.string "Ez daukazu gordetzeko lekurik…\n"
	.string "Itzuli lekua egin ondoren.$"

Route117_Text_ReceivedEgg:
	.string "{PLAYER}(e)k ARRAUTZA jaso du\n"
	.string "ZAINDEGIKO GIZONARENGANDIK.$"

Route117_Text_TakeGoodCareOfIt:
	.string "Ondo zaindu ezazu.$"

Route117_Text_FriendlyWithOtherTrainersMon:
	.string "Bestalde, zure {STR_VAR_1},\n"
	.string "oso lagun on du {STR_VAR_2}(r)en\l"
	.string "{STR_VAR_3}.\p"
	.string "GUTUN bat jaso duela ere\n"
	.string "esango nuke.$"

@ Unused
Route117_Text_SeeWifeIfYouWantToPickUpMon:
	.string "Zure POKéMONA jaso nahi baduzu,\n"
	.string "hitz egin nire emaztearekin.$"

Route117_Text_YourMonsAreDoingFine:
	.string "Ene, zu zara eta! Zure {STR_VAR_1} eta\n"
	.string "{STR_VAR_2} ondo daude.$"

Route117_Text_IWillKeepDoYouWantIt:
	.string "Oso ondo gordeko dut.\n"
	.string "Nahi duzu hau, ezta?$"

Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon:
	.string "ZAINDEGIKO EMAKUMEA naiz.\p"
	.string "Zure POKéMONAK zain ditzakegu.\p"
	.string "Nahi al duzu bat zaintzea?$"

Route117_PokemonDayCare_Text_WhichMonShouldWeRaise:
	.string "Zein POKéMON zaindu behar\n"
	.string "genuke zure partez?$"

Route117_PokemonDayCare_Text_WellRaiseYourMon:
	.string "Ongi, zure {STR_VAR_1} zainduko\n"
	.string "dugu aldi baterako.\p"
	.string "Itzuli bere bila nahi duzunean.$"

Route117_PokemonDayCare_Text_WeCanRaiseOneMore:
	.string "Zure bi POKéMON zain ditzakegu.\n"
	.string "Nahi al duzu beste bat zaintzea?$"

Route117_PokemonDayCare_Text_HusbandWasLookingForYou:
	.string "Nire senarra zure bila dabil.$"

Route117_PokemonDayCare_Text_FineThenComeAgain:
	.string "Ongi, orduan.\n"
	.string "Itzuli nahi duzunean.$"

Route117_PokemonDayCare_Text_NotEnoughMoney:
	.string "Ez duzu nahikoa diru…$"

Route117_PokemonDayCare_Text_TakeOtherOneBackToo:
	.string "Nahi al duzu bestea ere jaso?$"

Route117_PokemonDayCare_Text_ComeAgain:
	.string "Ongi.\n"
	.string "Itzuli nahi duzunean.$"

Route117_PokemonDayCare_Text_GoodToSeeYou:
	.string "Ene, zu zara eta! Pozten naiz zu ikusita.\n"
	.string "Zure POKéMONA ederki dabil!$"

Route117_PokemonDayCare_Text_YourMonHasGrownXLevels:
	.string "Zure {STR_VAR_1}(e)k {STR_VAR_2}\n"
	.string "maila igo ditu.$"

Route117_PokemonDayCare_Text_YourTeamIsFull:
	.string "Zure POKéMON taldea betea dago.\n"
	.string "Egin tokia, eta itzuli.$"

@ Unused
Route117_PokemonDayCare_Text_TakeBackWhichMon:
	.string "Zein POKéMON jasoko duzu?$"

Route117_PokemonDayCare_Text_ItWillCostX:
	.string "Zure {STR_VAR_1} jaso nahi baduzu,\n"
	.string "{STR_VAR_2}¥ izango dira guztira.$"

Route117_PokemonDayCare_Text_HeresYourMon:
	.string "Bikain!\n"
	.string "Tori zure POKéMONA.$"

Route117_PokemonDayCare_Text_TookBackMon:
	.string "{PLAYER}(e)k {STR_VAR_1} jaso du\n"
	.string "ZAINDEGIKO EMAKUMEARENGANDIK.$"

Route117_PokemonDayCare_Text_YouHaveJustOneMon:
	.string "Nola? Baina POKéMON bakarra\n"
	.string "duzu eta.\p"
	.string "Etorri beste batean.$"

Route117_PokemonDayCare_Text_TakeYourMonBack:
	.string "Zure POKéMONA jaso nahi al duzu?$"

Route117_PokemonDayCare_Text_WhatWillYouBattleWith:
	.string "POKéMON hori ematen badidazu,\n"
	.string "norekin egingo duzu borrokan?\p"
	.string "Itzuli beste batean.$"

Text_EggHatchHuh:
	.string "Nola?$"

Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne:
	.string "Nola?\n"
	.string "Ea, ea.\p"
	.string "POKéMON hori ematen badidazu,\n"
	.string "bakarrarekin geratuko zara.\p"
	.string "Hobe beste POKéMON batzuk ere\n"
	.string "harrapatzen badituzu.$"
