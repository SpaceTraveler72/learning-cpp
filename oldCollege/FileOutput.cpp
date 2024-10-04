#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream inputFile;
    string fromFile;

    inputFile.open("stuff.txt");
    if (!inputFile)
    {
        cout << "Error finding file";
        exit(102);
    }

    inputFile >> fromFile;

    cout << fromFile;

    inputFile.close();
}

int binary_search(int *array, int size, int value)
{
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (array[mid] == value)
        {
            return mid;
        }
        else if (array[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}