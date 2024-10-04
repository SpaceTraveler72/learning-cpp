#ifndef SORTS_H
#define SORTS_H

#include <vector>
using namespace std;


class Sorts {

    // Merge two sorted subarrays arr[left..mid] and arr[mid+1..right]
    void merge(vector<int>& arr, int l, int m, int r);

    // Function to partition the array and return the pivot index
    int partition(vector<int>& arr, int low, int high);

    // Recusive call for heap sort
    void heapify(vector<int>& arr, int n, int i);

public:

    // Function to implement Insertion Sort
    void insertionSort(vector<int>& arr);

    // Main function to perform merge sort
    void mergeSort(vector<int>& arr, int l, int r);

    // Main function to perform Quick Sort
    void quickSort(vector<int>& arr, int low, int high);

    // Main function to perform Heap Sort
    void heapSort(vector<int>& arr);

    void printArray(vector<int>& arr);
};

#endif