#include <iostream>
using namespace std;

int main(){
    int number;
    cout << "Enter a number: ";
    cin >> number;

    int a = 0, b = 1, next;

    cout << "Fibonacci Series up to " << number << ": ";

    for(int i = 1; i <= number; i++){
        if(i == 1){
            cout << a << " ";
            continue;
        }
        if(i == 2){
            cout << b << " ";
            continue;
        }

        next = a + b;
        cout << next << " ";
        a = b;
        b = next;
    }

    return 0;
}

