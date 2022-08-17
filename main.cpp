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

#include "main.h"
#include <iostream>
#include <cstring>
#include <cctype>

int main() {

    cout << "Welcome to my word counter application "
         << "I hope you find this useful!" << endl;

    ifstream file;
    list sortedWordList;
    openFile(file, sortedWordList);
    sortedWordList.SortList();
    sortedWordList.CleanList();
    sortedWordList.printList();


    return 0;
}

void openFile(ifstream &file, list &wordList) {
    int wordSize = 0;
    char * filename = nullptr;
    cout << "enter a filename: > ";

    // loop through the cin stream and grab each letter.
    while(cin.good())
    {
        char letter = cin.get();
        // if the letter we get from the stream is a newline then break from this loop as that is end of user input
        if(letter == '\n')
        {
            break;
        }

        // if we haven't used filename yet, allocate memory for it.
        if(filename == nullptr)
        {
            filename = new char[2];
            filename[0] = letter;
            filename[1] = '\0';
            wordSize = 1;
        }
        else // we have used filename already, copy to temp delete previous pointer, and copy new cstring
        {
            wordSize = strlen(filename);
            char * temp = new char[wordSize + 2] {0};
            strcpy(temp, filename);
            delete[]filename;
            filename = temp;
            filename[wordSize] = letter;
            filename[wordSize + 1] = '\0';
        }
    }

   cout << "filename: [" << filename << "]\n";


    file.open(filename);

    if(!file.is_open())
    {
        // we need to loop and keep trying this method if the file isn't open.
        cout << "Error opening file: " << filename << " please try again " << endl;
        cout << endl;
        openFile(file, wordList);
    }
    else
    {
        cout << endl;
        readFile(file,wordList);
        cout << "[ " << filename << " ] has " << wordList.GetSize() << " words" << endl;


    }


    delete []filename; // release the memory from the []filename pointer.
}

void readFile(ifstream &file, list & index) {
    char * buffer = nullptr;
    word tempWord;

    while(file.good() && !file.eof())
    {
        int letter = file.get();

        if (isspace(letter) || letter == EOF)
        {
            if (buffer == nullptr) {
                continue;
            }

            tempWord.SetData(buffer);
            index.insert(tempWord);
            delete []buffer;
            buffer = nullptr;
            continue;
        }

        if(buffer == nullptr)
        {
            buffer = new char[2];
            buffer[0] = letter;
            buffer[1] = '\0';
        }
        else
        {
            int wordSize = strlen(buffer);
            char *temp = new char[wordSize + 2]{0};
            strcpy(temp,buffer);
            delete []buffer;
            buffer = temp;
            buffer[wordSize] = letter;
            buffer[wordSize + 1] = '\0';
        }
    }
    if (buffer != nullptr) {
        tempWord.SetData(buffer);
        index.insert(tempWord);
        delete []buffer;
    }

    file.close(); // all done with the file close it up.

}
