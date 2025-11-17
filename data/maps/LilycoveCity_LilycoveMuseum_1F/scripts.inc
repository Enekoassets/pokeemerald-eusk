.set LOCALID_CURATOR, 2
.set LOCALID_ARTIST_2, 8

LilycoveCity_LilycoveMuseum_1F_MapScripts::
	.byte 0

LilycoveCity_LilycoveMuseum_1F_EventScript_Greeter::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Curator::
	lockall
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	message LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings
	waitmessage
	multichoice 20, 8, MULTI_VIEWED_PAINTINGS, TRUE
	goto_if_eq VAR_RESULT, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings
	goto_if_eq VAR_RESULT, 1, LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested
	goto_if_eq VAR_RESULT, YES, LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat, MSGBOX_SIGN
	releaseall
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe, MSGBOX_SIGN
	applymovement LOCALID_CURATOR, LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs
	waitmovement 0
	removeobject LOCALID_CURATOR
	switch VAR_FACING
	case DIR_NORTH, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth
	case DIR_WEST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest
	case DIR_EAST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs:
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest:
	walk_left
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast:
	walk_right
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth:
	walk_up
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_EventScript_OldPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FantasyPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_WomanPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_LegendaryPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_GrassPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_BerryPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_EventScript_BirdSculpture::
	msgbox LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PokeBallSculpture::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_StoneTablet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SchoolKidM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NinjaBoy::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman2::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PsychicM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist2::
	lock
	faceplayer
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARTIST_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FatMan::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum:
	.string "Ongi etorri UR-LILIKO MUSEORA.\p"
	.string "Hartu behar duzun denbora guztia\n"
	.string "POKéMONEZ beteriko gure artelan\l"
	.string "bilduma zabala ikusteko.$"

LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings:
	.string "MUSEO honetako artelan finen\n"
	.string "ARDURADUNA naiz.\p"
	.string "Zu bezalako pertsona gazte bat\n"
	.string "MUSEOAN ikusteak asko pozten nau.\p"
	.string "Ikusi al duzu gure margolanen\n"
	.string "bilduma jada?$"

LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime:
	.string "Ongi, orduan ez dizut enbarazu egingo.\n"
	.string "Mesedez, hartu behar duzun denbora guztia.$"

LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings:
	.string "Zer? POKéMON ENTRENATZAILEA\n"
	.string "dirudizu, dudarik gabe.\p"
	.string "Margolanetan ere interesa al\n"
	.string "duzu, ba?$"

LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat:
	.string "Ongi…\p"
	.string "Asko pozten nau hala ere gu\n"
	.string "bisitatzera etortzeak.$"

LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe:
	.string "Ene, bikain!\n"
	.string "Atsgein dituzu margolanak!\p"
	.string "Orduan, etorriko zinateke nirekin?$"

LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting:
	.string "Oso margolan zaharra da.\n"
	.string "Pintura askatzen ari da leku guztietan.$"

LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery:
	.string "Eszenografia bitxi eta fantastikoa\n"
	.string "duen paisaia berezia da.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman:
	.string "POKéMON bat altzoan duen emakume eder\n"
	.string "eta irribarretsu baten margolana da.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon:
	.string "Antzinako POKéMON legendario baten\n"
	.string "margolana da.\p"
	.string "Artistak bere imaginaziotik\n"
	.string "abiatuta margotu zuen.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon:
	.string "Haizearekin kulunkan ari den\n"
	.string "LANDARE POKéMON baten artelana.\p"
	.string "Haizearen fereka leuna gozatzen\n"
	.string "ari dela dirudi.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries:
	.string "Itxura gozo-gozoa duten\n"
	.string "BAIA batzuen margolana da.\p"
	.string "Gose izugarria ematen du koadroak!$"

LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica:
	.string "Eskultura famatu baten erreplika da.\p"
	.string "Antzinako TXORI POKéMON baten itxura du.$"

LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone:
	.string "Harri beltz batean zizelkatutako\n"
	.string "POKé BALL erraldoia da.\p"
	.string "Garai batean jaialdietan\n"
	.string "erabiltzen omen zen.$"

LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText:
	.string "POKéMONAK eta antzinako hizkuntza\n"
	.string "irakurtezin bateko karaktereak\l"
	.string "grabatuta dituen harrizko\l"
	.string "taula bat da.$"

LilycoveCity_LilycoveMuseum_1F_Text_WorksOfMagnificence:
	.string "Hmmm…\n"
	.string "Hauek bai sekulako lanak…$"

LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts:
	.string "POKéMONEKIN borrokan aritzea oso\n"
	.string "dibertigarria da, arrazoia duzu.\p"
	.string "Baina ezin dugu artearekiko dugun\n"
	.string "maitasuna ahaztu.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration:
	.string "ARTE MUSEO hau… Beno, hainbat\n"
	.string "margolan izugarri ikus ditzakezu.\p"
	.string "Eta ARDURADUNA oso pertsona jatorra da.\p"
	.string "Ni bezalako artistentzat, MUSEO hau\n"
	.string "inspirazio iturri itzela da.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty:
	.string "Andereño hau ederra da!\n"
	.string "Amatxo bezalakoa da!$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable:
	.string "POKéMON hau polit-polita da!\n"
	.string "Gure mutikoa bezala!$"

LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings:
	.string "Entzun dut ARTE MUSEO honetan\n"
	.string "margolan berriak ipini dituztela.\p"
	.string "Noski, ziztu batean etorri naiz.\p"
	.string "Margolan berriak bigarren\n"
	.string "pisuan al daude?$"

LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful:
	.string "Azkenaldian, ARDURADUNA bereziki\n"
	.string "pozik dago.\p"
	.string "Ziur zeozer ona pasa zaiola.\n"
	.string "Ezbairik gabe.$"

LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings:
	.string "Nire helburua hainbat margolan itzel\n"
	.string "ikusi eta haiengandik ikastea da.\p"
	.string "Egunen batean nire artelanak hemen\n"
	.string "erakustea da nire ametsa.$"

LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination:
	.string "ARTE MUSEOA turisten helmuga\n"
	.string "gustokoena bihurtu da.\p"
	.string "UR-LILIRENTZAT oso ona da…\n"
	.string "Ez, HOENN osoarentzat da ona!\p"
	.string "Entzun dudanez, ENTRENATZAILE bakarrak\n"
	.string "bildu ditu goiko pisuko koadroak.$"

