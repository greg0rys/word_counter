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
    char * filename = nullptr;
    list list1;
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

    std::cout << "filename: [" << filename << "]\n";


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
        cout << "file: " << filename << " has been opened! " << endl;
        cout << endl << endl;
        readFile(file,list1);

    }

    cout << "Before list clean: " << list1.GetSize() << endl;
    list1.printList();
    list1.SortList();
    list1.CleanList();
    cout << endl << endl;
    cout << "After list clean: " << list1.GetSize() << endl;
    list1.printList();

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
