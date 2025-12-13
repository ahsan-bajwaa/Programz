#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int age;
	double price = 0;
	string day;
	
	cout << "Enter your age: ";
	cin >> age;
	cout << "Enter day: ";
	cin >> day;
	
	cout << fixed << setprecision(2);
	
	if(age >= 0){
		if(day == "monday" || day == "tuesday" || day == "wednesday" || day == "thursday" ||
		   day == "Monday" || day == "Tuesday" || day == "Wednesday" || day == "Thursday"){
			if(age >= 5 && age <= 12)
				price = 7;
			else if(age >= 13 && age <= 64)
				price = 12;
			else if(age >= 65)
				price = 8;
			}
						
		else if(day == "Friday" || day == "Saturday" || day == "Sunday" ||
		   		day == "friday" || day == "saturday" || day == "sunday"){
			if(age >= 5 && age <= 12)
				price = 10;
			else if(age >= 13 && age <= 64)
				price = 15;
			else if(age >= 65)
				price = 12;
		}
	cout << "Ticket price is $" << price << ".";
	return 0;
	}
	
	else
		cout << "Invalid date enterd!!";		
}
