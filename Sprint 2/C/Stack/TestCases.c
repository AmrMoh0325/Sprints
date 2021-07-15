/*****************************************************************************
* Task: Stack
* File Name: TestCases.c
* Description: library file for the testing functions
* Author: Amr Mohamed
* Date: 4/7/2021
******************************************************************************/



#include "TestCases.h"
void test_list_Add_Remove_nodes(void)
{
    list_t *l1=create_list();
    list_add_node(l1,create_node(5));
    list_add_node(l1,create_node(7));
    list_add_node(l1,create_node(8));
    list_add_node(l1,create_node(4));
    list_add_node(l1,create_node(9));
    list_add_node(l1,create_node(2));
    print_list(l1);
    list_delete_node(l1);
    print_list(l1);
    list_delete_node(l1);
    print_list(l1);
    list_delete_node(l1);
    print_list(l1);
    list_delete_node(l1);
    print_list(l1);
    list_delete_node(l1);
    print_list(l1);
    list_delete_node(l1);
    print_list(l1);
    list_delete_node(l1);
    print_list(l1);

}

void test_list_delete(void)
{
    list_t *l1=create_list();
    list_add_node(l1,create_node(5));
    list_add_node(l1,create_node(7));
    list_add_node(l1,create_node(8));
    list_add_node(l1,create_node(4));
    list_add_node(l1,create_node(9));
    list_add_node(l1,create_node(2));
    delete_list(l1);
    print_list(l1);
}


void test_stack(void)
{
        int pop_flag=0,push_flag=0;

    stack_t *s1=create_stack(5);
    printf("print empty stack:\n\n");
    print_stack(s1);
    printf("\n=============================================\n");

    sint32_t x;
    printf("pop empty stack:\n\n");
    pop_flag=pop_stack(s1,&x);
    if (pop_flag)       printf("popped value= %d",x);
    else                printf("popped value= invalid");
    print_stack(s1);
    printf("\n=============================================\n");




    printf("pushing to stack and pushing to full stack:\n\n");
    for (int i=0;i<6;i++)
    {
        push_flag=push_stack(s1,i);
        printf("\n\n%s",((push_flag)? "push successful":"push fail"));

        print_stack(s1);
    }
    printf("\n=============================================\n");

    printf("popping stack and popping empty stack:\n\n");
    for (int i=0;i<6;i++)
    {
        pop_flag=pop_stack(s1,&x);
        if (pop_flag)       printf("popped value= %d",x);
        else                printf("popped value= invalid");
        print_stack(s1);
    }
    printf("\n=============================================\n");
    return 0;
}

void Parentheses_test(void)
{
    printf("(2*3+(5/2+(4*3)))\t%s\n{({2+10}}*11}\t\t%s\n", balancedParentheses("(2*3+(5/2+(4*3)))"),balancedParentheses("{({2+10}}*11}"));
}
