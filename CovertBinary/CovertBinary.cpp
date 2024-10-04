#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int main () {
    int input;

    while (true) {
        // Gets a decimal number from the user
        cout << "Enter Decimal Number: ";
        cin >> input;

        if (input == -1) break;

        // Calculates the binary digits required for the decimal number
        int size = (int)(log2(input) + 1);
        cout << "Digits: " << size << endl;
        
        string binaryCov = "";

        // Calculates the binary number
        for (int i = 0; input > 0; i++) {
            int output = 0;
            output = input % 2;
            input = input / 2;

            binaryCov+= to_string((int)(output));
        }

        // Adds spaces to the binary number for easy reading
        for (int i = 4; i < size; i+=4) binaryCov.insert(i + i/4 - 1, " ");

        // prints the binary number backwards to correct it
        for (int i = 0; i < binaryCov.length(); i++) {
            cout << binaryCov[binaryCov.length()- i - 1];
        }
        cout << endl;
    }
}