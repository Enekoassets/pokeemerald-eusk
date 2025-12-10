Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "Zer diozu?\n"
	.string "Zertan ari naizen?\p"
	.string "Niretzako gela bat egin nahi dut\n"
	.string "hemen, POKéMON eraso batekin.\p"
	.string "Badakit! MT hau emango dizut.\n"
	.string "Zure gela egiteko erabiliko al duzu?$"

Route111_Text_ExplainSecretPower:
	.string "Aurkitu aihen batzuk dituen\n"
	.string "zuhaitz handiren bat.\p"
	.string "Erabili BOTERE EZKUTUA zuhaitzaren aurrean.\n"
	.string "Aihen batzuk askatu egingo dira, eta\l"
	.string "zuhaitzera igotzeko aukera izango duzu.\p"
	.string "Leku asko izango duzu zure gauzak\n"
	.string "bertan jartzeko.\p"
	.string "Zure gela sekretua izango da…\n"
	.string "BASE SEKRETUA!\p"
	.string "Bat egin behar zenuke, zuk ere.\p"
	.string "Beste gauza bat, ez duzu zertan zure\n"
	.string "BASE SEKRETUA zuhaitz batean egin.\p"
	.string "Erabili BOTERE EZKUTUA zulo txiki\n"
	.string "bat duten hormetan. Nik ere\p"
	.string "beste leku batuzk bilatuko ditut.\n"
	.string "Ongi, aio!$"

Route111_Text_DontWantThis:
	.string "Zer, ez al duzu hau nahi?\n"
	.string "Iritzia aldatzen baduzu, abisatu, bai?$"

Route111_Text_DontHaveAnyRoom:
	.string "Ene, ez duzu honentzako lekurik.\p"
	.string "Gorde egingo dizut, eta itzuli\n"
	.string "bila beste batean, ados?$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
