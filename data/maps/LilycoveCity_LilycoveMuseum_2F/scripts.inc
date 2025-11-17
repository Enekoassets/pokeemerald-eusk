.set LOCALID_CURATOR, 1

LilycoveCity_LilycoveMuseum_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_LilycoveMuseum_2F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_LilycoveMuseum_2F_OnFrame
	.byte 0

LilycoveCity_LilycoveMuseum_2F_OnLoad:
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting::
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting::
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting::
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting::
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting::
	setmetatile 10, 6, METATILE_LilycoveMuseum_Painting2_Left, TRUE
	setmetatile 11, 6, METATILE_LilycoveMuseum_Painting2_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting::
	setmetatile 18, 6, METATILE_LilycoveMuseum_Painting1_Left, TRUE
	setmetatile 19, 6, METATILE_LilycoveMuseum_Painting1_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting::
	setmetatile 14, 10, METATILE_LilycoveMuseum_Painting3_Left, TRUE
	setmetatile 15, 10, METATILE_LilycoveMuseum_Painting3_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting::
	setmetatile 6, 10, METATILE_LilycoveMuseum_Painting0_Left, TRUE
	setmetatile 7, 10, METATILE_LilycoveMuseum_Painting0_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting::
	setmetatile 2, 6, METATILE_LilycoveMuseum_Painting4_Left, TRUE
	setmetatile 3, 6, METATILE_LilycoveMuseum_Painting4_Right, TRUE
	end

LilycoveCity_LilycoveMuseum_2F_OnFrame:
	map_script_2 VAR_LILYCOVE_MUSEUM_2F_STATE, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall
	.2byte 0

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall::
	lockall
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall, MSGBOX_SIGN
	applymovement LOCALID_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall, MSGBOX_SIGN
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit, MSGBOX_SIGN
	copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft:
	walk_in_place_faster_left
	step_end

LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall:
	face_up
	delay_16
	step_end

LilycoveCity_LilycoveMuseum_2F_EventScript_Curator::
	lockall
	goto_if_set FLAG_RECEIVED_GLASS_ORNAMENT, LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 1, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 2, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 3, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 4, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 5, LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer::
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer, MSGBOX_DEFAULT
	applymovement LOCALID_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests, MSGBOX_DEFAULT
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament::
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude, MSGBOX_DEFAULT
	givedecoration DECOR_GLASS_ORNAMENT
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament
	setflag FLAG_RECEIVED_GLASS_ORNAMENT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament::
	call Common_EventScript_NoRoomForDecor
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit, MSGBOX_NPC
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CutePainting::
	lockall
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ToughPainting::
	lockall
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CoolPainting::
	lockall
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_BeautyPainting::
	lockall
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SmartPainting::
	lockall
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_Girl::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ExpertM::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_RichBoy::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_COOL
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_BEAUTY
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_CUTE
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_SMART
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_TOUGH
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall:
	.string "Hau gure erakusketa areto berezia da.$"

LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall:
	.string "Ikus dezakezunez, ez dugu margolan\n"
	.string "bat bera ere eskegita.\p"
	.string "Hemen ez nuke klasiko deritzen\n"
	.string "artelanik jarri nahi.\p"
	.string "Halako artelan klasikoak beheko\n"
	.string "pisuan ikus ditzakezu.\p"
	.string "Pisu honetan bestelako artelanak\n"
	.string "erakutsi nahi nituzke.\p"
	.string "Artea, azken finean, ez dute artelan\n"
	.string "zahar famatuek bakarrik osatzen!\p"
	.string "Erakusketa areto hau bete nahi nuke…\p"
	.string "POKéMONEN artelan moderno eta\n"
	.string "biziak, mundu guztiak ikus\l"
	.string "ditzan hemen eskegita!$"

LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit:
	.string "Barkatu, benetan. Ez nuen\n"
	.string "elkarrizketa monopolizatu nahi.\p"
	.string "Baina, gaztea zarenez, eta asko\n"
	.string "bidaiatutakoa, begi bistan denez…\p"
	.string "Ziur POKéMONEN artelan bizi\n"
	.string "asko ikusten dituzula.\p"
	.string "Halako amrgolanen bat aurkituko\n"
	.string "bazenu, zer iruditzen zaizu hemen\l"
	.string "eskegitzeko artistaren baimena\l"
	.string "lortzen saiatuko bazina?$"

LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit:
	.string "Erakusketa areto hau POKéMONEN\n"
	.string "artelan moderno eta biziz bete\l"
	.string "nahi nuke.$"

LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting:
	.string "Zuri esker, margolan berri bat\n"
	.string "gehitu dugu bildumara!\p"
	.string "Zure POKéMONARENA dela entzun dut.\n"
	.string "Benetan sekulakoa!\p"
	.string "benetan, eskerrik asko!$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer:
	.string "Ei! Zu zara eta!\n"
	.string "{PLAYER}!$"

LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests:
	.string "Ez al da izugarria?\n"
	.string "Margolan bilduma hau!\p"
	.string "Akatsik gabeak dira denak!\n"
	.string "Ez dago besteak baino hobea denik!\p"
	.string "Margolan hauei esker bezero gehiago\n"
	.string "etorri dira gure ARTE MUSEORA.\p"
	.string "Zinez, eskerrik asko, {PLAYER}.\n"
	.string "Nire ametsa bete da!$"

LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude:
	.string "Hau nire esker onaren erakusle.$"

LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou:
	.string "Berriz elkar ikusten dugun arte\n"
	.string "gordeko dizut hau.$"

LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit:
	.string "Ene, a zer poza, {PLAYER}!\p"
	.string "Ohorea da zu bisitan etortzea,\n"
	.string "ziur oso lanpetuta zaudela.\p"
	.string "Mesedez, erlaxatu eta gozatu\n"
	.string "zure bisita.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame:
	.string "Kolore larrosako apaingarridun\n"
	.string "marko bat da.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame:
	.string "Kolore horiko apaingarridun\n"
	.string "marko bat da.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame:
	.string "Kolore urdineko apaingarridun\n"
	.string "marko bat da.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame:
	.string "Kolore gorriko apaingarridun\n"
	.string "marko bat da.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame:
	.string "Kolore berdeko apaingarridun\n"
	.string "marko bat da.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon:
	.string "POKéMON baten margolana da.$"

LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe:
	.string "Kanpoan ibili naiz, beraz, margolan\n"
	.string "berriek harrituta utzi naute.\p"
	.string "Norbaitek nire POKéMONAK horren\n"
	.string "eder margotzea nahi nuke.$"

LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing:
	.string "Ados… Hemen erakusten dituzte\n"
	.string "POKéMONEN margolanak, beraz.\p"
	.string "Ikusten dut, margolan berri hauek\n"
	.string "nahikoa dibertigarriak dira.$"

LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon:
	.string "Ene, egia al da hori?\n"
	.string "Margolan hauek zure POKéMONENAK dira.\p"
	.string "Ez al da hori ENTRENATZAILE\n"
	.string "baten alaitsaun gorena?$"

