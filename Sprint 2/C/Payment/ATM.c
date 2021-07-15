

#include "ATM.h"


uint32_t Num_of_clients=10;
ST_accountBalance_t Bank_DataBase[]={{100.00,"123456789"},
                                     {6000.00,"234567891"},
                                     {3250.25,"567891234"},
                                     {1500.12,"456789123"},
                                     {500.00,"258649173"},
                                     {2100.00,"654823719"},
                                     {0.00,"971362485"},
                                     {1.00,"793148625"},
                                     {10.12,"123123456"},
                                     {0.55,"456789321"}};





/************************************************************************************
* Parameters (in): void
* Parameters (out): ST_cardData_t *
* Return value: a pointer to strcuture containing card data
* Description: gets card data from the user and stores them in a structure
************************************************************************************/
ST_cardData_t *get_card_data(void)
{
    //assign space for the card data structure
    ST_cardData_t *card=(ST_cardData_t *)malloc(sizeof(ST_cardData_t));

    //get card holder name
    printf("Please Enter the Card Holder Name: ");
    scan_string(card->cardHolderName,25);

    //get card PAN
    printf("Please Enter the Primary Account Number: ");
    scan_string(card->primaryAccountNumber,20);

    //get card Expiry date
    printf("Please Enter the Card Expiry Date(MM/YY): ");
    scan_string(card->cardExpirationDate,6);
    return card;
}


/************************************************************************************
* Parameters (in): void
* Parameters (out): ST_terminalData_t *
* Return value: a pointer to strcuture containing terminal data
* Description: gets terminal data from the user and stores them in a structure
************************************************************************************/
ST_terminalData_t *get_terminal_data(void)
{
    //assign space for the terminal data structure
    ST_terminalData_t *terminal=(ST_terminalData_t *)malloc(sizeof(ST_terminalData_t));

    //set the max transaction amount
    terminal->MaxTransAmount=MAX_TRANSACTION;

    //get the transaction amount
    printf("Please Enter the Transaction Amount: ");
    fflush(stdin);
    scanf("%f",&(terminal->transAmount));

    // if the amount is higher than the max amount end the transaction
    if (terminal->transAmount>MAX_TRANSACTION)      return terminal;

    //get the transaction date
    printf("Please Enter the Transaction Date(DD/MM/YYYY): ");
    scan_string(terminal->transactionDate,11);

    return terminal;
}


/************************************************************************************
* Parameters (in): ST_cardData_t *card, ST_terminalData_t *terminal
* Parameters (out): EN_transStat_t
* Return value: Approved or Declined
* Description: performs terminal checks on the provided card and terminal data
************************************************************************************/
EN_transStat_t Terminal_check(ST_cardData_t *card, ST_terminalData_t *terminal)
{
    // if the amount is higher than the max amount end the transaction
    if ((terminal->transAmount)>(terminal->MaxTransAmount))
    {
        return DECLINED;
    }

    //compare the transaction month with expiry month
    sint8_t year_flag=strncmp(card->cardExpirationDate+3,terminal->transactionDate+8,2);
    //compare the transaction year with expiry year
    sint8_t month_flag=strncmp(card->cardExpirationDate,terminal->transactionDate+3,2);

    //if transaction date is after expiry date, decline the transaction
    if (year_flag>=0)
    {
        if (year_flag==0)
        {
            if (month_flag<0)
            {
                return DECLINED;
            }
        }
    }
    else
    {
        return DECLINED;
    }
    //else approve
    return APPROVED;
}


/************************************************************************************
* Parameters (in): ST_cardData_t *card, ST_terminalData_t *terminal
* Parameters (out): EN_transStat_t
* Return value: Approved or Declined
* Description: performs server checks on the provided card and terminal data
************************************************************************************/
EN_transStat_t Server_check(ST_cardData_t *card, ST_terminalData_t *terminal)
{
    int i,client_found=0;
    //search for client PAN number and check if it exists in the database
    for (i=0;i<Num_of_clients;i++)
    {
        if(strncmp(card->primaryAccountNumber,Bank_DataBase[i].primaryAccountNumber,10)==0)
        {
            client_found=1;
            break;
        }
    }
    // if the client PAN number exists in the data base and the amount he's requesting is less than his balance approve the transaction
    if((client_found) && (terminal->transAmount<=Bank_DataBase[i].Balance))
    {
        return APPROVED;
    }
    //else decline
    return DECLINED;
}


