/*****************************************************************************
* Task: Thermostat
* File Name: Thermo.c
* Description: File for Thermostat application functions
* Author: Amr Mohamed
* Date: 26/7/2021
******************************************************************************/

/*- INCLUDES --------------------------------------------------*/
#include "APP/Thermostat/Thermo.h"

/*- MACROS --------------------------------------------------*/
#define TEMP_TOLERANCE     2
#define DEFAULT_TEMP       25


/*- APIs IMPLEMENTATION --------------------------------------------------*/
/************************************************************************************
* Parameters (in): void
* Parameters (out): void
* Return value: void
* Description: A function to initialize application peripherals and devices
************************************************************************************/
void Thermo_Init(void)
{
   DIO_Init();
   Sensor_Init();
   LCD_Init();
   
   LCD_WriteStringXY((uint8_t *)"CT:     TT:     ",0,0);
   LCD_WriteStringXY((uint8_t *)"USER Temp:      ",1,0);
}


/************************************************************************************
* Parameters (in): void
* Parameters (out): void
* Return value: void
* Description: A function to update the application status
************************************************************************************/
void Thermo_Update(void)
{
   static uint8_t u8stage=0;
   static uint8_t u8CurrentTemp=0;
   static uint8_t u8TargetTemp=DEFAULT_TEMP;
   static uint8_t u8TempBuffer=0;
   static uint8_t u8KeypadInput=0;
   static uint8_t u8FanFlag=0;
   
   //switch on the stage 
   switch(u8stage)
   {
      case 0:    //update Temp readings
      //get current temp from LM35
      LM35_GetTemperature(&u8CurrentTemp);
      //get target temp from user
      if (Keypad_GetKey(&u8KeypadInput))
      {
         if (u8KeypadInput>='0' && u8KeypadInput<='9')
         {
            u8TempBuffer*=10;
            u8TempBuffer+=(u8KeypadInput-'0');
         }
         else if (u8KeypadInput== '=')
         {
            u8TargetTemp=u8TempBuffer;
            u8TempBuffer=0;
            u8KeypadInput=0;
         }
      }
      //move to next stage
      u8stage=1;
      break;
      
      case 1:    //update motors
      //if current temp is too high and fan is not working
      if ((u8CurrentTemp>(u8TargetTemp+TEMP_TOLERANCE)) && u8FanFlag==0)
      {
         //start the fan
         u8FanFlag=1;
         MotorStart(Fan);
      }
      //if current temp is too low and fan is working
      else if ((u8CurrentTemp<=(u8TargetTemp-TEMP_TOLERANCE)) && u8FanFlag==1 )
      {
         //stop the fan
         u8FanFlag=0;
         MotorStop(Fan);
      }
      //move to next stage
      u8stage=2;
      break;
      
      case 2:    //update start screen
      //display all application parameters on screen
      LCD_WriteNumXY(u8CurrentTemp,0,4);
      LCD_WriteChar(' ');
      LCD_WriteNumXY(u8TargetTemp,0,11);
      LCD_WriteChar(' ');
      if(u8KeypadInput>0)     LCD_WriteNumXY(u8TempBuffer,1,11);
      LCD_WriteChar(' ');
      //move to first stage
      u8stage=0;
      break;
   }
}