/*****************************************************************************
* Task: Thermostat
* File Name: ADC.h
* Description: header File for ADC driver
* Author: Amr Mohamed
* Date: 26/7/2021
******************************************************************************/


#ifndef __ADC__
#define __ADC__

/*- INCLUDES --------------------------------------------------*/
#include "DataTypes.h"
#include "Utils.h"
#include "MCAL/Register.h"
#include "MCAL/ADC/ADC_Cfg.h"

/*- ENUMS --------------------------------------------------*/
//channel select
typedef enum{CH0,CH1,CH2,CH3,CH4,CH5,CH6,CH7}enuADC_Channel_t;

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to initialize ADC according to config
************************************************************************************/
enuErrorStatus_t ADC_Init(void);

/************************************************************************************
* Parameters (in): enuADC_Channel_t enuChannel,uint16_t *pu16Reading
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to Read ADC channel voltage
************************************************************************************/
enuErrorStatus_t  ADC_Read(enuADC_Channel_t enuChannel,uint16_t *pu16Reading);

/************************************************************************************
* Parameters (in): enuADC_Channel_t enuChannel,uint8_t *pu8Percent
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to Read ADC channel percentage
************************************************************************************/
enuErrorStatus_t  ADC_Read_Percent(enuADC_Channel_t enuChannel,uint8_t *pu8Percent);



#endif /* __ADC__ */