ALIGNED(4) static const u8 sText_EmptyString[] = _("");
ALIGNED(4) static const u8 sText_Colon[] = _(":");
ALIGNED(4) static const u8 sText_ID[] = _("{ID}");
ALIGNED(4) static const u8 sText_PleaseStartOver[] = _("Mesedez, hasi berriro.");
ALIGNED(4) static const u8 sText_WirelessSearchCanceled[] = _("HARI GABEKO KOMUNIKAZIO\nSISTEMA ezeztatu egin da.");
ALIGNED(4) static const u8 sText_AwaitingCommunucation2[] = _("Beste jokalariari\nitxaroten."); // Unused
ALIGNED(4) static const u8 sText_AwaitingCommunication[] = _("{STR_VAR_1}! Beste\njokalariari itxaroten.");
ALIGNED(4) static const u8 sText_AwaitingLinkPressStart[] = _("{STR_VAR_1}! Lotura itxaroten!\nSakatu HASI denak prest daudenean.");
ALIGNED(4) static const u8 sJPText_SingleBattle[] = _("シングルバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_DoubleBattle[] = _("ダブルバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_MultiBattle[] = _("マルチバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_TradePokemon[] = _("ポケモンこうかんを かいさいする");
ALIGNED(4) static const u8 sJPText_Chat[] = _("チャットを かいさいする");
ALIGNED(4) static const u8 sJPText_DistWonderCard[] = _("ふしぎなカードをくばる");
ALIGNED(4) static const u8 sJPText_DistWonderNews[] = _("ふしぎなニュースをくばる");
ALIGNED(4) static const u8 sJPText_DistMysteryEvent[] = _("ふしぎなできごとを かいさいする"); // Unused
ALIGNED(4) static const u8 sJPText_HoldPokemonJump[] = _("なわとびを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldBerryCrush[] = _("きのみマッシャーを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldBerryPicking[] = _("きのみどりを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldSpinTrade[] = _("ぐるぐるこうかんを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldSpinShop[] = _("ぐるぐるショップを かいさいする");

// Unused
static const u8 *const sJPLinkGroupActionTexts[] = {
    sJPText_SingleBattle,
    sJPText_DoubleBattle,
    sJPText_MultiBattle,
    sJPText_TradePokemon,
    sJPText_Chat,
    sJPText_DistWonderCard,
    sJPText_DistWonderNews,
    sJPText_DistWonderCard,
    sJPText_HoldPokemonJump,
    sJPText_HoldBerryCrush,
    sJPText_HoldBerryPicking,
    sJPText_HoldBerryPicking,
    sJPText_HoldSpinTrade,
    sJPText_HoldSpinShop
};

static const u8 sText_1PlayerNeeded[] = _("Jokalari 1\nbehar dira.");
static const u8 sText_2PlayersNeeded[] = _("2 jokalari\nbehar dira.");
static const u8 sText_3PlayersNeeded[] = _("3 jokalari\nbehar dira.");
static const u8 sText_4PlayersNeeded[] = _("4 jokalari\nbehar dira.");
static const u8 sText_2PlayerMode[] = _("2-JOKALARIKO\nMODUA");
static const u8 sText_3PlayerMode[] = _("3-JOKALARIKO\nMODUA");
static const u8 sText_4PlayerMode[] = _("4-JOKALARIKO\nMODUA");
static const u8 sText_5PlayerMode[] = _("5-JOKALARIKO\nMODUA");

static const u8 *const sPlayersNeededOrModeTexts[][5] = {
    // 2 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode
    },
    // 4 players required
    {
        sText_3PlayersNeeded,
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_4PlayerMode
    },
    // 2-5 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 3-5 players required
    {
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 2-4 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode
    }
};

ALIGNED(4) static const u8 sText_BButtonCancel[] = _("{B_BUTTON}EZEZTATU");
ALIGNED(4) static const u8 sJPText_SearchingForParticipants[] = _("ため\nさんかしゃ ぼしゅうちゅう です！"); // Unused, may have been cut off
ALIGNED(4) static const u8 sText_PlayerContactedYouForXAccept[] = _("{STR_VAR_2} zurekin harremanetan jarri da\n{STR_VAR_1} egiteko. Onartu?");
ALIGNED(4) static const u8 sText_PlayerContactedYouShareX[] = _("{STR_VAR_2} zurekin harremanetan jarri da.\nBanatuko al duzu {STR_VAR_1}?");
ALIGNED(4) static const u8 sText_PlayerContactedYouAddToMembers[] = _("{STR_VAR_2} zurekin harremanetan jarri da.\nGehitu jokalarietara?");
ALIGNED(4) static const u8 sText_AreTheseMembersOK[] = _("{STR_VAR_1}!\nONGI al daude jokalariak?");
ALIGNED(4) static const u8 sText_CancelModeWithTheseMembers[] = _("Ezeztatu {STR_VAR_1} MODUA\njokalari hauekin?");
ALIGNED(4) static const u8 sText_AnOKWasSentToPlayer[] = _("“ONGI” erantzun\nzaio {STR_VAR_1}(e)ri.");
ALIGNED(4) static const u8 sText_OtherTrainerUnavailableNow[] = _("Beste ENTRENATZAILEA ez\ndago irisgarri orain…\p");
ALIGNED(4) static const u8 sText_CantTransmitTrainerTooFar[] = _("Ezin duzu urrutiegi dagoen\nENTENATZAILE batekin komunikatu.\p");
ALIGNED(4) static const u8 sText_TrainersNotReadyYet[] = _("Beste ENTRENATZAILEA(K)\nez dago/daude prest.\p");

static const u8 *const sCantTransmitToTrainerTexts[] = {
    [UR_TRADE_PLAYER_NOT_READY - 1]  = sText_CantTransmitTrainerTooFar,
    [UR_TRADE_PARTNER_NOT_READY - 1] = sText_TrainersNotReadyYet
};

ALIGNED(4) static const u8 sText_ModeWithTheseMembersWillBeCanceled[] = _("{STR_VAR_1} MODUA ezeztatu\negingo da jokalari hauekin.{PAUSE 60}");
ALIGNED(4) static const u8 sText_MemberNoLongerAvailable[] = _("Jokalari batek ezin du\nkonektatuta jarraitu.\p");

static const u8 *const sPlayerUnavailableTexts[] = {
    sText_OtherTrainerUnavailableNow,
    sText_MemberNoLongerAvailable
};

ALIGNED(4) static const u8 sText_TrainerAppearsUnavailable[] = _("Beste ENTRENATZAILEA ez\ndago irisgarri…\p");
ALIGNED(4) static const u8 sText_PlayerSentBackOK[] = _("{STR_VAR_1}(e)k “ADOS” erantzun du!");
ALIGNED(4) static const u8 sText_PlayerOKdRegistration[] = _("{STR_VAR_1}(e)k baiezkoa eman du\nzuk parte hartzeko.");
ALIGNED(4) static const u8 sText_PlayerRepliedNo[] = _("{STR_VAR_1}(e)k “Ez…” erantzun du\p");
ALIGNED(4) static const u8 sText_AwaitingOtherMembers[] = _("{STR_VAR_1}!\nbeste jokalariei itxaroten!");
ALIGNED(4) static const u8 sText_QuitBeingMember[] = _("Utzi parte hartzeari?");
ALIGNED(4) static const u8 sText_StoppedBeingMember[] = _("Jada ez zara parte hartzen ari.\p");

static const u8 *const sPlayerDisconnectedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_MemberNoLongerAvailable,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_TrainerAppearsUnavailable,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = sText_StoppedBeingMember
};

ALIGNED(4) static const u8 sText_WirelessLinkEstablished[] = _("HARI GABEKO KOMUNIKAZIO\nSISTEMA lotuta.");
ALIGNED(4) static const u8 sText_WirelessLinkDropped[] = _("HARI GABEKO KOMUNIKAZIO\nSISTEMA erori egin da…");
ALIGNED(4) static const u8 sText_LinkWithFriendDropped[] = _("Zure lagunarekin konexioa erori\negin da…");
ALIGNED(4) static const u8 sText_PlayerRepliedNo2[] = _("{STR_VAR_1}(e)k “Ez…” erantzun du");

static const u8 *const sLinkDroppedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_LinkWithFriendDropped,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_LinkWithFriendDropped,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo2,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = NULL
};

ALIGNED(4) static const u8 sText_DoYouWantXMode[] = _("{STR_VAR_2} MODUA nahi al\nduzu?");
ALIGNED(4) static const u8 sText_DoYouWantXMode2[] = _("{STR_VAR_2} MODUA nahi al\nduzu?");

// Unused
static const u8 *const sDoYouWantModeTexts[] = {
    sText_DoYouWantXMode,
    sText_DoYouWantXMode2
};

ALIGNED(4) static const u8 sText_CommunicatingPleaseWait[] = _("Komunikatzen\nItxaron, mesedez."); // Unused
ALIGNED(4) static const u8 sText_AwaitingPlayersResponseAboutTrade[] = _("{STR_VAR_1}(r)en erantzunaren zain\ntrukerako…");
ALIGNED(4) static const u8 sText_Communicating[] = _("Komunikatzen{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
                                                     "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_CommunicatingWithPlayer[] = _("{STR_VAR_1}(r)ekin komunikatzen{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
                                                               "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_PleaseWaitAWhile[] = _("Itxaron pixka bat, mesedez{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
                                                        "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");

static const u8 *const sCommunicatingWaitTexts[] = {
    sText_Communicating,
    sText_CommunicatingWithPlayer,
    sText_PleaseWaitAWhile
};

ALIGNED(4) static const u8 sText_HiDoSomethingMale[] = _("Aupa! Zerbait egin nahi al\nduzu?");
ALIGNED(4) static const u8 sText_HiDoSomethingFemale[] = _("Kaixo!\nZerbait egin nahi al duzu?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainMale[] = _("{STR_VAR_1}: Kaixo, berriz!\nZer nahi duzu egin oraingoan?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainFemale[] = _("{STR_VAR_1}: Ene! {PLAYER}, kaixo!\nZerbait egin nahi al duzu?");

static const u8 *const sHiDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_HiDoSomethingMale,
        sText_HiDoSomethingFemale
    }, {
        sText_HiDoSomethingAgainMale,
        sText_HiDoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_DoSomethingMale[] = _("Zeozer egin nahi?");
ALIGNED(4) static const u8 sText_DoSomethingFemale[] = _("Zeozer egin nahi al duzu?");
ALIGNED(4) static const u8 sText_DoSomethingAgainMale[] = _("{STR_VAR_1}: Zer egin nahi duzu\norain?");
ALIGNED(4) static const u8 sText_DoSomethingAgainFemale[] = _("{STR_VAR_1}: beste zerbait egin nahi?"); // Unused

// Unused
static const u8 *const sDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_DoSomethingMale,
        sText_DoSomethingFemale
    }, {
        sText_DoSomethingAgainMale,
        sText_DoSomethingAgainMale // was probably supposed to be sText_DoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_SomebodyHasContactedYou[] = _("Norbaitek dei egin dizu.{PAUSE 60}");
ALIGNED(4) static const u8 sText_PlayerHasContactedYou[] = _("{STR_VAR_1}(e)k dei egin dizu.{PAUSE 60}");

static const u8 *const sPlayerContactedYouTexts[] = {
    sText_SomebodyHasContactedYou,
    sText_PlayerHasContactedYou
};

ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer[] = _("Beste ENTENATZAILEAREN\nerantzunari itxaroten…");
ALIGNED(4) static const u8 sText_AwaitingResponseFromPlayer[] = _("{STR_VAR_1}(r)en\nerantzunari itxaroten…");

static const u8 *const sAwaitingResponseTexts[] = {
    sText_AwaitingResponseFromTrainer,
    sText_AwaitingResponseFromPlayer
};

ALIGNED(4) static const u8 sText_ShowTrainerCard[] = _("Beste ENTRENATZAILEAK bere\nENTRENATZAILE TXARTELA erakutsi dizu.\pNahi duzu zure ENTRENATZAILE\nXTARTELA erakutsi?");
ALIGNED(4) static const u8 sText_BattleChallenge[] = _("Beste ENTRENATZAILEAK erronka\nbota dizu.\pOnartzen al duzu borrokarako\nerronka?");
ALIGNED(4) static const u8 sText_ChatInvitation[] = _("Beste ENTRENATZAILEAK txatera\ngonbidatu zaitu.\pOnartuko al duzu txaterako\ngonbidapena?");
ALIGNED(4) static const u8 sText_OfferToTradeMon[] = _("Eskaintza bat dago zure\n {DYNAMIC 0} Ml.ko {DYNAMIC 1}\paldatzeko\n{DYNAMIC 2}Ml.ko {DYNAMIC 3}(r)en truke.\pOnartzen al duzu trukea?");
ALIGNED(4) static const u8 sText_OfferToTradeEgg[] = _("Eskaintza bat dago zure\n ARRAUTZA eskatzen duena.\lOnartzen al duzu trukea?");
ALIGNED(4) static const u8 sText_ChatDropped[] = _("Txata erori da.\p");
ALIGNED(4) static const u8 sText_OfferDeclined1[] = _("Eskaintza ezeztatu duzu.\p");
ALIGNED(4) static const u8 sText_OfferDeclined2[] = _("Eskaintza ezeztatu duzu.\p");
ALIGNED(4) static const u8 sText_ChatEnded[] = _("Txata amaitu da.\p");

// Unused
static const u8 *const sInvitationTexts[] = {
    sText_ShowTrainerCard,
    sText_BattleChallenge,
    sText_ChatInvitation,
    sText_OfferToTradeMon
};

ALIGNED(4) static const u8 sText_JoinChatMale[] = _("Ei, aupa! Txateatzen ari gara orain.\nBatu nahi al duzu?");
ALIGNED(4) static const u8 sText_PlayerJoinChatMale[] = _("{STR_VAR_1}: Ei, {PLAYER}!\nTxateatzen ari gara orain.\lBatu nahi al duzu?");
ALIGNED(4) static const u8 sText_JoinChatFemale[] = _("Ei, kaixo ! Txateatzen ari gara orain.\nBatu nahi al duzu?");
ALIGNED(4) static const u8 sText_PlayerJoinChatFemale[] = _("{STR_VAR_1}: Ei, aupa, {PLAYER}!\nTxateatzen ari gara orain.\lBatu nahi al duzu?");

static const u8 *const sJoinChatTexts[][GENDER_COUNT] = {
    {
        sText_JoinChatMale,
        sText_JoinChatFemale
    }, {
        sText_PlayerJoinChatMale,
        sText_PlayerJoinChatFemale
    }
};

ALIGNED(4) static const u8 sText_TrainerAppearsBusy[] = _("……\nENTRENATZAILEA lanpetuta dago…\p");
ALIGNED(4) static const u8 sText_WaitForBattleMale[] = _("Borroka bat, beraz?\nOngi, eman denbora pixka bat.");
ALIGNED(4) static const u8 sText_WaitForChatMale[] = _("Txateatu egin nahi duzu?\nOngi, itxaron pixka bat.");
ALIGNED(4) static const u8 sText_ShowTrainerCardMale[] = _("Noski! Hemen nire ENTRENATZAILE\nTXARTELA, agur gisan.");
ALIGNED(4) static const u8 sText_WaitForBattleFemale[] = _("Borroka bat? Noski, baina denbora\nbehar dut prestatzeko.");
ALIGNED(4) static const u8 sText_WaitForChatFemale[] = _("Txateatu egin nahi zenuen?\nOngi, itxaron momentu bat, mesedez.");
ALIGNED(4) static const u8 sText_ShowTrainerCardFemale[] = _("Agurtzeko, nire ENTRENATZAILE\nTXARTELA erakutsiko dizut.");

static const u8 *const sText_WaitOrShowCardTexts[GENDER_COUNT][4] = {
    {
        sText_WaitForBattleMale,
        sText_WaitForChatMale,
        NULL,
        sText_ShowTrainerCardMale
    }, {
        sText_WaitForBattleFemale,
        sText_WaitForChatFemale,
        NULL,
        sText_ShowTrainerCardFemale
    }
};

ALIGNED(4) static const u8 sText_WaitForChatMale2[] = _("Txateatu egin nahi al duzu?\nAdos, itxaron pixka bat, mesedez."); // Unused
ALIGNED(4) static const u8 sText_DoneWaitingBattleMale[] = _("Eskerrik asko itxaroteagatik!\nhas gaietzen borrokan!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatMale[] = _("Bikain!\nTxateatu dezagun!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingBattleFemale[] = _("Barkatu itxaroten edukitzeagatik!\nHas gaitezen!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatFemale[] = _("Barkatu itxaroten edukitzeagatik!\nTxateatu dezagun.{PAUSE 60}");
ALIGNED(4) static const u8 sText_TradeWillBeStarted[] = _("Trukea hasi egingo da.{PAUSE 60}");
ALIGNED(4) static const u8 sText_BattleWillBeStarted[] = _("Borroka hasi egingo da.{PAUSE 60}");
ALIGNED(4) static const u8 sText_EnteringChat[] = _("Txatera sartzen…{PAUSE 60}");

static const u8 *const sStartActivityTexts[][GENDER_COUNT][3] = {
    {
        {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }, {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }
    }, {
        {
            sText_DoneWaitingBattleMale,
            sText_DoneWaitingChatMale,
            sText_TradeWillBeStarted
        }, {
            sText_DoneWaitingBattleFemale,
            sText_DoneWaitingChatFemale,
            sText_TradeWillBeStarted
        }
    }
};

ALIGNED(4) static const u8 sText_BattleDeclinedMale[] = _("Barkatu! Nire POKéMONAK ez daudela\noso ondo dirudi.\lBeste batean borrokatuko dugu.\p");
ALIGNED(4) static const u8 sText_BattleDeclinedFemale[] = _("Barkatu, baina nire POKéMONAK\nez daude oso ondo…\pBorroka dezagun beste batean.\p");

static const u8 *const sBattleDeclinedTexts[GENDER_COUNT] = {
    sText_BattleDeclinedMale,
    sText_BattleDeclinedFemale
};

ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedMale[] = _("Nola? Nire ENTRENATZAILE TXARTELA…\nNon daukat baina?\lBarkatu! Erakutsiko dizut beste batean!\p");
ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedFemale[] = _("Nola? Non sartu dut nire\nENTRENATZAILE TXARTELA?…\lBarkatu! Erakutsiko dizut geroago!\p");

static const u8 *const sShowTrainerCardDeclinedTexts[GENDER_COUNT] = {
    sText_ShowTrainerCardDeclinedMale,
    sText_ShowTrainerCardDeclinedFemale
};

ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingMale[] = _("Nirekin zerbait egin nahi baduzu,\n abisatu!\p");
ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingFemale[] = _("Nirekin zerbait egin nahi baduzu,\n lasai abisatu.\p");

static const u8 *const sIfYouWantToDoSomethingTexts[GENDER_COUNT] = {
    sText_IfYouWantToDoSomethingMale,
    sText_IfYouWantToDoSomethingFemale
};

ALIGNED(4) static const u8 sText_TrainerBattleBusy[] = _("Ene! barkatu, baina beste\nzerbait egin behar dut.\lbeste batean hobe, bai?\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower1[] = _("Borrokatzeko 30. Ml.\nbaino gutxiagoko bi POKéMON\lbehar dituzu.\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower2[] = _("Borrokarako 30. Ml.\nbaino gutxiagoko bi POKéMON\lbehar dituzu.\p");

ALIGNED(4) static const u8 sText_DeclineChatMale[] = _("Ene, noski.\nEtorri nahi duzunean, bai?\p");
ALIGNED(4) static const u8 stext_DeclineChatFemale[] = _("Ene…\nEtorri nahi duzunean.\p");

// Response from partner when player declines chat
static const u8 *const sDeclineChatTexts[GENDER_COUNT] = {
    sText_DeclineChatMale,
    stext_DeclineChatFemale
};

ALIGNED(4) static const u8 sText_ChatDeclinedMale[] = _("Ene, barkatu!\nEzin dut oraintxe bertan.\lTxateatuko dugu beste batean.\p");
ALIGNED(4) static const u8 sText_ChatDeclinedFemale[] = _("Ene, barkatu.\nBeste gauza batzuk egin behar ditut.\lTxateatuko dugu beste batean.\p");

// Response from partner when they decline chat
static const u8 *const sChatDeclinedTexts[GENDER_COUNT] = {
    sText_ChatDeclinedMale,
    sText_ChatDeclinedFemale
};

ALIGNED(4) static const u8 sText_YoureToughMale[] = _("Uau!\nIndartsua zara gero!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveMale[] = _("Eraso hori erabili duzu?\nEstrategia ona, bai!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseMale[] = _("Itzela!\nHarrigarria izan da!\p");
ALIGNED(4) static const u8 sText_SwitchedMonsMale[] = _("Ene! Nola erabili duzu\nPOKéMON hori une horretan?\p");
ALIGNED(4) static const u8 sText_YoureToughFemale[] = _("POKéMON hori…\nOndo hezita dago, alajaina!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveFemale[] = _("Hori da!\nHau da eraso egokia une honetan!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseFemale[] = _("Itzela!\nHorren ona al zara borrokan?\p");
ALIGNED(4) static const u8 sText_SwitchedMonsFemale[] = _("Bereziki ona zara\nPOKéMONAK aldatzen!\p");

static const u8 *const sBattleReactionTexts[GENDER_COUNT][4] = {
    {
        sText_YoureToughMale,
        sText_UsedGoodMoveMale,
        sText_BattleSurpriseMale,
        sText_SwitchedMonsMale
    },
    {
        sText_YoureToughFemale,
        sText_UsedGoodMoveFemale,
        sText_BattleSurpriseFemale,
        sText_SwitchedMonsFemale
    }
};

ALIGNED(4) static const u8 sText_LearnedSomethingMale[] = _("Ados, ados!\nAsko ikasi dut horrekin!\p");
ALIGNED(4) static const u8 sText_ThatsFunnyMale[] = _("Ez esan ezer horren barregarria!\nBarreak tripako mina eragin dit!\p");
ALIGNED(4) static const u8 sText_RandomChatMale1[] = _("Nola?\nHalako zerbait gertatu zen.\p");
ALIGNED(4) static const u8 sText_RandomChatMale2[] = _("Bai, bai… Zer?\nBenetan ari al zara?\p");
ALIGNED(4) static const u8 sText_LearnedSomethingFemale[] = _("Benetan?\nEz nekien hori.\p");
ALIGNED(4) static const u8 sText_ThatsFunnyFemale[] = _("Kar-kar-kar!\nZer diozu, baina?\p");
ALIGNED(4) static const u8 sText_RandomChatFemale1[] = _("Bai, horixe da zehazki!\nHorixe esan nahi nuen.\p");
ALIGNED(4) static const u8 sText_RandomChatFemale2[] = _("beste era batera…\nBai! Hori da!\p");

static const u8 *const sChatReactionTexts[GENDER_COUNT][4] = {
    {
        sText_LearnedSomethingMale,
        sText_ThatsFunnyMale,
        sText_RandomChatMale1,
        sText_RandomChatMale2
    },
    {
        sText_LearnedSomethingFemale,
        sText_ThatsFunnyFemale,
        sText_RandomChatFemale1,
        sText_RandomChatFemale2
    }
};

ALIGNED(4) static const u8 sText_ShowedTrainerCardMale1[] = _("ENTRENATZAILE TXARTELA erakusten\nari naiz, zu agurtzeko.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardMale2[] = _("Gehiago ezagutu nahi zintuzket!\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale1[] = _("ENTRENATZAILE TXARTELAK elkarri\nerakutsiz ezagutuko dugu elkar.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale2[] = _("Pozten naiz zu ezagututa.\nJada ez zara ezezaguna niretzat!\p");

static const u8 *const sTrainerCardReactionTexts[GENDER_COUNT][2] = {
    {
        sText_ShowedTrainerCardMale1,
        sText_ShowedTrainerCardMale2
    },
    {
        sText_ShowedTrainerCardFemale1,
        sText_ShowedTrainerCardFemale2
    }
};

ALIGNED(4) static const u8 sText_MaleTraded1[] = _("Bai, bikain!\nBenetan nahi nuen POKéMON hau!\p");
ALIGNED(4) static const u8 sText_MaleTraded2[] = _("Azkenean, lortu dut nahi nuen\nPOKéMONA truke bitartez.\p");
ALIGNED(4) static const u8 sText_FemaleTraded1[] = _("POKéMON bat trukatzen ari naiz.\p");
ALIGNED(4) static const u8 sText_FemaleTraded2[] = _("Azkenean, lortu dut nahi nuen\nPOKéMONA truke bitartez!\p");

static const u8 *const sTradeReactionTexts[GENDER_COUNT][4] = {
    {
        sText_MaleTraded1,
        sText_MaleTraded2
    },
    {
        sText_FemaleTraded1,
        sText_FemaleTraded2
    }
};

ALIGNED(4) static const u8 sText_XCheckedTradingBoard[] = _("{STR_VAR_1}(e)k TRUKE\nPANELA begiratu du.\p");
ALIGNED(4) static const u8 sText_RegisterMonAtTradingBoard[] = _("Ongi etorri TRUKE PANELERA.\pZure POKéMONA erregistratu\neta trukerako eskaini dezakezu.\pErregistratu nahi duzu zure\nPOKéMONA?");
ALIGNED(4) static const u8 sText_TradingBoardInfo[] = _("TRUKE PANEL honetan POKéMON bat\n"
                                                        "eskaini dezakezu trukerako.\p"
                                                        "Horretarako, trukatu nahi duzun\n"
                                                        "POKéMONA erregistratu behar duzu.\p"
                                                        "Beste ENTRENATZAILE batek beste\n"
                                                        "POKéMON bat eskaini dezake bueltan.\p"
                                                        "Espero dugu hainbat POKéMON\n"
                                                        "erregistratu eta ENTRENATZAILE\l"
                                                        "pila batekin trukatuko dituzula.\p"
                                                        "Erregistratu nahi duzu zure\nPOKéMON bat?");
ALIGNED(4) static const u8 sText_ThankYouForRegistering[] = _("Zure POKéMONA erregistratu dugu\ntrukerako TRUKE PANELEAN.\pMila esker zerbitzua erabiltzeagatik!\p"); // unused
ALIGNED(4) static const u8 sText_NobodyHasRegistered[] = _("Inork ez du erregistratu POKéMONIK\ntrukerako TRUKE PANELEAN.\p\n"); // unused
ALIGNED(4) static const u8 sText_ChooseRequestedMonType[] = _("Mesedez, aukeratu zein POKéMON\nmota nahi duzun trukatu.\n");
ALIGNED(4) static const u8 sText_WhichMonWillYouOffer[] = _("Zure taldeko zein POKéMON eskaini\nnahi duzu trukean?\p");
ALIGNED(4) static const u8 sText_RegistrationCanceled[] = _("Erregistroa ezeztatu egin da.\p");
ALIGNED(4) static const u8 sText_RegistrationCompleted[] = _("Erregistroa ongi burutu da.\p");
ALIGNED(4) static const u8 sText_TradeCanceled[] = _("Trukea ezeztatu egin da.\p");
ALIGNED(4) static const u8 sText_CancelRegistrationOfMon[] = _("Ezeztatu erregistroan zure\n{STR_VAR_2} Ml.ko {STR_VAR_1}?");
ALIGNED(4) static const u8 sText_CancelRegistrationOfEgg[] = _("Ezeztatu erregistroan zure\nARRAUTZA?");
ALIGNED(4) static const u8 sText_RegistrationCanceled2[] = _("Erregistroa ezeztatu egin da.\p");
ALIGNED(4) static const u8 sText_TradeTrainersWillBeListed[] = _("Trukea egin nahi duten ENTRENATZAILEAK\nzerrendatuko dira."); // unused
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith2[] = _("Aukeratu zein ENTRENATZAILEREKIN\ntrukatu nahi dituzun POKéMONAK."); // unused
ALIGNED(4) static const u8 sText_AskTrainerToMakeTrade[] = _("Eskatu nahi diozu {STR_VAR_1}(e)ri\ntrukea egiteko?");
ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer2[] = _("Beste ENTRENATZAILEAREN\nerantzunaren zain…"); // unused
ALIGNED(4) static const u8 sText_NotRegisteredAMonForTrade[] = _("Ez duzu POKéMONIK erregistratu\ntrukerako.\p"); // unused
ALIGNED(4) static const u8 sText_DontHaveTypeTrainerWants[] = _("Ez duzu {STR_VAR_2} motako\n{STR_VAR_1}(e)k nahi duen POKéMONA.\p");
ALIGNED(4) static const u8 sText_DontHaveEggTrainerWants[] = _("Ez duzu {STR_VAR_1}(e)k nahi\nduen arrautza.\p");
ALIGNED(4) static const u8 sText_PlayerCantTradeForYourMon[] = _("{STR_VAR_1}(e)k ezin du truke bat\negin zure POKéMONEKIN orain.\p");
ALIGNED(4) static const u8 sText_CantTradeForPartnersMon[] = _("Ezin duzu {STR_VAR_1}(r)ekin\nPOKéMONIK trukatu orain.\p");

// Unused
static const u8 *const sCantTradeMonTexts[] = {
    sText_PlayerCantTradeForYourMon,
    sText_CantTradeForPartnersMon
};

ALIGNED(4) static const u8 sText_TradeOfferRejected[] = _("Zure truke eskaintza ezeztatu egin da.\p");
ALIGNED(4) static const u8 sText_EggTrade[] = _("ARRAUTZA TRUKEA");
ALIGNED(4) static const u8 sText_ChooseJoinCancel[] = _("{DPAD_UPDOWN}AUKERATU  {A_BUTTON}BATU  {B_BUTTON}EZEZTATU");
ALIGNED(4) static const u8 sText_ChooseTrainer[] = _("Mesedez, aukeratu ENTRENATZAILE bat.");
ALIGNED(4) static const u8 sText_ChooseTrainerSingleBattle[] = _("Mesedez, aukeratu ENTRENATZAILE bat\nBANAKAKO BORROKARAKO.");
ALIGNED(4) static const u8 sText_ChooseTrainerDoubleBattle[] = _("Mesedez, aukeratu ENTRENATZAILE bat\nBINAKAKO BORROKARAKO.");
ALIGNED(4) static const u8 sText_ChooseLeaderMultiBattle[] = _("Mesedez, aukeratu LIDERRA\nMULTI BORROKARAKO.");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith[] = _("Mesedez, aukeratu zein\nENTRENATZAILEREKIN egin trukea.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderCards[] = _("Mesedez, aukeratu zein ENTRENATZAILEREKIN\ntrukatu MIRARI KARTAK.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderNews[] = _("Mesedez, aukeratu zein ENTRENATZAILEREKIN\ntrukatu MIRARI ALBISTEAK.");
ALIGNED(4) static const u8 sText_ChooseLeaderPokemonJump[] = _("Egin salto mini POKéMONEKIN!\nMesedez, aukeratu LIDERRA.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryCrush[] = _("BAIA BIRRINKETA!\nMesedez, aukeratu LIDERRA.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryPicking[] = _("DODRIO BAIA-BILKETA!\nMesedez, aukeratu LIDERRA.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryBlender[] = _("BAIA NAHASTAILEA!\nMesedez, aukeratu LIDERRA.");
ALIGNED(4) static const u8 sText_ChooseLeaderRecordCorner[] = _("ERREKORREN TXOKOA!\nMesedez, aukeratu LIDERRA.");
ALIGNED(4) static const u8 sText_ChooseLeaderCoolContest[] = _("KARISMA TXAPELKETA!\nMesedez, aukeratu LIDERRA.");
ALIGNED(4) static const u8 sText_ChooseLeaderBeautyContest[] = _("EDERTASUN TXAPELKETA!\nMesedez, aukeratu LIDERRA.");
ALIGNED(4) static const u8 sText_ChooseLeaderCuteContest[] = _("POLITASUN TXAPELKETA!\nMesedez, aukeratu LIDERRA.");
ALIGNED(4) static const u8 sText_ChooseLeaderSmartContest[] = _("AZKARTASUN TXAPELKETA!\nMesedez, aukeratu LIDERRA.");
ALIGNED(4) static const u8 sText_ChooseLeaderToughContest[] = _("GOGORTASUN TXAPELKETA!\nMesedez, aukeratu LIDERRA.");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerLv50[] = _("BORROKA DORREA, 50. MAILA!\nMesedez, aukeratu LIDERRA.");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerOpenLv[] = _("BORROKA DORREA, MAILA IREKIA!\nMesedez, aukeratu LIDERRA.");

static const u8 *const sChooseTrainerTexts[NUM_LINK_GROUP_TYPES] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = sText_ChooseTrainerSingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sText_ChooseTrainerDoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sText_ChooseLeaderMultiBattle,
    [LINK_GROUP_TRADE]             = sText_ChooseTrainerToTradeWith,
    [LINK_GROUP_POKEMON_JUMP]      = sText_ChooseLeaderPokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sText_ChooseLeaderBerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sText_ChooseLeaderBerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sText_ChooseTrainerToShareWonderCards,
    [LINK_GROUP_WONDER_NEWS]       = sText_ChooseTrainerToShareWonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = NULL,
    [LINK_GROUP_UNION_ROOM_INIT]   = NULL,
    [LINK_GROUP_UNK_11]            = NULL,
    [LINK_GROUP_RECORD_CORNER]     = sText_ChooseLeaderRecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sText_ChooseLeaderBerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sText_ChooseLeaderCoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sText_ChooseLeaderBeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sText_ChooseLeaderCuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sText_ChooseLeaderSmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sText_ChooseLeaderToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sText_ChooseLeaderBattleTowerLv50,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sText_ChooseLeaderBattleTowerOpenLv
};

ALIGNED(4) static const u8 sText_SearchingForWirelessSystemWait[] = _("HARI GABEKO KOMUNIKAZIO SISTEMA\nbilatzen. Itxaron...");
ALIGNED(4) static const u8 sText_MustHaveTwoMonsForDoubleBattle[] = _("BINAKAKO BORROKARAKO, gutxienez\nbi POKéMON behar dituzu.\p"); // Unused
ALIGNED(4) static const u8 sText_AwaitingPlayersResponse[] = _("{STR_VAR_1}(r)en erantzunaren zain…");
ALIGNED(4) static const u8 sText_PlayerHasBeenAskedToRegisterYouPleaseWait[] = _("{STR_VAR_1}(e)ri eskatu zaio zu\nerregistratzeko. Itxaron, mesedez.");
ALIGNED(4) static const u8 sText_AwaitingResponseFromWirelessSystem[] = _("HARI GABEKO KOMUNIKAZIO SISTEMAREN\nerantzunaren zain.");
ALIGNED(4) static const u8 sText_PleaseWaitForOtherTrainersToGather[] = _("Itxaron beste ENTRENATZAILEAK\nbildu eta prestatu arte."); // Unused
ALIGNED(4) static const u8 sText_NoCardsSharedRightNow[] = _("Ez dago konpartitu daitekeen\nKARTARIK oraintxe.");
ALIGNED(4) static const u8 sText_NoNewsSharedRightNow[] = _("HARI GABEKO KOMUNIKAZIO SISTEMA\nALBISTERIK oraintxe.");

static const u8 *const sNoWonderSharedTexts[] = {
    sText_NoCardsSharedRightNow,
    sText_NoNewsSharedRightNow
};

ALIGNED(4) static const u8 sText_Battle[] = _("BORROKA");
ALIGNED(4) static const u8 sText_Chat2[] = _("TXATA");
ALIGNED(4) static const u8 sText_Greetings[] = _("AGURTU");
ALIGNED(4) static const u8 sText_Exit[] = _("IRTEN");
ALIGNED(4) static const u8 sText_Exit2[] = _("IRTEN");
ALIGNED(4) static const u8 sText_Info[] = _("INFO");
ALIGNED(4) static const u8 sText_NameWantedOfferLv[] = _("IZENA{CLEAR_TO 60}NAHIA{CLEAR_TO 110}ESKAINTZA{CLEAR_TO 198}ML.");
ALIGNED(4) static const u8 sText_SingleBattle[] = _("BANAKAKO BORROKA");
ALIGNED(4) static const u8 sText_DoubleBattle[] = _("BINAKAKO BORROKA");
ALIGNED(4) static const u8 sText_MultiBattle[] = _("MULTI BORROKA");
ALIGNED(4) static const u8 sText_PokemonTrades[] = _("POKéMON TRUKEAK");
ALIGNED(4) static const u8 sText_Chat[] = _("TXATA");
ALIGNED(4) static const u8 sText_Cards[] = _("KARTAK");
ALIGNED(4) static const u8 sText_WonderCards[] = _("MIRARI KARTAK");
ALIGNED(4) static const u8 sText_WonderNews[] = _("MIARRI ALBISTEAK");
ALIGNED(4) static const u8 sText_PokemonJump[] = _("POKéMON JAUZIA");
ALIGNED(4) static const u8 sText_BerryCrush[] = _("BAIA BIRRINKETA");
ALIGNED(4) static const u8 sText_BerryPicking[] = _("BAIA-BILKETA");
ALIGNED(4) static const u8 sText_Search[] = _("BILATU");
ALIGNED(4) static const u8 sText_BerryBlender[] = _("BAIA NAHASTAILEA");
ALIGNED(4) static const u8 sText_RecordCorner[] = _("ERREKORREN TXOKOA");
ALIGNED(4) static const u8 sText_CoolContest[] = _("KARISMA TXAPELKETA");
ALIGNED(4) static const u8 sText_BeautyContest[] = _("EDERTASUN TXAPELKETA");
ALIGNED(4) static const u8 sText_CuteContest[] = _("POLITASUN TXAPELKETA");
ALIGNED(4) static const u8 sText_SmartContest[] = _("AZKARTASUN TXAPELKETA");
ALIGNED(4) static const u8 sText_ToughContest[] = _("GOGORTASUN TXAPELKETA");
ALIGNED(4) static const u8 sText_BattleTowerLv50[] = _("BORROKA DORREA, 50. ML.");
ALIGNED(4) static const u8 sText_BattleTowerOpenLv[] = _("BORROKA DORREA, MAILA IREKIA");
ALIGNED(4) static const u8 sText_ItsNormalCard[] = _("KARTA NORMALA da.");
ALIGNED(4) static const u8 sText_ItsBronzeCard[] = _("BRONTZEZKO KARTA da!");
ALIGNED(4) static const u8 sText_ItsCopperCard[] = _("KOBREZKO KARTA da!");
ALIGNED(4) static const u8 sText_ItsSilverCard[] = _("ZILARREZKO KARTA da!");
ALIGNED(4) static const u8 sText_ItsGoldCard[] = _("URREZKO KARTA da!");

static const u8 *const sCardColorTexts[] = {
    sText_ItsNormalCard,
    sText_ItsBronzeCard,
    sText_ItsCopperCard,
    sText_ItsSilverCard,
    sText_ItsGoldCard
};

ALIGNED(4) static const u8 sText_TrainerCardInfoPage1[] = _("Hau da {DYNAMIC 0} {DYNAMIC 1}(r)en\nENTRENATZAILE TXARTELA…\l{DYNAMIC 2}\pPOKéDEXA: {DYNAMIC 3}\nDENBORA:  {DYNAMIC 4}:{DYNAMIC 5}\p");
ALIGNED(4) static const u8 sText_TrainerCardInfoPage2[] = _("BORROKAK: IRABAZI: {DYNAMIC 0}  GALDU: {DYNAMIC 2}\nTRUKEAK: {DYNAMIC 3}\p“{DYNAMIC 4} {DYNAMIC 5}\n{DYNAMIC 6} {DYNAMIC 7}”\p");
ALIGNED(4) static const u8 sText_GladToMeetYouMale[] = _("{DYNAMIC 1}: Pozten naiz zu ezagututa!{PAUSE 60}");
ALIGNED(4) static const u8 sText_GladToMeetYouFemale[] = _("{DYNAMIC 1}: Pozten naiz zu ezagututa!{PAUSE 60}");

static const u8 *const sGladToMeetYouTexts[GENDER_COUNT] = {
    sText_GladToMeetYouMale,
    sText_GladToMeetYouFemale
};

ALIGNED(4) static const u8 sText_FinishedCheckingPlayersTrainerCard[] = _("Amaitu duzu {DYNAMIC 1}(r)en\nENTRENATZAILE TXARTLEA ikusten.{PAUSE 60}");

static const u8 *const sLinkGroupActivityNameTexts[] = {
    [ACTIVITY_NONE]              = sText_EmptyString,
    [ACTIVITY_BATTLE_SINGLE]     = sText_SingleBattle,
    [ACTIVITY_BATTLE_DOUBLE]     = sText_DoubleBattle,
    [ACTIVITY_BATTLE_MULTI]      = sText_MultiBattle,
    [ACTIVITY_TRADE]             = sText_PokemonTrades,
    [ACTIVITY_CHAT]              = sText_Chat,
    [ACTIVITY_WONDER_CARD_DUP]   = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS_DUP]   = sText_WonderNews,
    [ACTIVITY_CARD]              = sText_Cards,
    [ACTIVITY_POKEMON_JUMP]      = sText_PokemonJump,
    [ACTIVITY_BERRY_CRUSH]       = sText_BerryCrush,
    [ACTIVITY_BERRY_PICK]        = sText_BerryPicking,
    [ACTIVITY_SEARCH]            = sText_Search,
    [ACTIVITY_SPIN_TRADE]        = sText_EmptyString,
    [ACTIVITY_BATTLE_TOWER_OPEN] = sText_BattleTowerOpenLv,
    [ACTIVITY_RECORD_CORNER]     = sText_RecordCorner,
    [ACTIVITY_BERRY_BLENDER]     = sText_BerryBlender,
    [ACTIVITY_ACCEPT]            = sText_EmptyString,
    [ACTIVITY_DECLINE]           = sText_EmptyString,
    [ACTIVITY_NPCTALK]           = sText_EmptyString,
    [ACTIVITY_PLYRTALK]          = sText_EmptyString,
    [ACTIVITY_WONDER_CARD]       = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS]       = sText_WonderNews,
    [ACTIVITY_CONTEST_COOL]      = sText_CoolContest,
    [ACTIVITY_CONTEST_BEAUTY]    = sText_BeautyContest,
    [ACTIVITY_CONTEST_CUTE]      = sText_CuteContest,
    [ACTIVITY_CONTEST_SMART]     = sText_SmartContest,
    [ACTIVITY_CONTEST_TOUGH]     = sText_ToughContest,
    [ACTIVITY_BATTLE_TOWER]      = sText_BattleTowerLv50
};

static const struct WindowTemplate sWindowTemplate_BButtonCancel = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 30,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x0008
};

// Minimum and maximum number of players for a link group
// A minimum of 0 means the min and max are equal
#define LINK_GROUP_CAPACITY(min, max) (((min) << 12) | ((max) << 8))
#define GROUP_MAX(capacity) (capacity & 0x0F)
#define GROUP_MIN(capacity) (capacity >> 4)
#define GROUP_MIN2(capacity) (capacity & 0xF0) // Unnecessary to have both, but needed to match

static const u32 sLinkGroupToActivityAndCapacity[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI      | LINK_GROUP_CAPACITY(0, 4),
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE             | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP      | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH       | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK        | LINK_GROUP_CAPACITY(3, 5),
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY    | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER      | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN | LINK_GROUP_CAPACITY(0, 2)
};

static const struct WindowTemplate sWindowTemplate_PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_5PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_NumPlayerMode = {
    .bg = 0,
    .tilemapLeft = 16,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00c6
};

static const struct ListMenuItem sPossibleGroupMembersListMenuItems[] = {
    { sText_EmptyString, 0 },
    { sText_EmptyString, 1 },
    { sText_EmptyString, 2 },
    { sText_EmptyString, 3 },
    { sText_EmptyString, 4 }
};

static const struct ListMenuTemplate sListMenuTemplate_PossibleGroupMembers = {
    .items = sPossibleGroupMembersListMenuItems,
    .moveCursorFunc = NULL,
    .itemPrintFunc = ItemPrintFunc_PossibleGroupMembers,
    .totalItems = ARRAY_COUNT(sPossibleGroupMembersListMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 0,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_INVISIBLE
};

static const struct WindowTemplate sWindowTemplate_GroupList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 17,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_PlayerNameAndId = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00ee
};

static const struct ListMenuItem sUnionRoomGroupsMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

static const struct ListMenuTemplate sListMenuTemplate_UnionRoomGroups = {
    .items = sUnionRoomGroupsMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ListMenuItemPrintFunc_UnionRoomGroups,
    .totalItems = ARRAY_COUNT(sUnionRoomGroupsMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_InviteToActivity = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 5,
    .width = 16,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sInviteToActivityMenuItems[] = {
    { sText_Greetings, ACTIVITY_CARD | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Battle,    ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Chat2,     ACTIVITY_CHAT | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Exit,      ACTIVITY_NONE | IN_UNION_ROOM }
};

static const struct ListMenuTemplate sListMenuTemplate_InviteToActivity = {
    .items = sInviteToActivityMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sInviteToActivityMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_RegisterForTrade = {
    .bg = 0,
    .tilemapLeft = 18,
    .tilemapTop = 7,
    .width = 16,
    .height = 6,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sRegisterForTradeListMenuItems[] = {
    { gText_Register, 1 },
    { sText_Info, 2 },
    { sText_Exit, 3 }
};

static const struct ListMenuTemplate sListMenuTemplate_RegisterForTrade = {
    .items = sRegisterForTradeListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sRegisterForTradeListMenuItems),
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_TradingBoardRequestType = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 1,
    .width = 16,
    .height = 12,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sTradingBoardTypes[NUMBER_OF_MON_TYPES] = {
    { gTypeNames[TYPE_NORMAL],   TYPE_NORMAL         },
    { gTypeNames[TYPE_FIRE],     TYPE_FIRE           },
    { gTypeNames[TYPE_WATER],    TYPE_WATER          },
    { gTypeNames[TYPE_ELECTRIC], TYPE_ELECTRIC       },
    { gTypeNames[TYPE_GRASS],    TYPE_GRASS          },
    { gTypeNames[TYPE_ICE],      TYPE_ICE            },
    { gTypeNames[TYPE_GROUND],   TYPE_GROUND         },
    { gTypeNames[TYPE_ROCK],     TYPE_ROCK           },
    { gTypeNames[TYPE_FLYING],   TYPE_FLYING         },
    { gTypeNames[TYPE_PSYCHIC],  TYPE_PSYCHIC        },
    { gTypeNames[TYPE_FIGHTING], TYPE_FIGHTING       },
    { gTypeNames[TYPE_POISON],   TYPE_POISON         },
    { gTypeNames[TYPE_BUG],      TYPE_BUG            },
    { gTypeNames[TYPE_GHOST],    TYPE_GHOST          },
    { gTypeNames[TYPE_DRAGON],   TYPE_DRAGON         },
    { gTypeNames[TYPE_STEEL],    TYPE_STEEL          },
    { gTypeNames[TYPE_DARK],     TYPE_DARK           },
    { sText_Exit,                NUMBER_OF_MON_TYPES }
};

static const struct ListMenuTemplate sMenuTemplate_TradingBoardRequestType = {
    .items = sTradingBoardTypes,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sTradingBoardTypes),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_TradingBoardHeader = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 28,
    .height = 2,
    .paletteNum = 13,
    .baseBlock = 0x0001
};

static const struct WindowTemplate sWindowTemplate_TradingBoardMain = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sTradeBoardListMenuItems[] = {
    { sText_EmptyString, LIST_HEADER },
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_Exit2,  8 }
};

static const struct ListMenuTemplate sTradeBoardListMenuTemplate = {
    .items = sTradeBoardListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = TradeBoardListMenuItemPrintFunc,
    .totalItems = ARRAY_COUNT(sTradeBoardListMenuItems),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 14,
    .fillValue = 15,
    .cursorShadowPal = 13,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

// Unused
static const struct WindowTemplate sWindowTemplate_Unused = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sEmptyListMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

// Unused
static const struct ListMenuTemplate sEmptyListMenuTemplate = {
    .items = sEmptyListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ItemPrintFunc_EmptyList,
    .totalItems = ARRAY_COUNT(sEmptyListMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct RfuPlayerData sUnionRoomPlayer_DummyRfu = {0};

ALIGNED(4) static const u8 sAcceptedActivityIds_SingleBattle[]    = {ACTIVITY_BATTLE_SINGLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_DoubleBattle[]    = {ACTIVITY_BATTLE_DOUBLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_MultiBattle[]     = {ACTIVITY_BATTLE_MULTI, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Trade[]           = {ACTIVITY_TRADE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_PokemonJump[]     = {ACTIVITY_POKEMON_JUMP, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryCrush[]      = {ACTIVITY_BERRY_CRUSH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryPicking[]    = {ACTIVITY_BERRY_PICK, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderCard[]      = {ACTIVITY_WONDER_CARD, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderNews[]      = {ACTIVITY_WONDER_NEWS, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Resume[]          = {
    IN_UNION_ROOM | ACTIVITY_NONE,
    IN_UNION_ROOM | ACTIVITY_BATTLE_SINGLE,
    IN_UNION_ROOM | ACTIVITY_TRADE,
    IN_UNION_ROOM | ACTIVITY_CHAT,
    IN_UNION_ROOM | ACTIVITY_CARD,
    IN_UNION_ROOM | ACTIVITY_ACCEPT,
    IN_UNION_ROOM | ACTIVITY_DECLINE,
    IN_UNION_ROOM | ACTIVITY_NPCTALK,
    IN_UNION_ROOM | ACTIVITY_PLYRTALK,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_Init[]            = {ACTIVITY_SEARCH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Unk11[]           = {
    ACTIVITY_BATTLE_SINGLE,
    ACTIVITY_BATTLE_DOUBLE,
    ACTIVITY_BATTLE_MULTI,
    ACTIVITY_TRADE,
    ACTIVITY_POKEMON_JUMP,
    ACTIVITY_BERRY_CRUSH,
    ACTIVITY_BERRY_PICK,
    ACTIVITY_WONDER_CARD,
    ACTIVITY_WONDER_NEWS,
    ACTIVITY_SPIN_TRADE,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_RecordCorner[]    = {ACTIVITY_RECORD_CORNER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryBlender[]    = {ACTIVITY_BERRY_BLENDER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CoolContest[]     = {ACTIVITY_CONTEST_COOL, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BeautyContest[]   = {ACTIVITY_CONTEST_BEAUTY, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CuteContest[]     = {ACTIVITY_CONTEST_CUTE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_SmartContest[]    = {ACTIVITY_CONTEST_SMART, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_ToughContest[]    = {ACTIVITY_CONTEST_TOUGH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTower[]     = {ACTIVITY_BATTLE_TOWER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTowerOpen[] = {ACTIVITY_BATTLE_TOWER_OPEN, 0xff};

static const u8 *const sAcceptedActivityIds[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = sAcceptedActivityIds_SingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sAcceptedActivityIds_DoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sAcceptedActivityIds_MultiBattle,
    [LINK_GROUP_TRADE]             = sAcceptedActivityIds_Trade,
    [LINK_GROUP_POKEMON_JUMP]      = sAcceptedActivityIds_PokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sAcceptedActivityIds_BerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sAcceptedActivityIds_BerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sAcceptedActivityIds_WonderCard,
    [LINK_GROUP_WONDER_NEWS]       = sAcceptedActivityIds_WonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = sAcceptedActivityIds_Resume,
    [LINK_GROUP_UNION_ROOM_INIT]   = sAcceptedActivityIds_Init,
    [LINK_GROUP_UNK_11]            = sAcceptedActivityIds_Unk11,
    [LINK_GROUP_RECORD_CORNER]     = sAcceptedActivityIds_RecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sAcceptedActivityIds_BerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sAcceptedActivityIds_CoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sAcceptedActivityIds_BeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sAcceptedActivityIds_CuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sAcceptedActivityIds_SmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sAcceptedActivityIds_ToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sAcceptedActivityIds_BattleTower,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sAcceptedActivityIds_BattleTowerOpen
};

static const u8 sLinkGroupToURoomActivity[NUM_LINK_GROUP_TYPES + 2] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE,
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE,
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI,
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE,
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP,
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH,
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK,
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_WONDER_CARD,
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_WONDER_NEWS,
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE,
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE,
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE,
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER,
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER,
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE,
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL,
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY,
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE,
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART,
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH,
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN
};
