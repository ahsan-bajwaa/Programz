#include <iostream>
using namespace std;

inline void primeFactors(int number){
	while(number != 1){
		for(int j = 2; number >= j; j++){
			if(number % j == 0){
				cout << j << " ";
				number /= j;
				break;
			}
		}
	}
}

int main(){
	int number;
	cout << "Enter a number: ";
	 cin >> number;
	
	cout << "Prime Factors of number is: ";
	
	// using inline function.
	primeFactors(number);
}
