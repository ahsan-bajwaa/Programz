#include <iostream>
using namespace std;

bool isPalindrome(int number){
	int reversed_number = 0;
	for(int i = number; i > 0; i /= 10){
		reversed_number *= 10;
		reversed_number += i % 10;			
	}
	if(reversed_number == number){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	int number;
	cout << "Enter a number: ";
	cin >> number;
	
	if(isPalindrome(number)){
		cout << "It's a Palindrome number.";
	}
	else{
		cout << "It's not a Palindrome number.";
	}
	
}
