#include "Application.h"

#include "util/delay.h"

#include "HMI/HMI.h"

#include "../HAL/Buzzer/Buzzer.h"
#include "../HAL/External_EEPROM/External_EEPROM.h"
#include "../HAL/LCD/LCD.h"

#include "../MCAL/TWI/TWI.h"

void Application_Setup() {
	uint8 i;
	TWI_ConfigType twi_config;

	twi_config.bit_rate=400;
	twi_config.address=0x01;

	TWI_init(&twi_config);

	LCD_init();
	HMI_init();
	Buzzer_init();

}

void Application_Loop() {
	static receivedPassword[6]={0};
	HMI_recivePassword(receivedPassword);
	LCD_displayString(receivedPassword);
	Buzzer_on();
	_delay_ms(500);
	Buzzer_off();
	_delay_ms(500);
}
