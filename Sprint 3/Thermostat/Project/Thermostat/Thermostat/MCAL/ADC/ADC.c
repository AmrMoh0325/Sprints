/*****************************************************************************
* Task: Thermostat
* File Name: ADC.c
* Description: File for ADC driver functions
* Author: Amr Mohamed
* Date: 26/7/2021
******************************************************************************/

/*- INCLUDES --------------------------------------------------*/
#include "MCAL/ADC/ADC.h"

/*- APIs IMPLEMENTATION --------------------------------------------------*/
/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to initialize ADC according to config
************************************************************************************/
enuErrorStatus_t ADC_Init(void)    
{
	//set ADC scaler
	ADCSRA_R = (ADCSRA_R & 0xF8) | ADC_PRESCALER_CONFIG;
	enuADC_Vref_t Vref=ADC_Vref_SOURCE;
	
	//set Vref mode
	switch(Vref)
	{
		case VREF_AREF:
		CLR_BIT(ADMUX_R,REFS0_B);
		CLR_BIT(ADMUX_R,REFS1_B);
		break;
		
		case VREF_AVCC:
		SET_BIT(ADMUX_R,REFS0_B);
		CLR_BIT(ADMUX_R,REFS1_B);
		break;
		
		case VREF_256:
		SET_BIT(ADMUX_R,REFS0_B);
		SET_BIT(ADMUX_R,REFS1_B);
		break;
	}
	
	//start ADC
	SET_BIT(ADCSRA_R,ADEN_B);
   return SUCCESS;
}


/************************************************************************************
* Parameters (in): enuADC_Channel_t enuChannel,uint16_t *pu16Reading
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to Read ADC channel voltage
************************************************************************************/
enuErrorStatus_t  ADC_Read(enuADC_Channel_t enuChannel,uint16_t *pu16Reading)
{
   //if pointer is invalid
   if (pu16Reading==NULLPTR)
   {
      //return an error
      return ERROR;
   }
	uint16_t u16buffer=0;
   //set ADMUX to select channel
	ADMUX_R= (ADMUX_R & 0xE0) | enuChannel;
   //start conversion
	SET_BIT(ADCSRA_R,ADSC_B);
   //wait for conversion to complete
	while (GET_BIT(ADCSRA_R,ADSC_B));	
   //return value
	u16buffer= ADC_R;
   *pu16Reading=u16buffer;
	return SUCCESS; 	
}


/************************************************************************************
* Parameters (in): enuADC_Channel_t enuChannel,uint8_t *pu8Percent
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to Read ADC channel percentage
************************************************************************************/
enuErrorStatus_t  ADC_Read_Percent(enuADC_Channel_t enuChannel,uint8_t *pu8Percent)
{
	uint16_t ADCVal=0;
   //read ADC value
   enuErrorStatus_t Status=ADC_Read(enuChannel,&ADCVal);
   if (!Status)   return ERROR;
   //calculate the percentage
	uint8_t ADCPercent=((uint32_t)ADCVal*100)/1023;
   //return the percentage
   *pu8Percent=ADCPercent;
	return SUCCESS;
}