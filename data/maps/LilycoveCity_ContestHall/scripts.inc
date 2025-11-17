@ VAR_LAST_TALKED would have made all these direct references unnecessary
.set LOCALID_SMART_MC, 4
.set LOCALID_SMART_JUDGE, 5
.set LOCALID_SMART_CONTESTANT_1, 6
.set LOCALID_SMART_CONTESTANT_2, 7
.set LOCALID_SMART_CONTESTANT_3, 8
.set LOCALID_SMART_CONTESTANT_4, 9
.set LOCALID_SMART_AUDIENCE_4, 11
.set LOCALID_SMART_AUDIENCE_2, 12
.set LOCALID_BEAUTY_MC, 13
.set LOCALID_BEAUTY_JUDGE, 14
.set LOCALID_BEAUTY_CONTESTANT_1, 15
.set LOCALID_BEAUTY_CONTESTANT_2, 16
.set LOCALID_BEAUTY_CONTESTANT_3, 17
.set LOCALID_BEAUTY_CONTESTANT_4, 18
.set LOCALID_BEAUTY_AUDIENCE_1, 19
.set LOCALID_BEAUTY_AUDIENCE_3, 20
.set LOCALID_BEAUTY_AUDIENCE_2, 21
.set LOCALID_SMART_AUDIENCE_3, 22
.set LOCALID_CUTE_MC, 23
.set LOCALID_CUTE_JUDGE, 24
.set LOCALID_CUTE_CONTESTANT_1, 25
.set LOCALID_CUTE_CONTESTANT_2, 26
.set LOCALID_CUTE_CONTESTANT_3, 27
.set LOCALID_CUTE_CONTESTANT_4, 28
.set LOCALID_CUTE_AUDIENCE_1, 29
.set LOCALID_CUTE_AUDIENCE_3, 30
.set LOCALID_CUTE_AUDIENCE_2, 31

LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "POKéMON honek irabazi du lehenago\n"
	.string "hemengo EDERTASUN TXAPELKETA.\p"
	.string "Ba, badakizu zer? Gaur AZKARTASUN\n"
	.string "TXAPELKETA irabaztea lortu dut!\p"
	.string "Nire trebetasunak beldurtu egiten nau…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "Hainbat TXAPELKETATAN sartu naiz,\n"
	.string "nola funtzionatzen duten ikusi dut.\p"
	.string "KARISMA TXAPELKETETAN, eraso\n"
	.string "karismatikoek ondo funtzionatzen dute.\p"
	.string "Baina eraso azkar eta politek ez dute\n"
	.string "horren ondo funtzionatzen, adibidez.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "Lehen irabazi duen gizon gazte horrek\n"
	.string "hainbat {POKEBLOCK} erabili ditu.\p"
	.string "Irabazi egingo ote zenuke horrenbeste\n"
	.string "{POKEBLOCK} erabiliko bazenitu?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "Ene, leku hau erraldoia da!\p"
	.string "Aireko tentsioa… Ez da edonolako\n"
	.string "TXAPELKETA aretoa, ez.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "ZM: Ongi, POKéMON AZKARRAK eta haien\n"
	.string "ENTRENATZAILEAK. Prest al zaudete?!\p"
	.string "Eman ezazue zuen onena!\n"
	.string "Has gaitezen!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "EPAILEA: Gustuko duzu TXAPELKETA hau?\p"
	.string "Etorri zaitez hiru lagunekin eta\n"
	.string "denek har dezakezue parte batera!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "Aiaiaiaia…\n"
	.string "Okerreko TXAPELKETAN sartu naiz.\p"
	.string "POKéMON gogor bat sartu dut\n"
	.string "AZKARTASUN TXAPELKETAN…\p"
	.string "Ea ba, harritu itzazu ARROKA\n"
	.string "KOLPE azkar batekin, orduan.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "Urte asko pasa ditut, nire zuhurtzia\n"
	.string "guztiarekin POKéMON hau hazten,\l"
	.string "azkarra izan dadin.\p"
	.string "Gaztetxo baten POKéMONAK ez dio\n"
	.string "berehalakoan irabaziko.\p"
	.string "Emazte maitea, ikusten ari al zara?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "Hori da!\p"
	.string "Nire POKéMONAK eraso azkar bat erabiltzen\n"
	.string "badu, publikoa izugarri animatuko da!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "Ai ene, ez!\p"
	.string "Nire ZUBAT maitearen BIZI XURGAKETA\n"
	.string "horren ederra da, etengabe erabili dudala!\p"
	.string "Baina pertsona desatsegin hauei ez\n"
	.string "zaie batere gustatu!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "Iaiiii! Ederra zara, aitona!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "ENTRENATZAILEEK POKéMON berdinak erabiltzen\n"
	.string "badituzte ere, eraso desberdinak\l"
	.string "agintzen dizkiete normalean.\p"
	.string "Jendeak borrokarako estilo\n"
	.string "desberdinak dituen bezala.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "POKéMONAK beraien ENTRENATZAILEAK\n"
	.string "baino askoz azkarragoak dira, nire ustez.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "Dena kontuan hartuta, benetan atsegin\n"
	.string "ditut AZKARTASUN TXAPELKETAK.\p"
	.string "Kolore berde intelektual hori…\n"
	.string "Benetan da… Oso… Itzela.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "ZM: Zure ere EDERTASUN TXAPELKETAN\n"
	.string "sartuko zara? Zorte on!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "EPAILEA: Hemengo POKéMON guztiak\n"
	.string "benetan dira ederrak eta apartak!\p"
	.string "Ia ia puntuak ematea ahaztu zait!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "Honen ederra den POKéMONIK…\n"
	.string "Ez dago halakorik inon.\p"
	.string "Denen begiak nire maite politari\n"
	.string "itsatsita egongo dira.$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "Buaaaa!\p"
	.string "Ondo orraztu eta apaindu dut nire\n"
	.string "POKéMONA TXAPELKETA honetarako…\p"
	.string "Baina pasa egin naiz…\n"
	.string "Nire POKéMONAREN ilea laztu egin da…\p"
	.string "Zer egingo dut?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "AURORA IZPIA horren miragarria da,\n"
	.string "EPAILEAK ez duela ikusi ere egingo.\p"
	.string "Ene, itxaron pixka bat…\n"
	.string "Orduan ez du ezertarako balioko!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "POKéMON honek gaztea nintzeneko\n"
	.string "edertasuna dauka.\p"
	.string "Hori esan nuenean, nire senarrak edaten\n"
	.string "ari zen kafea zurrustan bota zuen.\p"
	.string "Zerbait graziosoa esan al dut, bada?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "Badakizu, EDERTASUN TXAPELKETA bat\n"
	.string "irabazten badut, oso alai jartzen\l"
	.string "naiz. Normalean baino gehiago, bederen.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "Uajajajaja!\p"
	.string "Begiratu ondo POKéMON eder guzti\n"
	.string "horiek!\l"
	.string "Harrigarriak dira guztiz!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "Ezin duzu edertasunarekin bakarrik\n"
	.string "irabazi beti.\p"
	.string "Zure POKéMONA ondo orraztu behar duzu\n"
	.string "nirea bezain txukun egoteko.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "ZM: Ene! Kaixo!\n"
	.string "TXAPELKETA betean gaude orain!\p"
	.string "Mesedez, joan harrerara izena\n"
	.string "emateko eta bertatik sartu, bai?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "EPAILEA: Ene, hauek bai erakustaldi\n"
	.string "eder eta erakargarriak!\p"
	.string "Ene jainkoa! Hori bai UR ZORROTADA\n"
	.string "erakustaldi polita!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "Ai ene… Nire AZURILL txikiari beste\n"
	.string "POKéMON batek arreta galarazi dio.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "Nire POKéMONAK ez du inoiz borrokan irabazi,\n"
	.string "baina TXAPELKETETAN izugarria da!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "Nire POKéMONAREN PETALO DANTZA\n"
	.string "izugarri dotorea da.\p"
	.string "Ez diot inori utziko erakustaldia\n"
	.string "mozten.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "Denen POKéMONAK dira oso politak.\p"
	.string "Baina nire POKéMONAK POLITASUN\n"
	.string "erakustaldia egingo balu…\p"
	.string "Ziur nago besteena baino askoz\n"
	.string "politagoa izango litzatekeela.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "Nire haurra TXAPELKETA honetan dago.$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "Ea ba, maitea. Eman egurra!\n"
	.string "Zure POKéMONA onena da!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "Horko neska hori dela\n"
	.string "denetan politena uste dut.\p"
	.string "Zer diozu? POKéMONEN itxura\n"
	.string "dela baloratzen dutena?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "Ene, POKéMON polit hauek guztiak\n"
	.string "ikusita, niretzako bat nahi dut!\p"
	.string "Batzuk harrapatuko ditut!$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "EDERTASUN TXAPELKETA ARETOA\n"
	.string "POKéMON EDERREK ZORATUKO ZAITUZTE!$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "POLITASUN TXAPELKETA ARETOA\n"
	.string "POKéMON POLITEK MAITEMINDUKO ZAITUZTE!$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "AZKARTASUN TXAPELKETA ARETOA\n"
	.string "POKéMON AZKARREK HARRITUKO ZAITUZTE!$"

