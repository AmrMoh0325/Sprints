/*****************************************************************************
* Task: Thermostat
* File Name: Motor.h
* Description: Header File for Motor driver
* Author: Amr Mohamed
* Date: 26/7/2021
******************************************************************************/


#ifndef __MOTOR__
#define __MOTOR__

/*- INCLUDES --------------------------------------------------*/
#include "MCAL/DIO/DIO.h"
#include "ECUAL/Motor/Motor_Cfg.h"


/*- API PROTOTYPES --------------------------------------------------*/
/************************************************************************************
* Parameters (in): enuMotorSelect_t Motor
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to start the selected motor
************************************************************************************/
enuErrorStatus_t MotorStart(enuMotorSelect_t Motor);

/************************************************************************************
* Parameters (in): enuMotorSelect_t Motor
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to stop the selected motor
************************************************************************************/
enuErrorStatus_t MotorStop(enuMotorSelect_t Motor);


#endif /* __MOTOR__ */