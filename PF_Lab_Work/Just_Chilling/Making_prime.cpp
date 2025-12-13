#include <iostream>
using namespace std;

bool isPrime(int number){
	for(int i = 2; i <= number / 2; i++){
		if(number % i == 0){
			return false;
		}
	}
	return true;
		
}

int main(){
	int number;
	cout << "Enter number: ";
	cin >> number;
	
	if(isPrime(number)){
		cout << "It's a prime number.";
	}
	else{
		cout << "It's not a prime number.";
	}
}
