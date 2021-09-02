/*
 * BCM.c
 *
 *  Created on: Aug 26, 2021
 *      Author: Kariman
 */
#include "BCM.h"
#include "UART.h"
#include "SPI.h"
#include "I2C.h"

typedef enum {
	BCM_STATE_IDLE,
	BCM_STATE_RXCMD,
	BCM_STATE_RXSIZE,
	BCM_STATE_RXDATA,
	BCM_STATE_RXCS,
	BCM_STATE_FINISHED,
	BCM_STATE_ERROR
}enuBCMStateMachine_t;

typedef struct{
	strBCMTaskCfg_t*	     strBCMTaskCfg;
	uint16_t			        u16ByteCounter;
	enuBCMStateMachine_t   enuBCMStateMachine;
}strBCMPacket_t;

static strBCMPacket_t gstrBCMPacket;
static uint16_t gu16RxBuffer=LOW;
static uint8_t gu8RxFlag=LOW;
static uint8_t gu8BCMInitState = LOW;
static uint64_t gu64LocalCheckSum=LOW;
static uint16_t u16RxSize=LOW;

static void BCM_RxHandler(void);



enuErrorStatus_t BCM_Init(strBCMCfg_t *strBCMCfg)
{
	enuErrorStatus_t enuErrorStatus;

	if(strBCMCfg==NULLPTR)
	{
		enuErrorStatus = E_ERROR;
	}
	else
	{
		switch(strBCMCfg->enuBCMChannel)
		{
			case BCM_UART_CHANNEL:
				UART_Init();
				UART_RX_Enable_Interrupt();
				sei();
				UART_RX_SetCallBack(BCM_RxHandler);
				enuErrorStatus = E_OK;
				break;
			case BCM_SPI_CHANNEL:
				switch(strBCMCfg->enuBCMMode)
				{
					case BCM_TX:
						SPI_initMaster();
						enuErrorStatus = E_OK;
						break;
					case BCM_RX:
						SPI_initSlave();
						enuErrorStatus = E_OK;
						break;
					case BCM_TX_RX:
						enuErrorStatus = E_OK;
						break;
					default:
						enuErrorStatus = E_ERROR;
				}
				break;
			case BCM_I2C_CHANNEL:
				TWI_init();
				enuErrorStatus = E_OK;
				break;
			default:
				enuErrorStatus = E_ERROR;
		}
	}
	gu8BCMInitState = HIGH;

	return enuErrorStatus;
}



enuErrorStatus_t BCM_Setup(strBCMTaskCfg_t *pstrBCMTaskCfg)
{
	enuErrorStatus_t enuErrorStatus;

	if((pstrBCMTaskCfg==NULLPTR) || (gu8BCMInitState==LOW))
	{
		enuErrorStatus = E_ERROR;
	}
	else
	{
      gstrBCMPacket.strBCMTaskCfg=pstrBCMTaskCfg;
 		gstrBCMPacket.enuBCMStateMachine = BCM_STATE_IDLE;
		gstrBCMPacket.u16ByteCounter = 0;
		enuErrorStatus = E_OK;
	}
	return enuErrorStatus;
}


