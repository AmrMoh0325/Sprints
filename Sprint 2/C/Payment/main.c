#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Data_Types.h"
#include "ATM.h"
#include "TestCases.h"

#define TEST


#ifdef  APP
//Normal app
int main()
{
    uint8_t input;
    ST_cardData_t *card;
    ST_terminalData_t *terminal;
    while(1)
    {
        //clear screen
        system("cls");
        //get card data
        printf("Enter Card Data:\n");
        card=get_card_data();
        //get terminal data
        printf("\nEnter Terminal Data:\n");
        terminal=get_terminal_data();

        //perform checks on transaction and print a msg based on response
        if(check_transaction(card,terminal))
        {
            printf("\nThe Transaction is Approved\n\n");
        }
        else
        {
            printf("\nThe Transaction is Declined\n\n");
        }

        //ask if the user wants to perform another transaction
        printf("Do you wish to continue(y/n)?  ");
        fflush(stdin);
        while(input!='y' && input != 'n')
        {
            fflush(stdin);
            scanf("%c",&input);
            if (input>='A' && input<= 'Z')  input=input-'A'+'a';
        }

        if (input=='n')
        {
            system("cls");
            print_Transaction_List();
            break;
        }
        input=0;
    }

    return 0;
}
#endif // APP


#ifdef TEST
//App for testing
int main(void)
{
    testCase1();
    printf("\n===========================================================\n");
    testCase2();
    printf("\n===========================================================\n");
    testCase3();
    printf("\n===========================================================\n");
    testCase4();
    printf("\n===========================================================\n");
    testCase5();
    printf("\n===========================================================\n");
    print_Transaction_List();

}

#endif // TEST





