		// Ahsan Rehman
		// su92-bscbm-f24-003

#include <iostream>
using namespace std;

int main(){
	int day, month, year, days;
	
	cout << "Enter Days. ";
	cin >> day;
	cout << "Enter Month. ";
	cin >> month;
	cout << "Enter Year. ";
	cin >> year;
	
	if(year>1900 && month>0 && month<=12){
		 if (month == 2) {
            if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) 
                days = 29; 
            else
                days = 28; 
		}
		else if(month == 4 || month == 6 || month == 9 || month == 11)	
			days = 30;
		else
			days = 31;	
	
		if(day<1 || day>days)
			cout << "You have Entered invalid Days.";
		else{
			cout << endl;
			cout << "Date: " << day << "-" << month << "-" << year << endl;
			
			if(year%400== 0 || (year%4==0 && year%100!=0))
				cout << "This is Leap Year.";
			else
				cout << "This is not Leap Year.";	
		}
	}
	else
		cout << "You have enterd Wrong Month or Year.";
}
