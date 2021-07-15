/*****************************************************************************
* Task: Car Project
* File Name: PWM_Cfg.c
* Description: configuration for the PWM
* Author: TEAM2
* Date: 11/7/2021
******************************************************************************/

#include "PWM.h"

const strPWMConfigType_t strpwmConfig =
{
		TIMER0,
		FAST_PWM,
		PRESCALER_8,
		TIMER_INT_DIS,
		NON_INVERTING
};
