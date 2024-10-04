// Program to calculate the area and the perimeter of a rectangle
// Sawyer Theis
//  8/23/23
// CSC 250
// Intro Example

#include <iostream>
#include <iomanip>

using namespace std;

void readDimensions(float &len, float &wid);

int main()
{
    float length, width;

    readDimensions(length, width);

    cout << fixed << setprecision(2);

    // output the perimeter
    cout << left << setw(15) << "Perimeter is: " << setw(9) << length * 2 + width * 2 << endl;
    // output the area
    cout << setw(15) << "Area is: " << setw(9) << length * width << endl;

    return 0;
}

void readDimensions(float &len, float &wid)
{

    // read the length and the width of the rectangle
    cout << "Length of the Rectangle is: ";
    cin >> len;
    cout << "Width of the Rectangle is: ";
    cin >> wid;
}