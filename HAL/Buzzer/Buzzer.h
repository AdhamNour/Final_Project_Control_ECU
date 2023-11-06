/*
 * Buzzer.h
 *
 *  Created on: Nov 6, 2023
 *      Author: adham
 */

#ifndef HAL_BUZZER_BUZZER_H_
#define HAL_BUZZER_BUZZER_H_

#include "../../MCAL/GPIO/gpio.h"

#define BUZZER_PORT_ID PORTB_ID
#define BUZZER_PIN_ID PIN1_ID

void Buzzer_init();

void Buzzer_on();

void Buzzer_off();

#endif /* HAL_BUZZER_BUZZER_H_ */
