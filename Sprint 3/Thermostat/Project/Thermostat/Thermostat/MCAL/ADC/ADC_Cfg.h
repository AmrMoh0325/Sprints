/*****************************************************************************
* Task: Thermostat
* File Name: ADC.h
* Description: Config File for ADC driver
* Author: Amr Mohamed
* Date: 26/7/2021
******************************************************************************/


#ifndef __ADC_CFG__
#define __ADC_CFG__

/*- ENUMS --------------------------------------------------*/
//VREF select
typedef enum{VREF_AREF,VREF_AVCC,VREF_256}enuADC_Vref_t;
//Prescaler select
typedef enum{ADC_SCALER_2,ADC_SCALER_4,ADC_SCALER_8,ADC_SCALER_16,ADC_SCALER_32,ADC_SCALER_64,ADC_SCALER_128}enuADC_Scaler_t;


/*- MACROS --------------------------------------------------*/
//Prescaler select
#define  ADC_PRESCALER_CONFIG             ADC_SCALER_8

//VREF select
#define  ADC_Vref_SOURCE                  VREF_AVCC

#endif /* __ADC_CFG__ */