#ifndef REC_ACTIVITY_HPP
#define REC_ACTIVITY_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

const int nameSize = 20;
enum Location { GYM, PARK, CLASSROOM };
enum MenuOption { PRINTALL, ADDACTIVITY, EDITACTIVITY };

struct Activity
{
    char name[nameSize];
    Location m_Location;
    int maxEnrollment;
};

// opens the file and creates one if one doesn't already exist
void openFile(fstream& file, string fileName);

//creates a main menu that the user can interact with to edit/view the file
void menu(fstream& file);

// returns the number of activities stored in the file
int getNumOfActivities(fstream& file);

//returns the name of the location as a string
string getLocationName(Location location);

// returns the value assosiated with the location name
Location getLocationNumber(string location);

//runs the appropriate method for the given MenuOption(enmu)
void selectMenuOption(MenuOption input, fstream& file);

//prints all data about every activity
void printAll(fstream& file);

//allows the user to input an activity to the end of the file
void addActivity(fstream& file);

//lets the user select an activity and edit it 
void editActivity(fstream& file);

//print each activity name along with their place in the file
void printNumberedList(fstream& file);

#endif