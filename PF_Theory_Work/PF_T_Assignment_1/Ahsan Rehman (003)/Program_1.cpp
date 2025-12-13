#include <iostream>
using namespace std;

int main() {
    int number;
    int even = 0, odd = 0;
    cout << "Enter a positive number: ";
    cin >> number;
    
    if(number >= 0){
        for(int i = 1; i < number; i++){
            if(i%2 == 0){
                even += i;
            }
            if(i%2 != 0){
                odd += i;
            }
        }
    }
    cout << "Even: " << even<< endl;
    cout << "Odd: " << odd;
    return 0;
}

