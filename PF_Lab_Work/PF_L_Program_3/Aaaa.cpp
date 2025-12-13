#include <iostream>
using namespace std;

int main() {
    int n = 5;  // Highest number (number of rows)

    for (int i = n; i >= 1; i--) {  // Loop from 5 to 1
        for (int j = n; j > i; j--) {
            cout << " ";  // Print leading spaces
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << i;  // Print the current number
        }
        cout << endl;
    }

    return 0;
}

