RustboroCity_Flat2_3F_MapScripts::
	.byte 0

RustboroCity_Flat2_3F_EventScript_DevonEmployee::
	msgbox RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_EventScript_Woman::
	msgbox RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones:
	.string "DEVONEKO PRESIDENTEAK harri berezien\n"
	.string "bilduma egitea atsegin du.$"

RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones:
	.string "Uste dut PRESIDENTEAREN semeak ere\n"
	.string "harri bereziak biltzen dituela.$"

