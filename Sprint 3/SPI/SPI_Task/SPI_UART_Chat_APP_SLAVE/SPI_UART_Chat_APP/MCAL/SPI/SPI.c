#include "MCAL/SPI/SPI.h"


#if (SPI_CONFIG == MASTER)

enuErrorStatus_t SPI_Init(void)
{
   DIO_Init();
   
   //enable SPI Master Operation
   SET_BIT(SPCR_R,MSTR_B);
   //Enable SPI 
   SET_BIT(SPCR_R,SPE_B);
   return SUCCESS;
}

enuErrorStatus_t SPI_SendData(uint8_t u8Data)
{
   
   DIO_Write(SPI_SS0,LOW);
   SPDR_R=u8Data;
   while (!GET_BIT(SPSR_R,SPIF_B));
   
   DIO_Write(SPI_SS0,HIGH);
   return SUCCESS;
}

enuErrorStatus_t SPI_ReceiveData(uint8_t *pu8Data)
{
   DIO_Write(SPI_SS0,LOW);
   SPDR_R= *pu8Data;
   while (!GET_BIT(SPSR_R,SPIF_B));
   *pu8Data=SPDR_R;
   DIO_Write(SPI_SS0,HIGH);
   return SUCCESS;
}

#elif (SPI_CONFIG== SLAVE)

enuErrorStatus_t SPI_Init(void)
{
   DIO_Init();
   
   //Enable SPI
   SET_BIT(SPCR_R,SPE_B);
   return SUCCESS;
}

enuErrorStatus_t SPI_SendData(uint8_t u8Data)
{
   /*send a signal to the slave interrupt pin */
   SPDR_R=u8Data;
   while (!GET_BIT(SPSR_R,SPIF_B));
   return SUCCESS;
}

enuErrorStatus_t SPI_ReceiveData(uint8_t *pu8Data)
{
   while (!GET_BIT(SPSR_R,SPIF_B));
   *pu8Data=SPDR_R;
   return SUCCESS;
}

#endif

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
   SPI_SendData(0);
   
   return SUCCESS;
}

enuErrorStatus_t SPI_ReceiveString(uint8_t *pu8Data,uint8_t u8bufferMaxSize)
{
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