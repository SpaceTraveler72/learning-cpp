#include <iostream>
#include <math.h>
using namespace std;

int main() {
	double radius, volume, pi = 3.14159;

	cout << "Enter the radius: ";
	cin >> radius;

	volume = pow(radius, 3)*pi*4/3;
	cout << "The area equals: " << volume << endl;
}
