Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "Horko BURDIZELAI TUNEL hori…\p"
	.string "hasierean izugarrizko taldea genuen,\n"
	.string "punta-puntako makinekin harria zulatzen.\l"
	.string "Baina geratu egin behar izan genuen.\p"
	.string "Badirudi inguruko POKéMON basatietan\n"
	.string "eragin txarra izango genuela,\l"
	.string "jarraitzen bagenuen.\p"
	.string "Orduan, hemen ezer ez egiten\n"
	.string "geratu gaitezke, soilik.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "Gizon bat BERDEZELAIRA tunela\n"
	.string "zulatzen ari da, bakar-bakarrik.\l"
	.string "Pasatzeko premia larrian dago.\p"
	.string "Esaten du makinak erabili gabe, pixkanaka\n"
	.string "zuloa egiten badu, ez dituela POKéMONAK\l"
	.string "eragotziko, eta ez diola inguru\l"
	.string "naturalari kalterik egingo.\p"
	.string "Ez dakit oraindik iritsi ote den.$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "Tunela erabili gabe BERDEZELAIRA\n"
	.string "iristeko, itsasoa igaro behar zenuke\l"
	.string "IHINTZIBARRERA, gero PORTUONDORA\l"
	.string "nabigatu, eta azkenik MALBADI igaro.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "Entzun al duzu? BERDEZELAIKO\n"
	.string "TUNELA bukatzea lortu dute!\p"
	.string "Batzuetan, gogo handiz pentsatuz,\n"
	.string "ametsak egia bihurtzen dira.$"

