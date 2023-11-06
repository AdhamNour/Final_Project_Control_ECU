#include "Application.h"

#include "util/delay.h"

#include "HMI/HMI.h"

#include "../HAL/Buzzer/Buzzer.h"
#include "../HAL/External_EEPROM/External_EEPROM.h"
#include "../HAL/LCD/LCD.h"

#include "../MCAL/TWI/TWI.h"

static uint8 password[7] = { 0 };

static void savePassword() {
	register uint8 i = 0;
	HMI_recivePassword(password);
	while (password[i] != '\0') {
		EEPROM_writeByte(0x0000 + i, password[i]);
		_delay_ms(20);
		i++;
	}

}

static void checkPassword() {
	register uint8 i = 0;
	static uint8 storedPassword;
	HMI_recivePassword(password);

	for (i = 0; i < 5; ++i) {
		EEPROM_readByte(0x0000 + i, &storedPassword);
		if (storedPassword != password[i]) {
			HMI_sendPasswordStatus(HMI_WRONG_PASSWORD);
			return;
		}
		_delay_ms(20);

	}
	HMI_sendPasswordStatus(HMI_CORRECT_PASSWORD);
}

void Application_Setup() {
	TWI_ConfigType twi_config;

	twi_config.bit_rate = 400;
	twi_config.address = 0x01;

	TWI_init(&twi_config);

	LCD_init();
	HMI_init();
	Buzzer_init();

}

void Application_Loop() {
	static HMICommand cmd;
	cmd = HMI_recieveCommand();
	switch (cmd) {
	case HMI_SET_PASSWORD:
		//save the password to the EEPROM
		savePassword();
		break;
	case HMO_CHECK_PASSWORD:
		// check the password
		checkPassword();

	default:
		break;
	}
}
