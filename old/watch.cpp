#include <iostream>
#include "time205.hpp"
using namespace std;

int main() {
    struct Time *alarm = (Time*)malloc(sizeof(Time));
    alarm -> hrs = 2;
    alarm -> min = 45;
    alarm -> sec = 3;
    alarm -> isPM = true;

    printTime(alarm);
    printMilTime(alarm);

}
