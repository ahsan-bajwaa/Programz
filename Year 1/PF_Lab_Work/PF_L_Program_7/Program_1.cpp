#include <iostream>
using namespace std;

int add(int number_1, int number_2 = 0, int number_3 = 0){
	return number_1 + number_2 + number_3;	
}

int main(){
	int number_1, number_2, number_3;
	cout << "Enter a number: ";
	cin >> number_1;
	cout << "Enter second number: ";
	cin >> number_2;
	cout << "Enter third number: ";
	cin >> number_3;
	
	cout << "Sum: " << add(number_1, number_2, number_3);
}

