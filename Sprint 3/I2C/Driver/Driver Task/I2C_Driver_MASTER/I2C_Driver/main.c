/*****************************************************************************
* Task: I2C Driver_MASTER
* File Name: main.c
* Description: Master Application
* Author: Amr Mohamed
* Date: 24/7/2021
******************************************************************************/

#include "MCAL/I2C/I2C.h"
#include "MCAL/DIO/DIO.h"
#include "util/delay.h"



#define    MASTER_TRANSMITTER
int main(void)
{
    DIO_Init();
    I2C_Init();
    /* Replace with your application code */
    uint8_t Data=0;
    while (1) 
    {
       #ifdef MASTER_TRANSMITTER
      //Master Transmitter App
      _delay_ms(1000);
      PORTA_R=Data;
      I2C_MASTER_SendData(0x02,Data++);
      #endif
      
      #ifdef MASTER_RECEIVER
      //Master Receiver App
      I2C_MASTER_RecieveData(0x02,&Data);
      PORTA_R=Data;
      _delay_ms(1000);
      #endif
      
    }
}