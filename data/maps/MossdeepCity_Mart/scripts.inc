MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	pokemartlistend

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "BERPIZTAILEA itzela da!\p"
	.string "Eman indargabetutako POKéMON bati,\n"
	.string "eta POKéMONA berpiztu egingo da.\p"
	.string "Baina kontuz, BERPIZTAILEAK ez ditu\n"
	.string "erabilitako PPak sendatzen eta.$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "MAX UXAGARRIAK POKéMON ahulak uxatzen\p"
	.string "ditu. UXAGARRI guztietan gehien\n"
	.string "irauten duena da.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "SARE eta URPE BALLAK GOROLDIN soilik\n"
	.string "egiten diren POKé BALL arraroak dira.\p"
	.string "SARE BALLA egokia da ZOMORRO eta\n"
	.string "UR motako POKéMONENTZAT.\p"
	.string "URPE BALLA ona da itsas-hondoan\n"
	.string "bizi diren POKéMONENTZAT.$"

