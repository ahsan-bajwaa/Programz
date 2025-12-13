#include <iostream>
using namespace std;

int main() {
    int n;
=
    cout << "Enter a positive integer: ";
    cin >> n;

    int steps = 0;
    int max_value = n;
    int even_count = 0;
    int odd_count = 0;
    cout << "Collatz sequence for " << n << ": ";

    if (n % 2 == 0) {
            even_count--;
        } else {
            odd_count--;
        }
	while (n != 1) {
        cout << n << ", ";

        if (n % 2 == 0) {
            n = n / 2;
            even_count++;
        } else {
            n = 3 * n + 1;
            odd_count++;
        }

        if (n > max_value) {
            max_value = n;
        }

        steps++;
    }
    odd_count++;

    cout << n << endl;

    cout << "Total steps: " << steps << endl;
    cout << "Maximum value reached: " << max_value << endl;
    cout << "Even count: " << even_count << endl;
    cout << "Odd count: " << odd_count << endl;

    return 0;
}
