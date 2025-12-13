#include <iostream>
using namespace std;

int main() {
    int entered_number, maximum_value, number;
    int even = 0, odd = 0, steps = 0;

    cout << "Enter a positive number: ";
    cin >> entered_number;

    if (entered_number > 0) {
        number = entered_number;
        maximum_value = entered_number;  // Initialize with the entered number

        cout << "Collatz sequence for " << entered_number << " = " << number;

        // The entered number itself is not added to even or odd counts
        while (number != 1) {
            if (number % 2 == 0) {
                number /= 2;
                even++;
            } else {
                number = number * 3 + 1;
                odd++;
            }

            if (number > maximum_value) {
                maximum_value = number;  // Update maximum if needed
            }

            cout << ", " << number;
            steps++;
        }

        cout << endl;
        cout << "Total steps: " << steps << endl;
        cout << "Maximum value reached: " << maximum_value << endl;
        cout << "Even: " << even << endl;
        cout << "Odd: " << odd << endl;
    } else {
        cout << "You have entered zero or a negative number!!";
    }

    return 0;
}

