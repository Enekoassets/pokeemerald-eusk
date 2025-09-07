.set LOCALID_WALDAS_DAD, 6

RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	waitstate
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Ene, gogorrak dira egun guztiak…\p"
	.string "Zer den gogorra?\n"
	.string "Galdetzea ere!\p"
	.string "Egunero zer jan erabakitzea\n"
	.string "da gogorra.\p"
	.string "Ez da batere erraza egunero zein\n"
	.string "plater prestatu jakitea.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "Ei, kaixo!\n"
	.string "Ongi etorri PIPER etxera.\p"
	.string "Galdera bat dut zuretzat.\n"
	.string "Inoiz zaindu al duzu umerik?\p"
	.string "Izan ere, aita izan berri naiz, ume\n"
	.string "bat zaintzea guztiz berria da niretzat.\p"
	.string "Eta arazo bat dut. ANAPELEK, nire\n"
	.string "alabak, ez du nahikoa barrerik egiten.\p"
	.string "Uste nuen barre egingo zuela zerbait\n"
	.string "barregarria esan nionean.\p"
	.string "Ezagutzen duzu hitz edo esaldi\n"
	.string "barregarririk berari esateko?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "“{STR_VAR_1}” esaten aritu naiz\n"
	.string "bera dibertitzen saiatzeko.\p"
	.string "Ezagutzen al duzu funtzionatu\n"
	.string "dezakeen hitz edo esaldi hobetik?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "Bai, bikaina da hori.\n"
	.string "Beno, entzun dezagun zure ideia, orduan.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "Ene, benetan al diozu?\p"
	.string "Beno, ba ideiaren bat bururatzen\n"
	.string "bazaizu, lasai kontatu.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "Bai, ados.\n"
	.string "Beno, saiatu gaitezen, orduan?$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Bai, bai! Barrez ari da!\n"
	.string "Ene, bera bezain zoriontsu naiz orain!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "Bai, ados.\n"
	.string "Beno, saiatu gaitezen, orduan?$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… Ez du irribarrerik ere egin.\n"
	.string "Agian ANEPEL ume serioa da…$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "Beraz, ez duzu hitz egokirik ezagutzen.\n"
	.string "Nik pentsatuko dut orduan.\p"
	.string "Hmm…\n"
	.string "Zer iruditzen “{STR_VAR_1}”?\l"
	.string "Ikus dezagun, ea funtzionatzen duen.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… Ez du irribarrerik ere egin.\n"
	.string "Agian ANEPEL ume serioa da…$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "Beraz, ez duzu hitz egokirik ezagutzen.\n"
	.string "Orain arte esan diodana errepikatuz\l"
	.string "saiatuko naiz orduan.\p"
	.string "Beno, hitz egokiren bat bururatzekotan,\n"
	.string "abisatu niri, ados?$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Eskerrik asko!\p"
	.string "Zuri esker, nire ANEPEL maiteak\n"
	.string "barre egin du!\p"
	.string "Egia esan, nahi eta pertsona arrunta\n"
	.string "ematen dudan, DEVON KORPORAZIOKO\l"
	.string "goi mailako ikerlaria naiz.\p"
	.string "beraz, zer iruditzen zure laguntzagatik\n"
	.string "zerbait egiten badut trukean?\p"
	.string "Badakit, zure PCko KUTXENTZAKO\n"
	.string "horma paper berriak egingo ditut\l"
	.string "POKéMONEN Gordailu Sistemarako.\p"
	.string "Horma paperen diseinuen menuan,\n"
	.string "aukeratu “LAGUNAK.”\p"
	.string "Bertan aurkituko dituzu horma\n"
	.string "paperen diseinu berriak.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "POKéMON baten PANPINA bat da!$"

