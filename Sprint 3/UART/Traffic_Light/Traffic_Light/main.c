/*
 * Traffic_Light.c
 *
 * Created: 7/15/2021 5:57:07 AM
 * Author : Amrth
 */ 

#include "DataTypes.h"
#include "DIO.h"
#include "UART.h"

uint16_t String_length(uint8_t *str)
{
   uint16_t u16i;
   for (u16i=0;str[u16i];u16i++);
   return u16i;
}

sint8_t String_compare(uint8_t *str1,uint8_t *str2)
{
   uint16_t u16i;
   for(u16i=0;str1[u16i] || str2[u16i];u16i++)
   {
      if      (str1[u16i] < str2[u16i])     return -1;
      else if (str1[u16i] > str2[u16i])     return 1;
   }
   return 0;
}

int main(void)
{
   DIO_Init();
   UART_Init();
   uint8_t UART_buffer[10]={0};
   while (1) 
   {
      UART_ReceiveString(UART_buffer);
      if (String_compare(UART_buffer,(uint8_t *)"GREEN")==0)
      {
         DIO_Write(Green,HIGH);
         DIO_Write(Yellow,LOW);
         DIO_Write(Red,LOW);
         UART_SendString((uint8_t *)"Green LED is on\n");
      }
      else if (String_compare(UART_buffer,(uint8_t *)"YELLOW")==0)
      {
         DIO_Write(Green,LOW);
         DIO_Write(Yellow,HIGH);
         DIO_Write(Red,LOW);
         UART_SendString((uint8_t *)"YELLOW LED is on\n");
      }
      else if (String_compare(UART_buffer,(uint8_t *)"RED")==0)
      {
         DIO_Write(Green,LOW);
         DIO_Write(Yellow,LOW);
         DIO_Write(Red,HIGH);
         UART_SendString((uint8_t *)"RED LED is on\n");
      }
      else if (String_compare(UART_buffer,(uint8_t *)"AT")==0)
      {
         UART_SendString((uint8_t *)"OK\n");
      }
      
   }
}

