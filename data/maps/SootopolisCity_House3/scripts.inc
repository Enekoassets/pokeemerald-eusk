SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "POKéMON ENTRENATZAILEA zara, ezta?\p"
	.string "ARREZIPOLISEKO XALANTEK fan ugari ditu.\n"
	.string "Bere ikasle UREDERREK baino gehiago!\p"
	.string "Zuk ba al duzu fanik?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "Oh, orduan indartsua izango zara.$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "Ai ene…\n"
	.string "Pixka bat bakartia dirudi.\p"
	.string "Pixka bat gehiago saiatu, ea\n"
	.string "fanen bat lortzen duzun.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "HOENN kanpotik ere etortzen\n"
	.string "dira fan sutsuak.\p"
	.string "Izugarria izan zen UR-LILIKO\n"
	.string "ENTRENATZAILE FAN KLUBERA joatea.$"

