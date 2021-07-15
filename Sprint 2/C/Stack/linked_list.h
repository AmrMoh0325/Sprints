/*****************************************************************************
* Task: Stack
* File Name: linked_list.h
* Description: header file for the linked_list.c file
* Author: Amr Mohamed
* Date: 4/7/2021
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "Data_Types.h"

/************************************************************************************
* Parameters (in): void
* Parameters (out): list_t *
* Return value: a pointer to a linked list structure
* Description: creates a linked list structure and allocates space for it in the heap
************************************************************************************/
list_t *create_list(void);

/************************************************************************************
* Parameters (in): sint32_t value
* Parameters (out): node_t *
* Return value: a pointer to a linked list node
* Description: creates a linked list node and allocates space for it in the heap
************************************************************************************/
node_t *create_node(sint32_t value);

/************************************************************************************
* Parameters (in): list_t * list to be modified   ,    node_t * node to be added
* Parameters (out): uint32_t
* Return value: size of the list after adding the node
* Description: adds the provided node to the end of the provided list
************************************************************************************/
uint32_t list_add_node(list_t *l,node_t *n);

/************************************************************************************
* Parameters (in): list_t * list to be modified
* Parameters (out): uint32_t
* Return value: 1 for delete success or 0 for delete failed
* Description: deletes the last node from the provided list
************************************************************************************/
uint32_t list_delete_node(list_t *l);


/************************************************************************************
* Parameters (in): list_t * list to be printed
* Parameters (out): void
* Return value: void
* Description: prints the provided list to the console
************************************************************************************/
void print_list(list_t *l);

/************************************************************************************
* Parameters (in): list_t * list to be modified
* Parameters (out): void
* Return value: void
* Description: deletes an entire list
************************************************************************************/
void delete_list (list_t *l);

#endif // LINKED_LIST_H_


