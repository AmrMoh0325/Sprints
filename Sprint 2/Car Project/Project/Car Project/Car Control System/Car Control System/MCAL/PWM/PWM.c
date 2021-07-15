/*****************************************************************************
* Task: Car Project
* File Name: PWM.c
* Description: functions for the PWM driver
* Author: TEAM2
* Date: 11/7/2021
******************************************************************************/

/*- INCLUDES -----------------------------------------------*/
#include "../../LIB/BIT_math.h"
#include "../../LIB/Data_types.h"
#include "TM_registers.h"

#include "PWM.h"

//extern const strPWMConfigType_t strpwmConfig;

/*- FUNCTION PROTOTYPES ----------------------------------*/

static void setPrescaler(void);
/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to initialize the PWM
*************************************************************************************************/
enuErrorStatus_t PWM_Init(void)
{
	if(strpwmConfig.enuTimer == TIMER0)
	{
		//Select PWM mode
		if(strpwmConfig.enuPWMMode == FAST_PWM)
		{
			SET_BIT(TCCR0_R, WGM00_BIT);
			SET_BIT(TCCR0_R, WGM01_BIT);
		}
		else if(strpwmConfig.enuPWMMode == PC_PWM)
		{
			SET_BIT(TCCR0_R, WGM00_BIT);
			CLR_BIT(TCCR0_R, WGM01_BIT);
		}//end else if

		//select OC0 mode
		if(strpwmConfig.enuOCMode == NON_INVERTING)
		{
			CLR_BIT(TCCR0_R, COM00_BIT);
			SET_BIT(TCCR0_R, COM01_BIT);
		}//end if
		else if(strpwmConfig.enuOCMode == INVERTING)
		{
			SET_BIT(TCCR0_R, COM00_BIT);
			SET_BIT(TCCR0_R, COM01_BIT);
		}//end else if
	}//end if for timer0

	return E_OK;
}//end PWM_Init

//private function to set prescaler
static void setPrescaler(void)
{
	switch(strpwmConfig.enuPWMPrescal)
	{
	case NO_CLOCK:
		CLR_BIT(TCCR0_R, CS00_BIT);
		CLR_BIT(TCCR0_R, CS01_BIT);
		CLR_BIT(TCCR0_R, CS02_BIT);
		break;
	case NO_PRESCALER:
		SET_BIT(TCCR0_R, CS00_BIT);
		CLR_BIT(TCCR0_R, CS01_BIT);
		CLR_BIT(TCCR0_R, CS02_BIT);
		break;
	case PRESCALER_8:
		CLR_BIT(TCCR0_R, CS00_BIT);
		SET_BIT(TCCR0_R, CS01_BIT);
		CLR_BIT(TCCR0_R, CS02_BIT);
		break;
	case PRESCALER_64:
		SET_BIT(TCCR0_R, CS00_BIT);
		SET_BIT(TCCR0_R, CS01_BIT);
		CLR_BIT(TCCR0_R, CS02_BIT);
		break;
	case PRESCALER_256:
		CLR_BIT(TCCR0_R, CS00_BIT);
		CLR_BIT(TCCR0_R, CS01_BIT);
		SET_BIT(TCCR0_R, CS02_BIT);
		break;
	case PRESCALER_1024:
		SET_BIT(TCCR0_R, CS00_BIT);
		CLR_BIT(TCCR0_R, CS01_BIT);
		SET_BIT(TCCR0_R, CS02_BIT);
		break;
	case EXTERNAL_CLOCK_FALL_EDGE:
		CLR_BIT(TCCR0_R, CS00_BIT);
		SET_BIT(TCCR0_R, CS01_BIT);
		SET_BIT(TCCR0_R, CS02_BIT);
		break;
	case EXTERNAL_CLOCK_RISE_EDGE:
		SET_BIT(TCCR0_R, CS00_BIT);
		SET_BIT(TCCR0_R, CS01_BIT);
		SET_BIT(TCCR0_R, CS02_BIT);
		break;
	default:
		break;
	}//end switch for prescaler
}//end setPrescaler
/*************************************************************************************************
* Parameters (in) : u8_Duty
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to start generating PWM wave
*************************************************************************************************/
enuErrorStatus_t PWM_Start(uint8_t u8_Duty)
{
	switch(strpwmConfig.enuOCMode)
    {
    case NON_INVERTING:
        OCR0_R = ((u8_Duty *255)/100);
        break;
    case INVERTING:
        OCR0_R = 255 - ((256 * u8_Duty)/100);
    break;
    }
    setPrescaler();
	return E_OK;
}//end PWM_Start


/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A stop generating PWM wave
*************************************************************************************************/
enuErrorStatus_t PWM_Stop(void)
{
//	CLR_BIT(TCCR0_R, CS00_BIT);
//	CLR_BIT(TCCR0_R, CS01_BIT);
//	CLR_BIT(TCCR0_R, CS02_BIT);
	CLR_BIT(TCCR0_R, COM00_BIT);
	CLR_BIT(TCCR0_R, COM01_BIT);
	return E_OK;
}//end PWM_Stop
