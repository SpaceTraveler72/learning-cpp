#ifndef CHARLIST_HPP
#define CHARLIST_HPP

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    char data;
    Node* next;

    // Default constructor 
    Node() {
        data = '\0';
        next = nullptr;
    }

    // Parameterised Constructor 
    Node(char data) {
        this->data = data;
        this->next = nullptr;
    }
};


class CharList {
    Node* head;

    //returns a backwards string of all the entire char list
    string displayReverse(Node* ptr);

public:
    //sets up the inital nodes
    CharList();

    //Copys the passed in CharList
    CharList(const CharList& other);

    //Delets all nodes contained in class. Required to prevent memory leak
    ~CharList();

    //Adds a new Node at the end of the list
    void appendNode(char newChar);

    // inserts the newChar somewhere in the list based on char numerical order
    void insertNode(char newChar);

    //Deletes the node with the specifed character
    void deleteNode(char removeChar);

    // Adds a node at the front of the list
    void addNode(char value);

    // prints out the entire char list
    void displayList();

    //calls the recrusive function of the same name to get reversed list than displays
    void displayReverse();
};

#endif