#include "Application.h"

#include "util/delay.h"
#include <avr/interrupt.h>

#include "HMI/HMI.h"

#include "../HAL/Buzzer/Buzzer.h"
#include "../HAL/External_EEPROM/External_EEPROM.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/DC_Motor/DC_Motor.h"

#include "../MCAL/TWI/TWI.h"
#include "../MCAL/Timer1/Timer1.h"

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


static void handleThreeTimeError(){
	// configure the timer fot one minute
	//turn on the buzzer
	//send to HMI the current status



}

static void motorCW(){
DcMotor_Rotate(CW,100);
HMI_sendDoorStatus(DOOR_OPENING);
}
static void motorACW(){
	DcMotor_Rotate(ACW,100);
	HMI_sendDoorStatus(DOOR_CLOSED);

}

static void motorOFf(){
	DcMotor_Rotate(OFF,100);

	HMI_sendDoorStatus(DOOR_OPENED);


}
static void handleOpenDoor(){
	static uint8 i =0,counter =1;
	static void (*ptrs[])()={motorCW,motorOFf,motorACW};
	if(counter == 15){
		if(i<=2) (ptrs[i])();
		if(i==2){
			i=0;
//			Timer1_deInit();
		}
		i++;
	}
	counter++;
}
static void openDoor(){
	if(HMI_recieveCommand()==HMI_OPEN_DOOR){
		Timer1_ConfigType config ;
		config.prescaler=TIMER1_CLK_256;
		config.initial_value=0;
		config.mode=TIMER1_CTC;
		config.compare_value=312;
		Timer1_init(&config);

		Timer1_setCallBack(handleOpenDoor);
	}
}

void Application_Setup() {
	TWI_ConfigType twi_config;

	twi_config.bit_rate = 400;
	twi_config.address = 0x01;

	TWI_init(&twi_config);

	LCD_init();
	HMI_init();
	DcMotor_Init();
	Buzzer_init();
	sei();

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
		openDoor();
		break;
	case HMI_PASSWORD_WRONG_THREE_TIMES:
			handleThreeTimeError();
		break;
	default:
		break;
	}
}
