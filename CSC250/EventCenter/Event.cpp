#include "Event.hpp"

//An intialize constructor. Defualts to the values set equal if none are given
Event::Event(string name, EventType type, int maxAttandance) {
    this->name = name;
    this->type = type;
    this->maxAttandance = maxAttandance;
}

//returns enmu as a string so it can be printed
string Event::printType() {
    switch (type)
    {
    case GENERAL:
        return "General";
    case DINNER:
        return "Dinner";
    case CONCERT:
        return "Concert";
    default:
        return "How did you acomplish this?";
    }
}
