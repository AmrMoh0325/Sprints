/*****************************************************************************
* Task: I2C Driver_SLAVE
* File Name: main.c
* Description: Slave Application
* Author: Amr Mohamed
* Date: 24/7/2021
******************************************************************************/

#include "MCAL/I2C/I2C.h"
#include "MCAL/DIO/DIO.h"

int main(void)
{
    DIO_Init();
    I2C_Init();
    
    uint8_t Data=0;
    while (1) 
    {
       //Slave Receiver App
      I2C_SLAVE_ReceiveData(&Data);
      PORTA_R=Data;
      
      //Slave Transmitter App
      /*I2C_SLAVE_SendData(Data);
      PORTA_R=Data++;*/
      
      
    }
}

