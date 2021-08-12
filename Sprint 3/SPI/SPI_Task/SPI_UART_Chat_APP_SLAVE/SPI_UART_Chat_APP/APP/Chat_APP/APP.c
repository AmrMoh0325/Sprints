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
void APP_Init_Slave(void)
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
void APP_Update_Slave(void)
{
   //receive string from SPI Master
   SPI_ReceiveString(Send_Buffer,255);
   //when done, send that string to UART
   UART_SendString(Send_Buffer);
}
