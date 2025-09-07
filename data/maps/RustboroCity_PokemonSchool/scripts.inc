RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "Arbelean POKéMONEK jasan ditzaketen\n"
	.string "egoera aldaketen zerrenda dago.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Zein gai irakurri nahi duzu?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "POKéMON bat pozoinduta badago,\n"
	.string "pixkanaka BPak galduko ditu.\p"
	.string "Pozoiaren efektuak borrokaren\n"
	.string "ostean ere irauten du.\p"
	.string "Pozoindutako POKéMON baten BPak guztiz\n"
	.string "jaitsi daitezke bidaiatu bitartean.\p"
	.string "Pozoina sendatzeko ANTIDOTOA erabili.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "POKéMON bat paralizatuta badago,\n"
	.string "ABIADURA jaisten zaio.\p"
	.string "Gainera, agian ez da gai izango\n"
	.string "borrokan mugitzeko.\p"
	.string "Paralisiak borroka ostean irauten du.\n"
	.string "Erabili ANTIPARALISIA sendatzeko.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "POKéMON bat lo geratzen bada, ez\n"
	.string "da erasotzeko gai izango.\p"
	.string "POKéMONA bakarrik esnatu daiteke,\n"
	.string "baina borroka lo dagoela bukatzen\l"
	.string "bada, lo jarraituko du.\p"
	.string "Esnatu ezazu ESNATZAILEA erabiliz.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Erredura batek ERASOA jaisten du,\n"
	.string "eta pixkanaka biktimaren BPak jaitsi.\p"
	.string "Erredurak borrokaren ostean irauten du.\n"
	.string "Erabili ANTIERREDURA sendatzeko.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "POKéMON bat izoztuta badago,\n"
	.string "ez du ezer egiterik.\p"
	.string "Borrokaren ostean izoztuta irauten du.\n"
	.string "Urtu ezazu ANTIIZOTZA erabiliz.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Ikasten ez duten ikasleek nire\n"
	.string "ATZAPAR AZKARRA probatzen dute.\p"
	.string "Argi ikusiko da ikasle ona zaren\n"
	.string "edo ez, item hau erabiltzen duzun\l"
	.string "eraren arabera.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "ATZAPAR AZKARRA duen POKéMON batek\n"
	.string "batzuetan abiadura irabazi eta etsaia\l"
	.string "baino lehengao mugituko da.\p"
	.string "Beste item pila bat ere badaude,\n"
	.string "POKéMONEI emateko direnak.\p"
	.string "Horiekin bakarrik asko duzu\n"
	.string "ikasteko, jada!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "Nire lagunarekin POKéMONAK\n"
	.string "trukatzen ari naiz oraintxe.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "Beti nahi izan dut SEEDOT bat\n"
	.string "eta azkenean lortuko dut!$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "POKéMONEK itemak eduki ditzakete, baina\n"
	.string "ez dakite gizakiak egindakoekin zer egin,\l"
	.string "EDABE edo ANTIDOTO batekin, esaterako.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Badakizu POKéMON eraso batzuek\n"
	.string "POKéMON bat nahastu dezaketela?\p"
	.string "Nahastutako POKéMON batek batzuetan\n"
	.string "bere buruari joko dio nahigabe.\p"
	.string "Baina behin borroka amaituta, berriz\n"
	.string "egoera normalera itzuliko da.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "BAIA bat daukan POKéMON batek bere\n"
	.string "bere burua sendatu dezake…\p"
	.string "POKéMON batek eduki ditzakeen hainbat\n"
	.string "item mota daude…\p"
	.string "Ene, zaila da benetan apunteak\n"
	.string "ondo hartzea…$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "Ikasle koaderno hau…\p"
	.string "POKéMONAK POKé BALLAK erabiliz\n"
	.string "harrapatu behar dira.\p"
	.string "ENTRENATZAILE batek sei POKéMON\n"
	.string "eraman ditzake, gehienez.\p"
	.string "ENTRENATZAILE deritzo POKéMONAK\n"
	.string "harrapatu, hazi eta haiekin\l"
	.string "borrokatzen duenari.\p"
	.string "ENTRENATZAILE baten helburua\n"
	.string "POKéMON GIMNASIOETAKO beste\l"
	.string "ENTRENATZAILEAK garaitzea da.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Kaixo? Ezagutzen al dugu elkar?\n"
	.string "PETALORE HIRIAN, esango nuke.\p"
	.string "Aurkeztu egingo naiz.\n"
	.string "Nire izena TRIKI da.\p"
	.string "ENTRENATZAILE paregabeen bila\n"
	.string "aritzen naiz hara eta hona.\p"
	.string "Bereziki, POKéMON borroketan\n"
	.string "adituak direnen bila ari naiz.\p"
	.string "Zergatik etorri zara ESKOLA honetara?\n"
	.string "ENTRENATZAILEA al zara zu ere?\p"
	.string "Lehenik eta behin, EBAKIA erakutsi\n"
	.string "behar zenioke POKéMON bati.\p"
	.string "Ondo oroitzen badut, herri honetako\n"
	.string "norbaitek badu EBAKIA.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "TRIKI: Hmm…\p"
	.string "Hemengo ikasleen talentua ezezaguna\n"
	.string "da. POtentziala beti dago hor.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "TRIKI: Zer, zer da hori?\p"
	.string "HARRI DOMINA da, ezta?\n"
	.string "Nahikoa harrigarria, alajaina.\p"
	.string "Baina, badakizu, zu borrokan\n"
	.string "ikusi izana gustatuko zitzaidan.\p"
	.string "Zaila da nolako ENTRENATZAILEA zaren\n"
	.string "jakitea LIGAKO DOMINA batekin soilik.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Kaixo? Ezagutzen al dugu elkar?\n"
	.string "PETALORE HIRIAN, esango nuke.\p"
	.string "Aurkeztu egingo naiz.\n"
	.string "Nire izena TRIKI da.\p"
	.string "ENTRENATZAILE paregabeen bila\n"
	.string "aritzen naiz hara eta hona.\p"
	.string "Bereziki, POKéMON borroketan\n"
	.string "adituak direnen bila ari naiz.\p"
	.string "Zer, zer da hori?\p"
	.string "HARRI DOMINA da, ezta?\n"
	.string "Nahikoa harrigarria, esango nuke, zu\n"
	.string "bezalako ENTRENATZAILE hasiberriarentzat.\p"
	.string "Baina, badakizu, zu borrokan\n"
	.string "ikusi izana gustatuko zitzaidan.\p"
	.string "Zaila da nolako ENTRENATZAILEA zaren\n"
	.string "jakitea LIGAKO DOMINA batekin soilik.$"

