/*****************************************************************************
* Task: Car Project
* File Name: CAR.h
* Description: header file for car app
* Author: TEAM2
* Date: 12/7/2021
******************************************************************************/

#ifndef APP_CAR_CONTROL_SYSTEM_CAR_H_
#define APP_CAR_CONTROL_SYSTEM_CAR_H_

/*- INCLUDES --------------------------------------------------*/
#include "../../ECUAL/BTN/BTN.h"
#include "../../ECUAL/DC_MOTOR/DC_MOTOR.h"

/*- APIs DECLARATIONS-----------------------------------*/

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to initialize the application
*************************************************************************************************/
void App_Init(void);


/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to update the application
*************************************************************************************************/
void App_Update(void);


#endif /* APP_CAR_CONTROL_SYSTEM_CAR_H_ */
