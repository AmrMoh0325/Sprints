/*
 * SPI.h
 *
 * Created: 7/14/2021 10:29:13 AM
 *  Author: Amrth
 */ 


#ifndef __SPI__
#define __SPI__

#include "DataTypes.h"
#include "Register.h"
#include "Utils.h"
#include "DIO.h"
#include "SPI_Cfg.h"

#if (SPI_CONFIG == MASTER)

enuErrorStatus_t SPI_Init(void);
enuErrorStatus_t SPI_Send_Char(uint8_t u8Data);
enuErrorStatus_t SPI_Recieve_Char(uint8_t *pu8Data);

#elif (SPI_CONFIG == SLAVE)

enuErrorStatus_t SPI_Init(void);
enuErrorStatus_t SPI_Send_Char(uint8_t u8Data);
enuErrorStatus_t SPI_Recieve_Char(uint8_t *pu8Data)

#endif

enuErrorStatus_t SPI_Send_Str(uint8_t *strData);
enuErrorStatus_t SPI_Recieve_Str(uint8_t *pstrData);


enuErrorStatus_t SPI_Enable_Interrupt(void);
enuErrorStatus_t SPI_Disable_Interrupt(void);
enuErrorStatus_t SPI_SetCallBack(void(*local_fptr)(void));


#endif /* __SPI__ */