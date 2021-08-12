/*****************************************************************************
* Task: Thermostat
* File Name: Motor.c
* Description: File for motor driver functions
* Author: Amr Mohamed
* Date: 26/7/2021
******************************************************************************/

/*- INCLUDES --------------------------------------------------*/
#include "ECUAL/Motor/Motor.h"


/*- API IMPLEMENTATION --------------------------------------------------*/
/************************************************************************************
* Parameters (in): enuMotorSelect_t Motor
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to start the selected motor
************************************************************************************/
enuErrorStatus_t MotorStart(enuMotorSelect_t Motor)
{
   //enable motor enable pin
   DIO_Write(15,HIGH);
   return SUCCESS;
}

/************************************************************************************
* Parameters (in): enuMotorSelect_t Motor
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to stop the selected motor
************************************************************************************/
enuErrorStatus_t MotorStop(enuMotorSelect_t Motor)
{
   //disable motor enable pin
   DIO_Write(15,LOW);
   return SUCCESS;
}