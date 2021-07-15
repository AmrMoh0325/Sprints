/*****************************************************************************
* Task: Algorithms
* File Name: Algorithms.h
* Description: header file for the Algorithms.c
* Author: Amr Mohamed
* Date: 5/7/2021
******************************************************************************/

#ifndef ALGORITHMS_H_
#define ALGORITHMS_H_

#include <stdio.h>
#include <stdlib.h>
#include "Data_Types.h"

/************************************************************************************
* Parameters (in): uint32_t *array ,uint8_t array_size ,uint32_t number
* Parameters (out): sint16_t
* Return value: index of number or -1 if not found
* Description: searches for the number in the  array
************************************************************************************/
sint16_t binarySearch(uint32_t *arr,uint8_t size,uint32_t num);

/************************************************************************************
* Parameters (in): uint32_t *array ,uint8_t array_size
* Parameters (out): void
* Return value: void
* Description: sorts the  array using selection sorting algorithm
************************************************************************************/
void selection_sort(uint32_t *arr,uint8_t size);

/************************************************************************************
* Parameters (in): uint32_t *array ,uint8_t array_size
* Parameters (out): uint8_t
* Return value: 1 if the array is sorted or 0 if not sorted
* Description: checks if an array is sorted or not
************************************************************************************/
uint8_t array_is_sorted(uint32_t *arr,uint8_t size);

/************************************************************************************
* Parameters (in): uint32_t * number1, uint32_t *number2
* Parameters (out): void
* Return value: void
* Description: swaps the given numbers
************************************************************************************/
void num_swap(uint32_t *n1, uint32_t *n2);

/************************************************************************************
* Parameters (in): uint32_t *array ,uint8_t array_size
* Parameters (out): void
* Return value: void
* Description: prints an array
************************************************************************************/
void print_array(uint32_t *arr,uint32_t size);


#endif // ALGORITHMS_H_
