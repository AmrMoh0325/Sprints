/*****************************************************************************
* Task: Car Project
* File Name: dc.h
* Description: header file for the dc driver
* Author: TEAM2
* Date: 12/7/2021
******************************************************************************/

#ifndef ECUAL_DC_MOTOR_DC_MOTOR_H_
#define ECUAL_DC_MOTOR_DC_MOTOR_H_

/*- INCLUDES -----------------------------------------------*/
#include "../../LIB/BIT_math.h"
#include "../../LIB/BIT_math.h"
#include "../../MCAL/DIO/DIO_cfg.h"
#include "../../MCAL/DIO/DIO_init.h"
#include "../../MCAL/PWM/PWM.h"

#define MOTOR1 0
#define MOTOR2 1


/*- ENUMS -----------------------------------------------*/
typedef enum {FORWARD, BACKWARD}enuMotorDirection_t;

/*- FUNCTION PROTOTYPES ----------------------------------*/
/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to initialize the motor
*************************************************************************************************/
enuErrorStatus_t DCMotor_Init(void);

/*************************************************************************************************
* Parameters (in) : enuDirection
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to set the motor direction
*************************************************************************************************/
enuErrorStatus_t DCMotor_setDirection(uint8_t u8_Motor, enuMotorDirection_t enuDirection);

/*************************************************************************************************
* Parameters (in) : u8_Speed
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to set the motor speed
*************************************************************************************************/
enuErrorStatus_t DCMotor_setSpeed(uint8_t u8_Speed);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to stop the motor
*************************************************************************************************/
enuErrorStatus_t DCMotor_stop(uint8_t u8_Motor);


#endif /* ECUAL_DC_MOTOR_DC_MOTOR_H_ */
