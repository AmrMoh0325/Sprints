/*****************************************************************************
* Task: UART Driver
* File Name: UART.c
* Description: Driver function for atmega32 UART
* Author: Amr Mohamed
* Date: 14/7/2021
******************************************************************************/


#include "UART.h"

//macro for calculating UBRR value
#define UBRR_CALC(BAUD)       (((F_CPU)/(16UL*BAUD))-1)

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to initialize UART peripheral according to the configuration
************************************************************************************/
enuErrorStatus_t UART_Init(void)
{
   volatile uint8_t UCSRC_Copy=0;
   /*set baudrate */
   uint16_t UBRR_val=0;
   UBRR_val=UBRR_CALC(UART_BAUDRATE);
   UBRRH_R = (uint8_t)(UBRR_val>>8);
   UBRRL_R = (uint8_t)UBRR_val;
   
   /* enable TX */
   SET_BIT(UCSRB_R,TXEN_B);
   /* enable RX */
   SET_BIT(UCSRB_R,RXEN_B);
   
   /* configure number of data bits */
   /* 5, 6, 7, 8, or 9 bits */
   switch(UART_DATA_BITS)
   {
      case 5:
         CLR_BIT(UCSRC_Copy,UCSZ0_B);
         CLR_BIT(UCSRC_Copy,UCSZ1_B);
         CLR_BIT(UCSRB_R,UCSZ2_B);
         break;
      case 6:
          
         //SET_BIT(UCSRC_R,URSEL_B);
         SET_BIT(UCSRC_Copy,UCSZ0_B);
         CLR_BIT(UCSRC_Copy,UCSZ1_B);
         CLR_BIT(UCSRB_R,UCSZ2_B);
         break;
      case 7:
        
         CLR_BIT(UCSRC_Copy,UCSZ0_B);
         SET_BIT(UCSRC_Copy,UCSZ1_B);
         CLR_BIT(UCSRB_R,UCSZ2_B);
         break;
      case 8:
         //SET_BIT(UCSRC_R,URSEL_B);
         SET_BIT(UCSRC_Copy,UCSZ0_B);
         SET_BIT(UCSRC_Copy,UCSZ1_B);
         CLR_BIT(UCSRB_R,UCSZ2_B);
         break;
      case 9:
         //SET_BIT(UCSRC_R,URSEL_B);
         SET_BIT(UCSRC_Copy,UCSZ0_B);
         SET_BIT(UCSRC_Copy,UCSZ1_B);
         SET_BIT(UCSRB_R,UCSZ2_B);
         break;
      default:
         return ERROR;
         break;
   }
   
   /* configure parity bit */ 
   switch(UART_PARITY_BIT)
   {
      /* 0=OFF  1=ODD  2=EVEN */
      case 0:
         break;
      case 1:
         SET_BIT(UCSRC_Copy,UPM1_B);
         SET_BIT(UCSRC_Copy,UPM0_B);
         break;
      case 2:
         SET_BIT(UCSRC_Copy,UPM1_B);
         break;
      default:
         return ERROR;
         break;
   }
   
   /* configure stop bits */ 
   /* 1 or 2 Bits*/
   if (UART_STOP_BITS==1);
   else if (UART_STOP_BITS==2)
   {
      SET_BIT(UCSRC_Copy,USBS_B);
   }
   else
   {
      return ERROR;
   }
   //enable access to UCSRC register
   SET_BIT(UCSRC_R,URSEL_B);
   //store the buffer value into UCSRC buffer to achieve atomic access
   UCSRC_R |=UCSRC_Copy;
   //enable access to UDDRH register
   CLR_BIT(UCSRC_R,URSEL_B);
   
   return SUCCESS;
}

/************************************************************************************
* Parameters (in): uint16_t* pu16Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to recieve a value from uart module and store it in the provided variable
************************************************************************************/
enuErrorStatus_t UART_ReceiveData(uint16_t* pu16Data)
{
   //if sent pointer does not hold a valid address
   if (pu16Data == NULLPTR)
   {
      //return an error
      return ERROR;
   }
   //clear the sent buffer
   *pu16Data=0;
   //wait for the previous operations to complete
   while (!GET_BIT(UCSRA_R,RXC_B));
   
   //if 9 bit mode is enabled 
   if (UART_DATA_BITS==9)
   {
      //store UDR value and include 9th bit
      *pu16Data = (((uint16_t)(GET_BIT(UCSRB_R,RXB8_B)<<8)) | UDR_R);
   }
   else
   {
      //else only store UDR value
      *pu16Data = UDR_R;
   }
   //return a success
   return SUCCESS;
}

