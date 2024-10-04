#ifndef HASHPYTHON_H
#define HASHPYTHON_H

#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


const int TABLE_SIZE = 67;

class HashPython {
    struct TableElem
    {
        string element;
        int count;
    };
    TableElem hashTable[TABLE_SIZE];

    void openFile(ifstream& inputFile, string fileName);
    int calculateHash(const string keyword);

public:
    HashPython();       // constructor
    bool search(const string);
    void print() const;
    void clear();
};

#endif