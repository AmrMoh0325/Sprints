/*
 * I2C_Driver.c
 *
 * Created: 7/20/2021 12:04:00 PM
 * Author : Amrth
 */ 

#include "MCAL/I2C/I2C.h"
#include "util/delay.h"

int main(void)
{
    I2C_Init();
    /* Replace with your application code */
    _delay_ms(1000);
     I2C_MASTER_SendData(0x02,'A');
    while (1) 
    {
      
    }
}

