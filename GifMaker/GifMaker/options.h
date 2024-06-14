#ifndef OPTIONSH
#define OPTIONSH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "utilities.h"
#include "project.h"
#include "view.h"

#define WITH_COLOR 1
#define WITHOUT_COLOR 0
#define OPT_TEN 10
#define OPT_ZERO 0

void optOne(FrameNode** head);
void optTwo(FrameNode** head);
void optThree(FrameNode** head);
void optFour(FrameNode** head);
void optFive(FrameNode** head);
void optSix(FrameNode** head);
void optSeven(FrameNode** head);
void optEight(FrameNode** head);
void optNine(FrameNode** head);
void optTen(FrameNode** head);
void optZero(FrameNode** head);
void printMenu();
int getChoice();

#endif
