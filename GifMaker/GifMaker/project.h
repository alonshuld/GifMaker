#ifndef PROJECTH
#define PROJECTH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "utilities.h"

#define MAX_LENGTH 500
#define ONE 1
#define TWO 2
#define THREE 3
#define ZERO 0
#define STR_LEN 100
#define END_OF_STR '\0'
#define OPT_ZERO 0
#define OPT_ONE 1

void saveProject(FrameNode** head, char* path);
/*
* This function saves a project into a txt file
* Input: the head of the list and the path to save
* Output: none
*/

FrameNode* loadProject(char* path);
/*
* This function loads a project from txt file
* Input: the path of the saved file
* Output: pointer to a new head
*/

FrameNode* startMenuForProject();

#endif