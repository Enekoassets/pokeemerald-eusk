.set LOCALID_SCIENTIST_1, 1
.set LOCALID_SCIENTIST_2, 2
.set LOCALID_SAILOR, 3
.set LOCALID_OLD_MAN, 4
.set LOCALID_WOMAN, 5
.set LOCALID_STAIR_GRUNT, 9

MossdeepCity_SpaceCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_SpaceCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_1F_OnTransition
	.byte 0

MossdeepCity_SpaceCenter_1F_OnTransition:
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma::
	setobjectxyperm LOCALID_SAILOR, 1, 9
	setobjectmovementtype LOCALID_SAILOR, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_WOMAN, 0, 8
	setobjectmovementtype LOCALID_WOMAN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_OLD_MAN, 1, 6
	setobjectmovementtype LOCALID_OLD_MAN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SCIENTIST_1, 3, 4
	setobjectmovementtype LOCALID_SCIENTIST_1, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_SCIENTIST_2, MOVEMENT_TYPE_FACE_RIGHT
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 1, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft::
	setobjectxyperm LOCALID_STAIR_GRUNT, 12, 2
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown::
	setobjectxyperm LOCALID_STAIR_GRUNT, 13, 3
	end

@ Functionally unused. See comment on MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight::
	setobjectxyperm LOCALID_STAIR_GRUNT, 14, 2
	end

MossdeepCity_SpaceCenter_1F_OnLoad:
	goto_if_le VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote
	end

MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote::
	setmetatile 2, 5, METATILE_Facility_DataPad, TRUE
	return

MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter::
	lock
	faceplayer
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring STR_VAR_1, VAR_RESULT
	call_if_eq VAR_RESULT, 0, MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet
	call_if_ge VAR_RESULT, 1, MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet::
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber::
	msgbox MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma::
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring STR_VAR_1, VAR_RESULT
	call_if_eq VAR_RESULT, 0, MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma
	call_if_ge VAR_RESULT, 1, MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_Scientist::
	lock
	faceplayer
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_SunStoneMan::
	lock
	faceplayer
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone
	msgbox MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_SUN_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma::
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_SUN_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
	goto MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal::
	msgbox MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
	goto MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal::
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Steven::
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_MagmaNote::
	lockall
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_3, MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_1, MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_4, MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt2::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F, MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_2, MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat
	setflag FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F
	copyobjectxytoperm LOCALID_STAIR_GRUNT
	switch VAR_FACING
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest
#ifdef BUGFIX
	case DIR_EAST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
#else
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
#endif
	applymovement LOCALID_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 2
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated::
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest::
	applymovement LOCALID_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 1
	release
	end

@ Functionally unused by mistake. The movement is handled anyway after the switch (see above)
@ This also means VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE can never be 3
MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast::
	applymovement LOCALID_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3
	release
	end

MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

@ Functionally unused. See above
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

@ This was meant to only handle the player facing North, but by mistake(?) it also handles the player facing East
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs:
	face_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent:
	.string "Suziria segituan botako da!$"

MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber:
	.string "Suziria seguru jaurti da!\n"
	.string "{STR_VAR_1}. jaurtiketa arrakastatsua izan da!$"

MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent:
	.string "Badakit gauzak pixka bat\n"
	.string "kontrolez kanpo daudela, baina…\p"
	.string "Suziria segituan botako da!$"

MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber:
	.string "Badakit gauzak pixka bat\n"
	.string "kontrolez kanpo daudela, baina…\p"
	.string "Suziria seguru jaurti da!\n"
	.string "{STR_VAR_1}. jaurtiketa arrakastatsua izan da!$"

MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection:
	.string "Suziri jaurtiketa perfektua izan behar da.\n"
	.string "Ezin da %1eko akatsa ere gertatu.\p"
	.string "%99 ondo badago ere, ez du ezertarako\n"
	.string "balio %1 ez bada ondo egin.\p"
	.string "Hala ere, saiatzen jarraitzne dugu.\n"
	.string "Zergatik? Amaiera gabeko ametsa delako.$"

MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter:
	.string "MAGMA taldeko horiek gure ESPAZIO\n"
	.string "ZENTROA zelatatzen ari dira.\p"
	.string "Baina ezin diogu horrelako tontakeria\n"
	.string "bati suziriaren jaurtiketa eragozten utzi!$"

MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt:
	.string "Hondartzan paseo bat ematen ari\n"
	.string "nintzen eta hau aurkitu nuen.\p"
	.string "Ez dut ezertarako behar, beraz,\n"
	.string "zuretzat.$"

MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers:
	.string "HOENN eskualdean famatua da METEORITO\n"
	.string "euriak gertatzen direlako.$"

MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis:
	.string "Ezin diogu utzi MAGMA TALDEARI\n"
	.string "suziriaren erregaia lapurtzen.\p"
	.string "Portzierto, tori hondartzan\n"
	.string "aurkitu nuen harri hau.$"

MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma:
	.string "MAGMA TALDEA inguruan badabil,\n"
	.string "paseoak ez dira seguruak, jada.$"

MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace:
	.string "batzuek diote POKéMONAK espaziotik\n"
	.string "etorri zirela. Egia izango ote da?$"

MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma:
	.string "AQUA TALDEA arduratu behar\n"
	.string "litzateke MAGMA TALDEAZ!\p"
	.string "Baina hori egiten badute, AQUA TALDEA\n"
	.string "lotsagabea bihurtuko litzateke, ezta?$"

MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind:
	.string "Metalezko zati erraldoi batek zeruak\n"
	.string "zeharkatu eta espaziora ihes egitea…\p"
	.string "Sinesgaitza iruditzen zait!$"

MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream:
	.string "Metalezko zati erraldoi batek zeruak\n"
	.string "zeharkatu eta espaziora ihes egitea…\p"
	.string "Baina MAGMA TALDEAK nire ametsa\n"
	.string "zapuztu nahi du!\p"
	.string "Ez diet hori egiten utziko!$"

MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel:
	.string "MIKEL: {PLAYER}{KUN}, irakurri al duzu\n"
	.string "aldarrikapena?\p"
	.string "MAGMA TALDEA irla honetako suziriaren\n"
	.string "erregaiaren bila dator.\p"
	.string "Ez dakit zertarako behar duten,\n"
	.string "baina ezin diegu hartzen utzi.\p"
	.string "Hemen geratuko naiz zaintzen,\n"
	.string "pixka bat gehiago.\p"
	.string "Bitartean, zergatik ez zara herria\n"
	.string "bisitatzera joaten?$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro:
	.string "Esan genuen bezala, suziriaren\n"
	.string "erregaiaren bila gatoz!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat:
	.string "Erregairik gabe geratu naiz…$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle:
	.string "Ez pentsa ni garaitu nauzulako\n"
	.string "inor baino hobea zarenik!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro:
	.string "Abisatu genizuen!\n"
	.string "Ez gara ezer oker egiten ari!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat:
	.string "Grrr…\n"
	.string "Tranpa egin behar genuen…$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle:
	.string "Ongi, ulertu dut! Hurrengoan,\n"
	.string "ez dugu esango bagatozenik.$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro:
	.string "ESPAZIO ZENTROAK erreserban duen\n"
	.string "suziri erregaia, hori da nahi duguna.\p"
	.string "Tantarik ere ez dugu utziko!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat:
	.string "Mesedez, emango sobrako erregai\n"
	.string "pixka bat? Edalontzi bat bada ere!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle:
	.string "Zer egingo dugun suziriaren\n"
	.string "erregaiarekin?\p"
	.string "Nola jakingo dut nik hori?\n"
	.string "Galdetu goiko pisuan dagoen liderrari!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro:
	.string "Liderrak esan du inori, benetan,\n"
	.string "inori, ez uzteko igarotzen!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat:
	.string "Kaka! Kaka! Kakaa!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle:
	.string "Mesedez, esan liderrari ez\n"
	.string "nintzela lekutik mugitu.\l"
	.string "Azken unera arte geratu nintzela…$"

MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice:
	.string "Hau…\n"
	.string "Lapurreta aldarrikapena al da?\p"
	.string "“ESPAZIO ZENTROKO langileei:\n"
	.string "Zer moduz zaudete? Gu ondo.\p"
	.string "“Laister joango gara bisitan, zuen\n"
	.string "suziriaren erregaia hartzera.\p"
	.string "“Mesedez, ez saiatu gu geldiarazten.\n"
	.string "Berdin-berdin hartuko dugu erregaia.\p"
	.string "“Egon bedi lur gehiago!\n"
	.string "                                        MAGMA TALDEA”$"
