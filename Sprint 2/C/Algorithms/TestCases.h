/*****************************************************************************
* Task: Algorithms
* File Name: TestCases.h
* Description: header file for the TestCases.c
* Author: Amr Mohamed
* Date: 5/7/2021
******************************************************************************/



#ifndef TESTCASES_H_
#define ALGORITHMS_H_

#include <stdio.h>
#include <stdlib.h>
#include "Data_Types.h"
#include "Algorithms.h"

// tests the array_is_sorted function
void test_sorted_check(void);

//tests the sorting algorithm
void test_selection_sort(void);

//tests the binary search algorithm
void test_binary_search(void);

//tests the final application
void application_test (void);

#endif // ALGORITHMS_H_
