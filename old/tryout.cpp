#include <iostream>
#include "RPent.cpp"
using namespace std;

int main() {
    RegPentagon steve = {3};

    cout << "This is a shape of " << steve.getNumSides() << " sides" << endl;
    cout << "Perimeter Length: " << steve.getPerimeter() << endl;
    cout << "Area Size: " << steve.getArea() << endl;
}