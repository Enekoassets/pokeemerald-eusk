.set LOCALID_FAMILIAR_GRUNT, 13

SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "Ongi etorri MUSEO OZEANIKORA.\p"
	.string "Sarrera 50¥ dira.\n"
	.string "Sartu nahi al duzu?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "Gozatuko duzula espero dugu.$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "Zer? Barkatu baina badirudi\n"
	.string "ez duzula nahikoa diru.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "Zer? Lehen sartu den talde\n"
	.string "horretakoa al zara?\p"
	.string "Berandu datorren bakarra zara.\n"
	.string "Arin ibili, ea harrapatzen dituzun!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "Gu, AQUA TALDEA, guztien ongizatea\n"
	.string "lortzeko existitzen gara!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "Hemen batzeko esan digute,\n"
	.string "eta hala egin dugu, baina…\p"
	.string "Gure NAGUSIA ez da iritsi.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "Hemengo gauzak lapurtuko banitu,\n"
	.string "aberastuko ote nintzateke?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "Hemen ikasten dudana gure ekintza\n"
	.string "gaiztoetan erabili dezaket…$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "Gure kdieek ez balute BURDINTZAN guztia\n"
	.string "pikutara bidali, ez ginateke hemen!$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "Ez neuzkan 50¥, beraz, asko kostatu\n"
	.string "zait harreragileak pasatzen uztea.$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "Itsasoaren inguruan ikasi nahi dut\n"
	.string "eta jakinduria hori borrokan erabili.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "Zorabiatu egiten naiz itsasoa\n"
	.string "ikusten dudanean!\p"
	.string "Niretzat ABABOR KAPITAINA\n"
	.string "benetako eredua da!$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "Itsasoa amaigabea da eta\n"
	.string "sakoneran ere infinitua…\p"
	.string "Ziur ezagutzen ez ditugun\n"
	.string "POKéMON asko daudela.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "Itsasoko POKéMON bat nahi dut.\p"
	.string "Nik uste besarkatzeko fresko\n"
	.string "eta atsegina dela.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "Aizuuuuu!\n"
	.string "Zertan ari zara hemen?\p"
	.string "Ni? Lehen garaitu duzun AQUA\n"
	.string "TALDEKO kidea, ez zara gogoratzen?\l"
	.string "BURDIZELAI TUNELEAN?\p"
	.string "Aizu, tori hau!\n"
	.string "Barkatu egin behar didazu!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "MT hori hobe geratzen\n"
	.string "zaizu zuri niri baino.\p"
	.string "Espero dut ez zaitudala gehiago ikusiko!\n"
	.string "Kar-kar-kar!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "Aizu, bai zera!\n"
	.string "Hau hartu eta joaten utzi behar didazu!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "Kristalezko ontzi baten barruan\n"
	.string "likido urdin bat ikusi daiteke.\p"
	.string "“ZURRUNBILO bat haizea erabilita\n"
	.string "artifizialki sortzeko esperimentua.”$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "Kristalezko ontzi baten barruan\n"
	.string "bola gorri bat gora eta behera ari da.\p"
	.string "“UR-JAUZI bat bolaren flotagarritasuna\n"
	.string "erabilita simulatzeko esperimentua.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "Ozeanoaren hondoko lur\n"
	.string "lagin bat da.\p"
	.string "“Urteetan zehar, izaki bizidunen\n"
	.string "hondakinak itsas-hondoan geratzen\l"
	.string "dira, sedimentu geruzak eratuz.\p"
	.string "“Geruza hauek aztertuz, antzinako\n"
	.string "informazioa lortu daiteke.”$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "Hondartzako harea lagin bat da.\p"
	.string "“Mendietako harriak erreketan\n"
	.string "zehar jaisten dira, azkenean\l"
	.string "zatitu eta hauts bihurtzeko.\p"
	.string "“Ale txiki bihurtzen dira azkenean,\n"
	.string "hondartzeko harea bilakatuz.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "“1. OZEANOAREN DATUA\n"
	.string "Zergatik da itsasoa urdina?\p"
	.string "“Argia hainbat kolorek osatuta dago.\p"
	.string "“Argia uretan zehar igarotzean,\n"
	.string "argi gehienak kolorea galtzen du.\p"
	.string "“Hala ere, argi urdinak ez du galtzen\n"
	.string "galtzen, itsasoa urdin bihurtuz.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "“2. OZEANOAREN DATUA\n"
	.string "Zergatik da itsasoa gazia?\p"
	.string "“Itsasoko urak gatza du, sodio\n"
	.string "eta kloro ioi forman disolbatuta.\p"
	.string "“Ioi hauek arroketatik erauzten dira\n"
	.string "eta euriak itsasora eramaten ditu.\p"
	.string "“Disolbatutako gatzaren kontzentrazioak\n"
	.string "bihurtzen du itsasoa gazi.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "“3. OZEANOAREN DATUA\n"
	.string "Zein da handiagoa? Itsasoa edo lurra?\p"
	.string "“Itsasoak planetaren %70 estaltzen\n"
	.string "du, eta gainerakoa lurra da.\p"
	.string "“Ondorioz, itsasoa lurraren bikoitza\n"
	.string "baino handiagoa da tamainan.”$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "Marka uhindunak dituen fosil bat da.\p"
	.string "“Itsas hondoko harea ur lasterrek\n"
	.string "mugitzen dute.\p"
	.string "“Ur mugikor honek lurra markatzen\n"
	.string "du haran eta muino ñimiñoekin.\p"
	.string "“Lur hau fosilizatzen bada,\n"
	.string "uhin marka deitzen zaio.”$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "Makina arraro bat dago biraka\n"
	.string "kristalezko domo baten pean.\p"
	.string "Agian zerbaiten sakonera\n"
	.string "neurtzeko edo balio du…$"

