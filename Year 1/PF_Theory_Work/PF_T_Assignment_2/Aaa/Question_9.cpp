#include <iostream>
using namespace std;

int main(){
	int number;
	int even_sum = 0, odd_sum = 0;
	
	cout << "Enter a number: ";
	cin >> number;
	
	if(number > 0){
		for(int i = number; i >= 0; i--){
			if(i % 2 == 0){
				even_sum += i;
			}
			else{
				odd_sum += i;
			}
		}
	}
	else{
		cout << "You entered negative number or zero.";
		return 0;
	}
	
	cout << "Even sum: " << even_sum << endl;
	cout << "Odd sum: " << odd_sum << endl;
}
