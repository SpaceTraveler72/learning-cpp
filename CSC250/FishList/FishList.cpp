#include "FishList.h"

FishList::FishList(const FishList& other) {
    head = nullptr;

    if (other.head == nullptr) return;

    // Copy the head node
    head = new Node(other.head);

    Node* current = head;
    Node* otherCurrent = other.head->next;

    // Copy the rest of the nodes
    while (otherCurrent != nullptr) {
        current->next = new Node(otherCurrent);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
}

FishList::~FishList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void FishList::insertNode(string name, float length, float weight, Species species) {
    Node* newNode = new Node(name, length, weight, species);

    if (head == nullptr) {
        // If the list is empty, the new node becomes the head
        head = newNode;
        return;
    }

    Node* previous;
    Node* current = head;

    if (length+weight <= head->weight + head->length) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Finds where the new node can insert into the array based on getSize function
    while (current != nullptr && length+weight > current->length + current->weight) {
        previous = current;
        current = current->next;
    }

    previous->next = newNode;
    newNode->next = current;
}

//Deletes the node with the specifed string
void FishList::deleteNode(string removeString) {
    if (head == nullptr) return;

    Node* previous;
    Node* current = head;

    // Needs special code if head needs to be replaced
    if (head->name == removeString) {
        head = head->next;
        delete current;
        return;
    }

    while (current != nullptr) {
        if (current->name == removeString) {
            previous->next = current->next;
            delete current;
            return;
        }

        previous = current;
        current = current->next;
    }
}

void FishList::displayList() {
    Node* current = head;

    cout << left << setw(20) << "Name" << setw(10) << "Score" << setw(10) << "Length" 
        << setw(10) << "Weight" << setw(10) << "Species";
    cout << right << endl;
    while (current != nullptr) {
        cout << setw(20) << current->name
            << setw(10) << current->length + current->weight
            << setw(10) << current->length
            << setw(10) << current->weight
            << setw(10) << getStringSpecies(current->species)
            << endl;
        current = current->next;
    }
}

void FishList::displaySpecies(Species printSpecies) {
    Node* current = head;

    cout << left << setw(20) << "Name" << setw(10) << "Score" << setw(10) << "Length" << setw(10) << "Weight";
    cout << right << endl;
    while (current != nullptr) {
        if (printSpecies == current->species) {
            cout << setw(20) << current->name
                << setw(10) << current->length + current->weight
                << setw(10) << current->length
                << setw(10) << current->weight
                << endl;
        }
        
        current = current->next;
    }
}

void FishList::displayReverse() {
    cout << left << setw(20) << "Name" << setw(10) << "Score" << setw(10) 
        << "Length" << setw(10) << "Weight" << setw(10) << "Species";
    cout << right << endl;

    displayReverse(head);
}

void FishList::displayReverse(Node* ptr) {
    if (ptr == nullptr) return;

    displayReverse(ptr->next);

    cout << setw(20) << ptr->name
        << setw(10) << ptr->length + ptr->weight
        << setw(10) << ptr->length
        << setw(10) << ptr->weight
        << setw(10) << getStringSpecies(ptr->species)
        << endl;
}

string FishList::getStringSpecies(Species species) {
    switch (species) {
    case WALLEYE:
        return "Walleye";
    case PERCH:
        return "Perch";
    case BASS:
        return "Bass";

    default:
        return "Loc Ness";
    }
}
