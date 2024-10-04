#include <iostream>
using namespace std;

int main() {
    double sum = 0, value; 
    int totalValues = 0;

    while (cin >> value) {
        totalValues++;
        sum+=value;
    }

    cout << totalValues << " values read" << endl;
    cout << "for a sum of " << sum << endl;
    cout << "and a average of " << (sum/totalValues) << endl;
}
