/*****************************************************************************
* Task: Thermostat
* File Name: Keypad.c
* Description: File for keypad driver functions
* Author: Amr Mohamed
* Date: 26/7/2021
******************************************************************************/

/*- INCLUDES --------------------------------------------------*/
#include "ECUAL/Keypad/Keypad.h"
#include "ECUAL/Keypad/Keypad_Cfg.h"
#include "MCAL/Register.h"

/*- API IMPLEMENTATION --------------------------------------------------*/
/************************************************************************************
* Parameters (in): uint8_t * pu8btn
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to check for keypad key presses
************************************************************************************/
enuErrorStatus_t Keypad_GetKey(uint8_t * pu8btn)
{
	uint8_t r,c,flag=0,key=DEFAULT_KEY;
   static uint8_t Press_flag=0;
   //make all output pins high
	DIO_Write(KEYPAD_C1,HIGH);
	DIO_Write(KEYPAD_C2,HIGH);
	DIO_Write(KEYPAD_C3,HIGH);
	DIO_Write(KEYPAD_C4,HIGH);
   //loop on all columns
	for (c=0;c<KEYPAD_COLS;c++)
	{  
      //make each pin low
		DIO_Write(KEYPAD_C1+c,LOW);
      //loop on all rows
		for (r=0;r<KEYPAD_ROWS;r++)
		{
         DIO_Read(KEYPAD_R1+r,&flag);
			if (!flag)
			{
            //if a key is pressed record it 
				key=pu8Keys[r][c];
            //if the key was pressed before but isn't released yet return an error
            if(Press_flag==1)
            {
               return ERROR;
            }
				
			}
		}
      //make each pin high again
		DIO_Write(KEYPAD_C1+c,HIGH);
	}
	
   //if no key is pressed 
	if (key==DEFAULT_KEY)
	{
      //reset pressed flag
      Press_flag=0;
      //return an error
		return ERROR;
	}
   //else return the key
   Press_flag=1;
   *pu8btn=key;
	return SUCCESS;
}