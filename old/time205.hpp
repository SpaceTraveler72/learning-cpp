#ifndef TIME205_HPP
#define TIME205_HPP

struct Time
{
    int hrs, min, sec;
    bool isPM;
};

void printTime(Time*);

void printMilTime(Time*);
#endif