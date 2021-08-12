/*****************************************************************************
* Task: Chat Application 
* File Name: main.c
* Description: main file
* Author: Amr Mohamed
* Date: 16/7/2021
******************************************************************************/

 /*- INCLUDES --------------------------------------------------*/
 #include "APP/Chat_APP/APP.h"

/*- APIs IMPLEMENTATION-----------------------------------*/
int main(void)
{
   APP_Init_Master();
   while (1) 
   {
      APP_Update_Master();
   }
}

