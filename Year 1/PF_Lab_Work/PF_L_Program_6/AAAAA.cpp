#include <iostream>
using namespace std;

int main(){
    int number;
    string reversed_order, binary_number;
    cout << "Enter a number: ";
    cin >> number;
	
    for (int i = number; i > 0; i /= 2) {
        reversed_order += i % 2 + '0';
    }
	
    for (int i = reversed_order.length() - 1; i >= 0; i--) {
        binary_number += reversed_order[i];
    }
	
    cout << "Binary Number: " << binary_number << endl;
	
}

