#include <iostream>
using namespace std;

int main(){
	string number;
	int count = 0, digit, sum = 0;
	cout << "Enter your card number: ";
	cin >> number;
			//  here -1 is used because counting starts from zero.
	for(int i = number.length() - 1; i >= 0; i--){
		 // Converting character to digit by using '0'.
		digit = number[i] - '0';
        count++;
        
        if(count % 2 == 0){
            digit *= 2;
            while(digit > 0){
                sum += digit % 10;
                digit /= 10;
            }
        }
		else{
            sum += digit;
        }
	}
	
	if(sum % 10 == 0){
		cout << "This is valid card!!";
	}
	else{
		cout << "It's not a valid card!!";
	}
}
