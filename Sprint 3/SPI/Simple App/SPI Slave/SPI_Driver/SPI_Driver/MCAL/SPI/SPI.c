/*****************************************************************************
* Task: SPI Driver
* File Name: SPI.c
* Description: Functions for SPI driver
* Author: Amr Mohamed
* Date: 8/7/2021
******************************************************************************/
 
 
 /*- INCLUDES --------------------------------------------------*/
#include "MCAL/SPI/SPI.h"

/*- GLOBAL VARIABLES --------------------------------------------------*/
void (*SPI_Callback)(void)=NULLPTR;

/*- API IMPLEMENTATION --------------------------------------------------*/
#if (SPI_CONFIG == MASTER)

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to initialize SPI in MASTER Mode
************************************************************************************/
enuErrorStatus_t SPI_Init(void)
{
   DIO_Init();
   
   //enable SPI Master Operation
   SET_BIT(SPCR_R,MSTR_B);
   //Enable SPI 
   SET_BIT(SPCR_R,SPE_B);
   return SUCCESS;
}

/************************************************************************************
* Parameters (in): uint8_t u8Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to Send data in MASTER Mode
************************************************************************************/
enuErrorStatus_t SPI_SendData(uint8_t u8Data)
{
   //enable slave select pin
   DIO_Write(SPI_SS0,LOW);
   //send data
   SPDR_R=u8Data;
   //wait for communication to complete
   while (!GET_BIT(SPSR_R,SPIF_B));
   //disable slave select pin
   DIO_Write(SPI_SS0,HIGH);
   return SUCCESS;
}

/************************************************************************************
* Parameters (in): uint8_t *pu8Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to Receive data in MASTER Mode
************************************************************************************/
enuErrorStatus_t SPI_ReceiveData(uint8_t *pu8Data)
{
   //enable slave select pin
   DIO_Write(SPI_SS0,LOW);
   //send buffer data
   SPDR_R= *pu8Data;
   //wait for communication to complete
   while (!GET_BIT(SPSR_R,SPIF_B));
   //receive data
   *pu8Data=SPDR_R;
   //disable slave select pin
   DIO_Write(SPI_SS0,HIGH);
   return SUCCESS;
}

#elif (SPI_CONFIG== SLAVE)

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to initialize SPI in SLAVE Mode
************************************************************************************/
enuErrorStatus_t SPI_Init(void)
{
   //init DIO
   DIO_Init();
   //Enable SPI
   SET_BIT(SPCR_R,SPE_B);
   return SUCCESS;
}

/************************************************************************************
* Parameters (in): uint8_t u8Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to Send data in SLAVE Mode
************************************************************************************/
enuErrorStatus_t SPI_SendData(uint8_t u8Data)
{
   //send data
   SPDR_R=u8Data;
   //wait for communication to end
   while (!GET_BIT(SPSR_R,SPIF_B));
   return SUCCESS;
}

/************************************************************************************
* Parameters (in): uint8_t *pu8Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to Receive data in SLAVE Mode
************************************************************************************/
enuErrorStatus_t SPI_ReceiveData(uint8_t *pu8Data)
{
   //wait for communication to end
   while (!GET_BIT(SPSR_R,SPIF_B));
   //Receive data
   *pu8Data=SPDR_R;
   return SUCCESS;
}

#endif


/************************************************************************************
* Parameters (in): uint8_t *pu8Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to Send a string 
************************************************************************************/
 enuErrorStatus_t SPI_SendString(uint8_t *pu8Data)
 {
     uint8_t u8i;
     //loop on the string
     for (u8i=0;pu8Data[u8i];u8i++)
     {
        //send each character independently
        SPI_SendData(*(pu8Data+u8i));
     }
     //send termination characters when done
     SPI_SendData('\r');
     SPI_SendData('\n');
     
     return SUCCESS;
 }
 
 /************************************************************************************
 * Parameters (in): uint8_t *pu8Data ,uint8_t u8bufferMaxSize
 * Parameters (out): enuErrorStatus_t
 * Return value: 1=SUCCESS or 0=FAIL
 * Description: A function to Receive a string
 ************************************************************************************/
 enuErrorStatus_t SPI_ReceiveString(uint8_t *pu8Data,uint8_t u8bufferMaxSize)
 {
    uint8_t u8i;
    //traverse the string
    for (u8i=0; u8i<u8bufferMaxSize-1;u8i++)
    {
       //receive each character stored in the UDR and store it in the appropriate place in the string
       SPI_ReceiveData((pu8Data+u8i));
       //if termination characters are detected end the communication
       if (*(pu8Data+u8i)=='\r'  ||  *(pu8Data+u8i)=='\n')
       {
          break;
       }
    }
    //end the string with null
    *(pu8Data+u8i)=0;
    return SUCCESS;
 }

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to enable SPI interrupt
************************************************************************************/
enuErrorStatus_t SPI_Enable_Interrupt(void)
{
   //Enable SPI Interrupt
   SET_BIT(SPCR_R,SPIE_B);
   return SUCCESS;
}

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to disable SPI interrupt
************************************************************************************/
enuErrorStatus_t SPI_Disable_Interrupt(void)
{
   //Enable SPI Interrupt
   SET_BIT(SPCR_R,SPIE_B);
   return SUCCESS; 
}

/************************************************************************************
* Parameters (in): void(*local_fptr)(void)
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to setup SPI interrupt callback
************************************************************************************/
enuErrorStatus_t SPI_SetCallBack(void(*local_fptr)(void))
{
   //if sent pointer is invalid
   if (local_fptr != NULLPTR)
   {
      return ERROR;
   }
   //setup callback
   SPI_Callback=local_fptr;
   return SUCCESS;
}

/************************************************************************************
* Parameters (in): void
* Parameters (out): void
* Return value: void
* Description: SPI serial transfer complete interrupt service routine 
************************************************************************************/
ISR(SPI_STC_vect)
{
   if (SPI_Callback != NULLPTR)
   {
      SPI_Callback();
   }
}