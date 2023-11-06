/*
 * HMI.h
 *
 *  Created on: Nov 6, 2023
 *      Author: adham
 */

#ifndef APPLICATION_HMI_HMI_H_
#define APPLICATION_HMI_HMI_H_

#include "../../MCAL/UART/UART.h"

#define HMI_BIT_DATA 			UART_8_BIT_DATA
#define HMI_BIT_PARITY 			UART_PARITY_DISABLED
#define HMI_BIT_STOP_BIT		UART_STOP_BIT_ONE
#define HMI_BAUD_RATE 			9600


void HMI_init();

void HMI_recivePassword(uint8* password);
#endif /* APPLICATION_HMI_HMI_H_ */
