/*****************************************************************************
* Task: Chat Application - Master
* File Name: APP.h
* Description: header file for chat app - master application
* Author: Amr Mohamed
* Date: 16/7/2021
******************************************************************************/


#ifndef APP_H_
#define APP_H_

 /*- INCLUDES --------------------------------------------------*/
#include "DataTypes.h"
#include "MCAL/SPI/SPI.h"
#include "MCAL/UART/UART.h"


/*- APIs PROTOTYPES-----------------------------------*/
/*************************************************************************************************
* Parameters (in) : void
* Parameters (out): void
* Return Value    : void
* Description     : A function to initialize the application
*************************************************************************************************/
void APP_Init_Master(void);

/*************************************************************************************************
* Parameters (in) : void
* Parameters (out): void
* Return Value    : void
* Description     :  A function to update the application
*************************************************************************************************/
void APP_Update_Master(void);


#endif /* APP_H_ */