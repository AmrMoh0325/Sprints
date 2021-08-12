/*****************************************************************************
* Task: Thermostat
* File Name: Keypad.h
* Description: header File for keypad driver
* Author: Amr Mohamed
* Date: 26/7/2021
******************************************************************************/


#ifndef __KEYPAD__
#define __KEYPAD__

#include "DataTypes.h"
#include "Utils.h"
#include "MCAL/DIO/DIO.h"

/*- API PROTOTYPE --------------------------------------------------*/
/************************************************************************************
* Parameters (in): uint8_t * pu8btn
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to check for keypad key presses
************************************************************************************/
enuErrorStatus_t Keypad_GetKey(uint8_t * pu8btn);

#endif /* __KEYPAD__ */