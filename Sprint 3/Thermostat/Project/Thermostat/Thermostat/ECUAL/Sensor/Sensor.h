/*****************************************************************************
* Task: Thermostat
* File Name: Sensor.h
* Description: Header File for Sensor driver
* Author: Amr Mohamed
* Date: 26/7/2021
******************************************************************************/


#ifndef __SENSOR__
#define __SENSOR__

/*- INCLUDES --------------------------------------------------*/
#include "DataTypes.h"
#include "MCAL/ADC/ADC.h"
#include "ECUAL/Sensor/Sensor_Cfg.h"

/*- API PROTOTYPES --------------------------------------------------*/

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to Initialize sensors
************************************************************************************/
enuErrorStatus_t Sensor_Init(void);

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to get LM35 Temperature reading
************************************************************************************/
enuErrorStatus_t LM35_GetTemperature(uint8_t *pu8Temp);


#endif /* __SENSOR__ */