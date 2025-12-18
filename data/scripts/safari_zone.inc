SafariZone_EventScript_OutOfBallsMidBattle::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	end

SafariZone_EventScript_Exit::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
#ifdef BUGFIX
	releaseall  @ Only gets called from EventScript_PokeBlockFeeder which uses lockall.
#endif
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.string "Nahi al duzu SAFARI GUNETIK\n"
	.string "atera oraintxe bertan?$"

SafariZone_Text_TimesUp:
	.string "Din-don! Denbora amaitu da!\n"
	.string "Zure SAFARI Partida amaitu da.$"

SafariZone_Text_OutOfBalls:
	.string "SAFARI BALLIK gabe geratu zara.\n"
	.string "Zure SAFARI Partida amaitu da.$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "Nahi duzu {POKEBLOCK} bat jarri\n"
	.string "{POKEBLOCK} ELIKAGAILUAN?$"

SafariZone_Text_PokeblockStillHere:
	.string "Lehen jarri duzun {STR_VAR_1}\n"
	.string "hemen dago oraindik.$"

SafariZone_Text_PokeblockWasPlaced:
	.string "{STR_VAR_1} bat jarri duzu\n"
	.string "{POKEBLOCK} ELIKAGAILUAN.$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "Ongi etorri SAFARI GUNERA!\p"
	.string "Hemen, HOENNEN gutxi ikusten diren\n"
	.string "POKéMONAK aurkituko dituzu.\p"
	.string "Eta, beraien egoera basatian\n"
	.string "ikusiko dituzu, habitat naturalean.\p"
	.string "Gainera, ENTRENATZAILEENTZAKO\n"
	.string "sarrera ireki dugu.\p"
	.string "POKéMONAK harraptu ditzakezu,\n"
	.string "eta zuretzat izango dira!\p"
	.string "Sartu eta gozatu SAFARI GUNEAZ!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "Ongi etorri SAFARI GUNERA!\n"
	.string "Zure lehen aldia al da hemen?$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "Sartu eta gozatu SAFARI GUNEAZ!$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "SAFARI GUNERA sartzen zarenean,\n"
	.string "30 SAFARI BALL emango dizkizugu\l"
	.string "POKéMONAK harrapatzeko.\p"
	.string "SAFARI Partida amaitu egingo da\n"
	.string "SAFARI BALL gabe geratzen zarenean,\l"
	.string "edo 500 pausu ematen dituzunean.\p"
	.string "Pasa eta gozatu SAFARI GUNEAZ!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "Ongi etorri SAFARI GUNERA Harrapatu!\p"
	.string "ahal duzun guztia 500¥ren truke!\n"
	.string "Nahi al duzu SAFARI Partida bat egin?$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "Ados.\n"
	.string "Etorri beste batean, mesedez!$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "Ez daukazu nahikoa diru sartzeko.\n"
	.string "Barkatu.$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "500¥ izango lirateke, mesedez.$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "Tori zure SAFARI BALLAK.$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER}(r)ek 30 SAFARI BALL jaso ditu.$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "Abisatuko dizugu zure partida\n"
	.string "amaitzen denean.\p"
	.string "Beraz, ondo pasa ordura arte!\n"
	.string "Aurrera, segi zure abentura basatira!$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "Barkatu!\n"
	.string "Zure PC KUTXA betea dago.$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "Barkatu!\n"
	.string "Badirudi ez duzula {POKEBLOCK} KUTXARIK.\p"
	.string "Zure SAFARI Partida askoz aberasgarriagoa\n"
	.string "izango da {POKEBLOCK}AK erabilita.\p"
	.string "Mesedez, itzuli {POKEBLOCK} KUTXA batekin.\p"
	.string "{POKEBLOCK} KUTXA bat lor dezakezu\n"
	.string "UR-LILIKO TXAPELKETA ARETOAN.$"

SafariZone_South_Text_StillHaveTimeExit:
	.string "Denbora duzu oraindik. Nahi duzu\n"
	.string "SAFARI GUNETIK atera hala ere?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "Gozatu zure abentura basatitik\n"
	.string "geratzen zaizuna!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "Ados.\p"
	.string "Geratu zaikizun SAFARI BALLAK\n"
	.string "jasoko ditut.\p"
	.string "Eskerrik asko jolasteagatik.\n"
	.string "Berriz etorriko zarela espero dugu.$"

SafariZone_South_Text_GoodLuck:
	.string "Zorte on!\p"
	.string "Zeozer behar baduzu, esan niri\n"
	.string "lasai, mesedez!$"

SafariZone_South_Text_Boy:
	.string "Ba al zenekien?\p"
	.string "{POKEBLOCK} bat jartzen baduzu kutxa karratu\n"
	.string "horretan, POKéMONAK hurbiltzen dira.$"

