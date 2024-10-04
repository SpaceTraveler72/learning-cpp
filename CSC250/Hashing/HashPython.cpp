#include "HashPython.h"

// Opens an input file of the given name
void HashPython::openFile(ifstream& inputFile, string fileName) {
    inputFile.open(fileName);

    //ends the program if can't find file to read from
    if (!inputFile) {
        cout << "Error finding file";
        exit(102);
    }
}

// calculates the hash value for a given keyword
int HashPython::calculateHash(const string keyword) {
    int sum = 0;
    for (int i = 0; i < keyword.length(); i++) {
        sum += (int)keyword[i];
    }

    return sum % TABLE_SIZE;
}


HashPython::HashPython() {
    ifstream inputfile;
    openFile(inputfile, "keywords.txt");

    // intilizes all the values in the table to be blank
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i].element = "";
    clear();

    // Makes the hash table from the keywords given by the file
    string keyword;
    while (inputfile >> keyword) {
        // calculates the hash value for the keyword
        int hash = calculateHash(keyword);

        // places the new element
        if (hashTable[hash].element == "") {
            hashTable[hash].element = keyword;
            continue;
        }

        // finds an empty location in the hash table for the new element if orginal is taken
        // uses linear probing with step size of 3 to resolve collision
        int index;
        bool failed = false;
        for (index = hash + 3; hashTable[index].element != ""; index = (index + 3) % TABLE_SIZE) {
            if (index == hash) {
                cout << "No avaliable place for " << keyword << " in the hash table";
                failed = true;
                break;
            }
        }
        if (failed) continue;

        hashTable[index].element = keyword;
    }
}

// finds if a given 
bool HashPython::search(const string seachValue) {
    int hashIndex = calculateHash(seachValue);

    if (hashTable[hashIndex].element == "") return false;
    if (hashTable[hashIndex].element == seachValue) {
        hashTable[hashIndex].count++;
        return true;
    }

    int index;
    for (index = hashIndex + 3; hashTable[index].element != seachValue; index = (index + 3) % TABLE_SIZE) {
        // looks for if the table has a blank element or the loop has already checked all avaliable locations
        if (hashTable[index].element == "") return false;
        if (index == hashIndex) return false;
    }

    hashTable[index].count++;
    return true;
}

// prints all elements in the table including index, element name, and count
void HashPython::print() const {
    int indexW = 6, elementNameW = 15, countW = 6;
    cout << left << setw(indexW) << "Index" << setw(elementNameW) 
        << "Element Name" << setw(countW) << "Count" << endl;

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].element == "") continue;

        cout << right << setw(indexW) << i << setw(elementNameW) 
            << hashTable[i].element << setw(countW) << hashTable[i].count << endl;
    }
}

// resets the count for all elements
void HashPython::clear() {
    for (int i = 0; i < TABLE_SIZE; i++) hashTable[i].count = 0;
}