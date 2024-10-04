#include <iostream>
using namespace std;


string encrypt(string plainText, string key);

string decrypt(string cipher, string key);

int main() {
    string message = "attack at dawn";

    cout << encrypt(message, "fun");
}

string encrypt(string plainText, string key) {
    string result = "";
    int index = 0;

    while (index < plainText.length()) {
        for (int keyIndex = 0; keyIndex < key.length(); keyIndex++) {
            if (plainText[index] != ' ') 
                result += ((((plainText[index] - 96) + (key[keyIndex] - 96) - 1) % 26) + 96);
            else {
                result += plainText[index];
                keyIndex--;
            }
            index++;
        }
    }

    return result;
}

string decrypt(string cipher, string key) {
    string result = "";
    
}