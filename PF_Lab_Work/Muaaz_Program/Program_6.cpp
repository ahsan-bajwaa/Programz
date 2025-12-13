#include <iostream>
using namespace std;

void calculatePower(int base, int exponent){
    int result = 1;
    
    for(int i = 1; i <= exponent; i++){
        result *= base;
    }
    cout << base << " raised of power " << exponent << " is = " << result << endl;
}

int main(){
    int base, exponent;
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;
    
    calculatePower(base, exponent);
    return 0;
}

