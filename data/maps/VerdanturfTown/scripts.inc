.set LOCALID_TWIN, 2

VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "Aitak esan zidan.\p"
	.string "Tunel hau POKéMON beldurtiz\n"
	.string "beteta dago.\p"
	.string "Zarata handiek beldurtzen dituzte\n"
	.string "eta sekulako zalaparta egiten dut.\p"
	.string "Horregatik geratu behar izan zuten\n"
	.string "tunela egiteko proiektua.\p"
	.string "Baina tipo bat dago. Tunela berak\n"
	.string "bakarrik zulatu nahi du!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "Gizon batek maite zuen emakumeagatik\n"
	.string "zulatu zuen tunela.\p"
	.string "Ez dut ondo ulertzen, baina beno, aizu!$"

VerdanturfTown_Text_AirCleanHere:
	.string "Haizearen norabidearengatik, errauts\n"
	.string "bolkanikoak ez datoz hona inoiz.\p"
	.string "Airea garbia eta gozoa da hemen.\n"
	.string "Hemen bizitzea oso ona izango da\l"
	.string "pertsona gaixo eta ahulentzat.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "Nire POKéMONAK eta ni, jarraian borroka\n"
	.string "pila bat irabazten aritu gara.\p"
	.string "Beraz, BORROKA DENDAN izena ematea\n"
	.string "erabaki genuen.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "Ikusten duzu POKéMON DENDAREN\n"
	.string "alboko kobazulo hori?\p"
	.string "Tipo bat dago bertan, haitzak hautsi\n"
	.string "nahi dituena, beste aldetik atera\l"
	.string "ahal izateko.\p"
	.string "Izugarria litzateke lortuko balu…\n"
	.string "Errazagoa litzateke BURDINTZA bisitatzea.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "POKéMON DENDAREN alboko kobazuloa\n"
	.string "beste aldera joateko tunela da orain.\p"
	.string "Itzela da, orain errazagoa da DEVONEN\n"
	.string "produktuak erostera joatea BURDINTZARA.$"

VerdanturfTown_Text_TownSign:
	.string "BERDEZELAI HERRIA\p"
	.string "“Haizeak astindutako zelaiak eta\n"
	.string "belarraren usain gozoa.”$"

VerdanturfTown_Text_WandasHouse:
	.string "KLARAREN ETXEA$"

VerdanturfTown_Text_BattleTentSign:
	.string "BERDEZELAIKO BORROKA DENDA\n"
	.string "“Gozatu ezazu borrokak ikusita!”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "BURDIZELAI TUNELA\n"
	.string "“BURDINTZA eta BERDEZELAI lotuz\p"
	.string "“Tunela egiteko proiektua bertan\n"
	.string "behera gelditu da.”$"

