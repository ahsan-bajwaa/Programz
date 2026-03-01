#include <iostream>
using namespace std;

int main(){
	int  a,b;
	
	cout << "Enter first number : ";
	cin >> a;
	
	cout << "Enter second number : ";
	cin >> b;
	
	cout << "\n******************************************************************" << endl;
	cout << "*	The value of first number before swapping is : " << a << " 	 *" << endl;	//Value of A Before swaping.
	cout << "*	The value of second number before swapping is : " << b << "	 *" << endl;	// Value of B before swaping.
		
	cout << "******************************************************************" << endl;
	cout << "*	You entered you First value : " << b << "		 	 *" << endl;		//Value after swapping.
	cout << "*	You entered your Second value : " << a << "			 *" << endl;		//Value after swapping.
	cout << "******************************************************************";
	
	return 0;
}
