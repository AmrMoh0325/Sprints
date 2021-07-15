/*****************************************************************************
* Task: Algorithms
* File Name: Algorithms.c
* Description: library file for algorithms functions
* Author: Amr Mohamed
* Date: 5/7/2021
******************************************************************************/


#include "Algorithms.h"

/*====================== TASK ===================================*/

/************************************************************************************
* Parameters (in): uint32_t *array ,uint8_t array_size ,uint32_t number
* Parameters (out): sint16_t
* Return value: index of number or -1 if not found
* Description: searches for the number in the  array
************************************************************************************/
sint16_t binarySearch(uint32_t *arr,uint8_t size,uint32_t num)
{
    //if array is empty retun not found
    if (size==0)        return -1;
    //perform sorting check on the array
    uint8_t sort_check= array_is_sorted(arr,size);

    //if the array is not sorted, sort it first
    if (!sort_check)
    {
        //sort the array using selection sort algorithm
        selection_sort(arr,size);
    }

    //initialize start,mid and end indicators
    uint8_t start,end,mid;

    start=0;
    end=size-1;

    //if number is less than first element or more than last element return not found
    if (num<arr[start] || num>arr[end])     return -1;
    //if number is in the first element return it right away
    else if (num==arr[start])               return start;
    //if number is in the last element return it right away
    else if (num==arr[end])                 return end;

    //loop until start is > end
    while (start<=end)
    {
        //calcualte mid between start and end
       mid=(start+end)/2;

        //check is number at mid if yes return mid if not continue
       if (num==arr[mid])          return mid;

       //if number at mid is bigger than the number, modify end
       else if (arr[mid]>num)      end = mid-1;
       //if number at mid is less than the number, modify start
       else if (arr[mid]<num)      start = mid+1;
    }

    //if number is not found return not found
    return -1;
}

/*==========================================================================*/


/************************************************************************************
* Parameters (in): uint32_t *array ,uint8_t array_size
* Parameters (out): void
* Return value: void
* Description: sorts the  array using selection sorting algorithm
************************************************************************************/
void selection_sort(uint32_t *arr,uint8_t size)
{
    uint32_t i,j,min_index=0;

    //loop on all the array
    for (i=0;i<size-1;i++)
    {
        //stand on each element and set min_index on it
        min_index=i;
        //loop on all elements after it
        for (j=i+1;j<size;j++)
        {
            //if the current number is less than the number we stood on
            if (arr[j]<arr[min_index])
            {
                //update min_index
                min_index=j;
            }
        }
        //if min_index has changed swap the number we stood at with the new number
        if (min_index>i)    num_swap(arr+i,arr+min_index);
    }
}


/************************************************************************************
* Parameters (in): uint32_t *array ,uint8_t array_size
* Parameters (out): uint8_t
* Return value: 1 if the array is sorted or 0 if not sorted
* Description: checks if an array is sorted or not
************************************************************************************/
uint8_t array_is_sorted(uint32_t *arr,uint8_t size)
{
    //traverse the array
    for (uint32_t i=0;i<size-1;i++)
    {
        //if a number is bigger than the one after it return not sorted
        if (arr[i]>arr[i+1])    return 0;
    }
    //if all numbers are in order return sorted
    return 1;
}


/************************************************************************************
* Parameters (in): uint32_t * number1, uint32_t *number2
* Parameters (out): void
* Return value: void
* Description: swaps the given numbers
************************************************************************************/
void num_swap(uint32_t *n1, uint32_t *n2)
{
    *n1 ^= *n2;         //stores the second number within the first number
    *n2 = *n1 ^ *n2;    //stores n1 value inside n2
    *n1 ^= *n2;         //stores n2 value inside n1
}


/************************************************************************************
* Parameters (in): uint32_t *array ,uint8_t array_size
* Parameters (out): void
* Return value: void
* Description: prints an array
************************************************************************************/
void print_array(uint32_t *arr,uint32_t size)
{
    uint32_t i;
    //traverse the array
    for (i=0;i<size-1;i++)
    {
        //print each number in the array
        printf("%d, ",arr[i]);
    }
    //print the last number without ','
    printf("%d",arr[i]);
}
