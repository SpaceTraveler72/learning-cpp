#include <iostream>
#include <math.h>
using namespace std;

double fahrenheitToCelsius(double fahrenheit)
{
    return (fahrenheit - 32) * (5.0 / 9);
}

double celsiusToFahrenheit(double celsius)
{
    return (celsius + 32) * (9.0 / 5);
}

int main()
{
    int totalSpaceLength = 10, temp,
        startTemp, endTemp, step;
    char scaleSelector, scaleOpposite;
    bool isFahrenhit;

    cout << "starting temperature? ";
    cin >> startTemp;

    cout << "ending temperature? ";
    cin >> endTemp;

    cout << "step value? ";
    cin >> step;

    cout << "input scale (C or F)? ";
    cin >> scaleSelector;

    switch (scaleSelector)
    {
    case 'F':
        isFahrenhit = true;
        scaleOpposite = 'C';
        break;
    case 'C':
        isFahrenhit = false;
        scaleOpposite = 'F';
        break;
    default:
        cout << "did you forget to capatilize?";
        return -1;
    }

    string spaces = "";

    for (int i = 0; i < totalSpaceLength - 1; i++)
        spaces += ' ';

    cout << scaleSelector << spaces << scaleOpposite << endl;

    if (startTemp < endTemp)
        step = abs(step);
    else
        step = -abs(step);
    
    temp = startTemp;
    for (int i = 0; i <= abs(startTemp - endTemp); i += abs(step))
    {
        double oppsiteTemp;

        if (isFahrenhit)
            oppsiteTemp = fahrenheitToCelsius(temp);
        else
            oppsiteTemp = celsiusToFahrenheit(temp);

        int ajustedSpaceLength = totalSpaceLength - to_string(temp).length();
        if (ajustedSpaceLength < 1)
            ajustedSpaceLength = 1;

        string spaces = "";

        for (int i = 0; i < ajustedSpaceLength; i++)
            spaces += ' ';

        cout << temp << spaces << oppsiteTemp << endl;

        temp+=step;
    }
}