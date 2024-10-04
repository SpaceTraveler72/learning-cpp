#include <iostream>
using namespace std;

void dswap(double* xPointer, double* yPointer) {
    double x = *xPointer, y = *yPointer;

    double temp = x;
    x = y;
    y = temp;

    *xPointer = x;
    *yPointer = y;
}

int main() {
   double x = 3.14, y = 1.732, *dp = &x;
   cout << "x = " << x << "   " << "y = " << y << endl;
   dswap(dp , &y);
   cout << "x = " << x << "   " << "y = " << y << endl;
}