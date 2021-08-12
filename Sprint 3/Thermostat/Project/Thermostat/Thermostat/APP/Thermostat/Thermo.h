/*****************************************************************************
* Task: Thermostat
* File Name: Thermo.h
* Description: header File for Thermostat application
* Author: Amr Mohamed
* Date: 26/7/2021
******************************************************************************/


#ifndef __THERMO__
#define __THERMO__

/*- INCLUDES --------------------------------------------------*/
#include "MCAL/DIO/DIO.h"
#include "ECUAL/Sensor/Sensor.h"
#include "ECUAL/LCD/LCD.h"
#include "ECUAL/Keypad/Keypad.h"
#include "ECUAL/Motor/Motor.h"

/*- APIs PROTOTYPES-----------------------------------*/

/************************************************************************************
* Parameters (in): void
* Parameters (out): void
* Return value: void
* Description: A function to initialize application peripherals and devices
************************************************************************************/
void Thermo_Init(void);

/************************************************************************************
* Parameters (in): void
* Parameters (out): void
* Return value: void
* Description: A function to update the application status
************************************************************************************/
void Thermo_Update(void);


#endif /* __THERMO__ */