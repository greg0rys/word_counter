#include "main.h"
#include <iostream>
#include <cstring>
#include <cctype>

int main() {

    cout << "Welcome to my word counter application "
         << "I hope you find this useful!" << endl;

    word newWord("hello");
    word anotherWord("hi");
    char tester[6];
    strcpy(tester,"hello");
    list list1;
    list1.insert(newWord);
    list1.insert(anotherWord);
    word thirdWord("tester");
    list1.insert(thirdWord);
    thirdWord.SetData(tester);
    word fourth(thirdWord);
    fourth.GetData(tester);
    cout << tester << endl;
    fourth.SetData("Grego");
    fourth.GetData(tester);
    list1.insert(fourth);
    cout << "now tester is: " << tester << endl;
    list list2(list1);
    list1.printList();
    cout << endl << endl;
    list2.printList();

    ifstream file;
    openFile(file);

    return EXIT_SUCCESS;
}

void openFile(ifstream &file) {
    int wordSize = 0;
    char letter = 0;
    char * filename = nullptr;
    cout << "enter a filename: > ";

    // loop through the cin stream and grab each letter.
    while(cin.good())
    {
        letter = cin.get();
        // if we haven't used filename yet, allocate memory for it.
        if(filename == nullptr)
        {
            filename = new char[2];
            filename[0] = letter;
            filename[1] = '\0';
            wordSize = 2;

        }
        else // we have used filename already, copy to temp delete previous pointer, and copy new cstring
        {
            wordSize = strlen(filename);
            char * temp = new char[wordSize + 2] {0};
            strcpy(temp, filename);
            delete[]filename;
            filename = temp;
            filename[wordSize] = letter;

        }

        // if the letter we get from the stream is a newline then break from this loop as that is end of user input
        if(letter == '\n')
        {
            break;
        }


    }

//     make sure that our file name gettings the null node terminator appended to it so that it is a valid
//     cstring for the file.open(filename) method.
    if(filename[wordSize - 1] != '\0')
    {
        wordSize = strlen(filename);
        char * temp = new char[wordSize + 1];
        strcpy(temp, filename);
        delete []filename;
        filename = new char[wordSize + 1];
        strcpy(filename,temp);
        delete []temp;
        filename[wordSize - 1] = '\0'; // append null node to the end.
    }



    file.open(filename);

    if(!file.is_open())
    {
        // we need to loop and keep trying this method if the file isn't open.
        cout << "Error opening file: " << filename << " please try again " << endl;
        cout << endl;
        openFile(file);
    }
    else
    {
        list list1;
        cout << "file: " << filename << " has been opened! " << endl;
        cout << endl << endl;
        readFile(file,list1);
    }

    delete []filename; // release the memory from the []filename pointer.
}

void readFile(ifstream &file, list & index) {
    char * buffer = new char[2]{};
    word tempWord;
    char letter = 0;
    int wordSize = 1;

    // new approach get the whole line and break the line up into words.

    while(file.good() && !file.eof())
    {

        file.get(buffer, wordSize + 1);
        cout << buffer;




        file.get(buffer, wordSize + 1);
        cout << buffer;
//            char *temp = new char[wordSize + 2]{0};
//            strcpy(temp,buffer);
//            delete []buffer;
//            buffer = temp;
//            buffer[wordSize] = letter;


//
//        if(isspace(letter))
//        {
//            wordSize = strlen(buffer);
//            char *temp = new char[wordSize + 2]{0};
//            strcpy(temp,buffer);
//            delete []buffer;
//            buffer = temp;
//            buffer[wordSize] = '\0';
//            tempWord.SetData(buffer);
//            index.insert(tempWord);
//            buffer = nullptr;
//            continue;
//
//        }

    }


//    if(buffer && buffer[wordSize - 1] != '\0')
//    {
//        wordSize = strlen(buffer);
//        char * temp = new char[wordSize + 2]{0};
//        strcpy(temp,buffer);
//        delete []buffer;
//        buffer = temp;
//        buffer[wordSize] = '\0';
//        delete []temp;
//    }
//
//    tempWord.SetData(buffer);
//    index.insert(tempWord);
    delete []buffer;
//    index.printList();
}

void addNullNode(char * letters) {
    int size = strlen(letters) + 1;
    char * temp = new char[size];
    strcpy(temp, letters);
    delete []letters;
    letters = new char[size];
    strcpy(letters,temp);
    letters[size - 1] = '\0';
}

