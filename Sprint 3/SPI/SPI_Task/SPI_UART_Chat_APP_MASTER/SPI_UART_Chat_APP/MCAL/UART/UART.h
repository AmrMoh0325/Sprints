/*****************************************************************************
* Task: UART Driver
* File Name: UART.h
* Description: header file for atmega32 UART driver
* Author: Amr Mohamed
* Date: 14/7/2021
******************************************************************************/


#ifndef __UART__
#define __UART__

#include "DataTypes.h"
#include "MCAL/Register.h"
#include "Utils.h"
#include "MCAL/UART/UART_Cfg.h"


/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to initialize UART peripheral according to the configuration
************************************************************************************/
enuErrorStatus_t UART_Init(void);

/************************************************************************************
* Parameters (in): uint16_t* pu16Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to recieve a value from uart module and store it in the provided variable
************************************************************************************/
enuErrorStatus_t UART_ReceiveData(uint16_t* pu16Data);

/************************************************************************************
* Parameters (in): uint16_t u16Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to send the provided value using uart
************************************************************************************/
enuErrorStatus_t UART_SendData(uint16_t u16Data);

/************************************************************************************
* Parameters (in): uint16_t* pu16Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to receive data from uart module without waiting for transmission to complete
************************************************************************************/
enuErrorStatus_t UART_RecieveDataNoBLOCK(uint16_t* pu16Data);

/************************************************************************************
* Parameters (in): uint16_t u16Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to send provided data to uart module without waiting for transmission to complete
************************************************************************************/
enuErrorStatus_t UART_SendDataNoBLOCK(uint16_t u16Data);

/************************************************************************************
* Parameters (in): uint8_t* pu8String, uint8_t u8bufferMaxSize
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to receive a string using uart
************************************************************************************/
enuErrorStatus_t UART_ReceiveString(uint8_t* pu8String, uint8_t u8bufferMaxSize);

/************************************************************************************
* Parameters (in): uint8_t* pu8String
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to send a string using uart
************************************************************************************/
enuErrorStatus_t UART_SendString(uint8_t* pu8String);


/*
enuErrorStatus_t UART_TX_Enable_Interrupt(void);
enuErrorStatus_t UART_TX_Disable_Interrupt(void);
enuErrorStatus_t UART_TX_SetCallBack(void(*local_fptr)(void));

enuErrorStatus_t UART_RX_Enable_Interrupt(void);
enuErrorStatus_t UART_RX_Disable_Interrupt(void);
enuErrorStatus_t UART_RX_SetCallBack(void(*local_fptr)(void));
*/


#endif /* __UART__ */