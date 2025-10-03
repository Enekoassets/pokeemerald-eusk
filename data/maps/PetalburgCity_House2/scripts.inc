PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "NORMAN gure herriko GIMNASIOKO\n"
	.string "LIDER berria da.\p"
	.string "Uste dut bere familiarekin etorri\n"
	.string "dela, urrutiko lekuren batetik.$"

PetalburgCity_House2_Text_BattledNormanOnce:
	.string "NORMANEN aurka borrokatu nuen behin,\n"
	.string "baina, uf, indartsuegia zen.\p"
	.string "Nola esan dezaket?\p"
	.string "POKéMONENTZAT soilik bizi\n"
	.string "zela zirudien.$"

