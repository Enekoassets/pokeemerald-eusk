LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string "Ai, ene, ene! Bakarrik bidaiatzen ari zara?\n"
	.string "Baina oso gaztea zara! Bejondeizula!\p"
	.string "Nire umeek zerbait ikasiko\n"
	.string "lukete zugandik, alajaina!\p"
	.string "Ni? {POKEBLOCK}EN aditua naiz.\p"
	.string "Serio jartzen naizenean, {POKEBLOCK}\n"
	.string "itzelak egin ditzaket.\p"
	.string "Nigandik ikasi nahi al zenuke,\n"
	.string "{POKEBLOCK}EN aditu batengandik?$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "Zer? Ziur al zaude?\p"
	.string "Guztia ez duzu zuk bakarrik\n"
	.string "egin behar, maitea!$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "Oso ondo! Zu bai zarela argia!\n"
	.string "Hau pixka bat luzea da, ondo entzun!\p"
	.string "Prest?\p"
	.string "{POKEBLOCK}EI adituz gero, haien ukipenaren\n"
	.string "arabera baloratzen direla ikus dezakezu.\p"
	.string "Zenbat eta ukipen puntuazio baxuagoa,\n"
	.string "orduan eta hobe. Ez ahaztu!\p"
	.string "{POKEBLOCK} on batek ukipen puntuazio\n"
	.string "baxua eta maila altua dauka.\p"
	.string "POKéMON batek {POKEBLOCK} on\n"
	.string "gehiago jan ditzake, arruntak baino.\p"
	.string "Garrantzitsua da hau.\p"
	.string "{POKEBLOCK} leunak egin nahi badituzu,\n"
	.string "erabili BAIA mota desberdinak.\p"
	.string "Ez izan zekena, BAIA motek eragina\n"
	.string "dute {POKEBLOCK}EN leuntasunean.\p"
	.string "Eta beste kontu bat.\p"
	.string "Zenbat eta pertsona gehiago BAIAK nahasten,\n"
	.string "orduan eta {POKEBLOCK} leunagoak.\p"
	.string "Horregatik besteekin hitz egin\n"
	.string "{POKEBLOCK}AK elkarrekin egiteko.\p"
	.string "Esandakoa kontuan hartuta, nahikoa duzu\n"
	.string "{POKEBLOCK} onak egiteko.\p"
	.string "Mundu guztiak POKéMON maitekorrak,\n"
	.string "{POKEBLOCK} leunak, eta familia bat balitu,\l"
	.string "mundua leku alaiagoa litzateke.\p"
	.string "Ez amore eman, maitea!$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "Nire emazteak laukiak erditu zituenean,\n"
	.string "harrituta geratu nintzen.\p"
	.string "Baina, orain, batera jolasten ikusten\n"
	.string "ditudanean, oso pozik jartzen naiz.$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "MULTI BORROKAK egiten ari gara, baina\n"
	.string "badakit irabazi egingo dudala.$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "ERREKORREN TXOKOAN gauzak\n"
	.string "nahastea atsegin dugu.\p"
	.string "Baina zer nahasten ote dugu?$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "Super {POKEBLOCK}AK egingo ditugu\n"
	.string "BAIA NAHASLE batekin!$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "Nire POKéMONAREN indarra erakutsi nahi\n"
	.string "diot mundu guztiari, beraz, TXAPELKETA\l"
	.string "batean hartuko dugu parte.$"

