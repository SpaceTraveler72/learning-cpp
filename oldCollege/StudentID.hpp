
#ifndef STUDENTID_HPP
#define STUDENTID_HPP

#include <iostream>
#include <fstream>
using namespace std;

//Sets up the input file
void openFile(ifstream& inputFile);

// Allocates memory to the array based on the input file
int getLength(ifstream& inputFile, int*& ids, float*& costs);

// Puts data from a file into an array of student IDs and Costs
int getData(int*& ids, float*& costs);

// Sorts the arrays in order from lowest to highest student IDs
void sortData(int*& ids, float*& costs, int length);

// Search for a given studentID and return its index value in the array
int binarySearch(int searchValue, int* array, int length);

// Takes a user input ID and finds the corresponding cost
void userSearch(int* ids, float* costs, int length);

// Prints the arrays. Used for debugging
void printData(int* ids, float* costs, int length);

#endif