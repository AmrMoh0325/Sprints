/*****************************************************************************
* Task: Stack
* File Name: main.c
* Description: main file containing our main application
* Author: Amr Mohamed
* Date: 4/7/2021
******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "Data_Types.h"
#include "linked_list.h"
#include <string.h>



/************************************************************************************
* Parameters (in): uint8_t *expression    -    A string of the expression to be checked
* Parameters (out): uint8_t *
* Return value: A string of "Balanced" or "Not Balanced"
* Description: checks if an expression is parentheses balanced or not
************************************************************************************/
uint8_t *balancedParentheses(uint8_t *expression)
{
    //create a stack and necessary flags and buffers
    stack_t *s= create_stack(strlen(expression));
    sint32_t stack_buffer=0;
    uint8_t pop_flag=0;
    uint8_t expression_flag=1;

    //loop in the expression
    for (int i=0;expression[i];i++)
    {
        //if you find '{'
        if (expression[i]=='{')
        {
            //push 1 to the stack
            push_stack(s,1);
        }
        //if you find '('
        else if (expression[i]=='(')
        {
            //push 2 to the stack
            push_stack(s,2);
        }

        //if you find '}'
        else if (expression[i]=='}')
        {
            //pop a value from the stack
            pop_flag=pop_stack(s,&stack_buffer);
            //check if the popped value is 1
            if (!pop_flag || stack_buffer!=1)
            {
                //if not, set the expression as not balanced
                expression_flag=0;
                break;
            }
        }

        //if you find ')'
        else if (expression[i]==')')
        {
            //pop a value from the stack
            pop_flag=pop_stack(s,&stack_buffer);
            //check if the popped value is 2
            if (!pop_flag || stack_buffer!=2)
            {
                //if not, set the expression as not balanced
                expression_flag=0;
                break;
            }
        }
    }

    //if we're done looping on the expression and the stack is not empty
    if (expression_flag && get_stack_Size(s))
    {
        //set the expression as not balanced
        expression_flag=0;
    }

    //return the appropriate string
    return          ((expression_flag)? "Balanced":"Not Balanced");
}







int main()
{
   char str[100]={0};
   while (1)
   {
       //scan expression from the user
        printf("Enter the expression to be checked: ");
        fgets(str, 100, stdin);
        //perform parentheses check on the expression and print the returned string
        printf("\nExpression is %s\n\n\n",balancedParentheses(str));
   }

}
