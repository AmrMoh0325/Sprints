/*****************************************************************************
* Task: EEPROM Task
* File Name: APP.c
* Description: header file for EEPROM Application
* Author: Amr Mohamed
* Date: 25/7/2021
******************************************************************************/


#ifndef APP_H_
#define APP_H_

/*- INCLUDES --------------------------------------------------*/
#include "ECUAL/EEPROM/EEPROM.h"
#include "MCAL/UART/UART.h"

/*- APIs PROTOTYPES-----------------------------------*/

/************************************************************************************
* Parameters (in): void
* Parameters (out): void
* Return value: void
* Description: A function to initialize application peripherals and devices
************************************************************************************/
void APP_Init(void);

/************************************************************************************
* Parameters (in): void
* Parameters (out): void
* Return value: void
* Description: A function to update the application status
************************************************************************************/
void APP_Update(void);



#endif /* APP_H_ */