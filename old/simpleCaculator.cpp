#include <iostream>
using namespace std;

// I love vs code
int main()
{
    double firstNum, secondNum;
    char operatorVar;

    while (true)
    {
        cout << "Enter first number: ";
        cin >> firstNum;
        if (firstNum == 0) break;
        
        cout << "Enter second number: ";
        cin >> secondNum;
        cout << "Enter + - * / or %: ";
        cin >> operatorVar;

        cout << firstNum << " " << operatorVar << " " << secondNum << " = ";

        switch (operatorVar)
        {
        case '+':
            cout << firstNum + secondNum;
            break;
        case '-':
            cout << firstNum - secondNum;
            break;
        case '*':
            cout << firstNum * secondNum;
            break;
        case '/':
            cout << firstNum / secondNum;
            break;
        case '%':
            cout << (int)firstNum % (int)secondNum;
            break;

        default:
            cout << "Invalid Operator " << operatorVar;
            break;
        }

        cout << endl;
    }
}