.set LOCALID_NURSE, 1

FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Entzun, gazte, POKéDEX batekin\n"
	.string "lanean ari al zara?\p"
	.string "Hmm… Joan SAFARI GUNERA, orduan.\n"
	.string "Hori gomendatzen dizut.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Egun al duzu zeozer\n"
	.string "ERREKORREN TXOKOAN?\p"
	.string "Itzela da. ENTRENATZAILEEN errekorrak\n"
	.string "nahastu eta bateratzen ditu.\p"
	.string "Ez dakit nola funtzionatzen duen,\n"
	.string "baina ederra da. Bizigarria, alajaina!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Ene, bada, POKéNAV bat daukazu!\n"
	.string "Nirea bezalakoa, gainera!\p"
	.string "Ezagutzen al duzu POKéNAVEN\n"
	.string "BORROKA DEIEN sistema?\p"
	.string "Sartu bertan, eta erregistratutako\n"
	.string "ENTRENATZAILEEKIN hitz egin dezakezu.\p"
	.string "Gainera, zein ENTRENATZAILEK nahi\n"
	.string "duen errbantxa ere jartzen du.\p"
	.string "Oso erabilgarria da! DEVONEKO horiek\n"
	.string "badakite zertan ari diren!$"

