#include <iostream>
using namespace std;

int main(){
    int N, x;
    cout << "Enter the value of N: ";
    cin >> N;
    cout << "Enter the value of x: ";
    cin >> x;
    
    int sum = 0;
    for(int i = 1; i <= N; i++){
        if (i % x == 0)
        	sum += i;
    }
    cout << "The sum of all numbers divisible by " << x << " in the range 1 to " << N << " is: " << sum << endl;   
    return 0;
}

