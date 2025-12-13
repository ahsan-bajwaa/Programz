#include <iostream>
using namespace std;

int main() {
    int number, power, total = 1;
    cout << "Enter number: ";
    cin >> number;
    cout << "Enter power: ";
    cin >> power;
    
    for (int i = 0; i < power; i++) {
        total *= number;
    }
    cout << number << " raised to power of "<< power<< " is: "<< total << endl;
}
