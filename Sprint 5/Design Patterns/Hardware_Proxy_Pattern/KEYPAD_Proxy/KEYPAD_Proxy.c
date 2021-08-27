/*
 * KEYPAD_Proxy.c
 *
 *  Created on: Aug 23, 2021
 *      Author: DELLL
 */


#include "KEYPAD_Proxy.h"

/************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling
* Description     : Keypad initialization
*************************************************************/
enuErrorStatus_t KEYPADProxy_Init(void)
{
	enuErrorStatus_t RetVal = KEYPAD_Init();
	return RetVal;
}

/************************************************************
* Parameters (in) : ptr
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling
* Description     : Reading the Keypad buttons
*************************************************************/
enuErrorStatus_t KEYPADProxy_Read(uint8_t* ptr)
{
	enuErrorStatus_t RetVal = KEYPAD_Read(ptr);
	return RetVal;
}
