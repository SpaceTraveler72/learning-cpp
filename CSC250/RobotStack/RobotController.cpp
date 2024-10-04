// Robot Movement Controller
// Allows user to create a path for a robot to follow
// It can then find the path back to the start for the robot to follow
// Sawyer Theis
// 2/3/24
// CSC 300
// Project 7

#include "RobotNodes.h"
#include <iostream>
#include <iomanip>
using namespace std;

enum MenuOption {ADDSEGMENT, RETURNTOSTART};

void menu(RobotNodes& robot);

void addSegment(RobotNodes& robot);

void returnToStart(RobotNodes& robot);

int main() {
    RobotNodes robot;

    menu(robot);
}

// Menu function that allows the user to continues input until they exit
void menu(RobotNodes& robot) {
    while (true) {
        int input;
        cout << "Enter 0 to add a new segement, 1 to return to start, and any other to exit" << endl;
        cin >> input;

        switch ((MenuOption)input)
        {
        case ADDSEGMENT:
            addSegment(robot);
            break;
        case RETURNTOSTART:
            returnToStart(robot);
            break;
        default:
            return;
            break;
        }
    }
}

// adds a new Node to the robot stack via user input
void addSegment(RobotNodes& robot) {
    float distance, angle;
    char rotationDirection;
    bool clockwise;

    // Takes and stores user input
    cout << "Enter Distance Traveled: ";
    cin >> distance;
    cout << "Enter Angle Turned: ";
    cin >> angle;
    cout << "Enter 't' if turned clockwise, and 'f' for counterclockwise: ";
    cin >> rotationDirection;

    switch (rotationDirection)
    {
    case 't':
        clockwise = true;
        break;
    case 'f':
        clockwise = false;
        break;
    
    default:
        cout << "Didn't recognise input. Defaulted to true";
        clockwise = true;
        break;
    }

    // adds a new node to the stack
    robot.push(distance, angle, clockwise);
}

// Pops all the nodes out of the stack and prints all the nodes backwards
void returnToStart(RobotNodes& robot) {
    cout << left << setw(5) << "Step" << setw(10) << "Distance" << setw(10) << "Angle" << setw(20) << "Rotation Direction";
    cout << endl << right;

    for (int i = 1; !robot.isEmpty(); i++) {
        float distance, angle;
        bool clockwise;
        robot.pop(distance, angle, clockwise);

        cout << setw(5) << i << setw(10) << distance << setw(10) << (int)(angle + 180) % 360  << setw(20);
        if (clockwise)
            cout << "Counterclockwise";
        else
            cout << "Clockwise";
        cout << endl;

    }

}
