/*****************************************************************************
* Task: Stack
* File Name: linked_list.c
* Description: library file for the linked list related functions
* Author: Amr Mohamed
* Date: 4/7/2021
******************************************************************************/

#include "linked_list.h"

/************************************************************************************
* Parameters (in): void
* Parameters (out): list_t *
* Return value: a pointer to a linked list structure
* Description: creates a linked list structure and allocates space for it in the heap
************************************************************************************/
list_t *create_list(void)
{
    //create a list and allocate space for it
    list_t *l=(list_t *)malloc(sizeof(list_t));
    //initialize all the newly created list parameters
    l->head = NULL;
    l->end = NULL;
    l->size=0;
    //return a pointer to the list
    return l;
}


/************************************************************************************
* Parameters (in): sint32_t value
* Parameters (out): node_t *
* Return value: a pointer to a linked list node
* Description: creates a linked list node and allocates space for it in the heap
************************************************************************************/
node_t *create_node(sint32_t value)
{
    //create a node and allocate space for it
    node_t *n=(node_t *)malloc(sizeof(node_t));
    //initialize all the newly created node parameters
    n->Next=NULL;
    n->Previous=NULL;
    n->value=value;
    //return a pointer to the node
    return n;
}


/************************************************************************************
* Parameters (in): list_t * list to be modified   ,    node_t * node to be added
* Parameters (out): uint32_t
* Return value: size of the list after adding the node
* Description: adds the provided node to the end of the provided list
************************************************************************************/
uint32_t list_add_node(list_t *l,node_t *n)
{
    //if the list is empty
    if (l->size==0)
    {
        //make the node the first and last node in the list
        l->head=n;
        l->end=n;
    }
    //if the node has existing data
    else
    {
        //add the node to the last position in the list
        n->Previous=l->end;
        l->end->Next=n;
        l->end=n;
    }
    //increase list size
    l->size++;
    //return list size
    return l->size;
}



/************************************************************************************
* Parameters (in): list_t * list to be modified
* Parameters (out): uint32_t
* Return value: 1 for delete success or 0 for delete failed
* Description: deletes the last node from the provided list
************************************************************************************/
uint32_t list_delete_node(list_t *l)
{
    node_t *temp;
    //if list is already empty return 0
    if (l->size==0)         return 0;

    //if list has only one node in it
    else if(l->size==1)
    {
        //assign the node address to the temp pointer and declare the list as empty
        temp=l->end;
        l->head=NULL;
        l->end=NULL;
    }
    //if list has more node in it
    else
    {
        //assign the last node address to the temp pointer and decrease the list end address
        temp=l->end;
        l->end=temp->Previous;
        l->end->Next=NULL;
    }
    //free the memory pointed to by the address in the temp pointer
    free(temp);
    //decrease size of the list
    l->size--;
    //return 1 for success
    return 1;
}


/************************************************************************************
* Parameters (in): list_t * list to be printed
* Parameters (out): void
* Return value: void
* Description: prints the provided list to the console
************************************************************************************/
void print_list(list_t *l)
{
    node_t *temp;

    //if list is empty
    if (l->size==0)
    {
        //print a message informing the user
        printf("\nList is empty!\n");
    }

    //if list has elements
    else
    {
        //set the temp pointer to the head of the list
        temp=l->head;
        printf("\n");

        //loop on all elements untill temp points to NULL
        for (;temp;)
        {
            //print the value of the node pointed to by temp
            printf("%d, ",temp->value);

            //move temp to the next node
            temp=temp->Next;
        }
        printf("\n");
    }
}



/************************************************************************************
* Parameters (in): list_t * list to be modified
* Parameters (out): void
* Return value: void
* Description: deletes an entire list
************************************************************************************/
void delete_list (list_t *l)
{
    //loop on all elements of the list
    for (;l->size;)
    {
        //delete all the elements of the list until list size=0
        list_delete_node(l);
    }
    //free the space occupied by the list structure
    free(l);
}
