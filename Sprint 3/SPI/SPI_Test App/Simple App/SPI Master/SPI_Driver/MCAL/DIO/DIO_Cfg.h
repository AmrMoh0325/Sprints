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
#define DIO_GROUPS_NO							5u

/*- ENUMS --------------------------------------------------*/
typedef enum{SPI_SS0,SPI_MOSI,SPI_MISO,SPI_SCK,test}enuPinConfig_t;


#endif /* __DIO_CFG__ */