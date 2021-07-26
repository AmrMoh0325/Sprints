/*****************************************************************************
* Task: DIO Driver
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
   { PA0, OUTPUT,  NO_CONNECTION },     
   { PA1, OUTPUT,  NO_CONNECTION },     
   { PA2, OUTPUT,  NO_CONNECTION },    
   { PA3, OUTPUT,  NO_CONNECTION },     
   { PA4, OUTPUT,  NO_CONNECTION },      
   { PA5, OUTPUT,  NO_CONNECTION },       
   { PA6, OUTPUT,  NO_CONNECTION },      
   { PA7, OUTPUT,  NO_CONNECTION }       
};