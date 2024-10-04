#include <iostream>
using namespace std;

int main() {
    cout << "n   triangle number" << endl;

    for (int index = 5; index <= 50; index+=5) {
        int output = 0;

        for (int i = index; i > 0; i--) 
            output+=i;
        
        int spaceLength = 4 - to_string(index).length();
        if (spaceLength < 1)
            spaceLength = 1;
        
        string spaces = "";

        for (int i = 0; i < spaceLength; i++)
            spaces+=' ';
        
        cout << index << spaces << output << endl;
    }
}