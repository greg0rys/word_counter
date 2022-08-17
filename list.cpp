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

// remove an element from the array at a given index.
void list::remove(int indexToRemove) {

    word * temp = nullptr;

    if(index == nullptr)
    {
        cout << "Error index is null, nothing to delete. " << endl;
        return;
    }
    else
    {
        for(auto i = indexToRemove; i < (size - 1); i++)
        {
            index[i] = index[i + 1];
        }
        size--;
        temp = index;
        index = new word[size];
        for(auto j = 0; j < size; j++)
        {
            index[j] = temp[j];
        }
        delete []temp;
    }


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



int list::CountList() const {
    return 0;
}

// loop through the array find duplicates and remove them
void list::CleanList() {
    char *tempWordData = nullptr;
    char *tempWordData2 = nullptr;
    int totalCount = 0;
    word tempWord;
    word tempWord2;
    list sortedList;

    for (int i = 0; i < size; i++) {
        tempWord = index[i];

        if (tempWordData != nullptr) {
            delete[]tempWordData;
            tempWordData = new char[tempWord.GetWordLength() + 1];
        } else {
            tempWordData = new char[tempWord.GetWordLength() + 1];
        }

        tempWord.GetData(tempWordData);
        for(int k = i +1; k < size; k++)
        {
            FindWord(tempWordData);
        }


    }


    // this loop will set the word count to 1 for all words that only appear once in the list.
    for(int x = 0; x < size; x++)
    {
        totalCount = index[x].GetCount();
        if(totalCount < 1)
        {
                index[x].IncrementCount();

        }
    }

    for(int z = 0; z < size - 1; z++)
    {
        tempWord = index[z];
        tempWord2 = index[z + 1];

        if (tempWordData != nullptr) {
            delete[]tempWordData;
            tempWordData = new char[tempWord.GetWordLength() + 1];
        }
        else {
            tempWordData = new char[tempWord.GetWordLength() + 1];
        }
        tempWord.GetData(tempWordData);

        if (tempWordData2 != nullptr) {
            delete[]tempWordData2;
            tempWordData2 = new char[tempWord2.GetWordLength() + 1];
        }
        else {
            tempWordData2 = new char[tempWord2.GetWordLength() + 1];
        }
        tempWord2.GetData(tempWordData2);

        if(strcmp(tempWordData,tempWordData2) == 0)
        {
            remove(z);
            z = -1;
        }
    }



    if(tempWordData != nullptr)
    {
        delete []tempWordData;
    }

    if(tempWordData2 != nullptr)
    {
        delete []tempWordData2;
    }

}

// loop through the array and sort the words by ASCII val.
void list::SortList() {

    word tempWord;
    word tempWord2;
    char * tempWordData = nullptr;
    char * tempWordData2 = nullptr;
    list sortedList;


    for(int i = 0; i < size - 1; i++)
    {
        tempWord = index[i];
        if(tempWordData != nullptr)
        {
            delete []tempWordData;
            tempWordData = new char[tempWord.GetWordLength() + 1];
        }
        else
        {
            tempWordData = new char[tempWord.GetWordLength() + 1];
        }

        tempWord.GetData(tempWordData);

        tempWord2 = index[i + 1];

        if(tempWordData2 != nullptr)
        {
            delete []tempWordData2;
            tempWordData2 = new char[tempWord2.GetWordLength() + 1];
        }
        else
        {
            tempWordData2 = new char[tempWord2.GetWordLength() + 1];
        }

        tempWord2.GetData(tempWordData2);

        if(strcmp(tempWordData, tempWordData2) > 0)
        {

            index[i] = tempWord2;
            index[i + 1] = tempWord;

            i = -1;

        }



    }


    if(tempWordData != nullptr)
    {
        delete []tempWordData;
    }

    if(tempWordData2 != nullptr)
    {
        delete []tempWordData2;
    }


}

void list::FindWord(char * searchWord)  {
    char * currentWord = nullptr;
    int totalFound = 0;
    for(int i = 0; i < size; i++)
    {
        if(currentWord == nullptr)
        {
            currentWord = new char[index[i].GetWordLength() + 1];
        }
        else
        {
            delete []currentWord;
            currentWord = new char[index[i].GetWordLength() + 1];

        }
        index[i].GetData(currentWord);
        if(strcmp(searchWord,currentWord) == 0)
        {
            totalFound++;
        }


    }

    for(int y = 0; y < size; y++)
    {
        if(currentWord == nullptr)
        {
            currentWord = new char[index[y].GetWordLength() + 1];
        }
        else
        {
            delete []currentWord;
            currentWord = new char[index[y].GetWordLength() + 1];

        }

        index[y].GetData(currentWord);
        if(strcmp(searchWord, currentWord) == 0)
        {
            index[y].SetCount(totalFound);
        }
    }

    if(currentWord != nullptr)
    {
        delete []currentWord;
    }



}


