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
    cout << "enter a filename: " << endl;

    while(cin.good()==true && cin.peek() != EOF)
    {
        letter = cin.get();

        if(filename != nullptr)
        {
            char * temp = nullptr;
            temp = filename;
            filename = new char[wordSize + 1];
            for(int i=0; i < wordSize; i++)
            {
                filename[i] = temp[i];
            }
            delete []temp;
            wordSize++;
        }
        else
        {
            filename = new char[1];
            wordSize = 1;
        }
        filename[wordSize - 1] = letter;



        if(letter == '\n')
        {
            break;
        }

        file.open(filename);
        if(!file)
        {
            char * temp = nullptr;
            if(temp == nullptr)
            {
                temp = new char[wordSize + 1];
            }
            cout << "Error opening file: " << filename << endl;
            openFile(file);
        }

    }

    cout << "filename is: " << filename;
    delete []filename;
}

//if(filename == nullptr) {
//filename = new char[wordSize + 2];
//filename[0] = letter;
//wordSize = 1;
//
//}
//else
//{
//char * temp = new char[wordSize + 2];
//strcpy(temp, filename);
//for(int i =0; i < wordSize; i++)
//{
//filename[i] = temp[i];
//}
//wordSize++;
//filename[wordSize - 1] = letter;
//delete []temp;
//
//}