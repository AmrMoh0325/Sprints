/*
 * UART_Driver.c
 *
 * Created: 7/14/2021 5:00:30 AM
 * Author : Amrth
 */ 


#include "Register.h"
#include "DataTypes.h"
#include "Utils.h"
#include "UART/UART.h"


int main(void)
{
   uint16_t Data=0;
   UART_Init();
    /* Replace with your application code */
    while (1) 
    {
       UART_ReceiveData(&Data);
       UART_SendData(Data); 
    }
}

