#include <iostream>
using namespace std;

void swapValues(int &number_1, int &number_2){
	int temporary_number;
	temporary_number = number_1;
	number_1 = number_2;
	number_2 = temporary_number;
}

int main(){
	int number_1, number_2;
	cout << "Enter first number: ";
	cin >> number_1;
	cout << "Enter second number: ";
	cin >> number_2;
	
	cout << "Value of 1st number before swaping: " << number_1 << endl;
	cout << "Value of 2nd number before swaping: " << number_2 << endl;
	
	// calling the function by reference.
	swapValues(number_1, number_2);
	
	cout << endl;
	cout << "Value of 1st number after swaping: " << number_1 << endl;
	cout << "Value of 2nd number after swaping: " << number_2 << endl;
}
