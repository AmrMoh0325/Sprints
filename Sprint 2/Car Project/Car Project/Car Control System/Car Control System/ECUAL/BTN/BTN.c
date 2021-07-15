/*****************************************************************************
* Task: Car Project
* File Name: BTN.c
* Description: functions for the control buttons driver
* Author: TEAM2
* Date: 12/7/2021
******************************************************************************/


/*- INCLUDES----------------------------------------------*/
#include "BTN.h"

#define HOLD_DELAY      10000
/*- APIs IMPLEMENTATION-----------------------------------*/

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to initialize the button
*************************************************************************************************/
enuErrorStatus_t	BTN_Init(void)
{
	return DIO_Init();
}//end BTN_Init


/*************************************************************************************************
* Parameters (in) : u8_BtnNum(index to the button pin)
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to read the button status (pressed, not_pressed)
*************************************************************************************************/
enuErrorStatus_t	BTN_getState(uint8_t u8_BtnNum, enuBTNStatus_t* enuBTNStatus)
{

	static uint8_t u8_HeldFlag=0;
	uint64_t u64_Counter=0;

	if(enuBTNStatus == NULL_PTR)	return E_ERROR;
	else
	{
		uint8_t u8_Data;

		DIO_Read(u8_BtnNum, &u8_Data);

		while(u8_Data == LOW && u64_Counter < HOLD_DELAY)
		{
			u64_Counter++;
			DIO_Read(u8_BtnNum, &u8_Data);
		}
		if(u64_Counter == HOLD_DELAY)
		{
			*enuBTNStatus = HELD;
			u8_HeldFlag = 1;
		}
		else if(u64_Counter < HOLD_DELAY && u64_Counter > 0 && u8_HeldFlag == 0)
		{
			*enuBTNStatus = PRESSED;
		}
		else
		{
			*enuBTNStatus = NOT_PRESSED;
			u8_HeldFlag = 0;
		}//end else if
		u64_Counter = 0;

		return E_OK;
	}//end else
}//end BTN_getState
