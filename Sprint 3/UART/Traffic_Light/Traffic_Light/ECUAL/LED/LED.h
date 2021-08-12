/*****************************************************************************
* Task: Car Project
* File Name: LED.h
* Description: Header file for led driver
* Author: Amr Mohamed
* Date: 9/7/2021
******************************************************************************/

#ifndef __LED__
#define __LED__

/*- INCLUDES -----------------------------------------------*/
#include "Utils.h"
#include "DataTypes.h"
#include "MCAL/DIO/DIO_Cfg.h"
#include "MCAL/DIO/DIO.h"

/*- FUNCTION DECLARATIONS ----------------------------------*/

/*************************************************************************************************
* Parameters (in) : void
* Parameters (out): enuErrorStatus_t
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to initialize the led
*************************************************************************************************/
enuErrorStatus_t	LED_Init(void);

/*************************************************************************************************
* Parameters (in) : enuPinConfig_t LED(index to the led pin)
* Parameters (out): enuErrorStatus_t
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to turn the led on
*************************************************************************************************/
enuErrorStatus_t	LED_ON(enuPinConfig_t LED);

/*************************************************************************************************
* Parameters (in) : enuPinConfig_t LED(index to the led pin)
* Parameters (out): enuErrorStatus_t
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to turn the led off
*************************************************************************************************/
enuErrorStatus_t	LED_OFF(enuPinConfig_t LED);

/*************************************************************************************************
* Parameters (in) : enuPinConfig_t LED(index to the led pin)
* Parameters (out): enuErrorStatus_t
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to toggle the led
*************************************************************************************************/
enuErrorStatus_t	LED_toggle(enuPinConfig_t LED);

#endif /* __LED__ */
