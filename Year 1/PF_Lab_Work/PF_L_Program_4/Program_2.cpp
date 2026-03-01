#include <iostream>
using namespace std;

int main(){

	int number, reverse;
	cout << "Enter a number: ";
	cin >> number;
	
	if(number < 0)
		cout << "Enter a Positive number!";
		
	else{
		cout << "Reverse oreder is: ";
		for(int i = number;i > 0;i /= 10){
			reverse = i%10;		
			cout << reverse;
		}
	}	
}
