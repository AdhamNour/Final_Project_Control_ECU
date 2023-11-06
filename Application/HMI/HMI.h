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

typedef enum {HMI_SET_PASSWORD='A',HMO_CHECK_PASSWORD} HMICommand;
typedef enum {HMI_CORRECT_PASSWORD='a',HMI_WRONG_PASSWORD} PasswordStatus;



void HMI_init();

HMICommand HMI_recieveCommand();
void HMI_recivePassword(uint8* password);
void HMI_sendPasswordStatus(const PasswordStatus passwordStatus);

#endif /* APPLICATION_HMI_HMI_H_ */
