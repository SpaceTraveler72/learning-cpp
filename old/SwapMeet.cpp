#include <iostream>
using namespace std;

void printArray(int array[], int size) {
    for (int i = 0; i < size - 1; i++)
        cout << array[i] << " ";
    cout << array[size-1];
}

int main() {
    int array[35];
    int value, size = 0;

    while (cin >> value) {
        array[size++] = value;
    }

    cout << "original: ";
    printArray(array, size);

    for (int i = 0; i < size/2; i++) {
        int temp = array[i];
        array[i] = array[size-i-1];
        array[size-i-1] = temp;
    }
    cout << endl << "reversed: ";
    printArray(array, size);
}