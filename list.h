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
    void printList();
    int GetSize() const;

private:
    word * index;
    int size;
};