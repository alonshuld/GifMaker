#define _CRT_SECURE_NO_WARNINGS
#include "options.h"

void optOne(FrameNode** head)
{
	char path[STR_LEN] = { 0 };
	char name[STR_LEN] = { 0 };
	int duration = 0;
	printf("*** Creating new frame ***\nPlease insert frame path:\n");
	myFgets(path, STR_LEN);
	if (!fileExist(path)) //checks the input
	{
		printf("File doesn't exist!");
		return;
	}
	printf("Please insert frame duration <in milliseconds>:\n");
	scanf("%d", &duration);
	getchar();
	while (duration <= ZERO) //checks the input
	{
		printf("Invalid input! Only numbers and higher then zero\n");
		scanf("%d", &duration);
		getchar();
	}
	printf("Please choose a name for that frame:\n");
	myFgets(name, STR_LEN);
	while (searchFrameByName(head, name)) //checks the input
	{
		printf("The name is already taken, please enter another name\n");
		myFgets(name, STR_LEN);
	}
	insertFrameLast(head, createFrameNode(createFrame(name, duration, path)));
}

void optTwo(FrameNode** head)
{
	char name[STR_LEN] = { 0 };
	printf("Enter the name of the frame you wish to erase\n");
	myFgets(name, STR_LEN);
	if (searchFrameByName(head, name))
	{
		deleteFrame(head, searchFrameByName(head, name));
	}
	else //checks the input
	{
		printf("There is no frame with this name!\n");
	}
}

void optThree(FrameNode** head)
{
	char name[STR_LEN] = { 0 };
	int pos = 0;
	printf("Enter the name of the frame\n");
	myFgets(name, STR_LEN);
	if (!searchFrameByName(head, name)) //checks the input
	{
		printf("There is no frame with this name!\n");
		return;
	}
	printf("Enter the new index in the movie you wish to place the frame\n");
	scanf("%d", &pos);
	getchar();
	while (pos <= ZERO) //checks the input
	{
		printf("Invalid input! Only numbers and higher then zero\n");
		scanf("%d", &pos);
		getchar();
	}
	changePos(head, searchFrameByName(head, name), pos);
}

void optFour(FrameNode** head)
{
	char path[STR_LEN] = { 0 };
	char name[STR_LEN] = { 0 };
	int duration = 0;
	printf("Enter the name of the frame\n");
	myFgets(name, STR_LEN);
	if (!searchFrameByName(head, name)) //checks the input
	{
		printf("There is no frame with this name!\n");
		return;
	}
	printf("Enter the new duration of the frame\n");
	scanf("%d", &duration);
	getchar();
	while (duration <= ZERO) //checks the input
	{
		printf("Invalid input! Only numbers and higher then zero\n");
		scanf("%d", &duration);
		getchar();
	}
	changeDuration(searchFrameByName(head, name), duration);
}

void optFive(FrameNode** head)
{
	int duration = 0;
	printf("Enter the new duration of the frames\n");
	scanf("%d", &duration);
	getchar();
	while (duration <= ZERO) //checks the input
	{
		printf("Invalid input! Only numbers and higher then zero\n");
		scanf("%d", &duration);
		getchar();
	}
	changeAllDuration(head, duration);
}

void optSix(FrameNode** head)
{
	printFrameList(head);
}

void optSeven(FrameNode** head)
{
	play(*head, WITH_COLOR);
}

void optEight(FrameNode** head)
{
	char path[STR_LEN] = { 0 };
	printf("Where to save the project? enter a full path and file name\n");
	myFgets(path, STR_LEN);
	saveProject(head, path);
}

void optNine(FrameNode** head)
{
	reverseList(head);
	play(*head, WITH_COLOR);
	reverseList(head);
}

void optTen(FrameNode** head)
{
	play(*head, WITHOUT_COLOR);
}

void optZero(FrameNode** head)
{
	freeFrameList(head); //free all the mallocs
}

void printMenu()
/*
* This function prints the menu
* Input: none
* Output: none
*/
{
	{
		printf("\nWhat would you like to do?\n [0] Exit\n [1] Add new Frame\n [2] Remove a Frame\n [3] Change index\n [4] Change frame duration\n [5] Change duration of all frames\n [6] List frames\n [7] Play movie!\n [8] Save project\n [9] Play the movie in reverse!\n [10] Play the movie in black and white!\n");
	}
}

int getChoice()
{
	int choice;
	scanf("%d", &choice);
	getchar();
	while (choice < OPT_ZERO && choice > OPT_TEN) //checks the input
	{
		printf("Invalid input! Only 0 - 8\n");
		scanf("%d", &choice);
		getchar();
	}
	return choice;
}
