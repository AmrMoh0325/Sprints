/*****************************************************************************
* Task: Chat Application - Master
* File Name: APP.c
* Description: functions for the the master MCU in the chat application
* Author: Amr Mohamed
* Date: 16/7/2021
******************************************************************************/
 
 /*- INCLUDES --------------------------------------------------*/
#include "APP/Chat_APP/APP.h"


/*- GLOBAL VARIABLES --------------------------------------------------*/
uint8_t Send_Buffer[255]={0};


/*- APIs IMPLEMENTATION-----------------------------------*/
/*************************************************************************************************
* Parameters (in) : void
* Parameters (out): void
* Return Value    : void
* Description     : A function to initialize the application
*************************************************************************************************/
void APP_Init_Master(void)
{
   //initialize UART
   UART_Init();
   //initialize SPI
   SPI_Init();
}

/*************************************************************************************************
* Parameters (in) : void
* Parameters (out): void
* Return Value    : void
* Description     :  A function to update the application
*************************************************************************************************/
void APP_Update_Master(void)
{
   //receive string from UART
   UART_ReceiveString(Send_Buffer,255);
   //when done, send that string to SPI slave
   SPI_SendString(Send_Buffer);
}
