#include <iostream><cmath>
using namespace std;

int main(){
    int number, temp, sum = 0, digit, n = 0;

    cout << "Enter a number: ";
    cin >> number;
	
    temp = number;
    while(temp != 0){
        temp /= 10;
        n++;
    }

    temp = number;

    while(temp != 0){
        digit = temp % 10;
        sum += pow(digit, n);
        temp /= 10;
    }

    if(sum == number){
        cout << "Armstrong number.";
    }
	else{
        cout << "Not an armstrong number.";
    }

}

