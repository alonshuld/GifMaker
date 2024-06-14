#define _CRT_SECURE_NO_WARNINGS

#include "project.h"

const char SPLITER[TWO] = ";";

void saveProject(FrameNode** head, char* path)
/*
* This function saves a project into a txt file
* Input: the head of the list and the path to save
* Output: none
*/
{
	FILE* project = fopen(path, "w");
	FrameNode* current = *head;
	if (!project)
	{
		printf("Can't open this file!\n");
		return;
	}
	while (current)
	{
		fprintf(project, "%s;%d;%s\n", current->frame->name, current->frame->duration, current->frame->path);
		current = current->next;
	}
	fclose(project);
	printf("*** Project saved successfuly ***\n");
}

FrameNode* loadProject(char* pathToProject)
/*
* This function loads a project from txt file
* Input: the path of the saved file
* Output: pointer to a new head
*/
{
	FrameNode* current = NULL;
	FrameNode* head = current;
	FILE* project = fopen(pathToProject, "r");
	char buffer[MAX_LENGTH] = { 0 };
	char* token = NULL;
	char path[STR_LEN] = { 0 };
	char name[STR_LEN] = { 0 };
	int counter = ONE;
	int duration = 0;
	while (fgets(buffer, MAX_LENGTH, project))
	{
		token = strtok(buffer, SPLITER);
		while (token != NULL)
		{
			if (counter % TWO == ZERO)
			{
				duration = atoi(token); //copy duration
			}
			else if (counter % THREE == ZERO)
			{
				token[strlen(token) - ONE] = END_OF_STR;
				strcpy(path, token); //copy path
				insertFrameLast(&head, createFrameNode(createFrame(name, duration, path))); //create node
			}
			else
			{
				strcpy(name, token); //copy name
			}
			counter++;
			token = strtok(NULL, SPLITER);
		}
		counter = ONE;
	}
	fclose(project);
	printf("*** Project loaded successfuly ***\n");
	return head;
}

FrameNode* startMenuForProject()
{
	int choice = 0;
	FrameNode* head = NULL;
	char pathToProject[STR_LEN] = { 0 };
	printf("Welcome to Alon's Movie Maker! what would you like to do\n [0] Create a new project\n [1] Load existing project\n");
	scanf("%d", &choice);
	getchar();
	while (choice != OPT_ONE && choice != OPT_ZERO) //checks the input
	{
		printf("Invalid choice! only 0 or 1\n");
		scanf("%d", &choice);
		getchar();
	}
	if (choice) //(part 2)
	{
		printf("Enter the path of the project <includeing project name>:\n");
		myFgets(pathToProject, STR_LEN);
		while (!fileExist(pathToProject)) //checks the input
		{
			printf("Invalid path! Try again:\n");
			myFgets(pathToProject, STR_LEN);
		}
		head = loadProject(pathToProject);
	}
	return head;
}
