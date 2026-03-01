#include <iostream>
using namespace std;

int main(){
	int year;
	cout << "Enter year: ";
	cin >> year;
	
	if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
		cout << "It's leap year.";
	}
	else{
		cout << "It's not a leap year.";
	}
}
