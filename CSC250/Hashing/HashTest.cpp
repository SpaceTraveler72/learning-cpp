// Reads a python file and identifys keywords based off a hash table
// Sawyer Theis
// 4/13/24
// CSC 300
// Project 7

//#include "HashPython.h"
#include "HashPython.h"
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// Opens an input file of the given name
void openFile(ifstream& inputFile, string fileName) {
    inputFile.open(fileName);

    //ends the program if can't find file to read from
    if (!inputFile) {
        cout << "Error finding file";
        exit(102);
    }
}

// finds keywords from user inputed files until the user exits
void menu(HashPython hashTable) {
    while (true) {
        ifstream inputFile;
        string fileName;

        cout << "Enter name of python file (no spaces) or enter exit to quit: ";
        cin >> fileName;

        if (fileName == "exit") return;

        //Opens the users specifyied file
        openFile(inputFile, fileName);

        // searchs for all the words in the file in the hashTable
        string word;
        int totalWordsFound = 0;
        while (inputFile >> word) {
            if (hashTable.search(word)) 
                totalWordsFound++;
        }

        hashTable.print();
        cout << "Total Words Found: " << totalWordsFound << endl;
        hashTable.clear();
    }
}

int main() {
    HashPython hashTable;

    menu(hashTable);
}