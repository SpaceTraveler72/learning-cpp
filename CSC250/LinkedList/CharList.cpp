#include "CharList.hpp"

//sets up the inital nodes
CharList::CharList() {
    head = nullptr;
}

//Copys the passed in CharList
CharList::CharList(const CharList& other) {
    head = nullptr;

    if (other.head == nullptr) return;

    // Copy the head node
    head = new Node(other.head->data);

    Node* current = head;
    Node* otherCurrent = other.head->next;

    // Copy the rest of the nodes
    while (otherCurrent != nullptr) {
        current->next = new Node(otherCurrent->data);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
}

//Delets all nodes contained in class. Required to prevent memory leak
CharList::~CharList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

//Adds a new Node at the end of the list
void CharList::appendNode(char newChar) {
    Node* newNode = new Node(newChar);
    if (head == nullptr) {
        // If the list is empty, the new node becomes the head
        head = newNode;
        return;
    }

    Node* current = head;

    // Go to the end and append the new node
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
}

void CharList::addNode(char value) {
    if(head == nullptr) {
        head->data = value;
        head->next = nullptr;
        return;
    }

    Node* oldHead = new Node(head->data);
    oldHead->next = head->next;
    head->data = value;
    head->next = oldHead;
}


// inserts the newChar somewhere in the list based on char numerical order
void CharList::insertNode(char newChar) {
    Node* newNode = new Node(newChar);
    if (head == nullptr) {
        // If the list is empty, the new node becomes the head
        head = newNode;
        return;
    }

    Node* previous;
    Node* current = head;

    if (newChar <= head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Finds where the new node can insert into the array based on char int values 
    while (current != nullptr && newChar > current->data) {
        previous = current;
        current = current->next;
    }
    
    previous->next = newNode;
    newNode->next = current;
}

//Deletes the node with the specifed character
void CharList::deleteNode(char removeChar) {
    if (head == nullptr) return;

    Node* previous;
    Node* current = head;

    // Needs special code if head needs to be replaced
    if (head->data == removeChar) {
        head = head->next;
        delete current;
        return;
    }

    while (current != nullptr) {
        if (current->data == removeChar) {
            previous->next = current->next;
            delete current;
            return;
        }

        previous = current;
        current = current->next;
    }
}

// prints out the entire char list
void CharList::displayList() {
    Node* current = head;
    int count = 0;

    while (current != nullptr ) {
        cout << count << ":" << current->data << "  ";
        current = current->next;
        count++;
    }

    cout << endl;
}

//calls the recrusive function of the same name to get reversed list than displays
void CharList::displayReverse() {
    cout << displayReverse(head) << endl;
}

//returns a backwards string of all the entire char list
string CharList::displayReverse(Node* ptr) {
    if (ptr == nullptr) return "";

    return displayReverse(ptr->next) + ptr->data;
}