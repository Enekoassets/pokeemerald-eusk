.set LOCALID_DEVON_EMPLOYEE, 2

RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "HARRI JN. naiz, DEVON\n"
	.string "KORPORAZIOKO PRESIDENTEA.\p"
	.string "Zutaz hitz egin didate!\p"
	.string "Gure langileak salbatu dituzu,\n"
	.string "birritan, gainera!\p"
	.string "Fabore bat eskatu nahi nioke\n"
	.string "zu bezalako pertsona bati.\p"
	.string "Entzun dut PORTUONDOKO ONTZIDIRA\n"
	.string "pakete bat eramaten ari zarela.\p"
	.string "Beno, bidean pasa zintezke\n"
	.string "IHINTZIBAR HERRITIK?\p"
	.string "IHINTZIBARREN dagoen MIKELI\n"
	.string "ESKUTITZ bat eramatea behar dut.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "HARRI JN.: Beno, jakin behar zenuke\n"
	.string "PRESIDENTE bikaina naizela.\p"
	.string "Orduan, ez nizuke fabore hau\n"
	.string "ezeren truke eskatuko, noski.\p"
	.string "Horregatik, tori hau zuretzat!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER}(e)k POKéNAV bat jaso du.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "HARRI JN.: Tresna hori…\p"
	.string "POKéMON NABIGATZAILEA da,\n"
	.string "POKéNAVA, labur esanda.\p"
	.string "Edozein ENTRENATZAILE eta\n"
	.string "abenturarako derrigorrezko tresna.\p"
	.string "HOENN eskualdearen mapa bat du.\p"
	.string "IHINTZIBAR eta PORTUONDO non\n"
	.string "dauden ikusi dezakezu, erraz!\p"
	.string "Porzierto, entzun dut, kriminal horiek,\n"
	.string "MAGMA eta AQUA TALDEAK, uste dut,\l"
	.string "arazoak sortzen ari direla edonon.\p"
	.string "Uste dut deskantsatzea ongi etorriko\n"
	.string "zaizula bidaia jarraitu aurretik.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "HARRI JN.: Beno, orduan, {PLAYER}{KUN},\n"
	.string "kontuz eta adi ibili!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "HARRI JN.: Zugan konfidantza osoa dut!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "HARRI JN.: Nire GUTUNA eman duzu?\n"
	.string "Eskerrik asko, zinez!\p"
	.string "Hau nire esker ona adierazteko da.\n"
	.string "Lagunduko dizu, ENTRENATZAILE.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "HARRI JN.: ESP: BANATZAILEA duen\n"
	.string "POKéMON batek borrokako ESP Puntu\l"
	.string "batzuk jaso behar lituzke.\p"
	.string "ESP. puntuak lortuko ditu, nahiz eta\n"
	.string "ez duen borrokan parte hartu.\p"
	.string "POKéMON ahulak indartzeko tresna\n"
	.string "oso egokia da, nire ustez.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "HARRI JN.: Gaztea naizenetik,\n"
	.string "buru-belarri aritu naiz lanean.\p"
	.string "Ondorioz, ez ditut gaur egungo\n"
	.string "modak eta abar ezagutzen.\p"
	.string "Baina zergatik nahi duzue zuek\n"
	.string "gazteok POKéMON LIGARA iritsi?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "Hau DEVON KORPORAZIOKO\n"
	.string "hirugarren solairua da.\p"
	.string "PRESIDENTEAREN BULEGOA\n"
	.string "solairu honetan dago.\p"
	.string "Beno, ezin dizut nahikoa eskertu\n"
	.string "egin duzun guztia.\p"
	.string "Eta… Aizu, guretzat berreskuratu\n"
	.string "zenituen pieza horiek…\p"
	.string "Posible litzaizuke PORTUONDOKO\n"
	.string "ONTZIDIRA eramatea?\p"
	.string "Beldurgarria litzateke lapur horiek\n"
	.string "berriro agertuko balira.\p"
	.string "Eta… Beno, beraz, egingo zenuke\n"
	.string "hori niri laguntzeko?\p"
	.string "Bai, bikain.\n"
	.string "Itxaron zenezake hemen pixka bat?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Gure PRESIDENTEAK zurekin hitz\n"
	.string "egin nahi luke.\p"
	.string "Etorri nirekin, mesedez.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Pasa hemendik, mesedez.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "PORTUONDOKO ONTZIDIRA bazoaz,\n"
	.string "ABABOR KAPT. ezagutu behar zenuke.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "DEVONEN produktu berriak, BERRIZ BALLA\n"
	.string "eta TXANDA BALLA, asko zabaldu dira\l"
	.string "ENTRENATZAILEEN artean.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "PRESIDENTEAREN arroka eta harri\n"
	.string "bereziz osatutako bilduma da.$"

