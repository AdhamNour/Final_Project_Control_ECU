/*
 * HMI.c
 *
 *  Created on: Nov 6, 2023
 *      Author: adham
 */

#include "HMI.h"

void HMI_init(){
	UART_ConfigType uart_config;
	uart_config.baud_rate = HMI_BAUD_RATE;
	uart_config.bit_data = HMI_BIT_DATA;
	uart_config.parity=HMI_BIT_PARITY;
	uart_config.stop_bit=HMI_BIT_STOP_BIT;
	UART_init(&uart_config);

}

void HMI_recivePassword(uint8* str){
	UART_receiveString(str);
}

