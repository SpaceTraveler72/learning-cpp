// Recenter Winter Activity Sign-up
// Sawyer Theis
// 10/22/23
// CSC 250
// Project 5

#include "rec_center_ST.hpp"

int main() {
    Activity array[SIZE];

    fillArray(array);

    while (menu(array)) {}

}

//Fills the array with the winter activities
void fillArray(Activity array[SIZE]) {
    initalizeActivity(array[0], "Indoor Soccer", GYM, 50);
    initalizeActivity(array[1], "Cross Country Skiing", PARK, 25);
    initalizeActivity(array[2], "Video Editing", CLASSROOM, 40);
    initalizeActivity(array[3], "Hot Yoga", GYM, 20);
    initalizeActivity(array[4], "Water Color Painting", CLASSROOM, 15);
}

//Sets up the values of a single activity
void initalizeActivity(Activity& activity, string name, Location location, int max_enrollment) {
    activity.name = name;
    activity.m_Location = location;
    activity.maxEnrollment = max_enrollment;
    activity.currentEnrollment = 0;
    activity.participantEmails = "";
}

// Creates a menu that allows the user to print the activites, emails, or register
// returns false if user selects to exit menu
bool menu(Activity array[SIZE]) {
    cout << endl;
    cout << "Enter 1 to view Activities" << endl;
    cout << "Enter 2 to view Participate Emails" << endl;
    cout << "Enter 3 to Register" << endl;
    cout << "Enter -1 to exit" << endl;

    int input;
    cin >> input;
    switch (input) {
    case 1:
        printActivities(array);
        break;
    case 2:
        printEmailList(array);
        break;
    case 3:
        registerUser(array);
        break;
    case -1:
        return false;
    }

    return true;
}

//Prints a table of all the data in each activity except the email list 
void printActivities(Activity array[SIZE]) {
    cout << endl;

    int colWidth = 18;
    int maxStringLength = array[0].name.length();
    //Sets the size of max string to the longest name in the array
    for (int i = 1; i < SIZE; i++) {
        if (maxStringLength < array[i].name.length())
            maxStringLength = array[i].name.length();
    }

    // Sets up column headers
    for (int i = 0; i < maxStringLength; i++) cout << " ";
    cout << left << setw(colWidth) << "Location" << setw(colWidth) <<
        "Max Enrollment" << setw(colWidth) << "Current Enrollment" << endl;

    //Sets up row headers and values
    for (int i = 0; i < SIZE; i++) {
        cout << left << setw(maxStringLength) << array[i].name;
        cout << right;
        cout << setw(colWidth) << getLocationName(array[i].m_Location);
        cout << setw(colWidth) << array[i].maxEnrollment;
        cout << setw(colWidth) << array[i].currentEnrollment;
        cout << endl;
    }
}

//returns the name of the location as a string
string getLocationName(Location location) {
    switch (location) {
    case GYM:
        return "Gym";
    case PARK:
        return "PARK";
    case CLASSROOM:
        return "Classroom";

    default:
        return "N/A";
    }
}

//Prints the entire email list of each activity
void printEmailList(Activity array[SIZE]) {
    cout << endl;

    int maxStringLength = array[0].name.length();
    //Sets the size of max string to the longest name in the array
    for (int i = 1; i < SIZE; i++) {
        if (maxStringLength < array[i].name.length())
            maxStringLength = array[i].name.length();
    }

    for (int i = 0; i < SIZE; i++) {
        cout << setw(maxStringLength) << array[i].name << "   ";
        cout << array[i].participantEmails;
        cout << endl;
    }
}

// Allows the user to add their email and enrollment to an user selected activity
void registerUser(Activity array[SIZE]) {
    cout << endl;

    int activityIndex;
    cout << "Enter the number of the activity you wish to register with: ";
    cin >> activityIndex;

    //validates the inputed activity and loops until exited or a valid activity is inputed
    if (!validateActivitySelection(array, activityIndex)) {
        do {
            cout << endl << "Activity entered is ethier not valid or full" << endl;
            cout << "Enter a valid activity or enter -1 to return to menu: ";
            cin >> activityIndex;
            if (activityIndex == -1) return;
        } while (!validateActivitySelection(array, activityIndex));
    }

    activityIndex--;
    cout << "Enter your email address: ";
    string email;
    cin >> email;
    addNewParticapate(array, activityIndex, email);

}

// Checks if the inputed activity is a full and it is one of the activities
bool validateActivitySelection(Activity array[SIZE], int activityIndex) {
    if (activityIndex <= 0 || activityIndex > SIZE) return false;

    if (array[activityIndex - 1].maxEnrollment <= array[activityIndex - 1].currentEnrollment) return false;

    return true;
}

// Adds a new email and upps the enrollment of a given activity
void addNewParticapate(Activity array[SIZE], int activityIndex, string particapintEmail) {
    array[activityIndex].currentEnrollment++;

    if (array[activityIndex].participantEmails.length() == 0) {
        array[activityIndex].participantEmails += particapintEmail;
        return;
    }

    array[activityIndex].participantEmails += "; " + particapintEmail;
}