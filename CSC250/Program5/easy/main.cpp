#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

void printArray(vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < arr.size()-1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[arr.size() - 1] << "]" << endl;
}

void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        printArray(arr);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    printArray(arr);
    cout << "Sort" << endl;

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        printArray(arr);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}


int main() {
    vector<int> arr = {39,  27,  50,  23,  75,  14,  64,  41,  32};

    heapSort(arr);
}