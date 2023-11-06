/*
 * Buzzer.c
 *
 *  Created on: Nov 6, 2023
 *      Author: adham
 */


#include "Buzzer.h"

void Buzzer_init(){
	GPIO_setupPinDirection(BUZZER_PORT_ID,BUZZER_PIN_ID,PIN_OUTPUT);
	Buzzer_off();
}

void Buzzer_on(){
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,LOGIC_HIGH);
}

void Buzzer_off(){
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,LOGIC_LOW);
}
