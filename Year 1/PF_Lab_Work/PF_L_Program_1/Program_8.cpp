#include <iostream>
using namespace std;

int main(){
	int no_1, no_2, no_3, sum_1, sum_2, sum_3, total;
	
	cout << "\nEnter the number of units consumed in the first 100 units (at 10 PKR per unit) : ";
	cin >> no_1;
	
	cout << "Enter the number of units consumed in the next 200 units (at 15 PKR per unit) : ";
	cin >> no_2;
	
	cout << "Enter then number of units consumed above 300 units (at 20 PKR per unit) : ";
	cin >> no_3;
	
	sum_1 = no_1 * 10;		//multiplying with their rates.
	sum_2 = no_2 * 15;
	sum_3 = no_3 * 20;
	
	cout << "\n----------Electricity Bill Breakdown ----------- " << endl;
	cout << "	Cost for first " << no_1 << " units : " << sum_1 << endl;	//Displying by unit per rate.
	cout << "	Cost for next " << no_2 << " units : " << sum_2 << endl;
	cout << "	Cost for above " << no_3 << " units : " << sum_3 << endl;
	cout << "------------------------------------------------" << endl;
	
	total = sum_1 + sum_2 + sum_3;		//adding all enter.
	
	cout << "-------------------------------" << endl;
	cout << "Total Bill : " << total << " PKR" << endl;
	cout << "--------------------------------";
	return 0;
}
