#include <iostream>
using namespace std;

int main(){
	int income, taxes;
	cout << "Enter you income: ";
	cin >> income;
	
	if(income > 0){
		
		if(income <= 50000){
			cout << "No taxes charged."; 
		}
		else if(income <= 100000){
			taxes = income * 10 / 100;
			cout << "Taxes: " << taxes << endl;
			cout << "Net income: " << income - taxes;
		}
		else{
			taxes = income * 20 / 100;
			cout << "Taxes: " << taxes << endl;
			cout << "Net income: " << income - taxes;
		}
	}
	else{
		cout <<  "Enter valid income.";
	}
	return 0;
}
