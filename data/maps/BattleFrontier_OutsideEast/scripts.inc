.set LOCALID_SUDOWOODO, 14

BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "Hau BORROKA DORREA da!\n"
	.string "Irabazi behin eta berriro\l"
	.string "ENTRENATZAILE guztiei!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "Hau BORROKA JAUREGIA da!\n"
	.string "Egon adi POKéMON borrokei!$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "Hau BORROKA ARENA da!\n"
	.string "Elkar daitezela talde indartsuenak!$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "Hau BORROKA PIRAMIDEA da!\n"
	.string "Egin aurrera Bilaketa Borrokan!$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "BORROKA FRONTEKO ERREKORREN ARETOA\n"
	.string "Ezarri hemen errekor berriak!$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "BORROKA PUNTUEN TRUKE ZERBITZUA\n"
	.string "Trukatu zure Borroka Puntuak!$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "Uau!\n"
	.string "Erraldoia da!\p"
	.string "BORROKA DORREAK berezia dirudi.\n"
	.string "Desberdina da besteengandik.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "Nire helburu handia BORROKA FRONTEA\n"
	.string "eta POKéMON LIGA, biak garaitzea\l"
	.string "da.\p"
	.string "Nire ametsa egi bihurtzen bada…\p"
	.string "Nik… Alboko etxeko MIMIRI nire\n"
	.string "laguna izateko eskatuko diot!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "BORROKA PIRAMIDEA gogorregia da!\n"
	.string "Ezin naiz goraino iritsi!\p"
	.string "Aukerarik ez dudanez, agian\n"
	.string "kanpoko aldetik eskalatuko dut…$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "Iluntasunean onena naiz…\n"
	.string "Bai… Zertarako balio dut orduan?\l"
	.string "BORROKA PIRAMIDERAKO soilik…\p"
	.string "Zer iruditzen zaizu iluntasunean\n"
	.string "etsipen osoz bila aritzea?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "Ez dut lorik egin aste osoan, baina\n"
	.string "talderik bikainena osatu dut!\p"
	.string "Ezinezkoa da nik galtzea orain, serio.\n"
	.string "BORROKA ARENARA noa oraintxe!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "TRIKIK ekarri al zaitu hona?\n"
	.string "Zer du tipo horrek?\p"
	.string "Badirudi ENTRENATZAILE bikainak\n"
	.string "aurkitzen abila dela, baina…\p"
	.string "Ez dut inoiz ikusi bera borrokan.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "ZIGG!\n"
	.string "Zugan sinisten dut, lagun!\p"
	.string "Irabazten baduzu, nire ZIGG txikiari\n"
	.string "bere janari gustokoena egingo diot!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "ZIGZAGOONEK galdu itxura du…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "Jendeak beti kezkatuta nagoela dio,\n"
	.string "baina ezin dut ezer egin.\p"
	.string "Zure kapela okerra dago!\n"
	.string "Ai ene, zaborra dago lurrean!\l"
	.string "Ups, ia afaltzeko ordua da eta!\p"
	.string "Ez dakit BORROKA JAUREGIAN soilik\n"
	.string "begira egoteko balio dudanik…$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "Akaso ez dut itxura harrigarririk,\n"
	.string "baina, behin GIMNASIOKO LIDER bat\p"
	.string "garaitu nuen. Auskalo, agian berriz\n"
	.string "saiatu behar nuke.$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "Azkar ibiltzen naiz BIZIKLETAN,\n"
	.string "eta hala egiten dut borrokan ere.\p"
	.string "Begiak kliskatu aurretik irabazten\n"
	.string "ditut nik borrokak!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "Nire aitatxo baino hobea\n"
	.string "naiz POKéMONEKIN.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "Aurrera, nire maite txikia!\n"
	.string "Irabazi Aitatxorengatik!\p"
	.string "Zure ama bezalakoa zara,\n"
	.string "guztiak garaituko dituzu!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "Ez da erraza izan honaino iristea,\n"
	.string "baina BORROKA ARENAN neska polit\l"
	.string "bat dagoela esan didate.\p"
	.string "Ez dut bera aurkitu, baina badakizu\n"
	.string "zer aurkitu dudan bere ordez?\p"
	.string "Arte martzialetan aritzen den talde\n"
	.string "izerditsu eta kirastun bat!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "Batzuetan garrantzitsu itxura duen\n"
	.string "gizon zahar bat sartzen da hemen.\p"
	.string "POKéMON izugarriak dauzka.\n"
	.string "Oso jatorra dirudi, ordea.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "Ba al dakizu?\n"
	.string "BORROKA PIRAMIDEKO elezaharra?\p"
	.string "Bere bruuaz ziur dagoen ENTRENATZAILE\n"
	.string "bat urrezko tontorraren bila etortzen\l"
	.string "denean, gizon indartsuena agertuko da.\p"
	.string "Ezagutzen al duzu elezaharra?\n"
	.string "Beno, noski ezetz!\l"
	.string "Asmatu berri dut eta!\p"
	.string "Zer esan nahi duen?\n"
	.string "Hori ezin dizut esan, lagun!$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "Ene! Ai ene!\n"
	.string "Inoiz ez naiz galdu bizi osoan!\p"
	.string "Baina galdu eta sekulako egurra\n"
	.string "jaso dut!\p"
	.string "Eta ondoren talenturik ez dudala\n"
	.string "esan didate?! Ene!$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "Tipo hau ENTRENATZAILE izugarri baten\n"
	.string "aurka aritu behar izan da BORROKA\l"
	.string "DORREKO erronka.\p"
	.string "Eta begira orain…\p"
	.string "Kontuz ibili behar zara BORROKA\n"
	.string "DORRERA joatea erabakitzen baduzu.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "Bai!\n"
	.string "Azkenean badut nahikoa Borroka Puntu!\p"
	.string "Beste PANPINA erraldoi baten truke\n"
	.string "aldatuko ditut!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "Ah, bai, ongi!\n"
	.string "Hau da ERREKORREN ARETOA!\p"
	.string "Historian nire izena hemen\n"
	.string "grabatzea nahi dut, betirako\l"
	.string "oroitua izan nadin.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "Nire alboan bazaitut, edozer lor dezaket.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "Ene, maitea, bikaina zara!\p"
	.string "Ene, ezin dut gehiago itxaron!\p"
	.string "Goazen MULTI BORROKA ARETO\n"
	.string "batera oraintxe bertan!\p"
	.string "BORROKA ARETOAN batera sartzen bagara,\n"
	.string "gure maitasunaren indarrak edozein\l"
	.string "garaitzen lagunduko dugu.\p"
	.string "Gure parean jartzen den edonor\n"
	.string "dominoen gisan eroriko da!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "BORROKA FRONTEA ez da soilik\n"
	.string "ENTRENATZAILE indartsuentzako.\p"
	.string "Trebetasun ugaritako jendea\n"
	.string "gonbidatzen dute, dirudienez.\p"
	.string "TRIKI izeneko gizon hori…\p"
	.string "Agian helburu handiago bat lortzeko\n"
	.string "eraiki du toki hau…$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "Barkatu, gazte.\n"
	.string "Ikusmen ona al duzu?\p"
	.string "Zuhaitz arraro bat dago hurbil, eta\n"
	.string "nire begi nekatuek mugitzen ikusi dute.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "Barkatu, gazte.\n"
	.string "Memoria ona al duzu?\p"
	.string "Hemen lehen zuhaitz bat zegoela\n"
	.string "uste dut.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "Nik…\n"
	.string "Ikusi egin dut!\p"
	.string "Buztan luzea zaukan POKéMON bat\n"
	.string "zegoen hementxe lehenago!\p"
	.string "Arroka baten azpian ezkutatuta\n"
	.string "zegoen, niri begira!$"
