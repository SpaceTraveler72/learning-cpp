#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int main() {
	int firstSide;
	int secondSide;

	cout << "Enter first side of triangle: " << endl;
	cin >> firstSide;
	cout << "Enter second side of triangle: " << endl;
	cin >> secondSide;

	int hypo = sqrt(pow(firstSide, 2) + pow(secondSide, 2));
	cout << "The Hypotenuse is: " << hypo << endl;
}
