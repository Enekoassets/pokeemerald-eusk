MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Beno, beno, zer dugu hemen?\n"
	.string "Bezero energetiko eta alaia!\p"
	.string "Ni? ANAKLETO dei diezadakezu.\n"
	.string "Bizikleta dendaren jabea naiz.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "ANAKLETO: Zure KORRIKAKO ZAPATILAK…\n"
	.string "Oso zikinak daude.\p"
	.string "Urrutitik etorri al zara?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "ANAKLETO: Benetan?\p"
	.string "Orduan, ez duzu nire bizikletarik\n"
	.string "behar ezertarako.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "ANAKLETO: Hm, hm… … … … …\p"
	.string "ERROTXIKITIK honaino oinez\n"
	.string "etorri zarela diozu?\p"
	.string "Ene Jainkoa!\n"
	.string "Hori izugarri urruti dago eta!\p"
	.string "Nire BIZIKLETETAKO bat izango bazenu,\n"
	.string "haizearen laztana sentituz erraz\l"
	.string "joango zinateke edonora!\p"
	.string "Badakizu zer?\n"
	.string "BIZIKLETA bat emango dizut!\p"
	.string "Ene, itxaron segundu bat!\p"
	.string "Bi BIZIKLETA mota daudela\n"
	.string "kontatzea ahaztu zait!\p"
	.string "LASTERKETAKO BIZIKLETA eta\n"
	.string "BIZIKLETA AKROBATIKOA dira!\p"
	.string "LASTERKETAKO BIZIKLETA haizea gorputzean\n"
	.string "sentitu nahi duten txirrindularientzat da!\p"
	.string "Eta BIZIKLETA AKROBATIKOA gauza\n"
	.string "teknikoagoak egin nahi dituztenentzat!\p"
	.string "Benetan jatorra naiz, beraz, bietatik\n"
	.string "edozein aukeratu dezakezu!\p"
	.string "Zein hartuko duzu?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER}(e)k LASTERKETAKO BIZIKLETA hartu du.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER}(e)k BIZIKLETA AKROBATIKOA hartu du.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "ANAKLETO: BIZIKLETA aldatzeko gogoa\n"
	.string "baldin baduzu, etorri niregana!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "ANAKLETO: Zer? BIZIKLETA aldatzeko\n"
	.string "gogoz zabiltzala?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "ANAKLETO: Noski, ez dago arazorik!\n"
	.string "BIZIKLETA aldatuko dizut!$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER}(e)k LASTERKETAKO BIZIKLETA\n"
	.string "BIZIKLETA AKROBATIKOAREN truke hartu du.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER}(e)k BIZIKLETA AKROBATIKOA\n"
	.string "LASTERKETAKO BIZIKLETAREN truke hartu du.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "ANAKLETO: Ongi, ongi!\n"
	.string "Pozten nau gustatu izanak!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "Zer? Zer gertatu zaio eman\n"
	.string "nizun BIZIKLETARI?\p"
	.string "Ulertzen dut, PCAN gorde duzu.\p"
	.string "Beno, ba atera PCTIK, eta\n"
	.string "gustura trukatuko dizut!\p"
	.string "Eduki dezazula haizea beti\n"
	.string "alde zure abenturan!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "Hemen lanean ari naizenez, BIZIKLETEN\n"
	.string "inguruan ikasten ari naiz.\p"
	.string "Baina BIZIKLETAN nola ibili ikasi\n"
	.string "nahi baduzu, pare bat eskuliburu\l"
	.string "ditugu hor atzean.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "LASTERKETAKO BIZIKLETAREN eskuliburua da.\p"
	.string "Zein orrialde irakurri nahi duzu?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "BIZIKLETA + Kontrol Gurutzearen\n"
	.string "norabidean mugitzen da.\p"
	.string "Behin hasita, abiadura hartuko du.\p"
	.string "Gelditzeko, askatu + Kontrol Gurutzea.\n"
	.string "BIZIKLETA pixkanak geratuko da.\p"
	.string "Beste orrialde bat irakurri nahi al duzu?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "LASTERKETAKO BIZIKLETA oso azkarra\n"
	.string "da, baina ezin da azkar gelditu.\p"
	.string "Ez da oso erraza bihurguneetan\n"
	.string "erabiltzea.\p"
	.string "Askatu + Kontrol Gurutzea bihurgunea\n"
	.string "baino pixka bat lehenago, moteltzeko.\p"
	.string "Beste orrialde bat irakurri nahi al duzu?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "Hondarrezko aldapa txikiak daude\n"
	.string "HOENN eskualde osoan zehar.\p"
	.string "Hondar finaren ondorioz,\n"
	.string "ezin dira normal igo.\p"
	.string "Baina LASTERKETAKO BIZIKLETAREKIN,\n"
	.string "ziztuan igo ditzakezu.\p"
	.string "Beste orrialde bat irakurri nahi al duzu?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "BIZIKLETA AKROBATIKOAREN eskuliburua da.\p"
	.string "Zein orrialde irakurri nahi duzu?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Gainean zaudela B Botoia sakatu,\n"
	.string "eta aurreko gurpila altxatuko duzu.\p"
	.string "Norabidea aldatu dezakezu gurpila\n"
	.string "goian duzula, + Kontrol Gurutzearekin.\p"
	.string "Hondi zaldiko maldikoa deritzo.\p"
	.string "Beste orrialde bat irakurri nahi al duzu?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "B Botoia sakatuta edukita,\n"
	.string "BIZIKLETAREKIN jauziak eman ditzakezu.\p"
	.string "Honi untxi jauzia deitzen zaio.\p"
	.string "Saltoka ere gidatu dezakezu bizikleta.\p"
	.string "Beste orrialde bat irakurri nahi al duzu?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Sakatu B Botoia eta + Kontrol\n"
	.string "Gurutzea batera, jauzi egiteko.\p"
	.string "Sakatu + Kontrol Gurutzea alde batera\n"
	.string "alde horretaraka salto egiteko.\p"
	.string "Sakatu azteraka, BIZIKLETAK salto\n"
	.string "egin bitartean norabidea aldatzeko.\p"
	.string "Beste orrialde bat irakurri nahi al duzu?$"

