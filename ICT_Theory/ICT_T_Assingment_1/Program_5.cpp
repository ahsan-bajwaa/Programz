#include <iostream>
using namespace std;

int main(){
	int number;
	cout << "Enter a number: ";
	cin >> number;
	
	if(number % 2 == 0){
		cout << "It's even number.";
	}
	else{
		cout << "It's odd number.";
	}
}
