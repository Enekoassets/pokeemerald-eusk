BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "Kar-kar-kar!\n"
	.string "POKéMONEK pentsatzen dutena irakur\p"
	.string "dezaket! Mesedez!\n"
	.string "Ikus dezaket zure POKéMONA?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "Buu!\n"
	.string "Ez dakizu ezer!$"

BattleFrontier_Lounge5_Text_NatureGirlHardy::
	.string "Hmhm…\p"
	.string "Honi borrokatzea gustatzen zaio!\n"
	.string "Min asko badu ere borrokan\l"
	.string "jarraituko du!$"

BattleFrontier_Lounge5_Text_NatureGirlLonely::
	.string "Hmhm…\p"
	.string "Honi ezkutuan ibiltzea gustatzen zaio!\n"
	.string "Baina nahikoa min hartzen badu,\l"
	.string "bueltan egingo du eraso!$"

BattleFrontier_Lounge5_Text_NatureGirlBrave::
	.string "Hmhm…\p"
	.string "Honi borrokatzea gustatzen zaio!\n"
	.string "Baina nahikoa min hartzen badu,\l"
	.string "bere buruaz kezkatuko da!$"

BattleFrontier_Lounge5_Text_NatureGirlAdamant::
	.string "Hmhm…\p"
	.string "Honi borrokatzea gustatzen zaio!\n"
	.string "Min asko badu ere borrokan\l"
	.string "jarraituko du!$"

BattleFrontier_Lounge5_Text_NatureGirlNaughty::
	.string "Hmhm…\p"
	.string "Honek bere burua zaintzen duela dio!\n"
	.string "Baina nahikoa min hartzen badu,\l"
	.string "bueltan egingo du eraso!$"

BattleFrontier_Lounge5_Text_NatureGirlBold::
	.string "Hmhm…\p"
	.string "Honi ezkutuan ibiltzea gustatzen zaio!\n"
	.string "Baina nahikoa min hartzen badu,\l"
	.string "bere buruaz kezkatuko da!$"

BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky::
	.string "Hmhm…\p"
	.string "Honi borrokatzea gustatzen zaio!\n"
	.string "Min asko badu ere borrokan\l"
	.string "jarraituko du!$"

BattleFrontier_Lounge5_Text_NatureGirlRelaxed::
	.string "Hmhm…\p"
	.string "Honi ezkutuan ibiltzea gustatzen zaio!\n"
	.string "Baina nahikoa min hartzen badu,\l"
	.string "bueltan egingo du eraso!$"

BattleFrontier_Lounge5_Text_NatureGirlImpish::
	.string "Hmhm…\p"
	.string "Honi borrokatzea gustatzen zaio!\n"
	.string "Baina nahikoa min hartzen badu,\l"
	.string "bere buruaz kezkatuko da!$"

BattleFrontier_Lounge5_Text_NatureGirlLax::
	.string "Hmhm…\p"
	.string "Honi ezkutuan ibiltzea gustatzen zaio!\n"
	.string "Ezkutuan ibiliko da min\l"
	.string "handia hartu badu ere!$"

BattleFrontier_Lounge5_Text_NatureGirlTimid::
	.string "Hmhm…\p"
	.string "Honi borrokatzea gustatzen zaio!\n"
	.string "Baina nahikoa min hartzen badu,\l"
	.string "ezkutuan ibiltzen hasiko da!$"

BattleFrontier_Lounge5_Text_NatureGirlHasty::
	.string "Hmhm…\p"
	.string "Honi borrokatzea gustatzen zaio!\n"
	.string "Min asko badu ere borrokan\l"
	.string "jarraituko du!$"

BattleFrontier_Lounge5_Text_NatureGirlSerious::
	.string "Hmhm…\p"
	.string "Honi ezkutuan ibiltzea gustatzen zaio!\n"
	.string "Ezkutuan ibiliko da min\l"
	.string "handia hartu badu ere!$"

BattleFrontier_Lounge5_Text_NatureGirlJolly::
	.string "Hmhm…\p"
	.string "Honi ezkutuan ibiltzea gustatzen zaio!\n"
	.string "Baina nahikoa min hartzen badu,\l"
	.string "bere buruaz kezkatuko da!$"

BattleFrontier_Lounge5_Text_NatureGirlModest::
	.string "Hmhm…\p"
	.string "Honek bere burua zaintzen duela dio!\n"
	.string "Bere burua zaintzen omen du\l"
	.string "mina izan edo ez izan, berdin dio!$"

BattleFrontier_Lounge5_Text_NatureGirlMild::
	.string "Hmhm…\p"
	.string "Honek bere burua zaintzen duela dio!\n"
	.string "Baina nahikoa min hartzen badu,\l"
	.string "ezkutuan ibiltzen hasiko da!$"

BattleFrontier_Lounge5_Text_NatureGirlBashful::
	.string "Hmhm…\p"
	.string "Honek bere burua zaintzen duela dio!\n"
	.string "Bere burua zainduko omen du\l"
	.string "min handia baldin badu ere!$"

BattleFrontier_Lounge5_Text_NatureGirlRash::
	.string "Hmhm…\p"
	.string "Honi ezkutuan ibiltzea gustatzen zaio!\n"
	.string "Ezkutuan ibiliko da min\l"
	.string "handia hartu badu ere!$"

BattleFrontier_Lounge5_Text_NatureGirlCalm::
	.string "Hmhm…\p"
	.string "Honek bere burua zaintzen duela dio!\n"
	.string "Bere burua zainduko omen du\l"
	.string "min handia baldin badu ere!$"

BattleFrontier_Lounge5_Text_NatureGirlGentle::
	.string "Hmhm…\p"
	.string "Honek bere burua zaintzen duela dio!\n"
	.string "Baina nahikoa min hartzen badu,\l"
	.string "bueltan egingo du eraso!$"

BattleFrontier_Lounge5_Text_NatureGirlSassy::
	.string "Hmhm…\p"
	.string "Honi borrokatzea gustatzen zaio!\n"
	.string "Baina nahikoa min hartzen badu,\l"
	.string "ezkutuan ibiltzen hasiko da!$"

BattleFrontier_Lounge5_Text_NatureGirlCareful::
	.string "Hmhm…\p"
	.string "Honek bere burua zaintzen duela dio!\n"
	.string "Baina nahikoa min hartzen badu,\l"
	.string "ezkutuan ibiltzen hasiko da!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "Hau bai xelebrea! ARRAUTZAK lo daude!\n"
	.string "Ezin dut berarekin hitz egin!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "Hau bai ederra!\n"
	.string "Andereño txiki honek POKéMONAK\l"
	.string "uler ditzakeela dio!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "Neska txiki hau zerbait oso sakona\n"
	.string "kontatzen ari dela uste dut.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "Zerbait dakit!\p"
	.string "Neska txiki hori askotan ibiltzen da\n"
	.string "etxe gorrian jolasean!$"

