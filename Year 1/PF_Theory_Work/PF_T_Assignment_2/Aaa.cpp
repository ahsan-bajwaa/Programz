#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter a positive number: ";
    cin >> number;

    int even_sum = 0, odd_sum = 0;

    for (int i = number; i >= 1; i--) {
        if (i % 2 == 0) {
            even_sum += i;
        } else {
            odd_sum += i;
        }
    }

    cout << "Sum of even numbers: " << even_sum << endl;
    cout << "Sum of odd numbers: " << odd_sum << endl;

    return 0;
}

