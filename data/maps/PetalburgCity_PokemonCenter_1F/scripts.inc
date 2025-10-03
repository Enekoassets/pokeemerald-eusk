.set LOCALID_NURSE, 1

PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "Ordenagailuan POKéMONAK Gordetzeko\n"
	.string "Sistema hori…\p"
	.string "Asmatu zuena aztia edo horrelako\n"
	.string "zerbait izango da!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "Nire POKéMONAK ARANJA BAIA bat jan\n"
	.string "zuenean, BPak sendatu zituen!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "POKéMON mota asko daude.\p"
	.string "Mota guztiek dituzte ahulgunea eta\n"
	.string "indargunean beste moten aurka.\p"
	.string "POKéMONEN moten arabera, borroka\n"
	.string "bat erraza edo zaila izan daiteke.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "Adibidez, zure TREECKO\n"
	.string "LANDARE motakoa da.\p"
	.string "Indartsua da UR eta LUR\n"
	.string "moten aurka.\p"
	.string "Baina, ahula SU motako\n"
	.string "POKéMONEN aurka.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "Adibidez, zure TORCHIC\n"
	.string "SU motakoa da.\p"
	.string "Indartsua da LANDARE eta ZOMORRO\n"
	.string "moten aurka.\p"
	.string "Baina, ahula UR motako\n"
	.string "POKéMONEN aurka.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "Adibidez, zure MUDKIP\n"
	.string "UR motakoa da.\p"
	.string "Indartsua da SU motaren aurka.\p"
	.string "Baina, ahula LANDARE eta\n"
	.string "ELEKTRIKO motako POKéMONEN aurka.$"

