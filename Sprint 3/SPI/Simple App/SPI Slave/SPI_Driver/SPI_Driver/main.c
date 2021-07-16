/*
 * SPI_Driver.c
 *
 * Created: 7/15/2021 8:17:56 PM
 * Author : Amrth
 */ 

#include "MCAL/SPI/SPI.h"

int main(void)
{
    SPI_Init();
    uint8_t Data=7;
    PORTC_R=0;
    while (1) 
    {
       SPI_RecieveData(&Data);
       PORTC_R=Data;
    }
}

