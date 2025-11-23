.set LOCALID_EXPERT_M, 4
.set LOCALID_TWIN, 5
.set LOCALID_SCHOOL_KID_M, 7
.set LOCALID_PSYCHIC_M, 8

DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "Zer dago modan? Bada, noski,\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Ezin dut bizitza imaginatu ere egin\n"
	.string "“{STR_VAR_1}” gabe!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "Zer dago modan? Bada, noski,\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Baina pixka bat aspertzen hasi naiz.\p"
	.string "Zeozer berriagoa aurkitu behar dut.$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "Nire POKéMONEI ari naiz erakusten\n"
	.string "zer den “{STR_VAR_1},”\l"
	.string "baina ez doa ondo.\p"
	.string "Gehiegitxo da, nik uste.$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "Guztiz modan dagoen “{STR_VAR_1}”\n"
	.string "aztertzen ari naiz orain.\p"
	.string "Egia al da lotura sakona dagoela\n"
	.string "“{STR_VAR_1}” eta\l"
	.string "“{STR_VAR_2}” artean?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "Ene!\n"
	.string "Ondo nenbilen, orduan!\p"
	.string "Gero eta hurbilago nago modan\n"
	.string "egotetik, iuju!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "Zer?!\n"
	.string "Benetan ari al zara?!\p"
	.string "Ni bezalako pertsona zaharrarentzat\n"
	.string "ez da erraza moda jarraitzea!$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "“{STR_VAR_1}” honen gaineko\n"
	.string "kontu guzti hau…\l"
	.string "Ba al dago telesailik horren inguruan?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "Itsasoaren beste aldean…\p"
	.string "“{STR_VAR_1}” are\n"
	.string "ezagunagoa ote da?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "Benetako “{STR_VAR_1}”\n"
	.string "merkantzia ofiziala\l"
	.string "biltzen dut.\p"
	.string "“{STR_VAR_1}” PANPINA\n"
	.string "ofizialak ditut…\p"
	.string "“{STR_VAR_1}” markako\n"
	.string "arropa ofiziala…\p"
	.string "Eta “{STR_VAR_1}”\n"
	.string "argazki liburu\l"
	.string "ofizialak ere.\p"
	.string "Kar-kar-kar, nireak dira!\n"
	.string "Ez dut ezer zurekin partekatuko!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "NOLA IDENTIFIKATU\n"
	.string "“{STR_VAR_1}” ONA &\l"
	.string "“{STR_VAR_1}” TXARRA…\p"
	.string "“{STR_VAR_1}” ETA\n"
	.string "POKéMONEN ARTEKO\l"
	.string "LOTURA…\p"
	.string "“{STR_VAR_1}”\n"
	.string "ERABILGARRIAK…\p"
	.string "“{STR_VAR_1}” gaiaren inguruko\n"
	.string "liburuz gainezka dago$"

DewfordTown_Hall_Text_TrendsScream:
	.string "“{STR_VAR_1}(r)en\n"
	.string "OIHUA” da titulua.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "“{STR_VAR_1}(r)en\n"
	.string "IRRIBARREA” da titulua.$"

DewfordTown_Hall_Text_LastTrend:
	.string "Titulua “AZKEN\n"
	.string "{STR_VAR_1}(a)” da.$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "Titulua “{STR_VAR_1}(r)en\n"
	.string "JAIOTZA” da.$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "“{STR_VAR_1}” ikusi dut!\n"
	.string "Itzela, ezta?\p"
	.string "Gauza itzelena da oraintxe!\p"
	.string "Paregabea izan zen!\n"
	.string "Benetan paregabea, alajaina!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "Ai, ez, ez, ez.\p"
	.string "Zuk ikusi omen duzun\n"
	.string "“{STR_VAR_1}” hori\l"
	.string "ez da egiazkoa.\p"
	.string "Benetako artikulua, jakizu…\n"
	.string "Nola esan?\l"
	.string "Zorrotzagoa, baina leunagoa da!\p"
	.string "Ez du axola. Sinesgaitza da!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "Ei, entzun, kanta bat asmatu dut\n"
	.string "“{STR_VAR_1} goraipatuz.”\p"
	.string "“{STR_VAR_1}”\n"
	.string "moda-modan dago orain.\p"
	.string "Ongi, entzun!\n"
	.string "… …\p"
	.string "Uu!\n"
	.string "{STR_VAR_1}!\p"
	.string "{STR_VAR_1}\n"
	.string "bikaina!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "… …\p"
	.string "Barkatu, baina, esango nuke ahotsa\n"
	.string "pixka bat landu behar zenukeela\l"
	.string "kanta bat egin nahi baduzu\l"
	.string "“{STR_VAR_1}” goraipatuz.$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "Berdin da, lehen esan bezala, batu\n"
	.string "eta festa bat antolatu behar genuke\l"
	.string "“{STR_VAR_1}” goraipatzeko, irla\l"
	.string "honetan.$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "Ene, hori bai ideia aparta!\p"
	.string "Behingoz jakingo dugu nor\n"
	.string "den guztietan onena\l"
	.string "“{STR_VAR_1}”(e)ri dagokionez.\l"
	.string "Bikaina, alajaina!\p"
	.string "Gaur hasita, “{STR_VAR_1}”(r)en inguruan\n"
	.string "antolatuko ditugu gure bizitzak!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "Pentsatzen aritu naiz…\p"
	.string "Ez al zaizu iruditzen\n"
	.string "“{STR_VAR_1}” gero eta\l"
	.string "garrantzitsuagoa bihurtu dela\l"
	.string "gure eguneroko bizitzan?$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "Barkatu?\n"
	.string "Horrenbeste?\p"
	.string "Hala ere, egia da\n"
	.string "“{STR_VAR_1}” beti\l"
	.string "dagoela zure buruan, esna\l"
	.string "edo lo egonda ere.\p"
	.string "Dudarik gabe, zu zara\n"
	.string "“{STR_VAR_1}”\l"
	.string "KAPITAINA, bai jauna!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "Zu eta ni elkartzen bagara, garaitezinak\n"
	.string "izango gara “{STR_VAR_1}”(e)n\l"
	.string "inguruko gauzetan!$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "Hori da, lagun!\p"
	.string "“{STR_VAR_1}” BIKOTEA\n"
	.string "izango gara!\p"
	.string "Ez al da irudi ederra?\n"
	.string "Kar-kar-kar!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "Niretzat, LOKATZ BONBA moda-modan\n"
	.string "dago. Ez dago duda izpirik.\p"
	.string "Zer? LOKATZ BONBA zer den\n"
	.string "ez dakizula diozu?\p"
	.string "Pena handia da hori.\n"
	.string "Bat emango dizut.$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "LOKATZ BONBA atsegin dut.\p"
	.string "Baina “{STR_VAR_1}” erasoa\n"
	.string "duten POKéMONAK ere asko\l"
	.string "gustatzen zaizkit.$"

