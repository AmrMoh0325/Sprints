/*****************************************************************************
* Task: Thermostat
* File Name: LCD.h
* Description: header File for lcd driver
* Author: Amr Mohamed
* Date: 26/7/2021
******************************************************************************/


#ifndef __LCD__
#define __LCD__

/*- INCLUDES --------------------------------------------------*/
#include "MCAL/DIO/DIO.h"
#include "ECUAL/LCD/LCD_Cfg.h"
#include "MCAL/Register.h"
#include "DataTypes.h"
#include "Utils.h"
#include <util/delay.h>


/*- API PROTOTYPES --------------------------------------------------*/	

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to Initialize the LCD
************************************************************************************/
enuErrorStatus_t LCD_Init(void);

/************************************************************************************
* Parameters (in): void
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to send a clear screen command to the lcd
************************************************************************************/
enuErrorStatus_t LCD_ClearScreen(void);

/************************************************************************************
* Parameters (in): uint8_t u8line,uint8_t u8cell
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to set the cursor location to the specified location
************************************************************************************/
enuErrorStatus_t LCD_SetCursor(uint8_t u8line,uint8_t u8cell);

/************************************************************************************
* Parameters (in): uint8_t u8ch
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to display a character on the lcd
************************************************************************************/
enuErrorStatus_t LCD_WriteChar(uint8_t u8ch);

/************************************************************************************
* Parameters (in): uint8_t *pu8str
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to display a string on the lcd
************************************************************************************/
enuErrorStatus_t LCD_WriteString (uint8_t *pu8str);

/************************************************************************************
* Parameters (in): sint64_t s64num
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to display a number on the lcd
************************************************************************************/
enuErrorStatus_t LCD_WriteNum (sint64_t s64num);

/************************************************************************************
* Parameters (in): uint8_t u8ch,uint8_t u8line,uint8_t u8cell
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to display a character on the lcd in specified location
************************************************************************************/
enuErrorStatus_t LCD_WriteCharXY(uint8_t u8ch,uint8_t u8line,uint8_t u8cell);

/************************************************************************************
* Parameters (in): uint8_t *pu8str,uint8_t u8line,uint8_t u8cell
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to display a string on the lcd in specified location
************************************************************************************/
enuErrorStatus_t LCD_WriteStringXY (uint8_t *pu8str,uint8_t u8line,uint8_t u8cell);

/************************************************************************************
* Parameters (in): sint64_t s64num,uint8_t u8line,uint8_t u8cell
* Parameters (out): enuErrorStatus_t
* Return value: 1=SUCCESS or 0=FAIL
* Description: A function to display a number on the lcd in specified location
************************************************************************************/
enuErrorStatus_t LCD_WriteNumXY (sint64_t s64num,uint8_t u8line,uint8_t u8cell);



#endif /* __LCD__ */