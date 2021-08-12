/*****************************************************************************
* Task: EEPROM Task
* File Name: main.c
* Description: main file for EEPROM Application
* Author: Amr Mohamed
* Date: 25/7/2021
******************************************************************************/


/*- INCLUDES --------------------------------------------------*/
#include "APP/EEPROM_APP/APP.h"





/************************************************************************************
* Parameters (in): void
* Parameters (out): void
* Return value: void
* Description: main application function
************************************************************************************/
int main(void)
{
   //initialize the app
   APP_Init();
 
   while (1) 
   {
      //update the app state
      APP_Update();
   }
}

