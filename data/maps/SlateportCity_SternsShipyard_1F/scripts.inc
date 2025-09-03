.set LOCALID_DOCK, 1

SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "Umm… Hau hemen jartzen bada\n"
	.string "eta horko hori hor…\p"
	.string "Non jartzen da honako hay?\n"
	.string "Eta tramankulu hau?\p"
	.string "Ene! Honek ez du ez hanka ez buru!\n"
	.string "Ezin dut ulertu nola egin hau!$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "Zer?\n"
	.string "Kaixo, KAI naiz.\p"
	.string "SARDINZAR KAPITAINAK ferry bat\n"
	.string "diseinatzeko agindu dit.\p"
	.string "Aizu! Horko hori…\n"
	.string "DEVON PIEZAK al dira?\p"
	.string "Baina, hmm…\n"
	.string "Honek ez du balio…\p"
	.string "SARDINZAR KAPITAINA norabait joan da.\n"
	.string "Egiteko lanen bat zuela esan du.\p"
	.string "Joan al zaitezke SARDINZAR\n"
	.string "KAPITAINAREN bila eta berari eman?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "KAI: Nora joan ote da SARDINZAR\n"
	.string "KAPITAINA?\p"
	.string "Joan al zaitezke SARDINZAR\n"
	.string "KAPITAINAREN bila eta piezak eman?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "KAI: Ontzigintza artea da.\p"
	.string "Hainbat kontu ezin dira\n"
	.string "kalkuluekin soilik egin.\p"
	.string "Itsasoak ondo ezagutzen dituen eskarmentu\n"
	.string "handiko norabaiten laguntza eskertuko nuke…$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "KAI: Kaixo! SARDINZAR JAUNA etorri\n"
	.string "da bere laguntza eskaintzera.\p"
	.string "Eskarmentudun itsasgizonari esker\n"
	.string "ferrya gero eta amaituago dago.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "KAI: Ferrya prest dago!\p"
	.string "MAREA ONTZIA teknologiaren\n"
	.string "miraria da!\p"
	.string "Baina, esango nuke zeozer oraindik\n"
	.string "hobea egin dezakegula.\p"
	.string "badakizu, teknologia ez da\n"
	.string "inoiz gelditzen.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "SARDINZAR JN.: Ei, {PLAYER}{KUN}!\n"
	.string "Aspaldiko!\p"
	.string "Txo, zu ezagutu zintudanetik,\n"
	.string "marinel hau jostalari sentitu da!\p"
	.string "Horregatik, KAIRI lagundu diot\n"
	.string "ferry bat diseinatzen.\p"
	.string "Txo, azkenean, ferryak jende\n"
	.string "asko eraman dezake.\p"
	.string "Baina, badakizu zer? KAI hori\n"
	.string "benetan berezia da.\p"
	.string "Teknologiarekin duen trebetasunarekin\n"
	.string "eta nire esperientziarekin, ziur ontzi\l"
	.string "izugarri bat eraikiko dugula, txo!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "Urtaroak, eguraldia, non\n"
	.string "dagoen ilargia zerruan…\p"
	.string "Hauek eta beste baldintza batzuek\n"
	.string "itsasoa guztiz aldatzen dute.\p"
	.string "Hori da!\n"
	.string "Itsasoa biziduna da, ia!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "Erraz jartzen naiz ondoezik.\n"
	.string "Horregatik geratzen naiz hemen laguntzen.$"

