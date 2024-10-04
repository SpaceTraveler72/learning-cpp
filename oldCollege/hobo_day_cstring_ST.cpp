// Analysis of hobo day data using cstings
// Sawyer Theis
//  10/6/23
// CSC 250
// Project 4 Part 1

#include "hobo_day_cstring_ST.hpp"


int main() {
    int particapation[ROWS][COLS], rowTotals[ROWS],
        lowLocation, highLocation;
    char activityNames[ROWS][maxStringLength];

    readData(particapation, activityNames);

    rowSum(particapation, rowTotals);

    lowLocation = findLowLocation(rowTotals);

    highLocation = findHighLocation(rowTotals);

    saveHoboDayResults(particapation, activityNames, rowTotals, lowLocation, highLocation);
}

void openFile(ifstream& inputFile, string fileName) {
    inputFile.open(fileName);

    //ends the program if can't find file to read from
    if (!inputFile) {
        cout << "Error finding file";
        exit(102);
    }
}

void readData(int particapation[][COLS], char activityNames[][maxStringLength]) {
    ifstream inputFile;
    openFile(inputFile, "HoboDay.txt");

    // adds the data from the file to both arrays.
    for (int outer = 0; outer < ROWS; outer++) {
        inputFile.getline(activityNames[outer], maxStringLength - 1);

        for (int inner = 0; inner < COLS; inner++) {
            int data;
            inputFile >> data;
            if (data < 0) {
                cout << "Data can't be negative.";
                data = 0;
            }

            particapation[outer][inner] = data;
        }
        inputFile.ignore(100, '\n');
    }
}

void rowSum(int particapation[][COLS], int rowTotals[]) {
    for (int outer = 0; outer < ROWS; outer++) {
        rowTotals[outer] = 0;
        for (int inner = 0; inner < COLS; inner++) {
            rowTotals[outer] += particapation[outer][inner];
        }
    }
}

int findLowLocation(int rowTotals[]) {
    int lowLocation = 0;

    for (int i = 1; i < ROWS; i++) {
        if (rowTotals[lowLocation] > rowTotals[i]) {
            lowLocation = i;
        }
    }

    return lowLocation;
}

int findHighLocation(int rowTotals[]) {
    int highLocation = 0;

    for (int i = 1; i < ROWS; i++) {
        if (rowTotals[highLocation] < rowTotals[i]) {
            highLocation = i;
        }
    }

    return highLocation;
}

void saveHoboDayResults(int particapation[][COLS], char activityNames[][maxStringLength], int rowTotals[], int lowLocation, int highLocation) {
    ofstream outputFile;
    int colWidth = 11;

    outputFile.open("results.txt");

    //sets up column headers
    for (int i = 0; i < maxStringLength - 1; i++) outputFile << " ";
    for (int i = 0; i < COLS; i++) {
        outputFile << setw(colWidth) << getColName(i);
    }
    outputFile << endl;

    //Sets up row headers and values
    for (int outer = 0; outer < ROWS; outer++) {
        outputFile << setw(maxStringLength - 1) << activityNames[outer];
        for (int inner = 0; inner < COLS; inner++) {
            outputFile << setw(colWidth) << particapation[outer][inner];
        }
        outputFile << endl;
    }

    //prints highest and lowest values
    outputFile << endl;
    outputFile << "Activity with the lowest particpation was " << activityNames[lowLocation]
        << " with " << rowTotals[lowLocation] << " people attending" << endl;

    outputFile << "Activity with the highest particpation was " << activityNames[highLocation]
        << " with " << rowTotals[highLocation] << " people attending" << endl;
}

string getColName(int colLocation) {
    // Starts at 0 and has the name of each of the Columns
    // Simplier to read than using a Cstring
    switch (colLocation) {
    case 0:
        return "Freshman";
        break;

    case 1:
        return "Sophomore";
        break;

    case 2:
        return "Junior";
        break;

    case 3:
        return "Senior";
        break;

    default:
        return "Input valid col";
        break;
    }
}
