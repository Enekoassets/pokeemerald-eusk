.set LOCALID_GRUNT, 3
.set LOCALID_DEVON_EMPLOYEE, 4

PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_GRUNT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Hmmm…\n"
	.string "Ez dago bat bera ere…$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Kaixo, ikusi al duzu SHROOMISH\n"
	.string "izeneko POKéMONIK hemen inguruan?\p"
	.string "Benetan gustatzen zait POKéMON hori.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "Segada bat egin behar nizun,\n"
	.string "baina PETALORE BASOAN egon zara\l"
	.string "denbora pila bat!\p"
	.string "Nekatu naiz, itxaroten. Hemen nago!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "Aizu! DEVONEKO IKERTZAILEA!\p"
	.string "Ekarri paper horiek hona!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Ai ene!\p"
	.string "POKéMON ENTRENATZAILEA zara, ezta?\n"
	.string "Lagundu egin behar didazu, mesedez!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Zer? Zertan ari zarela uste duzu?\n"
	.string "Zer, babestu egingo al duzu?\p"
	.string "AQUA TALDEARI aurre egiten dionak ez du\n"
	.string "errukirik jasotzen, umea izanda ere!\p"
	.string "Ea ba, borrokatu dezagun!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "Ezinezkoa da! Indartsua zara!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Kaka… Baduzu ausardia AQUA\n"
	.string "TALDEAREN aurka errebelatzeko!\l"
	.string "Ea ba, borroka dezagun berriro!\p"
	.string "Hori egin nahi nuke, baina ez zait\n"
	.string "POKéMONIK geratzen…\p"
	.string "Gainera, AQUA TALDEKOOK zerbaiten\n"
	.string "bila ari gara BURDINTZAN.\p"
	.string "Ihes egiten utziko dizut, beraz!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Ufff…\n"
	.string "Ia-ia guztia lapurtu didate!\p"
	.string "Zuri esker ez ditut paper\n"
	.string "garrantzitsu hauek galdu.\p"
	.string "Badakit, SUPER BALL bat emango\n"
	.string "dizut eskertzeko!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Ez al du AQUA TALDEKO tipo horrek\n"
	.string "esan BURDINTZAN ere zerbaiten\l"
	.string "bila ari direla?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Ai ene! A zer krisia!\n"
	.string "Ezin dut denborarik galdu!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "Itemez gainezka zaude.\n"
	.string "Ezin dizut SUPER BALL hau eman.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "POKéMON pila bat harrapatu ditut!\p"
	.string "Aurrera, goazen!\n"
	.string "Nire ZOMORRO POKéMONEN taldea!$"

PetalburgWoods_Text_ICouldntWin:
	.string "Horrenbeste POKéMON,\n"
	.string "baina ezin irabazi…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "POKéMON mordo bat harrapatu ditut.\n"
	.string "Orain ez daukat POKé BALLIK.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "ZOMORRO POKéMONAK eskolara eramaten\n"
	.string "badituzu, guztiak txundituko dituzu!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "Ez dut inor txundituko galtzen badut.$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "ZOMORRO POKéMON handi bat baduzu,\n"
	.string "jendeak errespetua adieraziko dizu.$"

PetalburgWoods_Text_IWantRematch1:
	.string "Errebantxa nahi dut nire ZOMORRO\n"
	.string "POKéMONAK hazten direnean!\p"
	.string "Nire POKéNAVEAN erregistratuko zaitut!$"

PetalburgWoods_Text_IWantRematch2:
	.string "Errebantxa nahi dut nire ZOMORRO\n"
	.string "POKéMONAK hazten direnean!\p"
	.string "Nire POKéNAVEAN erregistratuko zaitut!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "Nire ZOMORROPOKéMONAK hazi egin dira.\n"
	.string "Denak txundituko ditut berriz.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "Ez dut inor txundituko galtzen badut.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "Guztiak txunditzen dituzu POKéMON\n"
	.string "indartsuak badituzu, ezta?\l"
	.string "Horregatik, gogor entrenatu dut.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Ei, aizu!\n"
	.string "Ondo al daude zure POKéMONAK?\p"
	.string "Zure POKéMONAK ahul badaude eta\n"
	.string "borrokak saihestu nahi badituzu,\l"
	.string "ez sartu belar garai artean.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "Batzuetan, gauzak daude lurrean,\n"
	.string "ikusi ezin badituzu ere.\p"
	.string "Horregatik ibiltzen naiz beti\n"
	.string "lurrera begira, adi.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Itzela!\n"
	.string "Hori BURDINTZAKO GIMNASIOKO DOMINA da!\p"
	.string "ENTRENATZAILEA izango zara.\n"
	.string "Item hau erabili behar zenuke.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "MIRARI HAZIA da.\n"
	.string "POKéMON batek edukita, bere BELAR\l"
	.string "motako erasoak indartzen dira.\p"
	.string "MIRARI HAZIAZ gain, uste dut\n"
	.string "badaudela POKéMONEK eduki ditzaketen\l"
	.string "item interesgarri gehiago.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "ENTRENATZAILEENTZAKO PISTAK\p"
	.string "Borrokan gutxienez behin ateratzen den\n"
	.string "POKéMONAK ESP. Puntuak lortzen ditu.\p"
	.string "POKéMON ahul bat hazteko, ipini\n"
	.string "zerrendaren ezkerreko aldean, goian.\p"
	.string "Borroka hasten denean, atera ezazu.\n"
	.string "ESP Puntuak irabaziko ditu inolako\l"
	.string "minik hartu gabe ere.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "ENTRENATZAILEENTZAKO PISTAK\p"
	.string "Bizitza Puntuez (BP) gain, POKéMONEK\n"
	.string "Indar Puntuak (PP) dituzte, borrokan\l"
	.string "erasoak erabili ahal izateko.\p"
	.string "POKéMON bat PP gabe geratzen bada,\n"
	.string "POKéMON ZENTRO batera eraman behar da.$"

