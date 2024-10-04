// Searches student IDs to find that student's cost
// Sawyer Theis
//  9/4/23
// CSC 250
// Project 1


#include "StudentID.hpp"


int main() {
    int length;
    int* ids;
    float* costs;

    length = getData(ids, costs);

    sortData(ids, costs, length);

    userSearch(ids, costs, length);
}

void openFile(ifstream& inputFile) {
    inputFile.open("StudentID.txt");
    if (!inputFile) {
        cout << "Error finding file";
        exit(102);
    }
}

int getLength(ifstream& inputFile, int*& ids, float*& costs) {
    int length = -1;
    inputFile >> length;
    ids = new int[length];
    costs = new float[length];

    return length;
}

int getData(int*& ids, float*& costs) {
    ifstream inputFile;

    openFile(inputFile);
    int length = getLength(inputFile, ids, costs);

    for (int i = 0; i < length; i++) {
        inputFile >> ids[i] >> costs[i];
    }

    return length;
}

void sortData(int*& ids, float*& costs, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int index = 0; index < length - 1 - i; index++) {
            if (ids[index] > ids[index + 1]) {
                int temp = ids[index];
                ids[index] = ids[index + 1];
                ids[index + 1] = temp;

                float temp2 = costs[index];
                costs[index] = costs[index + 1];
                costs[index + 1] = temp2;
            }
        }
    }
}

void printData(int* ids, float* costs, int length) {
    for (int i = 0; i < length; i++) {
        cout << ids[i] << "   " << costs[i] << endl;
    }
}

int binarySearch(int searchValue, int* array, int length) {
    int low = 0;
    int high = length - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (array[mid] == searchValue) {
            return mid;
        }
        else if (array[mid] < searchValue) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

void userSearch(int* ids, float* costs, int length) {
    int searchValue, foundValue;
    cout << "Type in a ID: ";
    while (cin >> searchValue) {
        foundValue = binarySearch(searchValue, ids, length);

        if (foundValue == -1)
            cout << "Inputed value not in array";
        else
            cout << "ID: " << searchValue << "  Dept Owed: " << costs[foundValue];

        cout << endl << "Input a valid ID to restart: ";
    }
}
