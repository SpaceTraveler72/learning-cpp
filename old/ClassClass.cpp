#include <iostream>
using namespace std;

class Date
{
private:
    int day, month, year;
    string monthString[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                              "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

public:
    void setDay(int givenDay) { day = givenDay; }
    void setMonth(int givenMonth) { month = givenMonth; }
    void setYear(int givenYear) { year = givenYear; }
    void printDate()
    {
        cout << month << "/" << day << "/" << year << endl;
    }
    void printEuroDate()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
    void printStdDate()
    {
        if (month > 12)
        {
            cout << "why do you hate me?";
            return;
        }
        cout << day << "-" << monthString[month - 1] << "-" << year << endl;
    }
};

int main()
{
    Date today;

    int *day, *month, *year;
    day = (int *)malloc(sizeof(int));
    month = (int *)malloc(sizeof(int));
    year = (int *)malloc(sizeof(int));

    cout << "enter the day: ";
    cin >> *day;

    cout << "enter the month: ";
    cin >> *month;

    cout << "enter the year: ";
    cin >> *year;

    today.setDay(*day);
    today.setMonth(*month);
    today.setYear(*year);
    free(day);
    free(month);
    free(year);

    today.printDate();
    today.printEuroDate();
    today.printStdDate();
}
