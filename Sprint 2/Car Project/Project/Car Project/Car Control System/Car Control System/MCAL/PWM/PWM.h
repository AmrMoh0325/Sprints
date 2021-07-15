/*****************************************************************************
* Task: Car Project
* File Name: PWM.h
* Description: header file for the pwm driver
* Author: TEAM2
* Date: 11/7/2021
******************************************************************************/
#ifndef MCAL_PWM_PWM_H_
#define MCAL_PWM_PWM_H_

/*- INCLUDES -----------------------------------------------*/
#include "../../LIB/Data_types.h"
#include "../../LIB/BIT_math.h"


/*- ENUMS --------------------------------------------------*/
typedef enum {TIMER0, TIMER1, TIMER2} enuTimerModule_t;
typedef enum {FAST_PWM, PC_PWM} enuPWMMode_t;
typedef enum {NO_CLOCK, NO_PRESCALER, PRESCALER_8, PRESCALER_64, PRESCALER_256, PRESCALER_1024,
			  EXTERNAL_CLOCK_FALL_EDGE, EXTERNAL_CLOCK_RISE_EDGE, PRESCALER_32, PRESCALER_128} enuPWMClock_t;
typedef enum {TIMER_INT_DIS, TIMER_INT_EN} enuTimerIntEn_t;
typedef enum {NON_INVERTING, INVERTING} enuOCMode_t;

typedef struct{
	enuTimerModule_t enuTimer;
	enuPWMMode_t	 enuPWMMode;
	enuPWMClock_t	 enuPWMPrescal;
	enuTimerIntEn_t  enuTimerInt;
	enuOCMode_t      enuOCMode;
}strPWMConfigType_t;


extern const strPWMConfigType_t strpwmConfig;
/*- FUNCTION PROTOTYPES ----------------------------------*/

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to initialize the PWM
*************************************************************************************************/
enuErrorStatus_t PWM_Init(void);


/*************************************************************************************************
* Parameters (in) : enuPrescaler, u8_Duty
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to start generating PWM wave
*************************************************************************************************/
enuErrorStatus_t PWM_Start(uint8_t u8_Duty);


/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A stop generating PWM wave
*************************************************************************************************/
enuErrorStatus_t PWM_Stop(void);

#endif /* MCAL_PWM_PWM_H_ */
