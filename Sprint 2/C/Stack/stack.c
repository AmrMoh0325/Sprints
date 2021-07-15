/*****************************************************************************
* Task: Stack
* File Name: stack.c
* Description: library file for the stack related functions
* Author: Amr Mohamed
* Date: 4/7/2021
******************************************************************************/


#include "stack.h"

/************************************************************************************
* Parameters (in): uint32_t max_size
* Parameters (out): stack_t *
* Return value: a pointer to a stack structure
* Description: creates a stack structure based on linked lists and allocates space for it in the heap
************************************************************************************/
stack_t *create_stack(uint32_t max_size)
{
    //create a stack and allocate space for it
    stack_t *s=(stack_t *) malloc(sizeof(stack_t));
    //initialize all the newly created stack parameters
    s->list=create_list();
    s->max_size=max_size;
    //return a pointer to the stack
    return s;
}

/************************************************************************************
* Parameters (in): stack_t *s
* Parameters (out): void
* Return value: void
* Description: deletes an entire stack
************************************************************************************/
void delete_stack(stack_t *s)
{
    //delete the stack linked list
    delete_list(s->list);
    //free the space occupied by the stack structure
    free(s);
}


/************************************************************************************
* Parameters (in): stack_t *stack address ,sint32_t value to be added
* Parameters (out): uint8_t
* Return value: 1=add successful, 0=add failed
* Description: pushes a new number to the end of the provided stack
************************************************************************************/
uint8_t push_stack(stack_t *s,sint32_t value)
{
    //if stack is not full
    if ((s->list->size)<(s->max_size))
    {
        //adds the number to the end of the stack
        list_add_node(s->list,create_node(value));
        //return 1 for success
        return 1;
    }
    //else return 0 for fail
    return 0;
}

/************************************************************************************
* Parameters (in): stack_t *stack address ,sint32_t *holder for the popped value to store
* Parameters (out): uint8_t
* Return value: 1=pop successful, 0=pop failed
* Description: pops the last elements of the stack and stores it in the provided value_holder
************************************************************************************/
uint8_t pop_stack(stack_t *s,sint32_t *value_holder)
{
    //if stack is not empty
    if ((s->list->size)>0)
    {
        //store the last value in the value holder
        *value_holder=s->list->end->value;
        //delete the last node
        list_delete_node(s->list);
        //return 1 for success
        return 1;
    }
    //if stack is empty return 0 for fail
    return 0;
}


/************************************************************************************
* Parameters (in): stack_t *s stack to be printed
* Parameters (out): void
* Return value: void
* Description: prints the provided stack to the console
************************************************************************************/
void print_stack(stack_t *s)
{
    //if stack is not empty
    if (s->list->size)
    {
        //print the list of the stack
        print_list(s->list);
        //print the stack size and max size
        printf("Stack size= %d      Max size= %d\n\n",s->list->size,s->max_size);
    }
    //if the stack is empty
    else
    {
        //inform the user
        printf("\nstack is empty!\n\n");
    }
}

/************************************************************************************
* Parameters (in): stack_t *s stack to get the size of
* Parameters (out): uint32_t
* Return value: stack size
* Description: return the size of the provided stack
************************************************************************************/
uint32_t get_stack_Size(stack_t *s)
{
    //return the size of the stack
    return s->list->size;
}
