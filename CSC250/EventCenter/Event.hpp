#ifndef EVENT_HPP
#define EVENT_HPP

#include <string>
using namespace std;

enum EventType { GENERAL, DINNER, CONCERT };

class Event{
    string name;
    EventType type;
    int maxAttandance;

public:
    //An intialize constructor. Defualts to the values set equal if none are given
    Event(string name = "",  EventType type = GENERAL, int maxAttandance = 0);

    //returns each of the data the class stores
    string getName() {return name;}
    EventType getType() {return type;}
    int getMaxAttandance() {return maxAttandance;}

    //returns enmu as a string so it can be printed
    string printType();

    //sets the values of each data to what is passed in the method. no return
    void setName(string newName) {name = newName;}
    void setType(EventType newType) {type = newType;}
    void setMaxAttandance(int newMaxAttandance) {maxAttandance = newMaxAttandance;}
};


#endif