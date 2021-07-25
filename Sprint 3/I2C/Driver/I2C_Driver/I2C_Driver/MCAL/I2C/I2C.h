/*
 * I2C.h
 *
 * Created: 7/20/2021 1:04:59 PM
 *  Author: Amrth
 */ 


#ifndef __I2C__
#define __I2C__

#include "DataTypes.h"
#include "Utils.h"
#include "MCAL/Register.h"
#include "MCAL/I2C/I2C_Cfg.h"

typedef enum{
   ACK,
   NACK
   }enuI2CAck_t;
   
  
enuErrorStatus_t I2C_Init(void);
enuErrorStatus_t I2C_Start(void);
enuErrorStatus_t I2C_Repeated_Start(void);
enuErrorStatus_t I2C_Stop(void);

enuErrorStatus_t I2C_MASTER_SendData(uint8_t u8SlaveAddress,uint8_t u8Data);
enuErrorStatus_t I2C_MASTER_RecieveData(uint8_t u8SlaveAddress,uint8_t  *pu8Data);
enuErrorStatus_t I2C_SLAVE_SendData(uint8_t u8Data);
enuErrorStatus_t I2C_SLAVE_ReceiveData(uint8_t *pu8Data);

enuErrorStatus_t I2C_SendString(uint8_t *pu8Data);
enuErrorStatus_t I2C_ReceiveString(uint8_t *pu8Data,uint8_t u8bufferMaxSize);
                 
enuErrorStatus_t I2C_Enable_Interrupt(void);
enuErrorStatus_t I2C_Disable_Interrupt(void);
enuErrorStatus_t I2C_SetCallBack(void(*local_fptr)(void));



#endif /* __I2C__ */