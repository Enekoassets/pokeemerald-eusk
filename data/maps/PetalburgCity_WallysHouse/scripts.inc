.set LOCALID_WALLYS_DAD, 1

PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Zu…\n"
	.string "Bai, {PLAYER}{KUN} zara, ezta?\p"
	.string "Eskerrik asko EKAITZEKIN jolasten\n"
	.string "ibiltzeagatik.\p"
	.string "Ume-umetatik mutiko gaixo eta\n"
	.string "ahula izan da.\p"
	.string "BERDEZELAIKO gure familiarengana bidali\n"
	.string "dugu aldi baterako.\p"
	.string "Hango airea hemengoa baino askoz\n"
	.string "garbiagoa da.\p"
	.string "Zer diozu? Non dagoen EKAITZ?\n"
	.string "Joan egin da, gure EKAITZ.\p"
	.string "Noraino iritsiko ote zen\n"
	.string "jadanik?$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Nola egongo ote da gure EKAITZ?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN}! Barkatu zu honaino\n"
	.string "ekartzeagatik. Baina gure\p"
	.string "EKAITZ oso ondo dago osasunez\n"
	.string "BERDEZELAI HERRIRA joan zenetik.\p"
	.string "Zuri esker izan da guztia!\p"
	.string "EKAITZ herritik joan zenean, POKéMON\n"
	.string "bat harrapatzen lagundu zenion, ezta?\p"
	.string "Uste dut EKAITZ asko poztu\n"
	.string "zuela horrek.\p"
	.string "Beno, ez EKAITZ bakarrik.\n"
	.string "Ni ere, bere aita, asko poztu nintzen.\p"
	.string "Zu bezalako lagun itzel bat egin\n"
	.string "zuelako poztu nintzen hainbeste.\p"
	.string "Ez da zu erosteko, baina hau\n"
	.string "oparitu nahi nizuke.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Zure POKéMONAK SURFA egin badezake,\n"
	.string "leku askotara joan ahal izango duzu.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "EKAITZ laister dator etxera.\n"
	.string "Bera etortzeko irrikan nago.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Zer? ITZELETA HIRIAN ikusi\n"
	.string "zenuela EKAITZ?\p"
	.string "Aizu, {PLAYER}{KUN}, ez ibili txantxetan.\p"
	.string "Egia da osasuntsuago dagoela, baina\n"
	.string "ezinezkoa da horren urruti dagoen leku\l"
	.string "batera bakarrik iritsi izana.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "EKAITZ asko poztu zen POKéMON bat\n"
	.string "harrapatu zuela esan zigunean.\p"
	.string "Urteak ziren horrelako irribarrea\n"
	.string "ikusten ez niola.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "Hau ez kontatu nire senarrari,\n"
	.string "mesedez…\p"
	.string "Baina gure EKAITZ BERDEZELAITIK\n"
	.string "joan da inori ezer esan gabe.\p"
	.string "Badakizu, EKAITZ ahula da, baina\n"
	.string "izugarrizko gogoz egiten du guztia.\p"
	.string "Ziur nago itzuliko dela egunen\n"
	.string "batean ongi, eta pozik!$"

