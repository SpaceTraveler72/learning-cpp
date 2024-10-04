#include <iostream>
using namespace std;

int main() {
    while (true) {
        int numPeople, time;
        cout << endl << "Enter number of people: ";
        cin >> numPeople;
        if (numPeople == -1) {
            break;
        }
        cout << "Enter time: ";
        cin >> time;

        if ((time) % ((numPeople-1)*2) < numPeople-1) {
            cout << "Person "  << (time) % (numPeople-1) + 1 << " will get the pillow";
        } else {
            cout << "Person " << numPeople - (time) % (numPeople-1) << " will get the pillow";
        }
    }
}