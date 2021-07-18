/*
 * SPI_Driver.c
 *
 * Created: 7/15/2021 8:17:56 PM
 * Author : Amrth
 */ 

#include "MCAL/SPI/SPI.h"
#include "MCAL/Timer/Timer.h"


void Simple_App(void)
{
   static uint8_t Data=0;
   DIO_Toggle(test);
   SPI_SendData(Data++);
}

int main(void)
{
    
    
    SPI_Init();
    DIO_Write(test,HIGH);
    T0_Init(TIMER0_NORMAL_MODE,TIMER0_SCALER_8);
    T0_OV_InterruptEnable();
    sei();
    T0_Start(1000000,Simple_App);
    
    while (1) 
    {
       

    }
}

