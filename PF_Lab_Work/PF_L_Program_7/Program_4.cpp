#include <iostream>
using namespace std;

void findMaxMin(int number_1, int number_2, int &min_number, int &max_number){
	if(number_1 > number_2){
		min_number = number_2;
		max_number = number_1;
	}
	else{
		min_number = number_1;
		max_number = number_2;
	}
}

int main(){
	int number_1, number_2, min_number, max_number;
	cout << "Enter 1st number: ";
	cin >> number_1;
	cout << "Enter 2nd number: ";
	cin >> number_2;
	
	// calling by reference.
	findMaxMin(number_1, number_2, min_number, max_number);
	
	cout << "Minimum number is: " << min_number << endl;
	cout << "Maximum number is: " << max_number << endl;
}
