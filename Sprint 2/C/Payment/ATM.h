/*****************************************************************************
* Task: Payment System
* File Name: ATM.h
* Description: header file for the ATM.c
* Author: Amr Mohamed
* Date: 5/7/2021
******************************************************************************/


#ifndef ATM_H_
#define ATM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Data_Types.h"

#define MAX_TRANSACTION      5000
typedef struct{

    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[6];

}ST_cardData_t;

typedef struct{

    float transAmount;
    float MaxTransAmount;
    uint8_t transactionDate[11];

}ST_terminalData_t;

typedef struct{
    float Balance;
    uint8_t primaryAccountNumber[20];
}ST_accountBalance_t;

typedef enum{
    DECLINED,
    APPROVED
} EN_transStat_t;


/************************************************************************************
* Parameters (in): void
* Parameters (out): ST_cardData_t *
* Return value: a pointer to strcuture containing card data
* Description: gets card data from the user and stores them in a structure
************************************************************************************/
ST_cardData_t *get_card_data(void);


/************************************************************************************
* Parameters (in): void
* Parameters (out): ST_terminalData_t *
* Return value: a pointer to strcuture containing terminal data
* Description: gets terminal data from the user and stores them in a structure
************************************************************************************/
ST_terminalData_t *get_terminal_data(void);


/************************************************************************************
* Parameters (in): ST_cardData_t *card, ST_terminalData_t *terminal
* Parameters (out): EN_transStat_t
* Return value: Approved or Declined
* Description: performs terminal checks on the provided card and terminal data
************************************************************************************/
EN_transStat_t Terminal_check(ST_cardData_t *card, ST_terminalData_t *terminal);


/************************************************************************************
* Parameters (in): ST_cardData_t *card, ST_terminalData_t *terminal
* Parameters (out): EN_transStat_t
* Return value: Approved or Declined
* Description: performs server checks on the provided card and terminal data
************************************************************************************/
EN_transStat_t Server_check(ST_cardData_t *card, ST_terminalData_t *terminal);


/************************************************************************************
* Parameters (in): ST_cardData_t *card, ST_terminalData_t *terminal
* Parameters (out): EN_transStat_t
* Return value: Approved or Declined
* Description: performs all checks on the trasnsaction
************************************************************************************/
EN_transStat_t check_transaction(ST_cardData_t *card,ST_terminalData_t *terminal);


/************************************ Bonus *****************************************/

//max number of transactions that can be logged
#define TRANSACTION_NUMBER_LIMIT        5


typedef struct{
    ST_cardData_t card;
    float transAmount;
    uint8_t transactionDate[11];
    EN_transStat_t status;
}ST_transactionData_t;



/************************************************************************************
* Parameters (in): ST_cardData_t *card, ST_terminalData_t *terminal ,EN_transStat_t status
* Parameters (out): uint8_t
* Return value: 0 if logging failed  -  1 if logging successful
* Description: logs the transaction with the provided card and terminal info to the database array
************************************************************************************/
uint8_t log_transaction(ST_cardData_t *card, ST_terminalData_t *terminal,EN_transStat_t status);


/************************************************************************************
* Parameters (in): ST_transactionData_t *transaction_database
* Parameters (out): void
* Return value: void
* Description: sorts the transaction database array based on PAN numbers
************************************************************************************/
void sort_Transaction_List(ST_transactionData_t *transaction_database);


/************************************************************************************
* Parameters (in): void
* Parameters (out): void
* Return value: void
* Description: prints the transaction database array
************************************************************************************/
void print_Transaction_List(void);

/************************************************************************************/


/************************************************************************************
* Parameters (in): uint8_t *buffer,uint32_t max_size
* Parameters (out): void
* Return value: void
* Description: scans a string from the user and terminates it with null
************************************************************************************/
void scan_string(uint8_t *buffer,uint32_t max_size);


#endif // ATM_H_




