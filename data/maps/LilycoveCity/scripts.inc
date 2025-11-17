.set LOCALID_WOMAN_1, 19
.set LOCALID_MAN_1, 20

LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.string "MAIA: Kaixo?\n"
	.string "{PLAYER}{KUN}, zu ere erosketak egiten?\p"
	.string "PANPINA eta POSTER sorta ederra\n"
	.string "erosi dut.\p"
	.string "Noski, POKéMON mordoa ere harrapatu\n"
	.string "dut, eta modu egokian ari naiz\l"
	.string "haiek hazten.\p"
	.string "Egia esan, gehiago kezkatzen nauena da ea zure\n"
	.string "POKéMONAK ondo hazten ari zaren, {PLAYER}{KUN}.\p"
	.string "Borroka egingo dugu, niri zure\n"
	.string "POKéMONAK erakusteko, {PLAYER}{KUN}.$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "MAIA: Zergatik? {PLAYER}{KUN}, ez al\n"
	.string "dituzu zure POKéMONAK hazi, ala?\p"
	.string "Hori ez da seinale ona\n"
	.string "ENTRENATZAILE batentzat…$"

LilycoveCity_Text_MayBattleMe:
	.string "MAIA: Ea ba, borrokatu nirekin, zure\n"
	.string "POKéMONAK ikus ditzadan!$"

LilycoveCity_Text_MayWontBeBeaten:
	.string "MAIA: Nik hazitako POKéMONAK ez dituzte\n"
	.string "zure POKéMONEK garaituko, {PLAYER}{KUN}!$"

LilycoveCity_Text_MayDefeat:
	.string "… … … … … … … …\p"
	.string "Gogoratzen dut zurekin egindako borroka,\n"
	.string "{PLAYER}{KUN}, 103. ERRUTAN.\p"
	.string "Borroka horrek lagundu zizun horren\n"
	.string "indartsu bilakatzen, {PLAYER}{KUN}, ezta?$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "MAIA: ERROTXIKIRA bueltatzeko\n"
	.string "asmotan nabil.\p"
	.string "POKéMON talde dezentea harrapatu dut,\n"
	.string "eta POKéDEXA betetzen ari naiz, beraz,\l"
	.string "aitari erakustera noa etxera.$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "{PLAYER}{KUN}, zuk zer egingo duzu?\p"
	.string "GIMNASIOKO DOMINA guztiak bildu eta\n"
	.string "POKéMON LIGAKO erronkari aurre egin?\p"
	.string "Beno, DOMINAK biltzen dituzun bitartean,\n"
	.string "{PLAYER}{KUN}, nik POKéDEXA beteko dut\l"
	.string "Ziur zu baino lehenago beteko dudala!\p"
	.string "Ikusi arte!$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "{PLAYER}{KUN}, zuk zer egingo duzu?\p"
	.string "POKéMON LIGAKO erronkari aurre\n"
	.string "egingo al diozu?\p"
	.string "Edo zure POKéDEXA betetzen saiatuko\n"
	.string "zara?\p"
	.string "Borroka galdu egingo nuen, baina\n"
	.string "POKéDEXA zu baino lehenago beteko dut!\p"
	.string "Ikusi arte!$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "{PLAYER}{KUN}, zuk zer egingo duzu?\p"
	.string "BORROKA FRONTEKO erronkari aurre\n"
	.string "egingo al diozu?\p"
	.string "Edo zure POKéDEXA betetzen saiatuko\n"
	.string "zara?\p"
	.string "Borroka galdu egingo nuen, baina\n"
	.string "POKéDEXA zu baino lehenago beteko dut!\p"
	.string "Ikusi arte!$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "BEÑAT: Ei, {PLAYER} da eta.\p"
	.string "Aitarentzako enkargu bat egiten ari naiz.\n"
	.string "Ez, ez naiz ari PANPINAK erosten.\p"
	.string "berdin da, aspaldiko.\p"
	.string "Egin nahi duzu borroka POKéMONAK nork\n"
	.string "hazi dituen hobeto neurtzeko?$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "BEÑAT: Zer, zer gertatzen da?\n"
	.string "Ez al duzu konfidantzarik?$"

LilycoveCity_Text_BrendanBattleMe:
	.string "BEÑAT: Egin nahi duzu borroka POKéMONAK\n"
	.string "nork hazi dituen hobeto neurtzeko?$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "BEÑAT: Oo, egon ziur ez dudala\n"
	.string "{PLAYER}(r)en kontra galduko.$"

