#include "word.h"
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

//default constructor
word::word() {
    data = nullptr; // right sized array so this must start as nullptr.
    count = 0;
}

word::word(const char * datum)
{
    this->data = new char[strlen(datum) + 1];
    strcpy(this->data, datum);
    this->count = 1;
}

//destructor
word::~word() {

    if(data){
        delete []data;
        data = nullptr;
    }

}

//copy constructor
word::word(const word &source) {

    data = nullptr;
   *this = source;
}

//overloaded assignment operator
word & word::operator=(const word &source) {

    if(this == &source) {
        return *this;
    }

    if(data)
    {
        delete []data;

    }

    if(source.data != nullptr)
    {
        this->data = new char[strlen(source.data) + 1];
        strcpy(this->data, source.data);

    }
    else
    {
        data = nullptr;
    }
    this->count = source.count;

    return *this;
}

void word::SetData(const char * datum) {

    // if we already have a data pointer delete it.
    if(data)
    {
        delete []data;
    }

    data = new char[strlen(datum) + 1];
    strcpy(data,datum);

}

void word::GetData(char * datum) const {
    strcpy(datum, data);
}

void word::PrintData() {
    cout << data << endl;
}