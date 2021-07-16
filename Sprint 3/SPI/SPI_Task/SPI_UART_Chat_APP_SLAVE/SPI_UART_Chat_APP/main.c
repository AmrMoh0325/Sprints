/*
 * SPI_UART_Chat_APP.c
 *
 * Created: 7/16/2021 8:20:07 PM
 * Author : Amrth
 */ 

#include "DataTypes.h"
#include "MCAL/SPI/SPI.h"
#include "MCAL/UART/UART.h"

int main(void)
{
   uint8_t Send_Buffer[255]={0};
   UART_Init();
   SPI_Init();
    /* Replace with your application code */
    while (1) 
    {
       SPI_ReceiveString(Send_Buffer,255);
       UART_SendString(Send_Buffer);
    }
}

