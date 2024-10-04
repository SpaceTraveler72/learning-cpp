#include "rec_activity_ST.hpp"

int main() {
    fstream file;

    openFile(file, "data.bin");

    menu(file);
}

void openFile(fstream& file, string fileName) {
    file.open(fileName, ios::in | ios::binary);

    if (!file) {
        file.open(fileName, ios::out | ios::binary);
        file.close();
    }
    file.close();

    file.open(fileName, ios::out | ios::in | ios::binary);
}

//creates a main menu that the user can interact with to edit/view the file
void menu(fstream& file) {
    while (true) {
        cout << endl << "0: view all activities, 1: add an activity, 2: edit an acivity, -1: exit" << endl;

        int input;
        cin >> input;
        if (input == -1) return;
        cout << endl;

        selectMenuOption((MenuOption)input, file);

    }
}

//runs the appropriate method for the given MenuOption(enmu)
void selectMenuOption(MenuOption input, fstream& file) {
    switch (input) {
    case PRINTALL:
        printAll(file);
        break;
    case ADDACTIVITY:
        addActivity(file);
        break;
    case EDITACTIVITY:
        editActivity(file);
        break;
    }
}

// returns the number of activities stored in the file
int getNumOfActivities(fstream& file) {
    file.seekg(0, ios::end);
    return file.tellg() / sizeof(Activity);
}

//prints all data about every activity
void printAll(fstream& file) {
    int colWidth = 15;
    int size = getNumOfActivities(file);

    // Sets up column headers
    for (int i = 0; i < nameSize; i++) cout << " ";
    cout << left << setw(colWidth) << "Location" << setw(colWidth) << "Max Enrollment" << endl;

    file.seekg(0, ios::beg);
    //Sets up row headers and values
    for (int i = 0; i < size; i++) {
        Activity temp;
        file.read(temp.name, sizeof(temp.name));
        file.read(reinterpret_cast<char*>(&temp.m_Location), sizeof(temp.m_Location));
        file.read(reinterpret_cast<char*>(&temp.maxEnrollment), sizeof(temp.maxEnrollment));

        cout << left << setw(nameSize) << temp.name;
        cout << right;
        cout << setw(colWidth) << getLocationName(temp.m_Location);
        cout << setw(colWidth) << temp.maxEnrollment;
        cout << endl;
    }
}

//allows the user to input an activity to the end of the file
void addActivity(fstream& file) {
    Activity newActivity;
    cout << "Enter Name (" << nameSize << " Char limit & no spaces): ";
    cin >> newActivity.name;
    cout << "Enter Location (Gym, Park, or Classroom): ";
    string temp;
    cin >> temp;
    newActivity.m_Location = getLocationNumber(temp);
    cout << "Enter Maximum Participants: ";
    cin >> newActivity.maxEnrollment;

    file.seekp(0, ios::end);
    file.write(newActivity.name, sizeof(newActivity.name));
    file.write(reinterpret_cast<const char*>(&newActivity.m_Location), sizeof(newActivity.m_Location));
    file.write(reinterpret_cast<const char*>(&newActivity.maxEnrollment), sizeof(newActivity.maxEnrollment));
}

//print each activity name along with their place in the file
void printNumberedList(fstream& file) {
    int size = getNumOfActivities(file);

    file.seekg(0, ios::beg);
    cout << left;
    for (int i = 0; i < size; i++) {
        file.seekg(i * sizeof(Activity), ios::beg);
        Activity temp;
        file.read(temp.name, sizeof(temp.name));
        cout << i << "   " << temp.name << endl;
    }
}

//lets the user select an activity and edit it 
void editActivity(fstream& file) {
    if (getNumOfActivities(file) == 0) return;

    int userInput;
    int colWidth = 15;

    printNumberedList(file);
    cout << "Enter the number of activity to edit: ";
    cin >> userInput;

    // loops until the user inputs the valid activity or exits
    while (!file.seekp(userInput * sizeof(Activity), ios::beg)) {
        cout << "Enter a valid activity value or -1 to exit: ";
        cin >> userInput;
        if (userInput == -1) return;
    }

    //prints the data on the selected activity
    cout << left << setw(nameSize) << "Activity selected"
        << setw(colWidth) << "Location"
        << setw(colWidth) << "Max Enrollment" << endl;

    Activity selectedActivity;
    file.seekg(userInput * sizeof(Activity), ios::beg);
    file.read(selectedActivity.name, sizeof(selectedActivity.name));
    file.read((char*)&selectedActivity.m_Location, sizeof(selectedActivity.m_Location));
    file.read((char*)&selectedActivity.maxEnrollment, sizeof(selectedActivity.maxEnrollment));

    cout << left << setw(nameSize) << selectedActivity.name;
    cout << setw(colWidth) << getLocationName(selectedActivity.m_Location);
    cout << setw(colWidth) << selectedActivity.maxEnrollment;
    cout << endl;

    //allows the user to enter new data for the activity
    cout << "Enter new name (" << nameSize << " Char limit & no spaces): ";
    cin >> selectedActivity.name;
    cout << "Enter new Location (Gym, Park, or Classroom): ";
    string temp;
    cin >> temp;
    selectedActivity.m_Location = getLocationNumber(temp);
    cout << "Enter new max particitation: ";
    cin >> selectedActivity.maxEnrollment;

    file.seekp(userInput * sizeof(Activity), ios::beg);
    file.write(selectedActivity.name, sizeof(selectedActivity.name));
    file.write(reinterpret_cast<const char*>(&selectedActivity.m_Location), sizeof(selectedActivity.m_Location));
    file.write(reinterpret_cast<const char*>(&selectedActivity.maxEnrollment), sizeof(selectedActivity.maxEnrollment));
}

// returns the value assosiated with the location name
Location getLocationNumber(string location) {
    char firstChar = tolower(location[0]);

    switch (firstChar) {
    case 'g':
        return GYM;
    case 'p':
        return PARK;
    case 'c':
        return CLASSROOM;
    default:
        cout << "inviald location. Defaulted to Gym";
        return GYM;
    }
}

//returns the name of the location as a string
string getLocationName(Location location) {
    switch (location) {
    case GYM:
        return "Gym";
    case PARK:
        return "Park";
    case CLASSROOM:
        return "Classroom";

    default:
        return "N/A";
    }
}