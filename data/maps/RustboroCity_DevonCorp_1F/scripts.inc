.set LOCALID_STAIR_GUARD, 2

RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Kaixo eta ongi etorri DEVON\n"
	.string "KORPORAZIORA.\p"
	.string "Zure bizitza hobetzen duten item\n"
	.string "eta botikak produzitzen ditugu.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Gure ikerlari bati pakete oso\n"
	.string "garrantzitsu bat lapurtu diote.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Aizu, KORRIKAKO ZAPATILA horiek!\n"
	.string "Gure produktuetako bat dira!\p"
	.string "Pozik jartzen naiz norbait guk\n"
	.string "egindako zerbaitekin ikusterakoan.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Lapurtutako pakete hori…\p"
	.string "Beno, ziru garrantzitsua dela, baina\n"
	.string "ez da inork erabili dezaken ezer.\p"
	.string "Nire ustez, lapur hori ez da\n"
	.string "bereziki argia.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "Badirudi lapurtutako DEVON PIEZAK\n"
	.string "berreskuratu dituztela.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Barkatu, baimendutako pertsonak\n"
	.string "soilik sar daitezke hemen.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "Benetan da ergelkeria.\n"
	.string "Nola lapurtu digute?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Kaixo!\n"
	.string "Hemen beti zara ongi etorria!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "Arroka eta metal zatiak daude\n"
	.string "kristalezko kutxan.\p"
	.string "Zerbait idatzita dago gainean\n"
	.string "duen panelean…\p"
	.string "“DEVON KORPORAZIOA harrobietatik\n"
	.string "harriak ateraz hasi zen.\p"
	.string "“Hondarra banatuz burdina ere\n"
	.string "produzitzen zuen hasieran.\p"
	.string "“Material gordinak produzituz, hasiera\n"
	.string "xume horrekin, garatu zen DEVON.\p"
	.string "“DEVONEK orain produktu industrial\n"
	.string "eskaintza zabala produzitzen du.”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "Kristalezko kutxa prototipoz eta\n"
	.string "probako produktuz beteta dago.\p"
	.string "Panel bat dago deskribapen batekin…\p"
	.string "“Produktu industrialez gain, DEVONEK\n"
	.string "botikak eta bestelakoak produzitzen\l"
	.string "ditu pertsonen bizitzak hobetzeko.\p"
	.string "“Duela gutxi, DEVON ENTRENATZAILEENTZAKO\n"
	.string "tresnak egiten hasi da, POKé BALLAK\l"
	.string "eta POKéNAV sistemak, esaterako.”$"

