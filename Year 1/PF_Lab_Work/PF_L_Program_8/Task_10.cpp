#include <iostream>
using namespace std;

int count_digits(int number){
    if(number == 0){
        return 0;
    }
    return 1 + count_digits(number / 10);
}

int main(){
    int number;
    cout << "Enter a number: ";
    cin >> number;

    int result;
    if (number == 0){
        result = 1;
    }
	else{
        result = count_digits(number);
    }

    cout << "Number of digits in " << number << " is: " << result << endl;
}

