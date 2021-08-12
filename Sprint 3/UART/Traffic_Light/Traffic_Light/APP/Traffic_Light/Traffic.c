/*****************************************************************************
* Task: Traffic Light
* File Name: Traffic.c
* Description: source file for Traffic light application
* Author: Amr Mohamed
* Date: 15/7/2021
******************************************************************************/

 /*- INCLUDES --------------------------------------------------*/
#include "APP/Traffic_Light/Traffic.h"

/*- GLOBAL VARIABLES --------------------------------------------------*/
uint8_t UART_buffer[10]={0};
   
/*- APIs IMPLEMENTATION-----------------------------------*/
/************************************************************************************
* Parameters (in): uint8_t *str1,uint8_t *str2
* Parameters (out): sint8_t
* Return value: -1= First>Second    ||    0=Strings are identical   ||   1= First<Second
* Description: A function to check if two strings are identical or not
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
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to make necessary initializations for the application
************************************************************************************/
enuErrorStatus_t Traffic_Init(void)
{
   //initialize LEDS
   uint8_t Flag1=LED_Init();
   //Initialize UART
   uint8_t Flag2=UART_Init();
   if (Flag1 && Flag2)  return SUCCESS;
   return(ERROR);
}


/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to update the state of the application
************************************************************************************/
enuErrorStatus_t Traffic_Update(void)
{
   //recieve uart input
   UART_ReceiveString(UART_buffer,10);
   //if received data = START
   if (String_compare(UART_buffer,(uint8_t *)"START")==0)
   {
      //turn on green led and turn off the rest
      LED_ON(Green);
      LED_OFF(Yellow);
      LED_OFF(Red);
      //show up feedback to the user
      UART_SendString((uint8_t *)"Green LED is on\n");
   }
   //if received data = WAIT
   else if (String_compare(UART_buffer,(uint8_t *)"WAIT")==0)
   {
      //turn on yellow led and turn off the rest
      LED_OFF(Green);
      LED_ON(Yellow);
      LED_OFF(Red);
      //show up feedback to the user
      UART_SendString((uint8_t *)"YELLOW LED is on\n");
   }
   //if received data = STOP
   else if (String_compare(UART_buffer,(uint8_t *)"STOP")==0)
   {
      //turn on red led and turn off the rest
      LED_OFF(Green);
      LED_OFF(Yellow);
      LED_ON(Red);
      //show up feedback to the user
      UART_SendString((uint8_t *)"RED LED is on\n");
   }
   //if received data = AT
   else if (String_compare(UART_buffer,(uint8_t *)"AT")==0)
   {
      //show up acknowledgment message
      UART_SendString((uint8_t *)"OK\n");
   }
   else
   {
      return ERROR;
   }
   return SUCCESS;
}