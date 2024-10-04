#include <iostream>
#include "Pllgrm.cpp"
using namespace std;


int main() {
    double tL, tW, tA;
    cout << "input length: ";
    cin >> tL;

    cout << "input width: ";
    cin >> tW;

    cout << "input angle: ";
    cin >> tA;

    Pllgrm pare(tL, tW, tA);

    cout << "Perimeter is: " << pare.getPerimeter() << endl;
    cout << "Area is: " << pare.getArea() << endl;
}