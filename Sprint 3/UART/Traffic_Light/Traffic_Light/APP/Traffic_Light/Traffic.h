/*****************************************************************************
* Task: Traffic Light
* File Name: Traffic.h
* Description: header file for Traffic light application
* Author: Amr Mohamed
* Date: 15/7/2021
******************************************************************************/


#ifndef __TRAFFIC__
#define __TRAFFIC__

#include "DataTypes.h"
#include "MCAL/DIO/DIO.h"
#include "MCAL/UART/UART.h"
#include "ECUAL/LED/LED.h"

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to make necessary initializations for the application
************************************************************************************/
enuErrorStatus_t Traffic_Init(void);

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to update the state of the application
************************************************************************************/
enuErrorStatus_t Traffic_Update(void);


#endif /* __TRAFFIC__ */