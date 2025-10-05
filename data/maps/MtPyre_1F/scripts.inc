MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "Mota guztietako izakiak daude\n"
	.string "PIRO MENDIAN…\p"
	.string "Inork ez daki zer gertatuko den.\n"
	.string "Tori hau. Zure onerako da.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Eman GARBITZE AMULETOA\n"
	.string "POKéMON bati.\p"
	.string "POKéMON basatiak uxatuko ditu.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Zendutako POKéMONEN espirituei\n"
	.string "agur esatera al zatoz?\p"
	.string "Asko zaintzen dituzu zure POKéMONAK.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "Hau da nire ZIGZAGOON maitearen\n"
	.string "deskantsu lekua. Asko maite nuen…$"

