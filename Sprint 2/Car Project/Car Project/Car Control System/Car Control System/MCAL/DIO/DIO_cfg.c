/*****************************************************************************
* Task: Car Project
* File Name: DIO_cfg.c
* Description: configuration file for used dio pins
* Author: TEAM2
* Date: 9/7/2021
******************************************************************************/

/*- INCLUDES----------------------------------------------*/
#include "DIO_init.h"


/*- GLOBAL VARIABLES-------------------------------------*/
const strDIOConfigType_t astrDIOConfigParameters[DIO_GROUPS_NO] =
{
	{ PA1, INPUT, PULL_UP_ENABLE },		//BTN0	0
	{ PA2, INPUT, PULL_UP_ENABLE },		//BTN1	1
	{ PA3, INPUT, PULL_UP_ENABLE },		//BTN2	2
	{ PA4, INPUT, PULL_UP_ENABLE },		//BTN3	3
	{ PC1, OUTPUT, NO_CONNECTION },		//LED1	4
	{ PC2, OUTPUT, NO_CONNECTION },		//LED2	5
	{ PC0, OUTPUT, NO_CONNECTION },		//LED0	6
	{ PB0, OUTPUT, NO_CONNECTION },		//DC1_IN1	7
	{ PB1, OUTPUT, NO_CONNECTION },		//DC1_IN2	8
	{ PB3, OUTPUT, NO_CONNECTION },		//OC0_PIN	9
	{ PB4, OUTPUT, NO_CONNECTION },		//DC2_IN1	10
	{ PB5, OUTPUT, NO_CONNECTION }		//DC2_IN2	11
};
