/*****************************************************************************
* Task: Thermostat
* File Name: LCD.c
* Description: File for LCD driver functions
* Author: Amr Mohamed
* Date: 26/7/2021
******************************************************************************/

/*- INCLUDES --------------------------------------------------*/
#include "ECUAL/LCD/LCD.h"

/*- API IMPLEMENTATION --------------------------------------------------*/
/************************************************************************************
* Parameters (in): uint8_t u8Data
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to send a data byte to the LCD
************************************************************************************/
static enuErrorStatus_t LCD_WriteData(uint8_t u8Data)
{
   //set lcd to data mode
	DIO_Write(RS,HIGH);
	
	#if LCD_MODE==8-BIT
	//set LCD data pins to the data byte
	LCD_PORT=u8Data;
	
	#elif	LCD_MODE==4-BIT
	//in 4 bit mode set higher 4 bits first
	DIO_Write(D4,GET_BIT(u8Data,4));
	DIO_Write(D5,GET_BIT(u8Data,5));
	DIO_Write(D6,GET_BIT(u8Data,6));
	DIO_Write(D7,GET_BIT(u8Data,7));
	
   //send an enable pulse
	DIO_Write(E,HIGH);
	_delay_ms(1);
	DIO_Write(E,LOW);
	_delay_ms(1);
   
   //then send lower 4 bits
	DIO_Write(D4,GET_BIT(u8Data,0));
	DIO_Write(D5,GET_BIT(u8Data,1));
	DIO_Write(D6,GET_BIT(u8Data,2));
	DIO_Write(D7,GET_BIT(u8Data,3));
	
	#endif

   //send an enable pulse
	DIO_Write(E,HIGH);
	_delay_ms(1);
	DIO_Write(E,LOW);
	_delay_ms(1);
   
   return SUCCESS;
}


/************************************************************************************
* Parameters (in): uint8_t u8Command
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to send a command byte to the LCD
************************************************************************************/
static enuErrorStatus_t LCD_WriteCommand(uint8_t u8Command)
{
   //set lcd to command mode
	DIO_Write(RS,LOW);
	
	#if LCD_MODE==8-BIT
	//set LCD data pins to the command byte
	DIO_Write(LCD_PORT,u8Command);
	
	#elif	LCD_MODE==4-BIT
	//in 4 bit mode set higher 4 bits first
	DIO_Write(D4,GET_BIT(u8Command,4));
	DIO_Write(D5,GET_BIT(u8Command,5));
	DIO_Write(D6,GET_BIT(u8Command,6));
	DIO_Write(D7,GET_BIT(u8Command,7));
   //send an enable pulse
	DIO_Write(E,HIGH);
	_delay_ms(1);
	DIO_Write(E,LOW);
	_delay_ms(1);
   //then send lower 4 bits
	DIO_Write(D4,GET_BIT(u8Command,0));
	DIO_Write(D5,GET_BIT(u8Command,1));
	DIO_Write(D6,GET_BIT(u8Command,2));
	DIO_Write(D7,GET_BIT(u8Command,3));
	
	#endif
   //send an enable pulse
	DIO_Write(E,HIGH);
	_delay_ms(1);
	DIO_Write(E,LOW);
	_delay_ms(1);
   
   return SUCCESS;
}




/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to Initialize the LCD
************************************************************************************/
enuErrorStatus_t LCD_Init(void)
{
	_delay_ms(50);
	
	#if LCD_MODE==8-BIT
	
	LCD_WriteCommand(0x38);			//8BIT mode - 5x7 font - 2 lines
	
	#elif	LCD_MODE==4-BIT
	
	LCD_WriteCommand(0x02);
	LCD_WriteCommand(0x28);        //4BIT mode - 5x7 font -2 lines
	
	#endif
	
	_delay_ms(1);
	LCD_WriteCommand(0x0C);			//Display on - Cursor off
	_delay_ms(1);
	LCD_WriteCommand(0x01);			//Clear LCD
	_delay_ms(2);
	LCD_WriteCommand(0x06);			//Increase DDRAM, no shift
	_delay_ms(1);
	return SUCCESS;
	
}

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to send a clear screen command to the lcd
************************************************************************************/
enuErrorStatus_t LCD_ClearScreen(void)
{
	LCD_WriteCommand(0x01);          //Clear LCD
   return SUCCESS;
}



