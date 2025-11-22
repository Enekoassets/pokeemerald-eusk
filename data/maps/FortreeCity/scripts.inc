FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "Inork ez dit sinisten, baina POKéMON\n"
	.string "erraldoi bat ikusi dut zeruan.\p"
	.string "131. ERRUTARANTZ zihoala\n"
	.string "iruditu zait.\p"
	.string "Bestalde… Zintz…\n"
	.string "Beno… Zuk…usain berezia duzu.\p"
	.string "Sumendi batean egon al zara?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "POKéMON GIMNASIORA joan nahi dut,\n"
	.string "baina zerbait dago bidean.\p"
	.string "120. ERRUTAN horrenbeste\n"
	.string "entrenatzen egon ostean…$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "Nire POKéMON kuttuna dut nirekin.\n"
	.string "Oraingoan HAIZEA garaituko dut.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "Lurrak euria xurgatzen du eta\n"
	.string "hala hazten dira zuhaitzak…\p"
	.string "ZUHAITZAGA HIRIA hemen ura eta lurra,\n"
	.string "biak daudelako existitzen da.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "HIRIA zuhaitzetan eraikitako etxeek\n"
	.string "osatzen dute.\p"
	.string "Agian, bizimodu horri esker daude\n"
	.string "biztanleak osasuntsu eta pozik.\p"
	.string "Ni ere hogeita haman urte gaztetu\n"
	.string "izan banitu bezala sentitzen naiz.$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "Zuhaitz gainean bizitzea ondo dago.\p"
	.string "Baina, batzuetan ZOMORRO POKéMONAK\n"
	.string "sartzen dira leihoetatik.\l"
	.string "Pixka bat nazkagarria da.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "Trukatzean eboluzionatzen diren\n"
	.string "POKéMONAK daude! Hori entzun dut.$"

FortreeCity_Text_SomethingUnseeable:
	.string "Zerbait ikustezina dago bidean.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "Zerbait ikustezina dago bidean.\p"
	.string "DEVON DETEKTAGAILUA erabili nahi duzu?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{PLAYER}(e)k DEVON DETEKTAGAILUA erabili du.\p"
	.string "POKéMON ikusezin bat guztiz\n"
	.string "ikusgai bihurtu da!\p"
	.string "POKéMON izutuak ihes egin du!$"

FortreeCity_Text_CitySign:
	.string "ZUHAITZAGA HIRIA\n"
	.string "“Naturarekin jolasten den\l"
	.string "zuhaitz gaineko hiria.”$"

FortreeCity_Text_GymSign:
	.string "ZUHAITZAGA HIRIKO POKéMON GIMNASIOA\n"
	.string "LIDERRA: HAIZEA\p"
	.string "“Txoriak erabiliz hegan\n"
	.string "egiten duena.”$"

