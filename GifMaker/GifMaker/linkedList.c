#define _CRT_SECURE_NO_WARNINGS

#include "linkedList.h"
#include "utilities.h"

Frame* createFrame(char* name, int duration, char* path)
/*
* This function will create new frame and set all the variables
* Input: the name of the frame the duration of it and the path of the image
* Output: pointer to the frame
*/
{
    Frame* newFrame = (Frame*)malloc(sizeof(Frame));
    checkAllocation(newFrame);
    newFrame->name = (char*)malloc((strlen(name) + ONE) * sizeof(char));
    checkAllocation(newFrame->name);
    strcpy(newFrame->name, name);
    newFrame->duration = duration;
    newFrame->path = (char*)malloc((strlen(path) + ONE) * sizeof(char));
    checkAllocation(newFrame->path);
    strcpy(newFrame->path, path);
    return newFrame;
}

FrameNode* createFrameNode(Frame* newFrame)
/*
* This function will create a new FrameNode, it will set the valure of next to null
* Input: the new frame
* Output: pointer to the FrameNode*
*/
{
    FrameNode* newFrameNode = (FrameNode*)malloc(sizeof(FrameNode));
    checkAllocation(newFrameNode);
    newFrameNode->frame = newFrame;
    newFrameNode->next = NULL;
    return newFrameNode;
}

void insertFrameLast(FrameNode** head, FrameNode* newFrameNode)
/*
* This function adds a FrameNode to the end of the linked list
* Input: the head of the linked list and the new node
* Output: none
*/

{
    FrameNode* current = *head;
    if (*head == NULL) //if the list doesn`t exists than it is the first person
    {
        *head = newFrameNode;
    }
    else //if the list does exist
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newFrameNode;
    }
}

void deleteFrame(FrameNode** head, FrameNode* frameToDelete)
/*
* This function delete a FrameNode from linked list
* Input: the head of the list and the frame that we want to delete
* Output: none
*/
{
    FrameNode* current = *head;
    if (current != NULL && current == frameToDelete) //if the list doesn`t exists than it is the first person
    {
        *head = current->next;
    }
    else //if the list doesn`t exists than it is the first person
    {
        while (current)
        {
            if (current->next == frameToDelete)
            {
                current->next = frameToDelete->next;
            }
            current = current->next;
        }
    }
    free(frameToDelete->frame->name);
    free(frameToDelete->frame->path);
    free(frameToDelete->frame);
    free(frameToDelete);
}

void changePos(FrameNode** head, FrameNode* node, int pos)
{
    FrameNode* root = *head;
    FrameNode* current = *head;
    FrameNode* prevToNewPos = NULL;
    FrameNode* prev = NULL;
    int count = 0;
    int i = 0;
    pos--;
    while (current && current != node)
    {
        prev = current;
        current = current->next;
        count++;
    }
    if (count == pos)
    {
        return;
    }
    if (!count)
    {
        *head = root->next;
        root = *head;
    }
    else
    {
        prev->next = current->next;
    }
    if (pos == ZERO)
    {
        current->next = root;
        *head = current;
        return;
    }
    prevToNewPos = root;
    for (i = 0; i < pos - ONE && prevToNewPos->next != ZERO; i++)
    {
        prevToNewPos = prevToNewPos->next;
    }
    current->next = prevToNewPos->next;
    prevToNewPos->next = current;
}


void changeDuration(FrameNode* frameToChange, int duration)
/*
* This function changes the duration of a frame
* Input: the FrameNode and the new duration
* Output: none
*/
{
    frameToChange->frame->duration = duration;
}

void changeAllDuration(FrameNode** head, int duration)
/*
* This function changes the duration of all the frames
* Input: the head of the linked list and the new duration
* Output: none
*/
{
    FrameNode* current = *head;
    while (current)
    {
        changeDuration(current, duration);
        current = current->next;
    }
}

void printFrameList(FrameNode** head)
/*
* This function prints the list of frames, the name of each frame duration and path
* Input: the head of the linked list
* Output: none
*/
{
    FrameNode* current = *head;
    printf("\tName\t\tDuration\t\tPath\n");
    while (current)
    {
        printf("\t%s\t\t%d ms\t\t\t%s\n", current->frame->name, current->frame->duration, current->frame->path);
        current = current->next;
    }
}

void freeFrameList(FrameNode** head)
/*
* This function frees the linked list
* Input: the head of the linked list
* Output: none
*/

{
    FrameNode* current = *head;
    FrameNode* temp = NULL;
    while (current)
    {
        temp = current->next;
        free(current->frame->name);
        free(current->frame->path);
        free(current->frame);
        free(current);
        current = temp;
    }
    *head = NULL;
}

FrameNode* searchFrameByName(FrameNode** head, char* name)
/*
* This function searches for a frame by name
* Input: the head of the frame and the name we want to search
* Output: pointer to the frame node
*/
{
    FrameNode* current = *head;
    while (current)
    {
        if (!strcmp(current->frame->name, name))
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void reverseList(FrameNode** head)
/*
Reverse the list
Input: the head of the list
Output: none
*/
{
    FrameNode* prev = NULL;
    FrameNode* next = NULL;
    FrameNode* current = *head;
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
