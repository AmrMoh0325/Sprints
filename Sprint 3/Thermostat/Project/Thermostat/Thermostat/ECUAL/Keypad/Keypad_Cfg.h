/*****************************************************************************
* Task: Thermostat
* File Name: Keypad_Cfg.h
* Description: Configuration File for keypad driver
* Author: Amr Mohamed
* Date: 26/7/2021
******************************************************************************/


#ifndef __KEYPAD_CFG__
#define __KEYPAD_CFG__

/*- MACROS --------------------------------------------------*/
//keypad dimensions select
#define  KEYPAD_ROWS    4
#define  KEYPAD_COLS    4

//keypad pins config
#define  KEYPAD_C1		7
#define  KEYPAD_C2		8
#define  KEYPAD_C3		9
#define  KEYPAD_C4		10

#define  KEYPAD_R1		11
#define  KEYPAD_R2		12
#define  KEYPAD_R3		13
#define  KEYPAD_R4		14

//keypad No button pressed value
#define  DEFAULT_KEY		0


/*- GLOBAL VARIABLES --------------------------------------------------*/
//keypad map 
static uint8_t pu8Keys[KEYPAD_ROWS][KEYPAD_COLS]={{'7','8','9','/'},
                                                  {'4','5','6','*'},
                                                  {'1','2','3','-'},
                                                  {'c','0','=','+'}};


#endif /* __KEYPAD_CFG__ */