#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n, last_digit, power = 0;
	int sum = 0;
	cout << "Enter a number: ";
	cin >> n;
	
	int N = n;
	
	for(int j = N; j > 0; j /= 10){
		power++;
	}
	for(int i= 1; N > 0; i++){
		last_digit = N % 10;
		sum += pow(last_digit, power);
		N /= 10;
	}
	if(n == sum){
		cout << sum << " is an Armstrong number.";
	}
	else{
		cout << n << " is not an Armstrong number. It's equal to = " << sum;
	}
}
