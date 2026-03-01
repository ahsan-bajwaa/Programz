#include <iostream>
using namespace std;

int main() {
    int number;
    int count0 = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    int count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0;

    cout << "Enter a number: ";
    cin >> number;

    // Loop to process each digit
    for (; number > 0; number /= 10) {
        int digit = number % 10;  // Extract the last digit

        // Use if-else statements to count each digit
        if (digit == 0) count0++;
        else if (digit == 1) count1++;
        else if (digit == 2) count2++;
        else if (digit == 3) count3++;
        else if (digit == 4) count4++;
        else if (digit == 5) count5++;
        else if (digit == 6) count6++;
        else if (digit == 7) count7++;
        else if (digit == 8) count8++;
        else if (digit == 9) count9++;
    }

    // Display the count of each digit if it appears
    if (count0 > 0) cout << "0 appears " << count0 << " times." << endl;
    if (count1 > 0) cout << "1 appears " << count1 << " times." << endl;
    if (count2 > 0) cout << "2 appears " << count2 << " times." << endl;
    if (count3 > 0) cout << "3 appears " << count3 << " times." << endl;
    if (count4 > 0) cout << "4 appears " << count4 << " times." << endl;
    if (count5 > 0) cout << "5 appears " << count5 << " times." << endl;
    if (count6 > 0) cout << "6 appears " << count6 << " times." << endl;
    if (count7 > 0) cout << "7 appears " << count7 << " times." << endl;
    if (count8 > 0) cout << "8 appears " << count8 << " times." << endl;
    if (count9 > 0) cout << "9 appears " << count9 << " times." << endl;

    return 0;
}

