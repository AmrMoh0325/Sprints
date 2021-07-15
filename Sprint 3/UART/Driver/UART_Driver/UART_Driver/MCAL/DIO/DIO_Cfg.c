/*****************************************************************************
* Task: AVR_DRIVERS
* File Name: DIO.h
* Description: configuration File for DIO driver
* Author: Amr Mohamed
* Date: 8/7/2021
******************************************************************************/

#include "DIO.h"
#include "DIO_Cfg.h"

//array of micro controller pins to be configured 
const strDIOConfigType_t astrDIOConfigParameters[DIO_GROUPS_NO] =
{
   { PA0, INPUT, PULL_UP_ENABLE },
   { PD4, OUTPUT, NO_CONNECTION }
};
