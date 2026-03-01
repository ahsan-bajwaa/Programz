#include <iostream>
using namespace std;

int main(){
	int number,num1;
	int nu1 = 0,nu2 = 0,nu3 = 0,nu4 = 0,nu5 = 0,nu6 = 0,nu7 = 0,nu8 = 0,nu9 = 0,nu0 = 0;
	cout << "Enter number: ";
	cin >> number;

	for(;number > 0;number = number/10){
		num1 = number%10;

		if(num1 == 0)
			nu0 = nu0 + 1;
		else if(num1 == 1)
			nu1 = nu1 +1;
		else if(num1 == 2)
			nu2 = nu2 +1;
		else if(num1 == 3)
			nu3 = nu3 +1;
		else if(num1 == 4)
			nu4 = nu4 +1;
		else if(num1 == 5)
			nu5 = nu5 +1;
		else if(num1 == 6)
			nu6 = nu6 +1;
		else if(num1 == 7)
			nu7 = nu7 +1;
		else if(num1 == 8)
			nu8 = nu8 +1;
		else if(num1 == 9)
			nu9 = nu9 +1;
	}
		if(nu0>=1)
			cout << "0  appears " << nu0 << " time(s)." << endl;
		if(nu1>=1)
			cout << "1  appears " << nu1 << " time(s)." << endl;
		if(nu2>=1)
			cout << "2  appears " << nu2 << " time(s)." << endl;
		if(nu3>=1)
			cout << "3  appears " << nu3 << " time(s)."  << endl;
		if(nu4>=1)
			cout << "4  appears " << nu4 << " time(s)."  << endl;
		if(nu5>=1)
			cout << "5  appears " << nu5 << " time(s)."  << endl;
		if(nu6>=1)
			cout << "6  appears " << nu6 << " time(s)."  << endl;
		if(nu7>=1)
			cout << "7  appears " << nu7 << " time(s)."  << endl;
		if(nu8>=1)
			cout << "8  appears " << nu8 << " time(s)."  << endl;
		if(nu9>=1)
			cout << "9  appears " << nu9 << " time(s)."  << endl;
}
