/*****************************************************************************
* Task: Algorithms
* File Name: main.c
* Description: main file
* Author: Amr Mohamed
* Date: 5/7/2021
******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "Algorithms.h"
#include "TestCases.h"



//IMPORTANT NOTE
// Please note that the requested task function is located in the
// beginning of the "Algorithms.c" file


int main()
{
    //create all necessary variables
    uint32_t input;
    sint32_t num;
    uint8_t arr_size;

    //ask user for array size and await his response
    printf("Enter number of array members: ");
    scanf("%d", &input);
    arr_size=(uint8_t)input;

    //create an array with the size the user selected
    uint32_t arr[arr_size];
    uint32_t original_arr[arr_size];
    // fill the array elements with user inputs
    printf("\nEnter array members in any order: ");
    for (uint32_t i=0;i<arr_size;i++)
    {
       scanf("%d", &input);
       original_arr[i]=arr[i]=input;
    }

    while (1)
    {
        //ask the user of the number he wants to find
        printf("Enter number you want to find: ");
        scanf("%d", &num);

        //clear console
        system("cls");
        //print the original array
        printf("Your array:\t");
        print_array(original_arr,arr_size);
        //perform binary search for the number in the array
        sint16_t index=binarySearch(arr,arr_size,num);
        //print out sorted array after search
        printf("\n\nSorted array:\t");
        print_array(arr,arr_size);
        //print the index of the number after the search or if the number is not found
        if (index>=0)
        {
            printf("\n\nindex of %d is: %d\n\n",num,index);
        }
        else
        {
            printf("\n\nNumber not found\nSearch result = %i\n\n",index);
        }

    }

    return 0;
}



