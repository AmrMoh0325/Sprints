/*****************************************************************************
* Task: SPI Driver
* File Name: SPI.c
* Description: functions for the the SPI driver
* Author: Amr Mohamed
* Date: 16/7/2021
******************************************************************************/
 
 /*- INCLUDES --------------------------------------------------*/
#include "MCAL/SPI/SPI.h"

/*- GLOBAL VARIABLES --------------------------------------------------*/
void (*SPI_Callback)(void)=NULLPTR;

/*- APIs IMPLEMENTATION-----------------------------------*/
#if (SPI_CONFIG == MASTER)

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to initialize SPI peripheral for master device
************************************************************************************/
enuErrorStatus_t SPI_Init(void)
{
   //initialize DIO with SPI configuration
   DIO_Init();
   //enable SPI Master Operation
   SET_BIT(SPCR_R,MSTR_B);
   //Enable SPI 
   SET_BIT(SPCR_R,SPE_B);
   return SUCCESS;
}

/************************************************************************************
* Parameters (in): uint16_t u16Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to send the provided value using SPI
************************************************************************************/
enuErrorStatus_t SPI_SendData(uint8_t u8Data)
{
   //enable the target slave
   DIO_Write(SPI_SS0,LOW);
   //store the value in the SPI data register to initialize communication
   SPDR_R=u8Data;
   //wait for transmission to complete
   while (!GET_BIT(SPSR_R,SPIF_B));
   //disable the target slave
   DIO_Write(SPI_SS0,HIGH);
   return SUCCESS;
}

/************************************************************************************
* Parameters (in): uint16_t* pu16Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to recieve a value from SPI module and store it in the provided variable
************************************************************************************/
enuErrorStatus_t SPI_ReceiveData(uint8_t *pu8Data)
{
   //check if sent pointer points to a valid location
   if (pu8Data == NULLPTR)
   {
      //return an error
      return ERROR;
   }
   //enable the target slave
   DIO_Write(SPI_SS0,LOW);
   //store the pointer contents in the SPI data register to initialize communication
   SPDR_R= *pu8Data;
   //wait for transmission to complete
   while (!GET_BIT(SPSR_R,SPIF_B));
   //store the new data in the SPI data register in the pointer location
   *pu8Data=SPDR_R;
   //disable the target slave
   DIO_Write(SPI_SS0,HIGH);
   return SUCCESS;
}

#elif (SPI_CONFIG== SLAVE)


/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to initialize SPI peripheral for slave device
************************************************************************************/
enuErrorStatus_t SPI_Init(void)
{
   //initialize DIO with SPI configuration
   DIO_Init();
   
   //Enable SPI
   SET_BIT(SPCR_R,SPE_B);
   return SUCCESS;
}

/************************************************************************************
* Parameters (in): uint16_t u16Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to send the provided value using SPI
************************************************************************************/
enuErrorStatus_t SPI_SendData(uint8_t u8Data)
{
   //store the value in the SPI data register
   SPDR_R=u8Data;
   //wait for transmission to complete
   while (!GET_BIT(SPSR_R,SPIF_B));
   return SUCCESS;
}

/************************************************************************************
* Parameters (in): uint16_t* pu16Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to receive a value from SPI module and store it in the provided variable
************************************************************************************/
enuErrorStatus_t SPI_ReceiveData(uint8_t *pu8Data)
{
   //check if sent pointer points to a valid location
   if (pu8Data == NULLPTR)
   {
      //return an error
      return ERROR;
   }
   //wait for transmission to complete
   while (!GET_BIT(SPSR_R,SPIF_B));
   //store the new data in the SPI data register in the pointer location
   *pu8Data=SPDR_R;
   return SUCCESS;
}

#endif




/************************************************************************************
* Parameters (in): uint8_t* pu8String
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to send a string using SPI
************************************************************************************/
 enuErrorStatus_t SPI_SendString(uint8_t *pu8Data)
 {
    //check if sent pointer points to a valid location
    if (pu8Data == NULLPTR)
    {
       //return an error
       return ERROR;
    }
    uint8_t u8i;
    //loop on the string
    for (u8i=0;pu8Data[u8i];u8i++)
    {
       //send each character independently
       SPI_SendData(*(pu8Data+u8i));
    }
    //send termination characters when done
    SPI_SendData(0);
     
    return SUCCESS;
 }
 
 
/************************************************************************************
* Parameters (in): uint8_t* pu8String, uint8_t u8bufferMaxSize
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to receive a string using SPI
************************************************************************************/
 enuErrorStatus_t SPI_ReceiveString(uint8_t *pu8Data,uint8_t u8bufferMaxSize)
 {
    //check if sent pointer points to a valid location
    if (pu8Data == NULLPTR)
    {
       //return an error
       return ERROR;
    }
    uint8_t u8i;
    //traverse the string
    for (u8i=0; u8i<u8bufferMaxSize-1;u8i++)
    {
       //receive each character stored in the UDR and store it in the appropriate place in the string
       SPI_ReceiveData((pu8Data+u8i));
       //if termination characters are detected end the communication
       if (*(pu8Data+u8i)==0)
       {
          break;
       }
    }
    //end the string with null
    return SUCCESS;
 }


/**************************************** PREPARED APIs FOR FUTURE USE ******************************************/

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to enable SPI interrupt for transmission complete
************************************************************************************/
enuErrorStatus_t SPI_Enable_Interrupt(void)
{
   //set appropriate bit to enable interrupt
   SET_BIT(SPCR_R,SPIE_B);
   return SUCCESS;
}

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to disable SPI interrupt for transmission complete
************************************************************************************/
enuErrorStatus_t SPI_Disable_Interrupt(void)
{
   //clear appropriate bit to disable interrupt
   CLR_BIT(SPCR_R,SPIE_B);
   return SUCCESS;
}

/************************************************************************************
* Parameters (in): void(*local_fptr)(void)
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to setup callback function for SPI transmission complete interrupt
************************************************************************************/
enuErrorStatus_t SPI_SetCallBack(void(*local_fptr)(void))
{
   //check if the sent pointer points to a valid position
   if (local_fptr== NULLPTR)     return ERROR;
   //if so, store the pointer address in the global pointer to function
   SPI_Callback=local_fptr;
   return SUCCESS;
}



/* ISRs----------------------------------------------------------*/

ISR(SPI_STC_vect)
{
   //if the global pointer to function points to a valid position
   if (SPI_Callback!=NULLPTR)
   {
      //call the function
      SPI_Callback();
   }
}