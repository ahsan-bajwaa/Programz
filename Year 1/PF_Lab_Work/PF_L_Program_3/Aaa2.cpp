#include <iostream>
using namespace std;

int main() {
	int number, multi;
	cout << "Enter number: ";
	cin >> number;
	
	if(number <= 0){
	cout << "You have entered negative number or zero!";
	}
	else
	for(int i = 1; i <= 10; i++){
		multi = number * i;
		cout << endl;
		cout << number << " * " << i << " = " << multi;
	}
}
	
