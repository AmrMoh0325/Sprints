/*
 * SPI.h
 *
 * Created: 7/15/2021 8:19:29 PM
 *  Author: Amrth
 */   


#ifndef __SPI__
#define __SPI__

#include "DataTypes.h"
#include "MCAL/Register.h"
#include "Utils.h"
#include "MCAL/SPI/SPI_Cfg.h"
#include "MCAL/DIO/DIO.h"
#include "MCAL/DIO/DIO_Cfg.h"



#if (SPI_CONFIG == MASTER)

enuErrorStatus_t SPI_Init(void);
enuErrorStatus_t SPI_SendData(uint8_t u8Data);
enuErrorStatus_t SPI_ReceiveData(uint8_t *pu8Data);

#elif (SPI_CONFIG == SLAVE)

enuErrorStatus_t SPI_Init(void);
enuErrorStatus_t SPI_SendData(uint8_t u8Data);
enuErrorStatus_t SPI_ReceiveData(uint8_t *pu8Data);

#endif

enuErrorStatus_t SPI_SendString(uint8_t *pu8Data);
enuErrorStatus_t SPI_ReceiveString(uint8_t *pu8Data,uint8_t u8bufferMaxSize);


enuErrorStatus_t SPI_Enable_Interrupt(void);
enuErrorStatus_t SPI_Disable_Interrupt(void);
enuErrorStatus_t SPI_SetCallBack(void(*local_fptr)(void));



#endif /* __SPI__ */