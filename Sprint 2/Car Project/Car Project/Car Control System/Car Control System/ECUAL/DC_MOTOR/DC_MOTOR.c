/*****************************************************************************
* Task: Car Project
* File Name: DC_MOTOR.c
* Description: functions for the dc driver
* Author: TEAM2
* Date: 12/7/2021
******************************************************************************/

#include "DC_MOTOR.h"


/*- FUNCTION PROTOTYPES ----------------------------------*/
/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to initialize the motor
*************************************************************************************************/
enuErrorStatus_t DCMotor_Init(void)
{
	//configure PB0,PB1(Motor pins) as output pins
	return DIO_Init();
}//end DCMotor_Init

/*************************************************************************************************
* Parameters (in) : enuDirection
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to set the motor direction
*************************************************************************************************/
enuErrorStatus_t DCMotor_setDirection(uint8_t u8_Motor, enuMotorDirection_t enuDirection)
{
	switch(enuDirection)
	{
	case FORWARD:

		if(u8_Motor == MOTOR1)
		{
			DIO_Write(DC1_IN1, HIGH);
			DIO_Write(DC1_IN2, LOW);
		}
		else if(u8_Motor == MOTOR2)
		{
			DIO_Write(DC2_IN1, HIGH);
			DIO_Write(DC2_IN2, LOW);
		}
		break;
	case BACKWARD:

		if(u8_Motor == MOTOR1)
		{
			DIO_Write(DC1_IN1, LOW);
			DIO_Write(DC1_IN2, HIGH);
		}
		else if(u8_Motor == MOTOR2)
		{
			DIO_Write(DC2_IN1, LOW);
			DIO_Write(DC2_IN2, HIGH);
		}
		break;
	}//end switch
	return E_OK;
}//end DCMotor_setDirection

/*************************************************************************************************
* Parameters (in) : u8_Speed
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to set the motor speed
*************************************************************************************************/
enuErrorStatus_t DCMotor_setSpeed(uint8_t u8_Speed)
{
	if(u8_Speed > 100)
	{
		return E_ERROR;
	}//end if
	PWM_Init();
	PWM_Start(u8_Speed);

	return E_OK;

}//end DCMotor_setSpeed

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to stop the motor
*************************************************************************************************/
enuErrorStatus_t DCMotor_stop(uint8_t u8_Motor)
{
	if(u8_Motor == MOTOR1)
	{
		DIO_Write(DC1_IN1, LOW);
		DIO_Write(DC1_IN2, LOW);
	}
	else if(u8_Motor == MOTOR2)
	{
		DIO_Write(DC2_IN1, LOW);
		DIO_Write(DC2_IN2, LOW);
	}

	return E_OK;
}//end DCMotor_stop

