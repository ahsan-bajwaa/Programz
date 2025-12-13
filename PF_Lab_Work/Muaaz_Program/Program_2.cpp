#include <iostream>
using namespace std;


bool isEven(int number){
    return (number & 1) == 0;
}

int main(){
    int number;
    cout << "Enter number: ";
    cin >> number;

    if(isEven(number)){
        cout << "It is even number.";
    }
	else{
        cout << "It is odd number.";
    }
    return 0;
}

