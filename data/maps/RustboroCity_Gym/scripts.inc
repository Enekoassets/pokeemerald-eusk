RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "Ei, zer moduz?\p"
	.string "Entzun, lagun!\n"
	.string "TXAPELDUNA bihurtu nahi al duzu?\p"
	.string "Ez naiz ENTRENATZAILEA, ez, baina\n"
	.string "irabazteko aholkuak emango dizkizut.\p"
	.string "Ongi, orduan! Batera saiatuko gara\n"
	.string "POKéMON TXAPELKETA irabazten!\p"
	.string "ENTRENATZAILE moduan, zure lana\n"
	.string "GIMNASIOKO DOMINAK lortzea da, ez?\p"
	.string "Baina LIDERRAK ez dira edonor!\p"
	.string "Eta horretan lagunduko dizut!\n"
	.string "Aholku bikainak emango dizkizut!\p"
	.string "HAITZIBER, GIMNASIOKO LIDERRAK,\n"
	.string "ARROKA motako POKéMONAK ditu.\p"
	.string "ARROKA mota oso gogorra da, baina\n"
	.string "baina UR eta LANDARE motako\l"
	.string "erasoak ezin ditu jasan.\p"
	.string "GIMNASIOKO LIDERRA garaitzen baduzu,\n"
	.string "etorri niregana ostean.\p"
	.string "Ea ba, animo!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Uau! A zer nolako garaipena!\n"
	.string "Nire animoek funtzionatu dute!\p"
	.string "Itzel! Begiratu orain zure\n"
	.string "ENTRENATZAILE TXARTELA.\p"
	.string "Lortutako HARRI DOMINA bertan\n"
	.string "grabatuta egongo da.\p"
	.string "Beste era batera esanda…\p"
	.string "TXAPELDUN bihurtzeko bidean\n"
	.string "lehen pausoa eman berri duzu!\p"
	.string "Izugarri ondo sentituko zara, ez?$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Ez pentsa GIMNASIOKO ARERIOOK ahulak\n"
	.string "garenik! GUre indarra erakutsiko dizut!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Onegia zara niretzat…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Ez duzu ARROKA motaren botere\n"
	.string "beldurgarria oraindik pairatu!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Nirekin ezin baduzu, are\n"
	.string "gutxiago HAITZIBERREKIN!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Uau! ZUk bai zuk potentziala!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "HAITZIBER ni bainoa nahikoa\n"
	.string "indartsuagoa da.\p"
	.string "Adi egon beharko duzu!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Herri erdian gaude orain,\n"
	.string "eta zer?\p"
	.string "Nire ARROKA POKéMONEK lekua\n"
	.string "behar dute borrokarako!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Ai ene, ai ene!\n"
	.string "Lehiakide indartsua zara, gero!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Gure LIDERRA benetan izugarria da.\p"
	.string "Azkarra eta bizia izan behar duzu\n"
	.string "ARROKA mota horren gazte aukeratzeko.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Kaixo, HAITZIBER naiz, BURDINTZAKO\n"
	.string "POKéMON GIMNASIOKO LIDERRA.\p"
	.string "LIDER bihurtu nintzen, POKéMON\n"
	.string "ENTRENATZAILEEN ESKOLAN\l"
	.string "ikasitakoa martxan jartzeko.\p"
	.string "Erakoutsiko zenidake nola, eta zein\n"
	.string "POKéMONEKIN egiten duzun borroka?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Beno…\n"
	.string "Galdu egin dut…\p"
	.string "Badirudi asko daukadala ikasteko\n"
	.string "oraindik…\p"
	.string "Ulertzen dut.\p"
	.string "POKéMON LIGAKO arauek esaten dute\n"
	.string "ENTRENATZAILEEK honakoa jaso\l"
	.string "behar dutela LIDERRA garaitzean.\p"
	.string "Onartu mesedez POKéMON LIGAKO\n"
	.string "HARRI DOMINA ofiziala.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER}(e)k HARRI DOMINA jaso\n"
	.string "du HAITZIBERRENGANDIK.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "HARRI DOMINAK zure POKéMONEN\n"
	.string "ERASOA handitzen du.\p"
	.string "gainera, borrokatik kanpo EBAKIA\n"
	.string "EMa erabiltzen uzten die.\p"
	.string "Hartu hau ere zuretzat, mesedez.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "MAKINA TEKNIKO horrek, MT39ak,\n"
	.string "ARROKA HOBIA dauka grabatuta.\p"
	.string "Ez du mina egiten soilik, arrokak\n"
	.string "botata, ABIADURA ere jaisten du.\p"
	.string "MT bat erabiltzen baduzu, une horretan\n"
	.string "eraso bat erakusten dio POKéMONARI.\p"
	.string "Gogoratu, MT bat behin bakarrik\n"
	.string "erabili daiteke, beraz, ondo pentsatu.$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Horren idnartsua izanik, erronka bota\n"
	.string "behar zenieke beste LIDER batzuei.\p"
	.string "ENTRENATZAILE askorekin borrokatuz,\n"
	.string "asko ikasi behar zenuke.$"

RustboroCity_Gym_Text_GymStatue:
	.string "BURDINTZA HIRIKO POKéMON GIMNASIOA$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "BURDINTZA HIRIKO POKéMON GIMNASIOA\p"
	.string "HAITZIBERREK ZIURTATUTAKO ENTRENATZAILEAK:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Bip!\p"
	.string "HAITZIBER: Kaixo, {PLAYER}?\n"
	.string "HAITZIBER naiz, BURDINTZA HIRIKOA.\p"
	.string "MARTZIALEK esan dit abiadura\n"
	.string "bizian ari zarela ENTRENATZAILE\l"
	.string "mailak igo eta igo.\p"
	.string "Beno, ez dut pentsatu nahi ezin\n"
	.string "zaitudala garaitu.\p"
	.string "Benetan, nire GIMNASIOA berregingo\n"
	.string "dut, zuk berriz erronka botatzeko.\p"
	.string "Espero dut zuk ere nik bezainbeste\n"
	.string "irrika izango duzula horretarako!\p"
	.string "… … … … … …\n"
	.string "… … … … … Klik!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "HAITZIBER GIMNASIOKO LIDERRA\n"
	.string "erregistratu duzu POKéNAVEAN.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "HAITZIBER: Pozten naiz zu berriz ikusita.\n"
	.string "HAITZIBER naiz, hemengo LIDERRA.\p"
	.string "Ziur nago borroka asko egin dugula\n"
	.string "biok, azkenengoz hemen izan zinenetik.\p"
	.string "Gu bion hobekuntza ikusi nahi nuke.\n"
	.string "Borrokatu dezagun!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Ene…\n"
	.string "Berriro galdu dut…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "HAITZIBER: Oraindik asko dut ikasteko\n"
	.string "POKéMON borroken inguruan.\p"
	.string "Hori jakiteak nire borrokarako\n"
	.string "grina are gehiago pizten du!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "HAITZIBER: Pozten naiz zu berriz ikusita.\n"
	.string "HAITZIBER naiz, hemengo LIDERRA.\p"
	.string "Ziur nago borroka asko egin dugula\n"
	.string "biok, azkenengoz hemen izan zinenetik.\p"
	.string "Gu bion hobekuntza ikusi nahi nuke\n"
	.string "azkenengo…\p"
	.string "Ai, ez…\n"
	.string "POKéMON bakarra daukazu aldean?\p"
	.string "Mesedez, itzuli gutxienez beste\n"
	.string "POKéMON batekin.$"
