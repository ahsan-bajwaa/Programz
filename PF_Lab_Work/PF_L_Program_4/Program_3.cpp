#include <iostream>
using namespace std;

int main(){
	int number, reverse, sum = 0;
	cout << "Enter number: ";
	cin >> number;
	
	for(int i = number; i > 0; i /= 10){
		reverse = i%10;
		sum += reverse;
	}
	cout << "The sum of digits = " << sum;
}
