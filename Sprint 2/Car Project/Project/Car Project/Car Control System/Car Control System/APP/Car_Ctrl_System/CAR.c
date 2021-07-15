/*****************************************************************************
* Task: Car Project
* File Name: CAR.c
* Description: functions for the car control system app
* Author: TEAM2
* Date: 12/7/2021
******************************************************************************/

/*- INCLUDES --------------------------------------------------*/
#include "CAR.h"

/*- GLOBAL VARIABLES --------------------------------------------------*/
enuMotorDirection_t genuMotorDirection;

/*- ENUMS --------------------------------------------------*/
typedef enum {SPEED_NEG_30, SPEED_0, SPEED_30, SPEED_60, SPEED_90} enuCarSpeed_t;


/*- APIs IMPLEMENTATION-----------------------------------*/

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to initialize the application
*************************************************************************************************/
void App_Init(void)
{
	DIO_Init();
	PWM_Init();
	BTN_Init();
}//end App_Init


/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to update the application
*************************************************************************************************/
void App_Update(void)
{
	enuBTNStatus_t enuButton0State;
	enuBTNStatus_t enuButton1State;
	enuBTNStatus_t enuButton2State;
	enuBTNStatus_t enuButton3State;
	static enuCarSpeed_t enuCarSpeed = SPEED_0;
	static uint8_t u8DutyCycle = 0;


	BTN_getState(BTN0, &enuButton0State);
	BTN_getState(BTN1, &enuButton1State);
	BTN_getState(BTN2, &enuButton2State);
	BTN_getState(BTN3, &enuButton3State);
	/* Forward Direction */
	if(enuButton0State == HELD)
	{
		DCMotor_setDirection(MOTOR1, genuMotorDirection);
		DCMotor_setDirection(MOTOR2, genuMotorDirection);
		DCMotor_setSpeed(u8DutyCycle);
	}
	/* Turn Right */
	else if(enuButton1State == HELD)
	{
		DCMotor_setDirection(MOTOR1, FORWARD);
		DCMotor_setDirection(MOTOR2, BACKWARD);
		DCMotor_setSpeed(30);
	}
	/*Turn Left */
	else if(enuButton2State == HELD)
	{
		DCMotor_setDirection(MOTOR2, FORWARD);
		DCMotor_setDirection(MOTOR1, BACKWARD);
		DCMotor_setSpeed(30);
	}
	/* Change Speed and Direction */
	else if(enuButton3State == PRESSED)
	{
		DCMotor_stop(MOTOR1);
		DCMotor_stop(MOTOR2);
		switch(enuCarSpeed)
		{
			case SPEED_NEG_30:
			{
				u8DutyCycle = 0;
				enuCarSpeed = SPEED_0;
				genuMotorDirection = FORWARD;
			}
			break;
			case SPEED_0:
			{
				u8DutyCycle = 30;
				enuCarSpeed = SPEED_30;
				genuMotorDirection = FORWARD;
			}
			break;
			case SPEED_30:
			{
				u8DutyCycle = 60;
				enuCarSpeed = SPEED_60;
				genuMotorDirection = FORWARD;
			}
			break;
			case SPEED_60:
			{
				u8DutyCycle = 90;
				enuCarSpeed = SPEED_90;
				genuMotorDirection = FORWARD;
			}
			break;
			case SPEED_90:
			{
				/* Toggling the direction of car movement */
				u8DutyCycle = 30;
				enuCarSpeed = SPEED_NEG_30;
				genuMotorDirection = BACKWARD;
			}
			break;
		}
	}
	else
	{
		PWM_Stop();
	}
}
