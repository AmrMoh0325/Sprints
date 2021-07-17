/*
 * SPI_UART_Chat_APP.c
 *
 * Created: 7/16/2021 8:20:07 PM
 * Author : Amrth
 */ 

#include "APP/Chat_APP/APP.h"

int main(void)
{
   APP_Init_Slave();
   while (1) 
   {
      APP_Update_Slave();
   }
}

