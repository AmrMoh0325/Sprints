/*****************************************************************************
* Task: EEPROM Task
* File Name: APP.c
* Description: functions for EEPROM Application
* Author: Amr Mohamed
* Date: 25/7/2021
******************************************************************************/

/*- INCLUDES --------------------------------------------------*/
#include "APP/EEPROM_APP/APP.h"


/*- APIs IMPLEMENTATION-----------------------------------*/
/************************************************************************************
* Parameters (in): uint8_t *string 1    ,    uint8_t * string 2
* Parameters (out): sint8_t
* Return value: 0= strings are identical ,  1= str1>str2  ,  -1= str1<str2
* Description: A function to compare string 1 with string 2 and check if they are identical 
************************************************************************************/
static sint8_t String_compare(uint8_t *str1,uint8_t *str2)
{
   uint16_t u16i;
   //Traverse both strings
   for(u16i=0;str1[u16i] || str2[u16i];u16i++)
   {
      // look for any difference
      if      (str1[u16i] < str2[u16i])     return -1;
      else if (str1[u16i] > str2[u16i])     return 1;
   }
   return 0;
}


/************************************************************************************
* Parameters (in): void
* Parameters (out): void
* Return value: void
* Description: A function to initialize application peripherals and devices
************************************************************************************/
void APP_Init(void)
{
     //initialize uart
     UART_Init();
     //initiialize EEPROM
     EEPROM_Init();
}


/************************************************************************************
* Parameters (in): void
* Parameters (out): void
* Return value: void
* Description: A function to update the application status
************************************************************************************/
void APP_Update(void)
{
   static uint16_t u8Data=0,Flag=0;
   static uint32_t u16Address=0;
   static uint8_t pu8uart_buf[10]={0};
   static enuI2CMode_t Operation=Read;
   //check the current flag status
   switch (Flag)
   {
      case 0:  //starting operation
      //receive READ or WRITE from the user
      UART_SendString((uint8_t *)"\rOPERATION: ");
      UART_ReceiveString(pu8uart_buf,10);
      //if user input a valid input
      if (String_compare(pu8uart_buf,(uint8_t *)"READ")==0)
      {
         //store user input
         Operation=Read;
         //change stage flag
         Flag=1;
      }
      else if (String_compare(pu8uart_buf,(uint8_t *)"WRITE")==0)
      {
         //store user input
         Operation=Write;
         //change stage flag
         Flag=1;
      }
      else
      {
         //if user input is invalid return an error
         UART_SendString((uint8_t *)"ERROR\r");
      }
      break;
      
      case 1:
      //receive location address from user
      UART_SendString((uint8_t *)"ADRESS: 0X");
      UART_ReceiveHex(&u16Address);
      //if user input is within EEPROM range
      if (u16Address>=0 && u16Address<2048)
      {
         //send an OK status
         UART_SendString((uint8_t *)"OK\r");
         if (Operation == Read)
         {
            //if the operation mode is read, go to read operation
            Flag=2;
         }
         else
         {
            //if the operation mode is write, go to write operation
            Flag=3;
         }
      }
      else
      {
         //else send an error and return to original state
         UART_SendString((uint8_t *)"ERROR\r");
         Flag=0;
      }
      break;
      
      case 2:
      //in case of read operation
      UART_SendString((uint8_t *)"Data in address: ");
      //get the data stored in the position the user selected
      EEPROM_ReadByte(u16Address,(uint8_t *)&u8Data);
      //send the data to the user
      UART_SendData(u8Data);
      UART_SendData('\r');
      //return to original state
      Flag = 0;
      break;
      
      case 3:
      //in case of write operation
      UART_SendString((uint8_t *)"Data: ");
      //get the new data value from the user
      UART_ReceiveData(&u8Data);
      //write the new data to the position the user selected
      EEPROM_WriteByte(u16Address,u8Data);
      UART_SendData('\n');
      //return an OK status
      UART_SendString((uint8_t *)"\rOK\r");
      //return to original state
      Flag = 0;
      break;
   }
}