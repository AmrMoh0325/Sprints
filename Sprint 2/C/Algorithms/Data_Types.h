/*****************************************************************************
* Task: Algorithms
* File Name: Data_Types.h
* Description: header file for the data types
* Author: Amr Mohamed
* Date: 5/7/2021
******************************************************************************/

#ifndef DATA_TYPES_H_
#define DATA_TYPES_H_

/********************** General Data Types **************************/
typedef unsigned char           uint8_t;
typedef signed char             sint8_t;
typedef unsigned int            uint32_t;
typedef signed int              sint32_t;
typedef unsigned short int      uint16_t;
typedef signed short int        sint16_t;
typedef unsigned long long int  uint64_t;
typedef signed long long int    sint64_t;


/*************************Linked list data types********************/
struct node_t{
struct node_t *Previous;
struct node_t *Next;
int value;
};

typedef struct node_t       node_t;


typedef struct{
node_t *head;
node_t *end;
int size;
}list_t;



/***************************Stack Types ***************************/

typedef struct{
list_t *list;
int max_size;
}stack_t;



#endif // DATA_TYPES_H_
