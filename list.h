//  this is the header file for the list class
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