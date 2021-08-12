/*****************************************************************************
* Task: Car Project
* File Name: led.c
* Description: functions for the led driver
* Author: Amr Mohamed
* Date: 9/7/2021
******************************************************************************/

/*- INCLUDES----------------------------------------------*/
#include "ECUAL/LED/LED.h"


/*- APIs IMPLEMENTATION-----------------------------------*/

/*************************************************************************************************
* Parameters (in) : void
* Parameters (out): enuErrorStatus_t
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to initialize the led
*************************************************************************************************/
enuErrorStatus_t	LED_Init(void)
{
   return DIO_Init();
}//end LED_Init


/*************************************************************************************************
* Parameters (in) : enuPinConfig_t LED(index to the led pin)
* Parameters (out): enuErrorStatus_t
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to turn the led on
*************************************************************************************************/
enuErrorStatus_t	LED_ON(enuPinConfig_t LED)
{
   DIO_Write(LED, HIGH);
   return SUCCESS;
}//end LED_ON


/*************************************************************************************************
* Parameters (in) : enuPinConfig_t LED(index to the led pin)
* Parameters (out): enuErrorStatus_t
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to turn the led off
*************************************************************************************************/
enuErrorStatus_t	LED_OFF(enuPinConfig_t LED)
{
   DIO_Write(LED, LOW);
   return SUCCESS;

}//end LED_OFF


/*************************************************************************************************
* Parameters (in) : enuPinConfig_t LED(index to the led pin)
* Parameters (out): enuErrorStatus_t
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to toggle the led
*************************************************************************************************/
enuErrorStatus_t	LED_toggle(enuPinConfig_t LED)
{
   DIO_Toggle(LED);
   return SUCCESS;
}