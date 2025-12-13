#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int number, digit, sum, power = 0;
	cout << "Enter a number: ";
	cin >> number;
	
	for(int i = number; i > 0; i /= 10){
		power++;
	}
	
	for(int i = number; i > 0; i /= 10){
		digit = i % 10;
		sum += pow(digit, power);
	}
	
	if(sum == number){
		cout << "Its's Armstrong.";
	}
	else{
		cout << "Its's not a Armstrong.";
	}
	return 0;
}
