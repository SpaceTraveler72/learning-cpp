#include <iostream>
using namespace std;

int sum(int *array, int size) {
    int result;
    for (int i = 0; i < size; i++)
        result+=*array++;

    return result;
}

int main() {
    int size = 3;
    int array[3] = {3,5,7};

    cout << sum(array, size) << endl;
}