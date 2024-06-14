#define _CRT_SECURE_NO_WARNINGS

#include "utilities.h"

int fileExist(char* path)
/*
* This function checks if a path is valid and the file in it can be opened
* Input: the path to the file
* Output: TRUE or FALSE if can be opened or not
*/
{
	FILE* file = fopen(path, "rb");
	if (file)
	{
		fclose(file);
		return TRUE;
	}
	return FALSE;
}

void myFgets(char* str, int n)
/*
* Function will perform the fgets command and also remove the newline that might be at the end of the string - a known issue with fgets.
* Input: the buffer to read into, the number of chars to read
* Output: none
*/
{
	fgets(str, n, stdin);
	str[strcspn(str, "\n")] = 0;
}

void checkAllocation(void* ptr)
/*
* This function checks in the allocating was good
* Input: a pointer
* Output: none
*/
{
	if (ptr == NULL) //if the pointer didnt got a value than exit
	{
		printf("Memory allocation error!\n");
		getchar();
		exit(EXIT_FAILURE);
	}
}
