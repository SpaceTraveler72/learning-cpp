#include <iostream>
#include <stdlib.h>
using namespace std;

char crypt(char input, int key)
{
    if (input + key > 122)
    {
        return input + key - 26;
    }
    if (input + key < 97)
    {
        return input + key + 26;
    }

    return input + key;
}

int main()
{
    char keyInput[80];
    cout << "key string: ";
    cin >> keyInput;

    int isEncrypt, size = 0;
    if (keyInput[0] == '-') {
        isEncrypt = -1;
        int i;
        for (i = 0; keyInput[i+1] != '\0'; i++) {
            keyInput[i] = keyInput[i+1];
            size++;
        }
        keyInput[i] = '\0';
    }
    else {
        isEncrypt = 1;
        for (int i = 0; keyInput[i] != '\0'; i++) {
            size++;
        }
    }
    char *key = keyInput;

    char phraseInput[80];
    cin >> phraseInput;

    char *phrase = phraseInput;

    while (*phrase != '\0')
    {
        char currentChar = *phrase;
        if (*key == '\0')
            key -= size;
        int currentKey = (*key - 96) * isEncrypt;

        currentChar = crypt(currentChar, currentKey);
        cout << currentChar;

        phrase++;
        key++;
    }
}