LilycoveCity_Text_BrendanDefeat:
	.string "Ufff…\n"
	.string "Oso ongi hazi dituzu.\p"
	.string "Kaka zaharra, zu baino lehenago\n"
	.string "bihurtu nintzen ENTRENATZAILE…$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "BEÑAT: Ni…\n"
	.string "ERROTXIKIRA bueltatzeko asmotan nabil.\p"
	.string "Badakizu aitari POKéDEXA betetzen laguntzen\n"
	.string "ari naizela. Nahikoa itxura ona du,\l"
	.string "beraz, erakutsi egin behar nioke.$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "{PLAYER}, zer egingo duzu zuk?\p"
	.string "GIMNASIOKO DOMINA guztiak bildu eta\n"
	.string "POKéMON LIGAKO erronkari aurre egin?\p"
	.string "Nik ere bai, agian…\p"
	.string "Beno, berdin da, gogor eutsi!$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{PLAYER}, zer egingo duzu zuk?\p"
	.string "Horren indartsua izanda, POKéMON\n"
	.string "LIGAKO erronkari aurre egingo al diozu?\p"
	.string "Beno, nik ere nire POKéMONAK pixka bat\n"
	.string "gehiago entrenatuko banitu, zu baino\l"
	.string "indartsuagoa izango nintzateke, {PLAYER}.\p"
	.string "Beno, berdin da, gogor eutsi!$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{PLAYER}, zer egingo duzu zuk?\p"
	.string "BORROKA FRONTEKO erronkari aurre\n"
	.string "egingo al diozu?\p"
	.string "Edo zure POKéDEXA betetzen saiatuko\n"
	.string "al zara?\p"
	.string "Horren indartsua zarenez, BORROKA\n"
	.string "FRONTERA joan behar zenuke.\p"
	.string "Beno, nire POKéMONAK gehiago entrenatuz,\n"
	.string "garaitu egingo zintuzket, {PLAYER}.\p"
	.string "Agian ni joan behar nintzateke\n"
	.string "BORROKA FRONTERA.\p"
	.string "Beno, berdin da, gogor eutsi!$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "Fufufu…\p"
	.string "Gure EZKUTALEKU sekretura altxor\n"
	.string "gehiago eraman ditugu…\p"
	.string "No-nor zara zu?!\n"
	.string "Nire buruarekin ari nintzen!$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "ERREKRUTA bat besterik ez naiz, beraz,\n"
	.string "ez dakit NAGUSIA zertan ari den…\p"
	.string "Baina AQUA TALDEAN egonda, badakit\n"
	.string "gauza izugarriak egingo ditudala!\p"
	.string "No-nor zara zu?!\n"
	.string "Nire buruarekin ari nintzen!$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "Ei, aizu!\p"
	.string "Ez zaitez hurbildu kobazulora!\p"
	.string "Zergatik? Ez zaizu axola!\n"
	.string "Nagusia naiz, egin kasu niri, beraz!$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "Mundu zabal hau gure bilakatzen bada,\n"
	.string "AQUA TALDEARENA, alegia, leku alaia\l"
	.string "izango da POKéMONENTZAT ere.$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "Ea ba! WAILMER!\n"
	.string "Atera zaitez uretatik!$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "Nola? Zer nahi duzu?\p"
	.string "Gure entrenamendua zapuzten ari\n"
	.string "zara. Joan zaitezke hemendik?$"

LilycoveCity_Text_ContestHallInTown:
	.string "POKéMON TXAPELKETA ARETO bat\n"
	.string "dago herrian.\p"
	.string "Horregatik, ondo hazitako POKéMONAK\n"
	.string "etorriko dira toki guztietatik.\p"
	.string "Zirraraz betetzen zait bihotza!$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "Ikusi al duzu herriaren ertzean\n"
	.string "dagoen kobazulo arraro hori?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "Nire POKéMONEI eraso berriak erakutsiko\n"
	.string "dizkiet TXAPELKETAN sartu aurretik.\p"
	.string "ERASO EZABATZAILEARENGANA joango naiz\n"
	.string "ME erasoak ahaztu ditzaten.$"

LilycoveCity_Text_ImFromKanto:
	.string "KANTOTIK etorri naiz.\p"
	.string "HOENN eskualdea izugarri ederra da,\n"
	.string "itsaso eta naturaz inguratua.\p"
	.string "Nola? Itxaron apur bat…\p"
	.string "Egongo ote da hemen inguruan soilik\n"
	.string "bizi den POKéMON arrarorik?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "AQUA TALDEKOAK beraien WAILMER\n"
	.string "entrenatzen aritu dira kobazuloan.\p"
	.string "MARINELOK ezin gara itsasoratu\n"
	.string "haiek parean badaude!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "Txo, ba al zenekien?\p"
	.string "Norbaitek AQUA TALDEA kaleratu\n"
	.string "du gure zorionerako!\p"
	.string "WAILMER kobatik atera denez,\n"
	.string "berriz itsasoratu gaitezke.$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "Siesta lasaigarria hartzen ari nintzen\n"
	.string "itsasertzeko etxean…\p"
	.string "Eta norbaitek POKéMONA lapurtu dit!\p"
	.string "Zein ote da lapurra?\n"
	.string "AQUA TALDEA? Haiek izan ote dira?$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "Nire POKéMON galdua…\n"
	.string "Bueltan etorri da bat-batean!$"

