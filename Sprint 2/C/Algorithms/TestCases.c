/*****************************************************************************
* Task: Algorithms
* File Name: TestCases.c
* Description: File for testing
* Author: Amr Mohamed
* Date: 5/7/2021
******************************************************************************/

#include "TestCases.h"

void test_sorted_check(void)
{
    uint32_t arr1[]={8,5,3,4,7,9,5,2};
    uint32_t arr2[]={4,5,6,7,8,9,10,2};
    uint32_t arr3[]={1,2,3,5,500,670,2000,3000};
    printf("8,5,3,4,7,9,5,2              is    %s\n",(array_is_sorted(arr1,8)? "sorted":"not sorted"));
    printf("4,5,6,7,8,9,10,2             is    %s\n",(array_is_sorted(arr2,8)? "sorted":"not sorted"));
    printf("1,2,3,5,500,670,2000,3000    is    %s\n",(array_is_sorted(arr3,8)? "sorted":"not sorted"));
}

void test_selection_sort(void)
{
    int arr1[]={5,3,7,9,2,1,6,5,3,4};
    print_array(arr1,10);
    printf("\n\n");
    selection_sort(arr1,10);
    print_array(arr1,10);
    printf("\n\n");
}

void test_binary_search(void)
{
    printf("Array= 0,1,1,8,9,15,20,82,99,150\n\n");
    int arr1[]={0,1,1,8,9,15,20,82,99,150};
    printf("search for %d results in %d\n",1,binarySearch(arr1,10,1));

    int arr2[]={0,1,1,8,9,15,20,82,99,150};
    printf("search for %d results in %d\n",99,binarySearch(arr2,10,99));

    int arr3[]={0,1,1,8,9,15,20,82,99,150};
    printf("search for %d results in %d\n",150,binarySearch(arr3,10,150));

    int arr4[]={0,1,1,8,9,15,20,82,99,150};
    printf("search for %d results in %d\n",500,binarySearch(arr4,10,500));
}


void application_test (void)
{
    uint32_t arr[15]={5,7,3,6,8,9,4,2,70,10,15,21,26,12,0};
    print_array(arr,15);
    printf("\n\n");

    uint32_t x=binarySearch(arr,15,500);
    print_array(arr,15);
    printf("\nresult= %d\n",x);
}
