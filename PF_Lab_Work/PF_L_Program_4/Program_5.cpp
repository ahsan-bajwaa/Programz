#include <iostream>
using namespace std;

int main(){	
	int number_1, number_2, divide_1 = 0, divide_2 = 0;
	int GCD = 0;
	cout << "Enter First number: ";
	cin >> number_1;
	cout << "Enter Second number: ";
	cin >> number_2;
	
	for(int i = 1; (i <= number_1) && (i <= number_2); i++){
		if(number_1 % i==0 && number_2 % i==0)
			GCD = i;	
	}
	cout << "GCD of two numbers is = " << GCD << endl;
}

