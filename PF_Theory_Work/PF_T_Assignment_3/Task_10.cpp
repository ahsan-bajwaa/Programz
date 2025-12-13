#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int number;

    cout << "Enter a number: ";
    cin >> number;

    cout << "Armstrong numbers are:" << endl;

    for (int num = 1; num <= limit; ++num) {
        int sum = 0, temp = num, digitCount = 0;

        while (temp != 0) {
            temp /= 10;
            ++digitCount;
        }

        temp = num;

        while (temp != 0) {
            int digit = temp % 10;
            sum += pow(digit, digitCount);
            temp /= 10;
        }

        if (sum == num) {
            cout << num << " ";
        }
    }

}

