/*****************************************************************************
* Task: UART Driver
* File Name: UART_Cfg.h
* Description: Configuration file for atmega32 UART driver 
* Author: Amr Mohamed
* Date: 14/7/2021
******************************************************************************/

#ifndef __UART_CFG__
#define __UART_CFG__

/*- MACROS --------------------------------------------------*/
#define UART_BAUDRATE         9600

#define UART_DATA_BITS        8        /* 5, 6, 7, 8, or 9 */

#define UART_PARITY_BIT       2        /* 0=OFF  1=ODD  2=EVEN */

#define UART_STOP_BITS        1        /* 1 or 2 */



#endif /* __UART_CFG__ */