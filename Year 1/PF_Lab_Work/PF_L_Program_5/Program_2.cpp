#include <iostream>
using namespace std;

bool isEven(int number){
	if(number % 2 == 0){
		return true;
	}
	else
		return false;
}

int main(){
	int number;
	cout << "Enter a positive number: ";
	cin >> number;
	
	if(isEven(number)){
		cout << "It's an even number." << endl;
	}
	else{
		cout << "It's an odd number.";
	}
}
