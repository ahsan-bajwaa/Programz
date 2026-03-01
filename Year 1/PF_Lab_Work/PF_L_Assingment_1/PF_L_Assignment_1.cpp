#include <iostream>
using namespace std;

int main(){
	int  Num;
	int maximum_value = 0;
	int even = 0;
	int odd = 0;
	int steps = 0;
	cout << "Enter an positive integer = ";
	cin >> Num;

	if(Num > 0){
		cout << "Collatz sequence for " << Num << " = " << Num;
		
		if(Num % 2 == 0)
			even--;
		else
			odd--;
		
		while(Num != 1){
			if(Num % 2 == 0){
				Num = Num / 2;
				even++;
			}
			else{
				Num = Num * 3 + 1;
				odd++;
			}
	
			if(Num > maximum_value){
				maximum_value = Num;
			}
			cout << ", " << Num;
			steps++;
		}
		odd++;
		cout << endl << "Total steps = " << steps << endl;
		cout << "Maximum value reached = " << maximum_value << endl;
		cout << "Even count = " << even << endl;
		cout << "Odd count = " << odd << endl;
		
		return 0;
	}
	else{
		cout << "You entered Negative or zero number. Please enter positive number.";
	}
	
	return 0;
}
