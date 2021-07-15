/*****************************************************************************
* Task: Traffic Light
* File Name: main.c
* Description: main application
* Author: Amr Mohamed
* Date: 15/7/2021
******************************************************************************/ 

#include "APP/Traffic_Light/Traffic.h"



int main(void)
{
   Traffic_Init();
   while (1) 
   {
      Traffic_Update();
   }
}

