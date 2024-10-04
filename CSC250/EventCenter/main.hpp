#ifndef MAIN_HPP
#define MAIN_HPP

#include "Event.hpp"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int const SIZE = 12;
enum MenuOption { PRINTALL, PRINTTYPE, EDITEVENT };

//creates a main menu that the user can interact with to edit/view the event array
void menu(Event events[]);

//runs the appropriate method for the given MenuOption(enmu)
void selectMenuOption(MenuOption input, Event events[]);

//prints all the events in the event array
void printAll(Event events[]);

// Prints all events of a user selected event
void printType(Event events[]);

// edits a selected event from the list
void editEvent(Event events[]);

//print each event name along with their place in the array
void printNumberedList(Event events[]);

#endif