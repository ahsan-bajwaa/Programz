#include <iostream>
using namespace std;

int factorial(int number){
    if (number <= 1){
        return 1;
    }
    return number * factorial(number - 1);
}

int main(){
    int number;
    cout << "Enter a number: ";
    cin >> number;
	
    int result = factorial(number);
    cout << "Factorial is: " << result;
	
}

