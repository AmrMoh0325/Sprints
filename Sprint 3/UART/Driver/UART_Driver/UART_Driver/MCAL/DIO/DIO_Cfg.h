/*****************************************************************************
* Task: DIO Driver
* File Name: DIO_Cfg.h
* Description: Configuration file for atmega32 UART driver
* Author: Amr Mohamed
* Date: 8/7/2021
******************************************************************************/


#ifndef __DIO_CFG__
#define __DIO_CFG__


#define DIO_GROUPS_NO							3u

//names of the connected devices in the same order as in the array
typedef enum{Green,Yellow,Red}enuPinConfig_t;


#endif /* __DIO_CFG__ */