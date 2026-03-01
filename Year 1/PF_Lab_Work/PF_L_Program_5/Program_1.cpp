#include <iostream>
using namespace std;

void printTable(int number){
	int multiply = 0;
	for(int i = 1; i <= 10; i++){
		multiply = number * i;
		cout << endl;
		cout << number << " * " << i << " = " << multiply;
	}
}

int main(){
	int number;
	cout << "Enter a number: ";
	cin >> number;
	printTable(number);
}
