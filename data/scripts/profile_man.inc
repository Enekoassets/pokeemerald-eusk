ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string "Kaixo, ENTRENATZAILE!\n"
	.string "Irribarre ederra duzu, alajaina.\p"
	.string "Zaletasun bat dut: POKéMON\n"
	.string "ENTRENATZAILEEN profilak biltzea.$"

ProfileMan_Text_MayISeeYourProfile:
	.string "Eta, zer iruditzen zaizu?\n"
	.string "Ikusi al dezaket zure profila?$"

ProfileMan_Text_EasyChatExplanation:
	.string "Lau hitz edo esaldi aukeratuta\n"
	.string "egin dezakezu zure profila.\p"
	.string "Entzun, adibide bat emango dizut\n"
	.string "lau testu zati erabilita.\p"
	.string "Lau zati horiek beste edozein\n"
	.string "zatirekin trukatu ditzakezu zure\l"
	.string "profil propioa egiteko.\p"
	.string "Testu zati desberdin asko\n"
	.string "erabili ditzakezu.\p"
	.string "Taldetan banatuta daude, hala nola,\n"
	.string "POKéMONAK, bizi-estiloak edo\l"
	.string "zaletasunak, bilatzeko errazagoak izateko.\p"
	.string "Beraz, lehenengo, aukeratu hitz\n"
	.string "talde bat, aukerak ikusteko.\p"
	.string "Ondoren, nahi duzun testua aukeratu.\p"
	.string "Errepikatu testu zati guztiekin,\n"
	.string "eta zure profil propioa izango duzu.$"

ProfileMan_Text_LetsSeeItThen:
	.string "Bai! Eskerrik asko!\n"
	.string "Ikus dezagun, orduan.$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "Ai, ez, benetan?\p"
	.string "Zu bezalako batek profil bikaina\n"
	.string "izango du, ziur…$"

ProfileMan_Text_NotIntoItRightNow:
	.string "Zer? Ez duzula nahi orain?\p"
	.string "Beno, edozein momentutan itzuli!$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "Kaixo, ENTRENATZAILE!\n"
	.string "Irribarre ederra daukazu.$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string "Ikusi al dezaket zure profil berria?$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "Bai! Eskerrik asko!\p"
	.string "Lehengoa baino are profil hobea\n"
	.string "izango duzula espero dut.$"

ProfileMan_Text_LikeProfileWayItIs:
	.string "Zure profila den bezelakoa izatea nahi duzu.\p"
	.string "Normala iruditzen zait, zure profila\n"
	.string "bikaina da orain dagoen bezala.$"

ProfileMan_Text_FantasticProfile:
	.string "B-Bikaina!\p"
	.string "Zure profila izugarria da!\n"
	.string "Nolakoa zaren adierazten du.\p"
	.string "Profil hau entzungo lukeen edonor\n"
	.string "txundituta geratuko litzateke!\p"
	.string "Eskerrik asko!$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string "Zer?\n"
	.string "Badakizu esaera sekretua!\p"
	.string "Horrek esan nahi du GERTAKARI\n"
	.string "MISTERIOTSUAREN KLUBEKOA zarela!$"
