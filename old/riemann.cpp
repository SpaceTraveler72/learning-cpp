#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double sum = 0.0, x, delta, height,
           min = 0.0, max = 10.0;
    int steps;

    for (int index = 0; index < 5; index++)
    {
        if (index + 1 == 10) // makes steps over 10,000,000,000. Causes integer overflow.
           break;

        steps = pow(10, index + 1); // could do this in for loop, but I wanted to use pow

        delta = (max - min) / steps;

        x = min;
        sum = 0;
        for (int i = 0; i < steps; i++)
        {
            // f(x) = (-1/200.0)*x*(x-3)*(x-9)*(x-10)+2
            height = (-1 / 200.0) * x * (x - 3) * (x - 9) * (x - 10) + 2;
            sum += height * delta;

            x += delta;
        }

        cout << "Area under the curve: " << sum << endl;
    }

} // main