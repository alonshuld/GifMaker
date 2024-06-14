#ifndef UTILITIESH
#define UTILITIESH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE !FALSE

int fileExist(char* path);
/*
* This function checks if a path is valid and the file in it can be opened
* Input: the path to the file
* Output: TRUE or FALSE if can be opened or not
*/

void myFgets(char* str, int n);
/*
* Function will perform the fgets command and also remove the newline that might be at the end of the string - a known issue with fgets.
* Input: the buffer to read into, the number of chars to read
* Output: none
*/

void checkAllocation(void* ptr);
/*
* This function checks in the allocating was good
* Input: a pointer
* Output: none
*/

#endif