//****************************************************************************
// Author:      Greg Shenefelt
// Assignment:  Homework Two
// Date:        August 10th 2022
// Description: This program reads in dynamic cstrings of user input to get a filename from the user
//              then a dynamic list is created that stores a word object for each word in the file.
//
// add, remove, and see grades
// Inputs: 		A file name the user wants to have counted.
// Outputs:		A unique list of words containing the count of each word.
// Sources:		cplusplus.com, zybooks, professor.
//****************************************************************************
#include "list.h"

int main();
void openFile(ifstream &file, list &);
void readFile(ifstream &file, list &);
