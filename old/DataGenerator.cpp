#include <iostream>
#include <stdlib.h>
using namespace std;

//run ./DataGenerator.exe | ./Stats1.exe
int main() {
    int valuesGenerated = 10, range = 100;

    unsigned seed;
    srand(seed);

    for (int i = 0; i < valuesGenerated; i++) {
        int randNum = rand();

        cout << randNum % range + 1 << endl;
    }

    cout << "stop" << endl;
}