/*****************************************************************************
* Task: Stack
* File Name: stack.h
* Description: header file for the stack.c file
* Author: Amr Mohamed
* Date: 4/7/2021
******************************************************************************/

#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include "Data_Types.h"
#include "linked_list.h"

/************************************************************************************
* Parameters (in): uint32_t max_size
* Parameters (out): stack_t *
* Return value: a pointer to a stack structure
* Description: creates a stack structure based on linked lists and allocates space for it in the heap
************************************************************************************/
stack_t *create_stack(uint32_t max_size);


/************************************************************************************
* Parameters (in): stack_t *s
* Parameters (out): void
* Return value: void
* Description: deletes an entire stack
************************************************************************************/
void delete_stack(stack_t *s);


/************************************************************************************
* Parameters (in): stack_t *stack address ,sint32_t value to be added
* Parameters (out): uint8_t
* Return value: 1=add successful, 0=add failed
* Description: pushes a new number to the end of the provided stack
************************************************************************************/
uint8_t push_stack(stack_t *s,sint32_t value);


/************************************************************************************
* Parameters (in): stack_t *stack address ,sint32_t *holder for the popped value to store
* Parameters (out): uint8_t
* Return value: 1=pop successful, 0=pop failed
* Description: pops the last elements of the stack and stores it in the provided value_holder
************************************************************************************/
uint8_t pop_stack(stack_t *s,sint32_t *value_holder);


/************************************************************************************
* Parameters (in): stack_t *s stack to be printed
* Parameters (out): void
* Return value: void
* Description: prints the provided stack to the console
************************************************************************************/
void print_stack(stack_t *s);


/************************************************************************************
* Parameters (in): stack_t *s stack to get the size of
* Parameters (out): uint32_t
* Return value: stack size
* Description: return the size of the provided stack
************************************************************************************/
uint32_t get_stack_Size(stack_t *s);

#endif // STACK_H_
