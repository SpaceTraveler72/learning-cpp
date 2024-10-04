// Linked List for tracking scores in a fishing tournament
// Sawyer Theis
// 1/26/24
// CSC 250
// Project 1

#include "FishList.h"
#include <iostream>
using namespace std;

enum MenuOption { INSERT, DISPLAYLIST, DISPLAYSPECIES, DISPLAYREVERSE, REMOVE};

void menu(FishList &scores);

void insert(FishList& scores);

void displaySpecies(FishList& scores);

void remove(FishList& scores);

int main() {
    FishList scores;

    menu(scores);
}

void menu(FishList& scores) {
    while (true) {
        int input;
        MenuOption selectedOption;
        cout << "Type 0 to insert, 1 to display list, 2 to display just certian species, 3 to display in reverse, and 4 to remove"
            << endl << "Type any other number to exit"
            << endl << "Select Menu Option: ";
        
        cin >> input;
        selectedOption = (MenuOption)input;

        switch (selectedOption)
        {
        case INSERT:
            insert(scores);
            break;
        case DISPLAYLIST:
            scores.displayList();
            break;
        case DISPLAYSPECIES:
            displaySpecies(scores);
            break;
        case DISPLAYREVERSE:
            scores.displayReverse();
            break;
        case REMOVE:
            remove(scores);
            break;
        
        default:
            return;
        }
    }
}

void insert(FishList &scores) {
    string name;
    float length, weight;
    int species;

    cout << "Enter name: ";
    getline(cin >> ws, name);
    cout << "Enter length: ";
    cin >> length;
    cout << "Enter weight: ";
    cin >> weight;
    cout << "Enter species (0 for Perch, 1 for Walleye, 2 for Bass): ";
    cin >> species;

    scores.insertNode(name, length, weight, (Species)species);
}

void displaySpecies(FishList& scores) {
    cout << "Enter species (0 for Perch, 1 for Walleye, 2 for Bass): ";
    int temp;
    cin >> temp;

    scores.displaySpecies((Species)temp);
}

void remove(FishList& scores) {
    string name;

    cout << "Enter name to remove: ";
    getline(cin >> ws, name);

    scores.deleteNode(name);
}
