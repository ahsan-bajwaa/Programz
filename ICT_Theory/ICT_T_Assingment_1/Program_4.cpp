#include <iostream>
using namespace std;

int main(){
	int number;
	cout << "Enter a number: ";
	cin >> number;
	
	if(number % 5 == 0 && number % 11 == 0){
		cout << "It's divisible with '5' and '15' number.";
	}
	else{
		cout << "It's not divisible with '5' and '15' number.";
	}
}
