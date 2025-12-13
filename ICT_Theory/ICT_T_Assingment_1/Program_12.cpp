#include <iostream>
using namespace std;

int main(){
	int month, days;
	cout << "Enter month number: ";
	cin >> month;
	
	if(month == 2){
		cout << "Days = 28 or 29";
	}
	else if(month ==4 || month == 6 || month == 9 || month == 11){
		cout << "Days = 30";
	}
	else if(month <= 12){
		cout << "Days = 31";
	}
}
