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
   { PB4, INPUT,  NO_CONNECTION },       //SS0
   { PB5, INPUT,  NO_CONNECTION },       //MOSI
   { PB6, OUTPUT, NO_CONNECTION },       //MISO
   { PB7, INPUT,  NO_CONNECTION }        //SCK
};