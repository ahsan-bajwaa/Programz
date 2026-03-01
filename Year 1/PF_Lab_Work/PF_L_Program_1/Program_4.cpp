#include <iostream>
#include <iomanip>	//using this libarary for fixed precision.
using namespace std;

int main (){
	float num_1, num_2, num_3, sum_1, sum_2, sum_3;
	cout << "Enter first number: ";
	cin >> num_1;
	cout << "Enter second number: ";
	cin >> num_2;
	cout << "Enter third number: ";
	cin >> num_3;
	
	cout << fixed << setprecision(2);
	/* Using fixed can stop decimal up to two. and without fixed 
	it, its leangth would be more than 2, as we are using setprecision
	 with two decimal limit. */
	 
	 sum_1 = num_1 + num_2 + num_3;
	 sum_2 = num_1 * num_2 * num_3;
	 sum_3 = num_1 + num_2 + num_3;
	
	cout << "\n*********************************************************" <<endl;
	cout << "*	Then sum of numbers is: " << sum_1 << "  		*" << endl;
	cout << "*	The product of numbers is: " << sum_2 << "		*" << endl;
	cout << "*	The average of numbers is: " << (sum_3) / (3) << "		*" << endl;
	cout << "*********************************************************";

}
