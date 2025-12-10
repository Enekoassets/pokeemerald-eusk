MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "Eskerrik asko MISTERIO OPARIEN\n"
	.string "Sistema erabiltzeagatik.\p"
	.string "MIRARI KARTA honekin, galdetegi\n"
	.string "bat erantzun dezakezu POKéMON\l"
	.string "DENDA batean.\p"
	.string "Erabili galdetegia ENTRENATZAILEAK\n"
	.string "ARREZIPOLIS HIRIRA gonbidatzeko.\p"
	.string "…Pasahitz ezkutu bat emango\n"
	.string "dizut galdetegirako:\p"
	.string "“EMAN NIRI\n"
	.string "ENTRENATZAILE BIKAINA”\p"
	.string "Idatzi hori galdetegian, eta bidali\n"
	.string "HARI GABEKO KOMUNIKAZIO\l"
	.string "SISTEMAREN bidez.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Eskerrik asko MISTERIO OPARIEN\n"
	.string "Sistema erabiltzeagatik.\p"
	.string "ENTRENATZAILE bat iritsi da\n"
	.string "ARREZIPOLIS HIRIRA zure bila.\p"
	.string "Iritsi den ENTRENATZAILEAREKIN\n"
	.string "borroka gozatuko duzula espero dugu.\p"
	.string "Beste ENTRENATZAILE batzuk gonbidatu\n"
	.string "ditzakezu, beste pasahitz batzuekin.\p"
	.string "Bbilatu funtzionatu dezaketen\n"
	.string "pasahitz gehiago.$"
