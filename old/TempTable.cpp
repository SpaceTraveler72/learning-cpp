#include <iostream>
using namespace std;

double celsiusToFahrenheit(double celsius) {
    return (celsius + 32) * (9.0 / 5);
}

int main() {
    float temps[1000];
    float input, sum = 0;
    int size = 0;

    while (cin >> input) {
        input = celsiusToFahrenheit(input);
        sum+=input;
        temps[size++] = input;
    }

    cout << "avg. is: " << sum/size << endl;

    for (int i = 0; i < size; i++) {
        cout << temps[i] << "     " << temps[i]-(sum/size) << endl;
    }
}