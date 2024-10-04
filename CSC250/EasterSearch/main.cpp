// Reads a file containing prizes and sorts them into a binary search tree
// The user can the use a menu to find stuff about the tree
// Sawyer Theis
// 3/25/24
// CSC 300
// Project 6

#include "BST.h"
#include <fstream>
#include <iostream>
using namespace std;

enum MenuSelection {PRINTROOT, PRINTPRIZES, FINDPRIZE, TREEHEIGHT, TOTALPRIZES};

// Opens an input file of the given name
void openFile(ifstream& inputFile, string fileName) {
    inputFile.open(fileName);

    //ends the program if can't find file to read from
    if (!inputFile) {
        cout << "Error finding file";
        exit(102);
    }
}

// Sorts the prizes from the input file into a binary search tree
void sortPrizes(ifstream& inputfile, BinaryTree& prizes) {
    int quantity;
    string name; 

    for (int i = 0; inputfile >> quantity; i++) {
        inputfile.ignore(100, ' ');

        getline(inputfile, name);

        // for debuging
        //cout << quantity << name << endl;

        prizes.insertNode(name, quantity);
    }
}

// Asks the user for the first part of a prize name the attempts to locate it in the tree
void findPrize(BinaryTree& prizes) {
    string input;
    cout << "Enter the first few letters of the prize (Capatilzation Matters): ";
    getline(cin >> ws, input);

    int quantity;
    string name;

    if (!prizes.searchNode(input, name, quantity)) {
        cout << "Prize not Found" << endl;
        return;
    }

    cout << quantity << " " << name << endl;
}

// Repeatedly prompts the user with different choices until they exit
void menu(BinaryTree& prizes) {
    while (true) {
        int input;
        cout << "0 to print the root, 1 to print all prizes" << endl;
        cout << "2 to search for a prize, 3 to print the tree height" << endl;
        cout << "4 to get total number of prizes, Type other number else to exit program" << endl; 
        cin >> input;

        switch ((MenuSelection)input) {
        case PRINTROOT:
            prizes.displayRoot();
            break;
        case PRINTPRIZES:
            prizes.displayPreOrder();
            break;
        case FINDPRIZE:
            findPrize(prizes);
            break;
        case TREEHEIGHT:
            cout << "Tree Height: " << prizes.getTreeHeight() << endl;
            break;
        case TOTALPRIZES:
            cout << "Total Prizes: " << prizes.getTotalQuantity() << endl;
            break;
        
        default:
            return;
        }
    }
}

int main() {
    ifstream file;
    BinaryTree prizes;
    openFile(file, "prizes.txt");

    sortPrizes(file, prizes);

    menu(prizes);
}