/*****************************************************************************
* Task: UART Driver
* File Name: UART.h
* Description: header file for atmega32 UART driver
* Author: Amr Mohamed
* Date: 14/7/2021
******************************************************************************/


#ifndef __UART__
#define __UART__

 /*- INCLUDES --------------------------------------------------*/
#include "DataTypes.h"
#include "MCAL/Register.h"
#include "Utils.h"
#include "MCAL/UART/UART_Cfg.h"

/*- APIs PROTOTYPES-----------------------------------*/
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

/************************************************************************************
* Parameters (in): uint32_t * pu32Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to receive a HEX number from uart
************************************************************************************/
enuErrorStatus_t UART_ReceiveHex(uint32_t * pu32Data);

/**************************************** PREPARED APIs FOR FUTURE USE ******************************************/

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to enable uart interrupt for TX complete
************************************************************************************/
enuErrorStatus_t UART_TX_Enable_Interrupt(void);

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to disable uart interrupt for TX complete
************************************************************************************/
enuErrorStatus_t UART_TX_Disable_Interrupt(void);

/************************************************************************************
* Parameters (in): void(*local_fptr)(void)
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to setup callback function for TX complete interrupt
************************************************************************************/
enuErrorStatus_t UART_TX_SetCallBack(void(*local_fptr)(void));

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to enable uart interrupt for RX complete
************************************************************************************/
enuErrorStatus_t UART_RX_Enable_Interrupt(void);

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to disable uart interrupt for RX complete
************************************************************************************/
enuErrorStatus_t UART_RX_Disable_Interrupt(void);

/************************************************************************************
* Parameters (in): void(*local_fptr)(void)
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to setup callback function for RX complete interrupt
************************************************************************************/
enuErrorStatus_t UART_RX_SetCallBack(void(*local_fptr)(void));





#endif /* __UART__ */