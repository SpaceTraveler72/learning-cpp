// This program tests 4 different sorting alogrithms: insertion, merge, quick sort, and heap sort
// Given a user inputed size it will print out how long each algorith took to sort the array
// Sawyer Theis
// 4/30/24
// CSC 300
// Project 9

#include <iostream>
#include <iomanip>
#include "Sorts.h"
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

// Takes a size from the and runs sorting alogrothims
void userInput(Sorts sort);
// Sorts an array of the given size using 3 varius methods and mesurse the time each took
void sortArrays(int size, Sorts sort);
// Fills an entire array with random numbers from 0 to 100
void generateRandomArray(vector<int>& arr);


int main() {
    Sorts sort;
    
    userInput(sort);
}

// Takes a size from the and runs sorting alogrothims, exits the loop if the user gives a non-viald number
void userInput(Sorts sort) {
    while (true) {
        int userSize;
        cout << "Enter a size, or a letter to exit loop: ";
        if (!(cin >> userSize)) { 
            return;
        }

        if (userSize <= 0) {
            cout << "Enter a valid size (size greater than 0)" << endl;
            continue;
        }

        sortArrays(userSize, sort);
    }
}


// Sorts an array of the given size using 3 varius methods and mesurse the time each took
void sortArrays(int size, Sorts sort) {
    vector<int> arr1(size);
    generateRandomArray(arr1);
    vector<int> arr2(arr1);
    vector<int> arr3(arr1);
    vector<int> arr4(arr1);

    clock_t timeStart;

    if (size <= 100) {
        cout << "Original Array" << endl;
        sort.printArray(arr1);
    }

   // Runs Insertion sort
    timeStart = clock();
    sort.insertionSort(arr1);
    cout << "Insertion Sort Time: " << (double)(clock() - timeStart) / CLOCKS_PER_SEC << endl;

    if (size <= 100) {
        sort.printArray(arr1);
    }

    // Runs Merge sort
    timeStart = clock();
    sort.mergeSort(arr2, 0, size-1);
    cout << "Merge Sort Time: " << (double)(clock() - timeStart) / CLOCKS_PER_SEC << endl;

    if (size <= 100) {
        sort.printArray(arr2);
    }

    // Runs quick sort
    timeStart = clock();
    sort.quickSort(arr3, 0, size-1);
    cout << "Quick Sort Time: " << (double)(clock() - timeStart) / CLOCKS_PER_SEC << endl;

    if (size <= 100) {
        sort.printArray(arr3);
    }

    // Runs heap sort
    timeStart = clock();
    sort.heapSort(arr4);
    cout << "Heap Sort Time: " << (double)(clock() - timeStart) / CLOCKS_PER_SEC << endl;

    if (size <= 100) {
        sort.printArray(arr4);
    }

}

// Fills an entire array with random numbers from 0 to 100
void generateRandomArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = rand();
    }
}
