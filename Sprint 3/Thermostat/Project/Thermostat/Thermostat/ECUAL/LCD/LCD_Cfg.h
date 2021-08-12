/*****************************************************************************
* Task: Thermostat
* File Name: LCD_Cfg.h
* Description: config File for LCD driver 
* Author: Amr Mohamed
* Date: 26/7/2021
******************************************************************************/


#ifndef __LCD_CFG__
#define __LCD_CFG__

/*- MACROS --------------------------------------------------*/
//LCD MODE SELECTION
#define LCD_MODE		4-BIT				//OPERATION MODE	(4-BIT/8-BIT)

//LCD CTRL pins configuration
#define E			1
#define RS			2

#if LCD_MODE==8-BIT

//LCD DATA pins configuration
#define	LCD_PORT	PORTA_R

#elif LCD_MODE==4-BIT

//LCD DATA pins configuration
#define D4	3
#define D5	4
#define D6	5
#define D7	6

#endif

#endif /* __LCD_CFG__ */