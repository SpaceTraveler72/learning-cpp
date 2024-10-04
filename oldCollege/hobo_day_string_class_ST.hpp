#ifndef HOBOS_ST_HPP
#define HOBOS_ST_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// Activities in order - Hobo Button Day, Lil’s Food Drive, Will’s Football Toss, Hobo Stew Feed, Band Rally
const int ROWS = 5;
// Class in order - Freshman, Sophomore, Junior, Senior
const int COLS = 4;
const int maxStringLength = 20;

//Sets up the input file
void openFile(ifstream& inputFile, string fileName);

// puts data from “HoboDay.txt” into the the arrays
void readData(int particapation[][COLS], string activityNames[]);

// finds the sum of each row and stores it in rowTotals
void rowSum(int particapation[][COLS], int rowTotals[]);

// finds the row location of the lowest value
int findLowLocation(int rowTotals[]);

// finds the row and col location of the highest value
int findHighLocation(int rowTotals[]);

// Saves a bunch of data analyzed from the Hobo Day array to “results.txt”
void saveHoboDayResults(int particapation[][COLS], string activityNames[], int rowTotals[], int lowLocation, int highLocation);

// converts a col location to the name of that location-  Freshman, Sophomore, Junior, or Senior
string getColName(int colLocation);

#endif