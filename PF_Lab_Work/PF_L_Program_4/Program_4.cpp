#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int number, decimal = 0, digit;
	int j = 0;
	
	cout << "Enter a  Binary number: ";
	cin >> number;
	
	for(int i = number; i > 0;i /= 10){
		digit = i%10;
		decimal += digit * pow(2,j);
		j++;
	}
	cout << "Decimal Equalant = " << decimal;
}
