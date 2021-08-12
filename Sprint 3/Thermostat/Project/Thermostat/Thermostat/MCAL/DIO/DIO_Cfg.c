/*****************************************************************************
* Task: DIO Driver
* File Name: DIO.h
* Description: configuration File for DIO driver
* Author: Amr Mohamed
* Date: 8/7/2021
******************************************************************************/
 /*- INCLUDES --------------------------------------------------*/
#include "MCAL/DIO/DIO.h"
#include "MCAL/DIO/DIO_Cfg.h"

/*- GLOBAL VARIABLES --------------------------------------------------*/
//array of micro controller pins to be configured
const strDIOConfigType_t astrDIOConfigParameters[DIO_GROUPS_NO] =
{
   { PA0, INPUT,  NO_CONNECTION },        //ADC_LM35
   { PB0, OUTPUT, NO_CONNECTION },        //LCD_EN
   { PB1, OUTPUT, NO_CONNECTION },        //LCD_RS
   { PB2, OUTPUT, NO_CONNECTION },        //LCD_D4
   { PB3, OUTPUT, NO_CONNECTION },        //LCD_D5
   { PB4, OUTPUT, NO_CONNECTION },        //LCD_D6
   { PB5, OUTPUT, NO_CONNECTION },        //LCD_D7
   { PD0, OUTPUT, NO_CONNECTION },        //KEYPAD_C1
   { PD1, OUTPUT, NO_CONNECTION },        //KEYPAD_C2
   { PD2, OUTPUT, NO_CONNECTION },        //KEYPAD_C3
   { PD3, OUTPUT, NO_CONNECTION },        //KEYPAD_C4
   { PD4, INPUT , PULL_UP_ENABLE},        //KEYPAD_R1
   { PD5, INPUT , PULL_UP_ENABLE},        //KEYPAD_R2
   { PD6, INPUT , PULL_UP_ENABLE},        //KEYPAD_R3
   { PD7, INPUT , PULL_UP_ENABLE},        //KEYPAD_R4
   { PC5, OUTPUT, NO_CONNECTION }         //Fan

};

