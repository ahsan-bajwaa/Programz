#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    int stepCount = 0;
    int maxVal = n;
    int evenCount = 0;
    int oddCount = 0;
    
    if (n % 2 == 0) {
            evenCount--; 
        } else { 
            oddCount--; 
        }

    cout << "Collatz sequence for " << n << ": ";

    while (n != 1) {
        cout << n << ", ";

        if (n % 2 == 0) {
            n = n / 2; 
            evenCount++; 
        } else {
            n = 3 * n + 1;  
            oddCount++; 
        }

        if (n > maxVal) {
            maxVal = n;
        }

        stepCount++;
        
    }

    cout << n << endl;
    oddCount++;

    cout << "Total steps: " << stepCount << endl;
    cout << "Maximum value reached: " << maxVal << endl;
    cout << "Even count: " << evenCount << endl;
    cout << "Odd count: " << oddCount << endl;

    return 0;
}
