
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

enum Species {PERCH, WALLEYE, BASS};

class Node  {
public:
    string name;
    float length, weight;
    Species species;
    Node* next;

    // Default constructor 
    Node() {
        next = nullptr;
    }

    // Parameterised Constructor 
    Node(string name, float length, float weight, Species species) {
        this->name = name;
        this->length = length;
        this->weight = weight;
        this->species = species;
        this->next = nullptr;
    }

    // Copy Construtor
    Node(const Node* other) {
        name = other->name;
        length = other->length;
        weight = other->weight;
        species = other->species;
        next = nullptr;
    }
};

class FishList {


    Node* head;
    
    void displayReverse(Node* ptr);


public:
    //sets up the inital nodes
    FishList() {head = nullptr;}

    //Copys the passed in CharList
    FishList(const FishList& other);

    //Delets all nodes contained in class. Required to prevent memory leak
    ~FishList();

    // inserts the new fish in descending order in the list based on the sum of weight and length
    void insertNode(string name, float length, float weight, Species species);

    //Deletes the node with the specifed string
    void deleteNode(string removeString);

    // prints out the entire list as a table
    void displayList();

    // prints all information of the given species in a table
    void displaySpecies(Species printSpecies);

    //calls the recrusive function of the same name to get reversed list than displays
    void displayReverse();

    // Returns the Species as a string, so it can be used for printing
    string getStringSpecies(Species species);
};