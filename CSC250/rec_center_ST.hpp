#ifndef REC_CENTER_HPP
#define REC_CENTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int SIZE = 5;
enum Location { GYM, PARK, CLASSROOM };


struct Activity
{
    string name;
    Location m_Location;
    int maxEnrollment, currentEnrollment;
    string participantEmails;
};


//Fills the array with the winter activities
void fillArray(Activity array[SIZE]);

//Sets up the values of a single activity
void initalizeActivity(Activity& activity, string name, Location location, int max_enrollment);

//returns the name of the location as a string
string getLocationName(Location location);

//Prints a table of all the data in each activity except the email list 
void printActivities(Activity array[SIZE]);

// Creates a menu that allows the user to print the activites, emails, or register
// returns false if user selects to exit menu
bool menu(Activity array[SIZE]);

//Prints the entire email list of each activity
void printEmailList(Activity array[SIZE]);

// Allows the user to add their email and enrollment to an user selected activity
void registerUser(Activity array[SIZE]);

// Checks if the inputed activity is a full and it is one of the activities
bool validateActivitySelection(Activity array[SIZE], int activityIndex);

// Adds a new email and upps the enrollment of a given activity
void addNewParticapate(Activity array[SIZE], int activityIndex, string particapintEmail);

#endif