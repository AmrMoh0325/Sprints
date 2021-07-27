/*
 * SPI.h
 *
 * Created: 7/15/2021 8:19:29 PM
 *  Author: Amrth
 */   
/*****************************************************************************
* Task: SPI Driver
* File Name: SPI.h
* Description: Header file for SPI driver
* Author: Amr Mohamed
* Date: 8/7/2021
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


/*- API PROTOTYPES --------------------------------------------------*/
#if (SPI_CONFIG == MASTER)

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to initialize SPI in MASTER Mode
************************************************************************************/
enuErrorStatus_t SPI_Init(void);

/************************************************************************************
* Parameters (in): uint8_t u8Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to Send data in MASTER Mode
************************************************************************************/
enuErrorStatus_t SPI_SendData(uint8_t u8Data);

/************************************************************************************
* Parameters (in): uint8_t *pu8Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to Receive data in MASTER Mode
************************************************************************************/
enuErrorStatus_t SPI_ReceiveData(uint8_t *pu8Data);

#elif (SPI_CONFIG == SLAVE)

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to initialize SPI in SLAVE Mode
************************************************************************************/
enuErrorStatus_t SPI_Init(void);

/************************************************************************************
* Parameters (in): uint8_t u8Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to Send data in SLAVE Mode
************************************************************************************/
enuErrorStatus_t SPI_SendData(uint8_t u8Data);

/************************************************************************************
* Parameters (in): uint8_t *pu8Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to Receive data in SLAVE Mode
************************************************************************************/
enuErrorStatus_t SPI_ReceiveData(uint8_t *pu8Data);

#endif

/************************************************************************************
* Parameters (in): uint8_t *pu8Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to Send a string
************************************************************************************/
enuErrorStatus_t SPI_SendString(uint8_t *pu8Data);

 /************************************************************************************
 * Parameters (in): uint8_t *pu8Data ,uint8_t u8bufferMaxSize
 * Parameters (out): enuErrorStatus_t
 * Return value: 1=SUCCESS or 0=FAIL
 * Description: A function to Receive a string
 ************************************************************************************/
enuErrorStatus_t SPI_ReceiveString(uint8_t *pu8Data,uint8_t u8bufferMaxSize);

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to enable SPI interrupt
************************************************************************************/
enuErrorStatus_t SPI_Enable_Interrupt(void);

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to disable SPI interrupt
************************************************************************************/
enuErrorStatus_t SPI_Disable_Interrupt(void);

/************************************************************************************
* Parameters (in): void(*local_fptr)(void)
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to setup SPI interrupt callback
************************************************************************************/
enuErrorStatus_t SPI_SetCallBack(void(*local_fptr)(void));



#endif /* __SPI__ */