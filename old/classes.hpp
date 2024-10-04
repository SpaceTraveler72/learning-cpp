#ifndef BETHELCLASSES_HPP
#define BETHELCLASSES_HPP

#include <string>

class ClassSchedule {
    protected:
        int ncourses;
	int courseIDs[10];
};

class BethelPeople {
public:
    string address, name, emailAddress, phoneNumber;
};

class Staff : BethelPeople {
public:
    string officeID;
};

class Teacher : Staff {
public:
    ClassSchedule classSchedule;
    string department;
};

class Student : BethelPeople {
public:
    ClassSchedule classSchedule;
    string swipes;
    double gpa;
};



#endif