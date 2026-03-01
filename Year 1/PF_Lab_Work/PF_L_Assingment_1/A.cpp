#include <iostream>
using namespace std;

int main(){
	int number, max_value = 0;
	int even = 0, odd = 0, steps = 0;
	cout << "Enter a positive number: ";
	cin >> number;

	if(number > 0){
		cout << "Collatz sequence for " << number << " = " << number;
		//	It will not add entered number in even or odd.
		if(number % 2 == 0)
			even--;
		else
			odd--;	
		
		while(number != 1){
			if(number % 2 == 0){
				number /= 2;
				even++;
			}		
			else{
				number *= 3;
				number += 1;
				odd++;
			}
			
			if(number > max_value){
				max_value = number;
			}
			cout << ", " << number;
			steps++;
		}
		odd++;
		cout << endl << "Total steps: " << steps << endl;
		cout << "Maximum value reached: " << max_value << endl;
		cout << "Even: " << even << endl;
		cout << "Odd: " << odd << endl;		
		
		return 0;
	}
	else{
		cout << "You have enterd zero or negative number!!";
	}	
	
	return 0;
}
