/*****************************************************************************
* Task: DIO Driver
* File Name: DIO_Cfg.h
* Description: Configuration file for atmega32 UART driver
* Author: Amr Mohamed
* Date: 8/7/2021
******************************************************************************/


#ifndef __DIO_CFG__
#define __DIO_CFG__

 /*- MACROS --------------------------------------------------*/
#define DIO_GROUPS_NO							16u

/*- ENUMS --------------------------------------------------*/
//names of the connected devices in the same order as in the array
typedef enum{ADC_LM35,LCD_EN,LCD_RS,LCD_D4,LCD_D5,LCD_D6,LCD_D7,
             }enuPinConfig_t;


#endif /* __DIO_CFG__ */