/*****************************************************************************
* Task: Traffic Light
* File Name: main.c
* Description: main application
* Author: Amr Mohamed
* Date: 15/7/2021
******************************************************************************/ 

/* INCLUDES ------------------------------------------------------------*/
#include "APP/Traffic_Light/Traffic.h"


/* API IMPLEMENTATION -------------------------------------------------- */
int main(void)
{
   //call initialization function
   Traffic_Init();
   while (1) 
   {
      //update the state of the system depending on user input
      Traffic_Update();
   }
}

