#include <iostream>
using namespace std;

int factorial(int num)
{
    if (num == 1)
        return 1;

    return num + factorial(num - 1);
}

int main()
{
    cout << "n   triangle number" << endl;

    for (int index = 5; index <= 50; index += 5)
    {
        int output = factorial(index);

        cout << index << "    " << output << endl;
    }
}
