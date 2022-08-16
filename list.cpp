#include "list.h"

list::list() {
    index = nullptr;
    size = 0;
}

list::~list() {
    if(index)
    {
        delete []index;
        index = nullptr;
    }
}

list::list(const list &source) {
    index = nullptr;
    *this = source;
}

list &list::operator=(const list &source) {
    //don't self assign
    if(this == &source)
    {
        return *this;
    }
    // if we already have an index pointer delete it.
    if(index)
    {
        delete []index;
    }

    // check to ensure it's not nullptr // if it is keep it set at nullptr.
    if(source.index != nullptr)
    {
        index = new word[source.size];
        for(auto i = 0; i < source.size; i++)
        {
            index[i] = source.index[i];
        }
    }
    else
    {
        index = nullptr;
    }
    size = source.size;

    return *this;
}

void list::insert(word &source)
{

    word *temp = nullptr;
    if(index != nullptr)
    {
        temp = index;
        index = new word[size + 1];
        for(int i = 0; i < size; i++)
        {
            index[i] = temp[i];
        }
        delete []temp;
        size++;

    }
    else
    {
        index = new word[1];
        size = 1;
    }
    index[size - 1] = source;


}

void list::printList() {
    for(int i = 0; i < size; i++)
    {
        index[i].PrintData();
    }
}

int list::GetSize() const {
    return size;
}