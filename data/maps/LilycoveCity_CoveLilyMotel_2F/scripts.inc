LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	waitstate
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "JOKO DISEINATZAILEA naiz.\p"
	.string "Ene, zer diozu?\n"
	.string "POKéDEXAREKIN lanean ari zarela?\p"
	.string "Oso zaila da guztia betetzea,\n"
	.string "baina ez galdu itxaropena.\p"
	.string "Betetzea lortzen baduzu, etorri\n"
	.string "erakustera, mesedez.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Uau! Izugarria!\n"
	.string "Bai, guztiz sinesgaitza!\p"
	.string "POKéDEXA guztiz bete duzu!\n"
	.string "Benetan maite dituzu POKéMONAK!\p"
	.string "Harrituta nago!\p"
	.string "Zerbait eman nahi dizut\n"
	.string "zure lorpen ikaragarriagatik!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Ni? Nirekin ari al zara?\n"
	.string "PROGRAMATZAILEA naiz.\p"
	.string "Hemengo MAKINA TXANPONJALEAK\n"
	.string "nolakoak diren jakin nahiko nuke.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "ARTISTA GRAFIKOA naiz! Ez al dira\n"
	.string "interesgarriak HOENNGO POKéMONAK?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "Neska BAINUZALEAK politak dira, ezta?\n"
	.string "BAINUZALE polit baten aurka jardutea…\p"
	.string "Itzela da!\p"
	.string "Eta BIKIAK! Ez al dira politak?\n"
	.string "BIKIEKIN 2 2ren aurka aritzea…\p"
	.string "Uau, izugarri dibertigarria da!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "Itsasoko brisak hunkitu egiten nau.\n"
	.string "Hau bai leku ederra!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "Ez dakizu non eta noiz botako\n"
	.string "dizun erronka norbaitek.\p"
	.string "Horregatik ateratzen naiz beti\n"
	.string "etxetik nire GAME BOY ADVANCEAREKIN.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "TRIKI: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Zer?!\n"
	.string "Ai, barkatu! Zurrungaka ari nintzen!\p"
	.string "POKéMON TXAPELKETEN kontu hau\n"
	.string "ikustera etorri naiz.\p"
	.string "Egia esanda, nahikoa entretenigarria\n"
	.string "dirudi, baina…\p"
	.string "Agian puristaegia naiz, nahiago ditut\n"
	.string "borrokak eta ENTRENATZAILE gogorrak.\p"
	.string "Baina hori nire iritzia besterik ez da.\p"
	.string "{PLAYER}{KUN}, espero dut zur guztia\n"
	.string "gustatuko zaizula: GIMNASIOAK, TXAPELKETAK,\l"
	.string "BORROKA DENDA eta beste dena!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "TRIKI: Esango nuke estrategia ona\n"
	.string "dela TXAPELKETA bat irabazteko.\p"
	.string "TXAPELKETETARAKO estrategiak garatuta,\n"
	.string "ENTRENATZAILE hobea bihurtuko zara.$"

