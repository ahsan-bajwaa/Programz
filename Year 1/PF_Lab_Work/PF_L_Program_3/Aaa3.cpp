#include <iostream>
using namespace std;

int main(){
	int number, power, num;
	cout << "Enter number: ";
	cin >> number;
	cout << "Enter power: ";
	cin >> power;
	
	num = 1;
	
	for(int i = 1; i <= power; i++){
	num = num * number;	
	}
	cout << number << " raised power of " << number << " is = " << num;
}
