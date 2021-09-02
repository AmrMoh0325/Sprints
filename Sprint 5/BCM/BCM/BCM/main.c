/*
 * main.c
 *
 *  Created on: Aug 26, 2021
 *      Author: Kariman
 */
#include "DIO_init.h"
#include "BCM.h"
#include "UART.h"

void Notify(void)
{
	DIO_toggle(0);
}

int main(void)
{
	DIO_Init();

	uint8_t au8Buffer[10] = {0};
	strBCMCfg_t strBCMCfg = {BCM_UART_CHANNEL, BCM_RX};
	strBCMTaskCfg_t strBCMTaskCfg = {BCM_ID, 10, au8Buffer, 0, Notify, BCM_UART_CHANNEL, BCM_RX};
         
	BCM_Init(&strBCMCfg);
	BCM_Setup(&strBCMTaskCfg);
	while(1)
	{
		BCM_RxDispatcher();
	}

}

