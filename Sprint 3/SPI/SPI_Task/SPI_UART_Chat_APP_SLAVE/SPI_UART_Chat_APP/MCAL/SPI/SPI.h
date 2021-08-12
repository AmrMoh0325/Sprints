/*****************************************************************************
* Task: SPI Driver
* File Name: SPI.h
* Description: header file for the the SPI driver
* Author: Amr Mohamed
* Date: 16/7/2021
******************************************************************************/  


#ifndef __SPI__
#define __SPI__

 /*- INCLUDES --------------------------------------------------*/
#include "DataTypes.h"
#include "MCAL/Register.h"
#include "Utils.h"
#include "MCAL/SPI/SPI_Cfg.h"
#include "MCAL/DIO/DIO.h"
#include "MCAL/DIO/DIO_Cfg.h"


/*- APIs PROTOTYPES-----------------------------------*/
#if (SPI_CONFIG == MASTER)

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to initialize SPI peripheral for master device
************************************************************************************/
enuErrorStatus_t SPI_Init(void);

/************************************************************************************
* Parameters (in): uint16_t u16Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to send the provided value using SPI
************************************************************************************/
enuErrorStatus_t SPI_SendData(uint8_t u8Data);

/************************************************************************************
* Parameters (in): uint16_t* pu16Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to recieve a value from SPI module and store it in the provided variable
************************************************************************************/
enuErrorStatus_t SPI_ReceiveData(uint8_t *pu8Data);

#elif (SPI_CONFIG == SLAVE)

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to initialize SPI peripheral for slave device
************************************************************************************/
enuErrorStatus_t SPI_Init(void);

/************************************************************************************
* Parameters (in): uint16_t u16Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to send the provided value using SPI
************************************************************************************/
enuErrorStatus_t SPI_SendData(uint8_t u8Data);

/************************************************************************************
* Parameters (in): uint16_t* pu16Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to recieve a value from SPI module and store it in the provided variable
************************************************************************************/
enuErrorStatus_t SPI_ReceiveData(uint8_t *pu8Data);

#endif

/************************************************************************************
* Parameters (in): uint8_t* pu8String
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to send a string using SPI
************************************************************************************/
enuErrorStatus_t SPI_SendString(uint8_t *pu8Data);

/************************************************************************************
* Parameters (in): uint8_t* pu8String, uint8_t u8bufferMaxSize
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to receive a string using SPI
************************************************************************************/
enuErrorStatus_t SPI_ReceiveString(uint8_t *pu8Data,uint8_t u8bufferMaxSize);


/**************************************** PREPARED APIs FOR FUTURE USE ******************************************/

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to enable SPI interrupt for transmission complete
************************************************************************************/
enuErrorStatus_t SPI_Enable_Interrupt(void);

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to disable SPI interrupt for transmission complete
************************************************************************************/
enuErrorStatus_t SPI_Disable_Interrupt(void);

/************************************************************************************
* Parameters (in): void(*local_fptr)(void)
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to setup callback function for SPI transmission complete interrupt
************************************************************************************/
enuErrorStatus_t SPI_SetCallBack(void(*local_fptr)(void));



#endif /* __SPI__ */