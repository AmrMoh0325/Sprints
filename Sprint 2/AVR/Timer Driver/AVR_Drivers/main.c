/*****************************************************************************
* Task: TIMER_DRIVER
* File Name: main.c
* Description: Main file
* Author: Amr Mohamed
* Date: 10/7/2021
******************************************************************************/


#include "Register.h"
#include "DIO.h"
#include "Timer.h"

#define  Button1     PA0
#define  Button2     PB2
#define  LED1        PC7
#define  LED2        PD4

#define BTN1_PRESSED 0
#define BTN2_PRESSED 1


//Testing Application


//test funtion to toggle two leds 
void led_Toggle(void)
{
   DIO_Toggle(LED1);
   DIO_Toggle(LED2);
}


int main(void)
{
   uint8_t u8button1_flag=0,u8button2_flag=0;
   //initialize DIO
   DIO_Init();
   //set initial values of LEDs
   DIO_Write(LED1,0);
   DIO_Write(LED2,1);
   //initialize timer 0
   T0_Init(TIMER0_NORMAL_MODE,TIMER0_SCALER_8);
   //enable global interrupts
   sei();
   while(1)
   {
      //read the states of both buttons
      DIO_Read(Button1,&u8button1_flag);
      DIO_Read(Button2,&u8button2_flag);
      
      //if button 1 is pressed
      if (u8button1_flag==BTN1_PRESSED)
      {
         //Enable Timer overflow interrupt
         T0_OV_InterruptEnable();
         //set up the delay function using timer
         T0_Start(1000000,led_Toggle);
         //loop on the button until it is released
         while (u8button1_flag==BTN1_PRESSED)
         {
            DIO_Read(Button1,&u8button1_flag);
         }
      }
      //if button 2 is pressed
      if (u8button2_flag==BTN2_PRESSED)
      {
         //stop the timer set up on the button
         T0_Stop();
         //loop on the button until it is released
         while (u8button2_flag==BTN2_PRESSED)
         {
            DIO_Read(Button2,&u8button2_flag);
         }
      }      
   }   
}

/*
 //test without interrupt
int main(void)
{
   volatile uint8_t T_Flag=0;
   //Initialize DIO
   DIO_Init();
   //Initialize timer 0
   T0_Init(TIMER0_NORMAL_MODE,TIMER0_SCALER_8);
   //start a delay of 1000 micro seconds
   T0_Start(1000,NULLPTR);
   while(1)
   {
      //keep checking if the timer's time is up
      T_Flag=T0_GetStatus();
      //if it's up
      if (T_Flag)
      {
       //toggle the leds
         led_Toggle();
         //and start another delay
         T0_Start(1000,NULLPTR);
      }      
   }
}*/