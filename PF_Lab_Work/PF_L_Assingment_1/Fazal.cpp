#include <iostream>
using namespace std;

int main() {
    int n;  
    int steps = 0;  
    int max_value = n; 
    int even_count = 0;  
    int odd_count = 0; 
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    int original = n;

    cout << "Collatz sequence for " << original << ": ";

    cout << n << ", ";

    while (n != 1) {
        steps++;  

        if (n % 2 == 0){
            n /= 2; 
            even_count++; 
        } else {
            n = 3 * n + 1;  
            odd_count++;  
        }

        if (n > max_value){
            max_value = n;
        }

        if (n != 1){
            cout << n << ", ";
        } else {
            cout << n << endl;  
        }
    }

    cout << "Total steps: " << steps << endl;
    cout << "Maximum value reached: " << max_value << endl;
    cout << "Even count: " << even_count << endl;
    cout << "Odd count: " << odd_count << endl;

    return 0;
}
