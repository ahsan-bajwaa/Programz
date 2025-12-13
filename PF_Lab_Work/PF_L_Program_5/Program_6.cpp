#include <iostream>
using namespace std;

void calculatePower(int base, int exponent){
	int result = 1;
	for(int i = 1; i <= exponent; i++){
		result *= base;
	}
	cout << base << " raised power of " << exponent << " is = " << result;
}

int main(){
	int base, exponent;
	cout << "Enter a number: ";
	cin >> base;
	cout << "Enter power: ";
	cin >> exponent;
	
	calculatePower(base, exponent);
}