/************************************************************************************
* Parameters (in): uint8_t u8line,uint8_t u8cell
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to set the cursor location to the specified location
************************************************************************************/
enuErrorStatus_t LCD_SetCursor(uint8_t u8line,uint8_t u8cell)
{
   //select line and jump to the appropriate location in CGRAM
	if (u8line==0)		     LCD_WriteCommand(0x80+u8cell);
	else if(u8line==1)     LCD_WriteCommand(0x80+0x40+u8cell);           
   else                   return ERROR;
   return SUCCESS;
}


/************************************************************************************
* Parameters (in): uint8_t u8ch
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to display a character on the lcd
************************************************************************************/
enuErrorStatus_t LCD_WriteChar(uint8_t u8ch)
{
   //send the character to lcd
	if(LCD_WriteData(u8ch))
   {
      return SUCCESS;
   }
   return ERROR;
}



/************************************************************************************
* Parameters (in): uint8_t *pu8str
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to display a string on the lcd
************************************************************************************/
enuErrorStatus_t LCD_WriteString (uint8_t *pu8str)
{
   //loop on all elements
	for (uint8_t u8i=0;pu8str[u8i];u8i++)
	{
      //send character by character
		LCD_WriteChar(pu8str[u8i]);
	}
   return SUCCESS;
}


/************************************************************************************
* Parameters (in): sint64_t s64num
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to display a number on the lcd
************************************************************************************/
enuErrorStatus_t LCD_WriteNum (sint64_t s64num)
{
	uint64_t u64digit=1;
	uint64_t u64temp;
   //if number is negative
	if (s64num<0)
	{
      //display the sign first
		LCD_WriteChar('-');
      //then transform number to positive
		s64num*= -1;
	}
   //if number is zero
	else if(s64num==0)
	{
      //type zero
		LCD_WriteChar('0');
		return SUCCESS;
	}
	
	u64temp=s64num;
	while (u64temp>0)	
	{
      //calculate number of digits in number
		u64temp/=10;
		u64digit*=10;
		
	}
   //then display digit by digit
	while(u64digit>1)
	{
		u64digit/=10;
		LCD_WriteChar((((s64num/u64digit)%10)+'0'));
	}
   return SUCCESS;
}



/************************************************************************************
* Parameters (in): uint8_t u8ch,uint8_t u8line,uint8_t u8cell
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to display a character on the lcd in specified location
************************************************************************************/
enuErrorStatus_t LCD_WriteCharXY(uint8_t u8ch,uint8_t u8line,uint8_t u8cell)
{
   //set cursor to the location
   LCD_SetCursor(u8line,u8cell);
   //display the character
   LCD_WriteChar(u8ch);
   return SUCCESS;   
}

/************************************************************************************
* Parameters (in): uint8_t *pu8str,uint8_t u8line,uint8_t u8cell
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to display a string on the lcd in specified location
************************************************************************************/
enuErrorStatus_t LCD_WriteStringXY (uint8_t *pu8str,uint8_t u8line,uint8_t u8cell)
{
   //set cursor to the location
   LCD_SetCursor(u8line,u8cell);
   //display the number
   LCD_WriteString(pu8str);
   return SUCCESS;
}

/************************************************************************************
* Parameters (in): sint64_t s64num,uint8_t u8line,uint8_t u8cell
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to display a number on the lcd in specified location
************************************************************************************/
enuErrorStatus_t LCD_WriteNumXY (sint64_t s64num,uint8_t u8line,uint8_t u8cell)
{
   //set cursor to the location
   LCD_SetCursor(u8line,u8cell);
   //display the number
   LCD_WriteNum(s64num);
   return SUCCESS;
}