/************************************************************************************
* Parameters (in): ST_cardData_t *card, ST_terminalData_t *terminal
* Parameters (out): EN_transStat_t
* Return value: Approved or Declined
* Description: performs all checks on the trasnsaction
************************************************************************************/
EN_transStat_t check_transaction(ST_cardData_t *card,ST_terminalData_t *terminal)
{
    EN_transStat_t local_check=0,remote_check=0;

    //perform the local terminal check on the transaction first
    local_check=Terminal_check(card,terminal);

    //if local check succeeds, sends transaction data to server for server check
    if (local_check==1)
    {
        remote_check=Server_check(card,terminal);
    }

    //log the transaction in the transaction database
    log_transaction(card,terminal,local_check && remote_check);

    //end the transaction by freeing all allocated data holders
    free(card);
    free(terminal);

    //if all checks pass approve the transaction
    if(local_check && remote_check)
    {
        return APPROVED;
    }
    //else decline the transaction
    return DECLINED;
}


/************************************ Bonus *****************************************/

ST_transactionData_t Database[TRANSACTION_NUMBER_LIMIT]={0};
uint32_t num_transaction=0;

/************************************************************************************
* Parameters (in): ST_cardData_t *card, ST_terminalData_t *terminal ,EN_transStat_t status
* Parameters (out): uint8_t
* Return value: 0 if logging failed  -  1 if logging successful
* Description: logs the transaction with the provided card and terminal info to the database array
************************************************************************************/
uint8_t log_transaction(ST_cardData_t *card, ST_terminalData_t *terminal,EN_transStat_t status)
{
    //if the number of transaction present in the transaction log database is less than the max amount
    if (num_transaction<TRANSACTION_NUMBER_LIMIT)
    {
        //copy all transaction data to the transaction log database
        Database[num_transaction].card=*card;
        Database[num_transaction].transAmount=terminal->transAmount;
        Database[num_transaction].status=status;
        strcpy(Database[num_transaction].transactionDate,terminal->transactionDate);
        //increase the number of stored transactions
        num_transaction++;
    }
    else
    {
        //don't store if the database cannot accept anymore entries
        return 0;
    }
    //if you stored a new entry, sort the transaction log database based on PAN numbers and end
    sort_Transaction_List(Database);
    return 1;
}


/************************************************************************************
* Parameters (in): ST_transactionData_t *transaction_database
* Parameters (out): void
* Return value: void
* Description: sorts the transaction database array based on PAN numbers
************************************************************************************/
void sort_Transaction_List(ST_transactionData_t *transaction_database)
{
    //this function uses the selection sort sorting algorithm
    uint32_t i,j,min_index=0;
    ST_transactionData_t temp;

    //stop on an element
    for (i=0;i<num_transaction-1;i++)
    {
        min_index=i;
        //loop on all elements after it
        for (j=i+1;j<num_transaction;j++)
        {
            //if an element PAN number is less than the minimum PAN number, update the min PAN number index
            if (strcmp(transaction_database[j].card.primaryAccountNumber , transaction_database[min_index].card.primaryAccountNumber)< 0)
            {
                min_index=j;
            }
        }
        //if the min PAN index has been changed, swap the elment we stood on with the min PAN number element
        if (min_index>i)
        {
            temp=transaction_database[i];
            transaction_database[i]=transaction_database[min_index];
            transaction_database[min_index]=temp;
        }
    }
}


/************************************************************************************
* Parameters (in): void
* Parameters (out): void
* Return value: void
* Description: prints the transaction database array
************************************************************************************/
void print_Transaction_List(void)
{
    //print page title
    printf("\n\n\t\t\t\t\t\t   Transaction log\n\n");

    //if the user haven't done any transactions, print a message to the user that the database is empty
    if (num_transaction==0)
    {
        printf("\t\tTransaction log empty\n\n");
    }
    else
    {   //if the database isn't empty, draw a table with all the data of the first (num_transaction) transactions.
         printf("\tID\t\t     Name\t      Exp. Date\t\t   Date\t\t\t  Amount\t    Status\n\n");
         for (int i=0;i<num_transaction;i++)
         {
             printf("    %s\t\t%s\t\t%s\t\t%s\t\t%f\t   %s\n\n", Database[i].card.primaryAccountNumber, Database[i].card.cardHolderName, Database[i].card.cardExpirationDate, Database[i].transactionDate, Database[i].transAmount, (Database[i].status ? "Approved":"Declined"));
         }
         printf("=======================================================================================================================");
    }
}


/*********************************** Misc *******************************************/


/************************************************************************************
* Parameters (in): uint8_t *buffer,uint32_t max_size
* Parameters (out): void
* Return value: void
* Description: scans a string from the user and terminates it with null
************************************************************************************/
void scan_string(uint8_t *buffer,uint32_t max_size)
{
    uint8_t x;
    uint32_t i;
    fflush(stdin);
    for(i=0;i<max_size-1;i++)
    {
        scanf("%c",&x);
        if (x=='\n' || x=='\0')
        {
            buffer[i]=0;
            return;
        }
        else
        {
            buffer[i]=x;
        }
    }
    buffer[i]=0;
}

