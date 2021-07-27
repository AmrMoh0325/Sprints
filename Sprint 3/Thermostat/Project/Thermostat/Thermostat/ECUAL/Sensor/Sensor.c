/*****************************************************************************
* Task: Thermostat
* File Name: Sensor.c
* Description: File for Sensor driver functions
* Author: Amr Mohamed
* Date: 26/7/2021
******************************************************************************/

/*- INCLUDES --------------------------------------------------*/
#include "ECUAL/Sensor/Sensor.h"

/*- API IMPLEMENTATION --------------------------------------------------*/
/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to Initialize sensors
************************************************************************************/
enuErrorStatus_t Sensor_Init(void)
{
   //initialize ADC
   ADC_Init();
   return SUCCESS;
}


/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to get LM35 Temperature reading
************************************************************************************/
enuErrorStatus_t LM35_GetTemperature(uint8_t *pu8Temp)
{
   uint16_t u16buffer=0;
   //get LM35 ADC reading
   ADC_Read(LM35_ADC_CHANNEL,&u16buffer);
   //transform ADC reading into temperature value and return it
   *pu8Temp = ((uint32_t)u16buffer *150)/307;
   return SUCCESS;
}