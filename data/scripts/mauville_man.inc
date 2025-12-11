MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, FALSE  @ Play his current song
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, TRUE  @ Play the new song
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_UNLOCKED_TRENDY_SAYINGS
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "Hi, I'm the TRADER.\n"
	.string "Want to trade decorations with me?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "Beno…\n"
	.string "Erdi triste utzi nauzu, bai…$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "But we've traded decorations already,\n"
	.string "you and I.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "If you see any decorative item that\n"
	.string "you want of mine, speak up.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "You don't want anything?\n"
	.string "I feel unwanted…$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "That decorative item once belonged\n"
	.string "to {STR_VAR_1}.\p"
	.string "Do you want it?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "Uh… Wait a second. You don't have a\n"
	.string "single piece of decoration!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "Okay, pick the decoration that you'll\n"
	.string "trade to me.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "You won't trade with me?\n"
	.string "I feel unwanted…$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "You've got all the {STR_VAR_2}S that can\n"
	.string "be stored. You've no room for this.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "Okay, so we'll trade my {STR_VAR_3}\n"
	.string "for your {STR_VAR_2}?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "That piece of decoration is in use.\n"
	.string "You can't trade it.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "Then we'll trade!\n"
	.string "I'll send my decoration to your PC.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "Oops! Sorry! That's a really rare\n"
	.string "piece of decoration.\l"
	.string "I can't trade that one away!\p"
	.string "Can I interest you in something else?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	waitstate
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	waitstate
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "IPUIN KONTALARIA naiz.\n"
	.string "Elezaharretako ENTRENATZAILEEN\l"
	.string "istorioak kontatzen ditut.\p"
	.string "Entzun nahi al duzu nire istorioa?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "Beno…\n"
	.string "Erdi triste utzi nauzu, bai…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "Elezahar hauek ezagutzen ditut.\n"
	.string "Zein nahi duzu kontatzea?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "Baina ez dut elezaharretako ENTRENATZAILERIK\n"
	.string "ezagutzen. Ondorioz, ez dut istoriorik.\p"
	.string "Non aurki daitezke elezaharretarako\n"
	.string "modukoak diren ENTRENATZAILEAK?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "Zer diozu?!\n"
	.string "Zu… Zu…\p"
	.string "{STR_VAR_2}\n"
	.string "{STR_VAR_1} aldiz?!\p"
	.string "Hori izugarria da!\n"
	.string "Mito berria jaio da!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "Pentsarazi egiten dit: egongo ote da\n"
	.string "ENTRENATZAILE gehiago kondairetan\l"
	.string "agertzeko modukorik?$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "ENTRENATZAILEA al zara?\p"
	.string "Esan, orduan, ezagutzen al duzu\n"
	.string "kondaira izan daitekeen istoriorik?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "Incidentally… Would you care to hear\n"
	.string "another legendary tale?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "Hmm…\n"
	.string "Ez da nahikoa…\p"
	.string "Mito dei diezaiekedan istorioak\n"
	.string "ekartzea behra dut.$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "Jendeak nire ENTRENATZAILE mitikoen\n"
	.string "istorioei kasu gehiago egitea\l"
	.string "nahi nuke.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "Gorde-gorde ENTRENATZAILEA$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "Partida gorde$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "gorde zuen bere partida!\p"
	.string "Ez dago inon {STR_VAR_3} baino\n"
	.string "ENTRENATZAILE zuhurragorik!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "ENTRENATZAILE Moda Ezarlea$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "Ezarritako modak$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1}\n"
	.string "hasi zituen modak!\p"
	.string "{STR_VAR_3} HOENN osoan moda berriak\n"
	.string "ezartzen ari da!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "ENTRENATZAILE BAIA landatzailea$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "Landatutako BAIAK$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1}\n"
	.string "aldiz landatu zituen BAIAK!\p"
	.string "{STR_VAR_3} BAIEN maitale\n"
	.string "mitikoa da!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "ENTRENATZAILE txirrinduzalea$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "Trukatutako BIZIKLETAK$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1}\n"
	.string "aldiz trukatu zituen BIZIKLETAK!\p"
	.string "{STR_VAR_3} honek bene-benetan\n"
	.string "maite ditu BIZIKLETAK!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "Elkarrizketatutako ENTRENATZAILEA$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "Elkarrizketatu zuten$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE hau {STR_VAR_1}\n"
	.string "aldiz elkarrizketatu zuten!\p"
	.string "{STR_VAR_3} atentzio asko ematen\n"
	.string "duen ENTRENATZAILEA izango da!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "ENTRENATZAILE borrokalaria$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "Borrokatu zuen$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "{STR_VAR_1} aldiz borrokatu zuen!\p"
	.string "{STR_VAR_3} honek ez dio inoiz\n"
	.string "ezetz esaten borroka on bati!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "ENTRENATZAILE POKéMON harrapatzailea$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "Harrapatutako POKéMONAK$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} POKéMON\n"
	.string "harrapatu zituen!\p"
	.string "{STR_VAR_3} kondairetako POKéMON\n"
	.string "harraptzaile onena da!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "ENTRENATZAILE arrantzalea$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "Arrantzatutako POKéMONAK$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} POKéMON\n"
	.string "harrapatu zituen arrantza eginda!\p"
	.string "{STR_VAR_3} kondairetako arrantzale\n"
	.string "adituena da!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "ENTRENATZAILE ARRAUTZA-jagolea$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "Zaindutako ARRAUTZAK$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} POKéMON\n"
	.string "jaioarazi zituen ARRAUTZETATIK!\p"
	.string "{STR_VAR_3} kondairetako ARRAUTZA\n"
	.string "jagolea da!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "ENTRENATZAILE eboluzionatzailea$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "Eboluzionatutako POKéMONAK$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} POKéMON\n"
	.string "eboluzionatu zituen!\p"
	.string "{STR_VAR_3} munduko POKéMON\n"
	.string "eboluzionatzaile onena da!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "ENTRENATZAILE POKéMON ZENTROZALEA$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "Erabilitako POKéMON ZENTROAK$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "sendatu zituen POKéMONAK ZENTROETAN!\p"
	.string "Ez dago {STR_VAR_3} baino POKéMON\n"
	.string "ZENTROEN maitale handiagorik!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "ENTRENATZAILE etxekoia$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "Etxean sendatutako POKéMONAK$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "sendatu zituen POKéMONAK etxean!\p"
	.string "Ez dago {STR_VAR_3} baino\n"
	.string "ENTRENATZAILE etxekoiagorik!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "ENTRENATZAILE SAFARIZALEA$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "SAFARI GUNEAN sartu$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE hau {STR_VAR_1} aldiz\n"
	.string "sartu zen SAFARI GUNEAN!\p"
	.string "{STR_VAR_3} ENTRENATZAILEAREN zati\n"
	.string "basatia SAFARI GUNEAN agertzen da!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "ENTRENATZAILE EBAKITZAILEA$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "EBAKIA erabili$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "erabili zuen EBAKIA!\p"
	.string "{STR_VAR_3} EBAKITZEA benetan\n"
	.string "atsegin duen ENTRENATZAILEA da!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "ENTRENATZAILE HAITZ APURLEA$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "Puskatutako haitzak$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "puskatu ditu haitzak!\p"
	.string "{STR_VAR_3} haitz bat hautsi gabe\n"
	.string "utzi ezin duen ENTRENATZAILEA da!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "ENTRENATZAILE etxe aldaketazalea$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "BASE SEKRETUA aldatu$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "aldatu du BASE SEKRETUA lekuz!\p"
	.string "{STR_VAR_3} etxe aldaketak atsegin\n"
	.string "dituen ENTRENATZAILEA da!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "ENTRENATZAILE ZIPRIZTINLARIA$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "ZIPRIZTINA erabili$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "erabili du ZIPRIZTINA!\p"
	.string "{STR_VAR_3} dena ZIPRIZTINTZEA\n"
	.string "gustoko duen ENTRENATZAILEA da!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "ENTRENATZAILE nekaezina$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "BORROKA erabili behar izan$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "erabili behar izan du BORROKA!\p"
	.string "{STR_VAR_3} guztiari aurre egiten\n"
	.string "dion ENTRENATZAILE nekaezina da!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "TXANPONJALEEN Aditua$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "MAKINA TXANPONJALEETAN irabazi$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "irabazi du MAKINA TXANPONJALEETAN.\p"
	.string "{STR_VAR_3} MAKINA TXANPONJALEETAN\n"
	.string "zortea duen ENTRENATZAILEA da!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "ERRULETAKO Txapelduna$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "ERRULETAN jarraian irabazi$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "irabazi zuen jarraian ERRULETAN\p"
	.string "{STR_VAR_3} zortekoa izan zen bolak\n"
	.string "ERRULETAN jauzi egin zuenean!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "BORROKA DORREKO Erronkaria$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "BORROKA DORREKO erronkari aurre egin$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "egin zion aurre BORROKA DORREARI!\p"
	.string "{STR_VAR_3} BORROKA DORREAN bikaintasuna\n"
	.string "bilatzen duen ENTRENATZAILEA da!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "ENTRENATZAILE BIRRINTZAILEA$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "{POKEBLOCK}AK egin$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "egin ditu {POKEBLOCK}AK!\p"
	.string "Ez dago {STR_VAR_3} baino hoberik\n"
	.string "BAIA BIRRINTZAILEA erabiltzen!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "ENTRENATZAILE TXAPELKETAZALEA$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "TXAPELKETETAN parte hartu$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "hartu du parte TXAPELKETETAN!\p"
	.string "{STR_VAR_3} bere POKéMONAK besteei\n"
	.string "erakusten onena da!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "TXAPELKETEN ADITUA$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "TXAPELKETAK irabazi$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "irabazi ditu TXAPELKETAK!\p"
	.string "{STR_VAR_3} TXAPELKETETAN inongo\n"
	.string "ADITUENA izango da!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "Erosle alaia$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "Erosi$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "erosi ditu itemak dendetan!\p"
	.string "{STR_VAR_3} guztia erosteko jaio\n"
	.string "zen horietakoa da.$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "ENTRENATZAILE item bilatzailea$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "ZAHORIA erabili$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "erabili du ZAHORIA!\p"
	.string "{STR_VAR_3} lurra item bila ondo\n"
	.string "aztertzen duen horietakoa da!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "Blai egindako ENTRENATZAILEA$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "Euriak harrapatu$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE hau {STR_VAR_1} aldiz\n"
	.string "harrapatu du euriak!\p"
	.string "{STR_VAR_3}(r)en izaerak euria\n"
	.string "ere erakartzen du!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "POKéDEX Irakurlea$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "POKéDEXA begiratu$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "begiratu du POKéDEXA!\p"
	.string "{STR_VAR_3} POKéDEXA ondo aztertzen\n"
	.string "duen horietako da!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "ZINTA Bildumagilea$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "ZINTAK jaso$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "jaso ditu zintak!\p"
	.string "{STR_VAR_3} ZINTAK biltzea atsegin\n"
	.string "duen ENTRENATZAILEA da!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "ENTRENATZAILE koska-saltaria$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "Koskak saltatu$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "saltatu ditu koskak!\p"
	.string "Saltatzeko koska bat badago,\n"
	.string "{STR_VAR_3} hortxe izango da!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "TELEBISTA Ikuslea$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "TELEBISTA ikusi$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "ikusi du TELEBISTA!\p"
	.string "{STR_VAR_3} TELEBISTA zale porrokatua da!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "ENTRENATZAILE Neurlea$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "Ordua begiratu$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "begiratu du ordua!\p"
	.string "{STR_VAR_3} garaiz iristen den\n"
	.string "ENTRENATZAILE puntuala da.$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "POKéMON LOTERIAKO Aztia$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "POKéMON LOTERIA irabazi$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "irabazi du POKéMON LOTERIA!\p"
	.string "{STR_VAR_3} honek lagun asko ditu\n"
	.string "haiekin POKéMONAK trukatzeko!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "ZAINDEGI erabiltzeailea$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "POKéMONAK ZAINDEGIAN utzi$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE honek {STR_VAR_1} aldiz\n"
	.string "utzi ditu POKéMONAK ZAINDEGIAN!\p"
	.string "{STR_VAR_3} POKéMONAK azkar hazten\n"
	.string "dituen ENTRENATZAILEA da!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "ENTRENATZAILE TELEFERIKOZALEA$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "TELEFERIKOAN ibili$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE hau {STR_VAR_1} aldiz\n"
	.string "ibili da TELEFERIKOAN!\p"
	.string "{STR_VAR_3} gora eta behera ibiltzen\n"
	.string "den ENTRENATZAILE lanpetua da!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "ENTRENATZAILE TERMAZALEA$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "Ur termaletan bainatu$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "Hau {STR_VAR_3} izeneko ENTRENATZAILE\n"
	.string "baten istorioa da.\p"
	.string "ENTRENATZAILE hau {STR_VAR_1} aldiz\n"
	.string "bainatu da ur-termaletan!\p"
	.string "{STR_VAR_3} ume azala duen\n"
	.string "ENTRENATZAILEA da!$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "HITZONTZI naiz!\n"
	.string "Zuretzat istorio zirraragarria dut!\p"
	.string "Entzun nahi al duzu nire istorioa?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "Beno…\n"
	.string "Erdi triste utzi nauzu, bai…$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "Pentsatzen ari nintzen…$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "Horixe da, esango nuke…\p"
	.string "Berriro hitz egin behar genuke!\n"
	.string "Aio-aio!$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "Kaixo, BARDOA naiz.\n"
	.string "Entzun nahi al duzu nire abestia?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "Beno…\n"
	.string "Erdi triste utzi nauzu, bai…$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "Ene, hori bai abesti hunkigarria…\n"
	.string "Besteei jo nahiko nieke…$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "Eta?\n"
	.string "Gustatu al zaizu abestia?\p"
	.string "Ez zaizkit hitzak gustatzen,\n"
	.string "ordea.\p"
	.string "Idatziko zenituzke hitz berriak\n"
	.string "niretzat?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "Beno…\n"
	.string "Erdi triste utzi nauzu, bai…$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "Eskerrik asko bihotzez!\n"
	.string "Utzi iezadazu abesten.$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "Abestia halakoa izatea nahi\n"
	.string "al zenuen?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "Ongi! Hala bedi, orduan.\n"
	.string "Hau kantatuko dut tarte batean.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "Ei, zu! HIPSTERRA naiz ni.\n"
	.string "Modan zer dagoen erakutsiko dizut.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "Baina, aizu, jada erakutsi dizut\n"
	.string "zer dagoen modan.\p"
	.string "Mundu guztiari irakatsi nahi nioke\n"
	.string "zer den modan dagoena.$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "Baina, aizu, zuk jada badakizu\n"
	.string "ondo zer dagoen modan.\p"
	.string "Ezin dizut ezer gehiago irakatsi!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.string "Ei, entuzn al duzu zer den\n"
	.string "“{STR_VAR_1}”?\p"
	.string "Zer esan nahi duen? Beno…\n"
	.string "Galdetu aitatxori eta amatxori, bai?$"
