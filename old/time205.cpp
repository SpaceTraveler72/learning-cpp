#include <iostream>
#include "time205.hpp"
using namespace std;

void printTime(Time *time) {
    cout << time -> hrs << ":" << time -> min << ":" << time -> sec << " " << ((time -> isPM) ? "p.m." : "a.m.") << endl;
}

void printMilTime(Time *time) {
    cout << time -> hrs + ((time -> isPM) ? 12 : 0) << ":" << time -> min << ":" << time -> sec << endl;
}