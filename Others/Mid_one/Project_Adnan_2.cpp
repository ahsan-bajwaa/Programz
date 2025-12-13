#include <iostream>
using namespace std;

int main() {
	int num1, num2, arzi;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;
	
	cout << "Value of first number: " << num1 << endl;
	cout << "Value of second number: " << num2 << endl;
	
	arzi = num1;
	num1 = num2;
	num2 = arzi;
	
	cout << "Value of second number: " << num1 << endl;
	cout << "Value of first number: " << num2 << endl;
	
}
