// Event Manager
// Sawyer Theis
// 11/13/23
// CSC 250
// Project 7

#include "main.hpp"

int main() {
    Event events[SIZE] = { Event("New Year's Party", CONCERT, 500),
        Event("Sweetheart Gala", DINNER, 250),
        Event("Jansen-Mendez Wedding", GENERAL, 350) };

    menu(events);

}

//creates a main menu that the user can interact with to edit/view the event array
void menu(Event events[]) {
    while (true) {
        cout << endl << "0: view all events, 1: view one type of event, 2: edit an event, -1: exit" << endl;

        int input;
        cin >> input;
        if (input == -1) return;
        cout << endl;

        selectMenuOption((MenuOption)input, events);

    }
}

//runs the appropriate method for the given MenuOption(enmu)
void selectMenuOption(MenuOption input, Event events[]) {
    switch (input) {
        case PRINTALL:
            printAll(events);
            break;
        case PRINTTYPE:
            printType(events);
            break;
        case EDITEVENT:
            editEvent(events);
            break;
    }
}

//prints all the events in the event array
void printAll(Event events[]) {
    int colWidth = 18;
    int maxStringLength = events[0].getName().length();
    //Sets the size of max string to the longest name in the array
    for (int i = 1; i < SIZE; i++) {
        if (maxStringLength < events[i].getName().length())
            maxStringLength = events[i].getName().length();
    }

    // Sets up column headers
    for (int i = 0; i < maxStringLength; i++) cout << " ";
    cout << left << setw(colWidth) << "Location" << setw(colWidth) <<
        "Max Enrollment" << endl;

    //Sets up row headers and values
    for (int i = 0; i < SIZE; i++) {
        cout << left << setw(maxStringLength) << events[i].getName();
        cout << right;
        cout << setw(colWidth) << events[i].printType();
        cout << setw(colWidth) << events[i].getMaxAttandance();
        cout << endl;
    }
}

// Prints all events of a user selected event
void printType(Event events[]) {
    int userInput;
    cout << "Pick a location to display all events for (0 for General, 1 for Dinners, 2 for Concerts)" <<endl;
    cin >> userInput;

    int typeSize = 0;
    Event typeArray[SIZE];

    //Makes a new array of the location specifyed by the user
    for (int i = 0; i < SIZE; i++) {
        if (events[i].getType() == (EventType)userInput) {
            typeArray[typeSize] = events[i];
            typeSize++;
        }
    }

    int colWidth = 18;
    int maxStringLength = typeArray[0].getName().length();
    //Sets the size of max string to the longest name in the array
    for (int i = 1; i < typeSize; i++) {
        if (maxStringLength < typeArray[i].getName().length())
            maxStringLength = typeArray[i].getName().length();
    }

    // Sets up column headers
    for (int i = 0; i < maxStringLength; i++) cout << " ";
    cout << left << setw(colWidth) << "Max Enrollment" << endl;

    //Sets up row headers and values
    for (int i = 0; i < typeSize; i++) {
        cout << left << setw(maxStringLength) << typeArray[i].getName();
        cout << right;
        cout << setw(colWidth) << typeArray[i].getMaxAttandance();
        cout << endl;
    }
}

// edits a selected event from the list
void editEvent(Event events[]) {
    printNumberedList(events);

    int selectedEvent;
    string newName;
    int newType, newMaxAttandance;

    cout << "Enter the number of the event to edit: ";
    cin >> selectedEvent;

    cout << "Enter new name: ";
    cin >> newName;
    cout << "Enter new type (0 for General, 1 for Dinners, 2 for Concerts): ";
    cin >> newType;
    cout << "Enter new max attandance: ";
    cin >> newMaxAttandance;
    
    events[selectedEvent].setName(newName);
    events[selectedEvent].setType((EventType)newType);
    events[selectedEvent].setMaxAttandance(newMaxAttandance);
}

//print each event name along with their place in the array
void printNumberedList(Event events[]) {
    for (int i = 0; i < SIZE; i++) {
        cout << i << "   " << events[i].getName() << endl;
    }
}

