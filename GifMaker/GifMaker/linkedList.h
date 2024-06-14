#ifndef LINKEDLISTH
#define LINKEDLISTH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE !FALSE
#define NAME_LEN 100

#define ZERO 0
#define ONE 1

// Frame struct
typedef struct Frame
{
	char* name;
	unsigned int	duration;
	char* path;
} Frame;


// Link (node) struct
typedef struct FrameNode
{
	Frame* frame;
	struct FrameNode* next;
} FrameNode;

Frame* createFrame(char* name, int duration, char* path);
/*
* This function will create new frame and set all the variables
* Input: the name of the frame the duration of it and the path of the image
* Output: pointer to the frame
*/

FrameNode* createFrameNode(Frame* newFrame);
/*
* This function will create a new FrameNode, it will set the valure of next to null
* Input: the new frame
* Output: pointer to the FrameNode*
*/

void insertFrameLast(FrameNode** head, FrameNode* newFrame);
/*
* This function adds a FrameNode to the end of the linked list
* Input: the head of the linked list and the new node
* Output: none
*/

void deleteFrame(FrameNode** head, FrameNode* frameToDelete);
/*
* This function delete a FrameNode from linked list
* Input: the head of the list and the frame that we want to delete
* Output: none
*/

void changePos(FrameNode** head, FrameNode* node, int pos);
/*
* This function changes position of a frame
* Input: the head of the linked list the name of the frame we want to move and the new postion
* Output: None
*/

void changeDuration(FrameNode* frameToChange, int duration);
/*
* This function changes the duration of a frame
* Input: the FrameNode and the new duration
* Output: none
*/

void changeAllDuration(FrameNode** head, int duration);
/*
* This function changes the duration of all the frames
* Input: the head of the linked list and the new duration
* Output: none
*/

void printFrameList(FrameNode** head);
/*
* This function prints the list of frames, the name of each frame duration and path
* Input: the head of the linked list
* Output: none
*/

void freeFrameList(FrameNode** head);
/*
* This function frees the linked list
* Input: the head of the linked list
* Output: none
*/

FrameNode* searchFrameByName(FrameNode** head, char* name);
/*
* This function searches for a frame by name
* Input: the head of the frame and the name we want to search
* Output: pointer to the frame node
*/

void reverseList(FrameNode** head);
/*
Reverse the list
Input: the head of the list
Output: none
*/

#endif
