/*****************************************************************************
* Task: Stack
* File Name: TestCases.h
* Description: header file for the TestCases.c
* Author: Amr Mohamed
* Date: 4/7/2021
******************************************************************************/

#ifndef TESTCASES_H_
#define TESTCASES_H_

#include <stdio.h>
#include <stdlib.h>
#include "Data_Types.h"
#include "stack.h"

//tests the addition and removal of nodes in linked list
void test_list_Add_Remove_nodes(void);

// tests the deletion of a full linked list
void test_list_delete(void);

//tests all stack functions
void test_stack(void);

//tests the balancedparantheses function
void Parentheses_test(void);

#endif // TESTCASES_H_
