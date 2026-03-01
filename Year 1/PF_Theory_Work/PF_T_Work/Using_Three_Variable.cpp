#include <iostream>
using namespace std;

int main(){
	int  a,b,c;
	
	cout << "Enter your first value: ";
	cin >> a;
	
	cout << "Enter your second value: ";
	cin >> b;
		
	c = b;
	b = a;
	a = c;
	
	cout << "\nSwap using three intergers"  << endl;
	
	cout << "\nYou entered you First value  " << a << endl;
	
	cout << "\nYou entered your Second value  " << b << endl;
	
	
}
