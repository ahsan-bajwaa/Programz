#include <iostream>
using namespace std;

int main() {
    int day, month, year, days;

    cout << "Enter Days: ";
    cin >> day;
    cout << "Enter Month: ";
    cin >> month;
    cout << "Enter Year: ";
    cin >> year;

    if (year > 1900 && month > 0 && month <= 12) {
        if (month == 2) {
            if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
                days = 29;
            else
                days = 28;
        } else if (month == 4 || month == 6 || month == 9 || month == 11)
            days = 30;
        else
            days = 31;

        if (day < 1 || day > days)
            cout << "You have entered invalid Days." << endl;
        else {
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
                cout << "This is a Leap Year." << endl;
            else
                cout << "This is not a Leap Year." << endl;
        }
    } else
        cout << "You have entered Wrong Month or Year." << endl;

    return 0;
}

