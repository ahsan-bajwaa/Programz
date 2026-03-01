#include <iostream>
using namespace std;

int main() {
    int number, highest_digit = 0, lowest_digit = 9, digit;
	
    cout << "Enter a number: ";
    cin >> number;
	
    while(number != 0){
        digit = number % 10;
	
        if(digit > highest_digit){
            highest_digit = digit;
        }
	
        if(digit < lowest_digit){
            lowest_digit = digit;
        }
	
        number /= 10;
    }

    cout << "Highest digit: " << highest_digit;
    cout << "Lowest digit: " << lowest_digit;

}

