/*
 * AVR_Drivers.c
 *
 * Created: 7/7/2021 8:22:53 PM
 * Author : Amrth
 */ 
#define  F_CPU    8000000UL

#include "Register.h"
#include "DIO.h"

#define  Button1     PA0
#define  Button2     PB2
#define  LED1        PD4
#define  LED2        PC7

#define BTN1_PRESSED 0
#define BTN2_PRESSED 1


//Testing Application
int main(void)
{
   uint8_t u8state=0,u8var1=0,u8var2=0;
   //initialize according to the DIO_Cfg file
   u8state=DIO_Init();
   
   //if process failed, exit
   if(u8state==0)    return 0;

   while (1) 
   {
      //read values of both button
      u8state=DIO_Read(Button1,&u8var1);
      u8state=DIO_Read(Button2,&u8var2);
      
      //if successful
      if(u8state)
      {
         //if button 1 is pressed
         if (u8var1 == BTN1_PRESSED)
         {
            //toggle led 1
            DIO_Toggle(LED1);
            //loop on button 1 until it is released
            while(u8var1 == BTN1_PRESSED)
            {
               //keep reading the button value
               DIO_Read(Button1,&u8var1);
            }
         } 
         //if button 2 is pressed
         if (u8var2 == BTN2_PRESSED)
         {
            //toggle led 2
            DIO_Toggle(LED2);
            //loop on button 2 until it is released
            while(u8var2 == BTN2_PRESSED)
            {
               //keep reading the button value
               DIO_Read(Button2,&u8var2);
            }
         }
     }
   }
}

