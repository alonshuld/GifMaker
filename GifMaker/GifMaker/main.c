#define _CRT_SECURE_NO_WARNINGS
//#define _CRTDBG_MAP_ALLOC //temp
#include "options.h"
//#include <crtdbg.h> //temp
#define OPT_ONE_STR "1"
#define OPT_TWO_STR "2"

#define OPT_ZERO 0
#define OPT_ONE 1
#define OPT_TWO 2
#define OPT_THREE 3
#define OPT_FOUR 4
#define OPT_FIVE 5
#define OPT_SIX 6
#define OPT_SEVEN 7
#define OPT_EIGHT 8
#define OPT_NINE 9
#define OPT_TEN 10

#define ZERO 0

void printMenu();

int main(void)
{	
	int choice = 0;
	FrameNode* head = NULL;
	head = startMenuForProject();
	choice = OPT_ONE;
	while (choice != OPT_ZERO)
	{
		printMenu();
		choice = getChoice();
		switch (choice)
		{
		case OPT_ONE: //option 1
			optOne(&head);
			break;
		case OPT_TWO: //option 2
			optTwo(&head);
			break;
		case OPT_THREE: // option 3
			optThree(&head);
			break;
		case OPT_FOUR: // option 4
			optFour(&head);
			break;
		case OPT_FIVE: // option 5
			optFive(&head);
			break;
		case OPT_SIX: // option 6
			optSix(&head);
			break;
		case OPT_SEVEN: // option 7
			optSeven(&head);
			break;
		case OPT_EIGHT: // option 8 (part 2)
			optEight(&head);
			break;
		case OPT_ZERO: // option 0
			optZero(&head);
			break;
		case OPT_NINE: // option 9 BONUS
			optNine(&head);
			break;
		case OPT_TEN: // option 10 BONUS
			optTen(&head);
			break;
		}
	}
	getchar();
	//printf("Leaks: %d", _CrtDumpMemoryLeaks()); //temp
	return EXIT_SUCCESS;
}