LilycoveCity_Text_ImArtDealer:
	.string "ARTE SALEROSLEA naiz.\p"
	.string "Goi mailako artea saltzen eta erosten dut,\n"
	.string "margolanak, batez ere.\p"
	.string "Entzun dut hemengo MUSEOAN artelan\n"
	.string "izugarriak daudela erakusgai…$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "Gu zahartu eta zimurtzen bagara ere,\n"
	.string "itsasoa beti izango da gazte, bizitzaren\l"
	.string "distira argia galdu gabe…\p"
	.string "Uojojo uojojojojo…$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "Duela hirurogei urte eskatu zidan\n"
	.string "senarrak berekin ezkontzeko.\l"
	.string "Itsasoa beti bezain eder dago oraingik.\p"
	.string "Mufufufu mufufufufufu…$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "Ezagutzen al duzu hemengo\n"
	.string "haitzulo berezia?\p"
	.string "Kobazulo naturala zen, baina\n"
	.string "AQUA TALDEA etorri zen\l"
	.string "berrikuntzak egitera.\p"
	.string "“AQUA TALDEA, naturaren maitaleak”\n"
	.string "direla esan ohi dute beti!\p"
	.string "Baina esaten dutena eta\n"
	.string "egiten dutena ez doaz bat!$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "Haitzulo hori…\p"
	.string "Ez nintzen konturatu, baina,\n"
	.string "guztiz hutsik dago.\p"
	.string "AQUA TALDE horrek betirako\n"
	.string "alde egin duela dirudi.$"

LilycoveCity_Text_CitySign:
	.string "UR-LILI HIRIA\p"
	.string "“Lurra amaitu eta itsasoa\n"
	.string "hasten den lekua.”$"

LilycoveCity_Text_ContestHallSign:
	.string "POKéMON TXAPELKETA ARETOA\n"
	.string "“ENTRENATZAILEEN elkarlekua!”$"

LilycoveCity_Text_MotelSign:
	.string "UR-LILI KOBA MOTELA\p"
	.string "“UR-LILIKO KOBA gara\n"
	.string "gu.”$"

LilycoveCity_Text_MuseumSign:
	.string "UR-LILIKO MUSEOA\p"
	.string "“POKéMON Artelanen Bilduma\n"
	.string "erakusgai!”$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "UR-LILIKO MUSEOA\p"
	.string "“{PLAYER}(r)en POKéMON Bilduma\n"
	.string "erakusgai!”$"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "UR-LILIKO KAIA\p"
	.string "“MAREA ONTZI ferrya eraikitzen\n"
	.string "ari dira PORTUONDO HIRIAN.\p"
	.string "“Zerbitzua laister jarriko da\n"
	.string "martxan.”$"

LilycoveCity_Text_HarborSign:
	.string "UR-LILIKO KAIA\p"
	.string "“Gozatu bidaia miragarria\n"
	.string "MAREA ONTZI ferryan.”$"

LilycoveCity_Text_TrainerFanClubSign:
	.string "POKéMON ENTRENATZAILE FAN KLUBA\p"
	.string "ENTRENATZAILEEN izenak daude\n"
	.string "kartelean zehar zirriborratuta…$"

LilycoveCity_Text_DepartmentStoreSign:
	.string "UR-LILIKO ZENTRO KOMERTZIALA\p"
	.string "“Merkantzia eta zirraraz\n"
	.string "lepo gaude beti!\p"
	.string "“Behar duzuna aurkitzeko\n"
	.string "leku paregabea!”$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "ERASO EZABATZAILEAREN ETXEA\p"
	.string "“Nahi ez dituzun erasoak ezabatzen ditut.”$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "Ezagutzen al duzu\n"
	.string "BAIA BIRRINTZAILEA?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "Jendeak elkarrekin egin behar du\n"
	.string "lan birak azkarrago emateko.\p"
	.string "Azkarrago bira emanez, {POKEBLOCK}\n"
	.string "hobeak lortuko dituzu, entzun dudanez.$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "{POKEBLOCK} deritzen gozoki mota\n"
	.string "bat egiteko erabiltzen dira.\p"
	.string "POKéMON bati {POKEBLOCK} on bat emanda,\n"
	.string "bere egoera asko hobetuko da.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "Entzun dut itsasoan nonbait dorre\n"
	.string "galdu bat dagoela.\p"
	.string "ZERUAREN ZUTABEA deitzen omen diote.$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "Dorre altu bat ikusi nuen\n"
	.string "131. ERRUTA inguruan.\p"
	.string "Hura izango ote da…?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "Ezkontza osteko oporretatik\n"
	.string "iritsi berri gara.\p"
	.string "DRAGOI motako POKéMON bat ikusi\n"
	.string "dugu zeruan zehar hegan.\p"
	.string "Halako POKéMON itzelak al daude\n"
	.string "HOENN eskualdean?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "Ezkontza osteko oporretan, ahalik eta\n"
	.string "POKéMON arraro gehien ikusi nahi genituen.\p"
	.string "Oso pozik gaude, beraz, iritsi berritan\n"
	.string "POKéMON arraro bat ikusita.\p"
	.string "Benetan, izugarri pozik gaude!$"

