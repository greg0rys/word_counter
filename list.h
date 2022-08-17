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
#pragma once
#include "word.h"

class list {
public:
    list();
    ~list();
    list(const list &);
    list & operator=(const list &);
    void insert(word &word);
    void remove(int); // remove a word at a given index
    void printList();
    int GetSize() const;
    int CountList() const; // count the words in the list
    void CleanList(); // remove duplicate entries in the list
    void SortList(); // sort the words in ASCII order.
    void FindWord(char *);

private:
    word * index;
    int size;
};