enuErrorStatus_t BCM_RxDispatcher(void)
{
	enuErrorStatus_t enuErrorStatus= E_ERROR;

	if((gu8BCMInitState == LOW) && (gstrBCMPacket.strBCMTaskCfg->enuBCMMode == BCM_TX))
	{
		enuErrorStatus = E_ERROR;
	}
	else
	{
		if(gu8RxFlag == HIGH)
		{
			switch(gstrBCMPacket.enuBCMStateMachine)
			{
				case BCM_STATE_IDLE:
					/* ISR will change state to BCM_STATE_RXBYTE */
					enuErrorStatus = E_OK;
					break;
				case BCM_STATE_RXCMD:
					gstrBCMPacket.strBCMTaskCfg->enuBCMCommand = (uint8_t)(gu16RxBuffer - '0');
					if (gstrBCMPacket.strBCMTaskCfg->enuBCMCommand == BCM_ID)
					{
						gstrBCMPacket.enuBCMStateMachine = BCM_STATE_RXSIZE;
						enuErrorStatus = E_OK;
					}
					else
					{
						gstrBCMPacket.enuBCMStateMachine = BCM_STATE_ERROR;
						enuErrorStatus = E_ERROR;
					}
					break;
				case BCM_STATE_RXSIZE:
					if (gstrBCMPacket.u16ByteCounter == 0)
					{
						u16RxSize = (uint8_t)(gu16RxBuffer - '0');
						gstrBCMPacket.u16ByteCounter++;
					}
					else
					{
						u16RxSize <<=8;
						u16RxSize |= (uint8_t)(gu16RxBuffer - '0');
                  gstrBCMPacket.u16ByteCounter=0;
                  if (u16RxSize<=gstrBCMPacket.strBCMTaskCfg->u16Size)
                  {
                     gstrBCMPacket.enuBCMStateMachine= BCM_STATE_RXDATA;
                     enuErrorStatus = E_OK;
                  }
                  else
                  {
                     gstrBCMPacket.enuBCMStateMachine= BCM_STATE_ERROR;
                     enuErrorStatus = E_ERROR;
                  }
					}
					break;
               
				case BCM_STATE_RXDATA:
               
               DIO_Write(0, HIGH);
					if (gstrBCMPacket.u16ByteCounter < (u16RxSize - 1))
					{
						gstrBCMPacket.strBCMTaskCfg->pu8DataBuffer[gstrBCMPacket.u16ByteCounter]=(uint8_t)gu16RxBuffer;
						gstrBCMPacket.u16ByteCounter++;
                  gu64LocalCheckSum+=gu16RxBuffer-'0';
					}
					else
					{
						gstrBCMPacket.strBCMTaskCfg->pu8DataBuffer[gstrBCMPacket.u16ByteCounter]=(uint8_t)gu16RxBuffer;
						gstrBCMPacket.u16ByteCounter = 0;
                  gu64LocalCheckSum+=gu16RxBuffer-'0';
						gstrBCMPacket.enuBCMStateMachine= BCM_STATE_RXCS;
                  
                  UART_SendData(gu64LocalCheckSum);
                  gstrBCMPacket.strBCMTaskCfg->u64CheckSum=0;
					}
					enuErrorStatus = E_OK;
					break;
               
				case BCM_STATE_RXCS:
                  
					if (gstrBCMPacket.u16ByteCounter < 7)
					{
 						gstrBCMPacket.strBCMTaskCfg->u64CheckSum<<=8;
 						gstrBCMPacket.strBCMTaskCfg->u64CheckSum|=(uint8_t)gu16RxBuffer-'0';
						gstrBCMPacket.u16ByteCounter++;
					}
					else
					{
 						gstrBCMPacket.strBCMTaskCfg->u64CheckSum<<=8;
 						gstrBCMPacket.strBCMTaskCfg->u64CheckSum|=(uint8_t)gu16RxBuffer-'0';
						gstrBCMPacket.u16ByteCounter=0;
                  if (gu64LocalCheckSum == gstrBCMPacket.strBCMTaskCfg->u64CheckSum)
                  {
                     gstrBCMPacket.strBCMTaskCfg->pfTaskCompleteNotify();
                     gstrBCMPacket.enuBCMStateMachine= BCM_STATE_FINISHED;
                     enuErrorStatus = E_OK;
                  }
                  else
                  {
                     gstrBCMPacket.enuBCMStateMachine= BCM_STATE_ERROR;
                     enuErrorStatus = E_ERROR;
                  }
					}
					break;
               
				case BCM_STATE_FINISHED:
					enuErrorStatus = E_OK;
					break;
               
				default:
					enuErrorStatus = E_ERROR;
			}
			gu8RxFlag=LOW;
		}
		else
		{
			enuErrorStatus = E_ERROR;
		}
	}
	return enuErrorStatus;
}


static void BCM_RxHandler(void)
{
	if(gstrBCMPacket.enuBCMStateMachine == BCM_STATE_IDLE)
	{
		gstrBCMPacket.enuBCMStateMachine = BCM_STATE_RXCMD;
	}
	else
	{
	}
	UART_RecieveDataNoBLOCK(&gu16RxBuffer);
	gu8RxFlag=HIGH;
}
