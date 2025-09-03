VerdanturfTown_FriendshipRatersHouse_MapScripts::
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
	case FRIENDSHIP_1_TO_49, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
	case FRIENDSHIP_50_TO_99, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
	case FRIENDSHIP_100_TO_149, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
	case FRIENDSHIP_150_TO_199, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
	case FRIENDSHIP_200_TO_254, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
	case FRIENDSHIP_MAX, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou:
	.string "Utzi zure POKéMONAK ikusten.\n"
	.string "Zenbat atsegin zaituen aztertuko dut.\p"
	.string "Ene.\n"
	.string "Zure POKéMONAK…$"

VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou:
	.string "Izugarri maite zaitu.\n"
	.string "Ezin zaitu gehiago maite.\l"
	.string "Pozik jarri naiz bera ikusita soilik.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy:
	.string "Oso pozik dirudi.\n"
	.string "Oso atsegin zaitu, dudarik gabe.$"

VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot:
	.string "Nahikoa maite zaitu.\n"
	.string "Haurtxo bat bezala zaintzea nahi du.$"

VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou:
	.string "Zugana ohitzen ari dela dio.\n"
	.string "Zugan sinisten duela dirudi.$"

VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou:
	.string "Ez dagoela zugana oso ohituta dio.\n"
	.string "Ez zaitu ez maite ez gorroto.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryWary:
	.string "Kontuz ibiltzeko ohitura du.\n"
	.string "Gaiztakeria beldugarria du begietan.\l"
	.string "Ez zaitu oso gogoko.$"

VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou:
	.string "Hau ez da esateko erraza…\p"
	.string "Zure POKéMONAK gorroto zaitu.\n"
	.string "Ez al zaitu horrek deseroso sentiarazten?$"

VerdanturfTown_FriendshipRatersHouse_Text_Pikachu:
	.string "PIKACHU: Pika pika!$"