SafariZone_South_Text_Man:
	.string "Aurrera jarraitu nahi dut, baina\n"
	.string "BIZIKLETA ekartzea ahaztu zait.\p"
	.string "Iruditzen zait POKéMON arraroak egongo\n"
	.string "direla kanpoaldeko guneetan.$"

SafariZone_Southwest_Text_Woman:
	.string "Batzuetan POKéMON bati {POKEBLOCK} bat\n"
	.string "botatzen badiot, ez dit kasurik egiten.\p"
	.string "POKéMONEK atsegin dituzten eta ez\n"
	.string "dituzten janariak al dituzte, ba?$"

SafariZone_Northwest_Text_Man:
	.string "Ufff… Ufff…\n"
	.string "Ni…honaino iritsi naiz…baina…\p"
	.string "Akituta nago… Ez dut energiarik\n"
	.string "POKéMONAK harrapatzen jarraitzeko…$"

SafariZone_North_Text_Fisherman:
	.string "HOENNEN agertzen ez diren UR POKéMONAK\n"
	.string "harrapatzea da nire misioa.\p"
	.string "Ba al dakizu non dagoen lakua?$"

SafariZone_North_Text_Man:
	.string "POKéMON arraro pila bat harrapatuko\n"
	.string "ditut nire lagunekin trukatzeko!$"

SafariZone_South_Text_Youngster:
	.string "{POKEBLOCK} bat jarri dut ELIKAGAILUAN.\n"
	.string "Baina desagertu egin dela dirudi.\p"
	.string "Agian POKéMONEK jan dute ni konturatu\n"
	.string "ere egin gabe.$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "SAFARI ENTRENATZAILEENTZAKO PISTA!\p"
	.string "Bota {POKEBLOCK}AK POKéMON BASATIEI\n"
	.string "gutxiagotan egin dezaten ihes.$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "“Deskantsatu zure oin nekatuak.”\n"
	.string "ATSEDEN ETXEA$"

SafariZone_RestHouse_Text_Youngster:
	.string "Ez dut {POKEBLOCK}IK, baina POKéMON\n"
	.string "asko harrapatu ditut jada.\p"
	.string "Harrapatzea errazagoa da SAFARI BALLA\n"
	.string "bota aurretik POKéMONARENGANA\l"
	.string "hurbiltzen bazara.$"

SafariZone_RestHouse_Text_PsychicM:
	.string "{POKEBLOCK}AK erabiltzen badituzu, POKéMON\n"
	.string "basatiek ez dute horren erraz ihes egingo.\p"
	.string "Ez du zentzu handirik gutxitan ihes egiten\n"
	.string "duten POKéMONEI {POKEBLOCK}AK emateak.$"

SafariZone_RestHouse_Text_FatMan:
	.string "ELIKAGAILUAN {POKEBLOCK} bat jartzen\n"
	.string "baduzu, POKéMONAK hurbiltzen dira.\p"
	.string "Uste dut izaera jakin bateko POKéMONAK\n"
	.string "{POKEBLOCK} batzuetara hurbiltzen direla.$"

SafariZone_South_Text_AreaOffLimits1:
	.string "Oraindik gune hau eraikitzen ari gara.\n"
	.string "Ezin duzu pasa, barkatu!$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "SAFARI GUNEKO zabalketa proiektua\n"
	.string "amaitu berri dago.\p"
	.string "Gune berria gozatzea espero dugu.$"

SafariZone_South_Text_AreaOffLimits2:
	.string "Oraindik gune hau eraikitzen ari gara.\n"
	.string "Ezin duzu pasa, barkatu!$"

SafariZone_Southeast_Text_LittleGirl:
	.string "Uau! Aizu! Ez dut inoiz hemengoak\n"
	.string "bezalako POKéMONIK ikusi!$"

SafariZone_Southeast_Text_FatMan:
	.string "Gune honetako POKéMONAK guztiz berriak\n"
	.string "dira niretzat.\p"
	.string "Eta POKéMON arraro hauek harrapatu\n"
	.string "ditzaket, gainera! Itzela!$"

SafariZone_Southeast_Text_RichBoy:
	.string "Hemen inguruko POKéMONAK ez dira\n"
	.string "HOENNEKOAK, beste nonbaitekoak baizik.$"

SafariZone_Northeast_Text_Boy:
	.string "Pare bat SAFARI BALL geratzen zaizkit.\p"
	.string "Asko ari zait kostatzen zer harrapatu\n"
	.string "erabakitzea.$"

SafariZone_Northeast_Text_Woman:
	.string "Entzun dut PIKACHUAK daudela hemen.\n"
	.string "Non egongo ote dira?$"

SafariZone_Northeast_Text_Girl:
	.string "Ene, kaka!\n"
	.string "Ezin dut ezer harrapatu!\p"
	.string "Sarrerako dirua alferrik galduko\n"
	.string "dut ez badut ezer harrapatzen!$"
