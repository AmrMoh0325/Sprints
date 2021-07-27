/*****************************************************************************
* Task: Thermostat
* File Name: ADC.h
* Description: Main application
* Author: Amr Mohamed
* Date: 26/7/2021
******************************************************************************/

/*- INCLUDES --------------------------------------------------*/
#include "APP/Thermostat/Thermo.h"

/*- API IMPLEMENTATION --------------------------------------------------*/
/************************************************************************************
* Parameters (in): void
* Parameters (out): int
* Return value: 0
* Description: MAin application
************************************************************************************/
int main(void)
{
   Thermo_Init();   
    while (1) 
    {
       Thermo_Update();
    }
}