/************************************************************************************
* Parameters (in): uint16_t u16Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to send the provided value using uart
************************************************************************************/
enuErrorStatus_t UART_SendData(uint16_t u16Data)
{ 
   //wait for previous operation to complete
   while (!GET_BIT(UCSRA_R,UDRE_B));
   //if 9 bit mode is enabled
   if (UART_DATA_BITS==9)
   {
      //write 9th bit first
      if (GET_BIT(u16Data,8))      SET_BIT(UCSRB_R,TXB8_B);
      else                         CLR_BIT(UCSRB_R,TXB8_B);
   }
   //then set UDR value
   UDR_R=(uint8_t)u16Data;
   return SUCCESS;
}

/************************************************************************************
* Parameters (in): uint16_t* pu16Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to receive data from uart module without waiting for transmission to complete
************************************************************************************/
enuErrorStatus_t UART_RecieveDataNoBLOCK(uint16_t* pu16Data)
{
   //if the sent pointer does not hold a valid address
   if (pu16Data == NULLPTR)
   {
      //return an error
      return ERROR;
   }
   
   if (GET_BIT(UCSRA_R,RXC_B))
   {
       //clear the sent buffer
       *pu16Data=0;
       //if 9 bit mode is enabled
       if (UART_DATA_BITS==9)
       {
          //receive whole value
          *pu16Data = (((uint16_t)(GET_BIT(UCSRB_R,RXB8_B)<<8)) | UDR_R);
       }
       else
       {
          //else only store the UDR value
          *pu16Data = UDR_R;
       }
       return SUCCESS;
   }
   //else return an error
   return ERROR;
}


/************************************************************************************
* Parameters (in): uint16_t u16Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to send provided data to uart module without waiting for transmission to complete
************************************************************************************/
enuErrorStatus_t UART_SendDataNoBLOCK(uint16_t u16Data)
{
   //if UDR register is empty
   if (GET_BIT(UCSRA_R,UDRE_B))
   {
      //if 9 bit mode is enabled
      if (UART_DATA_BITS==9)
      {
         //set the ninth bit in the appropriate location first
         if (GET_BIT(u16Data,8))      SET_BIT(UCSRB_R,TXB8_B);
         else                         CLR_BIT(UCSRB_R,TXB8_B);
      }
      //then store the rest of the data in UDR
      UDR_R=(uint8_t)u16Data;
      return SUCCESS;
   }
   //else return error
   return ERROR;
}

/************************************************************************************
* Parameters (in): uint8_t* pu8String
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to Receive a string using uart
************************************************************************************/
enuErrorStatus_t UART_ReceiveString(uint8_t* pu8String)
{
   uint8_t u8size=255,u8i;
   //traverse the string
   for (u8i=0; u8i<255;u8i++)
   {
      //receive each character stored in the UDR and store it in the appropriate place in the string
      UART_ReceiveData(pu8String+u8i);
      //if termination characters are detected end the communication
      if (*(pu8String+u8i)=='\r'  ||  *(pu8String+u8i)=='\n')
      {
         break;
      }
   }
   //end the string with null
   *(pu8String+u8i)=0;
   return SUCCESS;
   
}

/************************************************************************************
* Parameters (in): uint8_t* pu8String
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to send a string using uart
************************************************************************************/
enuErrorStatus_t UART_SendString(uint8_t* pu8String)
{
   uint8_t u8size=0,u8i;
   //loop on string to determine its size
   for (u8i=0;pu8String[u8i];u8i++)
   {
      u8size++;
   }
   //loop on the string
   for (u8i=0; u8i<u8size;u8i++)
   {
      //send each character independently
      UART_SendData(*(pu8String+u8i));
   }
   //send termination characters when done
   UART_SendData('\r');
   UART_SendData('\n');
   
   return SUCCESS;
}