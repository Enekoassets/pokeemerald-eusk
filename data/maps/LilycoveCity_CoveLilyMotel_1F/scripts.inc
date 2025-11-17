.set LOCALID_OWNER, 1

LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "Hm, gonbidatuak bikoztu dituzte\n"
	.string "POKéMONAK erakartzeko erabiliz?\p"
	.string "Hm, beno, orduan POKéMON bat gure\n"
	.string "ostatuko maskotatzat jarri behar genuke.\p"
	.string "Lortuko ote dut bezero\n"
	.string "gehiago ekartzea ostatura?$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "Ai, barkatu, barkatu!\n"
	.string "Telebista ikusten zentratuegi nengoen!\p"
	.string "AQUA TALDEA hirira etorri zenetik,\n"
	.string "turistak ez dira horrenbeste etortzen.$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "Aizu, kendu hortik!\n"
	.string "Ez dut telebista ikusten!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "Itzela! POKéMON batek norbaiten\n"
	.string "item galdua aurkitu zuela diozu?\p"
	.string "Harrigarria. Halako POKéMON\n"
	.string "argiak izango bagenitu…\p"
	.string "Gure bezeroek galdutako edozer\n"
	.string "berreskuratu ahalko genuke…$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "Ai, barkatu, barkatu!\n"
	.string "Telebista ikusten zentratuegi nengoen!\p"
	.string "Entzun dut norbaitek AQUA TALDEAREN\n"
	.string "GORDELEKUA hankaz gora jarri duela.\p"
	.string "Horri esker, talde handi batek\n"
	.string "erreserba egin du hemen.\p"
	.string "Nola zuen izena taldeak… Em…\n"
	.string "GAME zerbait…$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "Itzela! Etxea zaintzen zegoen POKéMON\n"
	.string "batek lapur bat harrapatu duela?\p"
	.string "Harrigarria. Halako POKéMON\n"
	.string "bat bagenu zaindari bezala…\p"
	.string "Gure bezeroei segurtasun handiagoa\n"
	.string "eskeiniko genieke.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "Ai, barkatu, barkatu!\n"
	.string "Telebista ikusten zentratuegi nengoen.\p"
	.string "Ah, bai. Bezero talde handi bat iritsi\n"
	.string "da duela gutxi.\p"
	.string "GAME FREAK izena erabili dute erreserban,\n"
	.string "suposatzen dut jokoak egiten dituztela.\p"
	.string "Ai ene, beraientzako afaria\n"
	.string "prestatu behar dut!$"

