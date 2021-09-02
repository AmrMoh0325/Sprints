/*
 * BCM.h
 *
 *  Created on: Aug 26, 2021
 *      Author: Kariman
 */

#ifndef BCM_BCM_H_
#define BCM_BCM_H_

#include "BIT_MANIPULATE.h"
#include "STD_TYPES.h"
#include "DIO_init.h"

typedef void (*pfTaskCompleteNotify_t) (void);

typedef enum {
	BCM_UART_CHANNEL,
	BCM_SPI_CHANNEL,
	BCM_I2C_CHANNEL
}enuBCMChannel_t;

typedef enum {
	BCM_TX,
	BCM_RX,
	BCM_TX_RX
}enuBCMMode_t;


typedef enum {
	BCM_ID,
	DEVICE_ID
}enuBCMCommand_t;

typedef struct {
	enuBCMChannel_t enuBCMChannel;
	enuBCMMode_t    enuBCMMode;
}strBCMCfg_t;

typedef struct {
	enuBCMCommand_t		   enuBCMCommand;
	uint16_t 			   u16Size;
	uint8_t*			   pu8DataBuffer;
	uint64_t			   u64CheckSum;
	pfTaskCompleteNotify_t pfTaskCompleteNotify;
	enuBCMChannel_t 	   enuBCMChannel;
	enuBCMMode_t           enuBCMMode;
}strBCMTaskCfg_t;

enuErrorStatus_t BCM_Init(strBCMCfg_t *strBCMCfg);

enuErrorStatus_t BCM_Setup(strBCMTaskCfg_t *strBCMTaskCfg);

enuErrorStatus_t BCM_RxDispatcher(void);

enuErrorStatus_t BCM_TxDispatcher(void);


void init (void);

#endif /* BCM_BCM_H_ */
