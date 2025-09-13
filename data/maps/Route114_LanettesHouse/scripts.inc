Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "LANETTE: Ene! {PLAYER}{KUN}!\p"
	.string "Barkatu dena hankaz gora egotea…\n"
	.string "Ikerketan buru-belarri aritzen\l"
	.string "naizenean, horrela uzten dut guztia…\p"
	.string "A zer lotsa… Mesedez, ez inori\n"
	.string "kontatu, hau emango dizut trukean.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "Eman diezazuket aholku bat POKéMONAK\n"
	.string "Gordetzeko Sistemaren inguruan?\p"
	.string "KUTXAK antolatu behar zenituzke,\n"
	.string bakoitzean zein POKéMON dauden jakiteko.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "LANETTEREN ikerketa oharrak dira.\n"
	.string "KUTXEN inguruko informazioa dago.\p"
	.string "Diseinatu KUTXAK 30 POKéMON edukitzeko.\p"
	.string "ENTRENATZAILE bakoitzak 420 POKéMON\n"
	.string "gorde behar lituzke bere PCAN.\p"
	.string "Irakurtzen jarraitu?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "Marka sistema bat gehitu behar da\n"
	.string "POKéMONAK antolatzea errazagoa izateko.\p"
	.string "KUTXA bakoitzaren hormapapera eta\n"
	.string "izena aldatzeko aukera egongo da\l"
	.string "barruko POKéMONAK pozik egoteko.\p"
	.string "Irakurtzen jarraitu?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "POKéMON bat gordetzean, azkenengoz\n"
	.string "ikusitako KUTXARA bidali behar da.\p"
	.string "KUTXA beteta balego, POKéMONA\n"
	.string "hurrengo KUTXARA bidaliko da.\p"
	.string "Beste era batera, KUTXA bat ikusten\n"
	.string "bada, automatikoki KUTXA horretara\l"
	.string "bidaliko dira POKéMONAK.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER}(e)k koadernoa itxi du.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "Norbaiten e.mail bat dago\n"
	.string "PCAN.\p"
	.string "“… … … … … … …\p"
	.string "“Zure Gordetzeko Sistemak nireak\n"
	.string "baino erraztasun gehiago ditu.\p"
	.string "“Erabiltzaileentzako tresna erabilgarri\n"
	.string "eta dibertigarriak ere baditu.\p"
	.string "“Pozik jartzen naiz garapenean\n"
	.string "parte hartu nuelako.\p"
	.string "“Espero dut Gordetzeko Sistemak\n"
	.string "ikertzen jarraituko duzula.\p"
	.string "“BILL\n"
	.string "… … … … … … … …”$"

