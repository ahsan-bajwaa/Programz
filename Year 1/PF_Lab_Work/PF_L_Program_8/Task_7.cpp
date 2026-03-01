#include <iostream>
using namespace std;

void decimal_to_binary(int number){
    if(number == 0){
        return;
    }
    decimal_to_binary(number / 2);
    cout << number % 2;
}

int main(){
    int number;
    cout << "Enter a decimal number: ";
    cin >> number;
	
    if(number == 0){
        cout << "0";
    }
	else{
        decimal_to_binary(number);
    }
	
    cout << endl;
    return 0;
}

