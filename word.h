#pragma once
#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;



class word {
public:
    word();
    word(const word &);
    word(const char *);
    ~word();
    word & operator=(const word &);
    void SetData(const char *);
    void GetData(char *) const;
    void PrintData();
private:
    char * data;
    int count;
};