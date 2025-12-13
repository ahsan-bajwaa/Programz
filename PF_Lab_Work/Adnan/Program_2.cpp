#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    
    for(int num = 1; num <= N; num++){
        int sum = 0;
        
        for(int i = 1; i <= num / 2; i++){
            if (num % i == 0)
                sum += i;
        }
        if(sum == num)
            cout << num << " is a perfect number." << endl;
        else
			cout << num << " is not a perfect number." << endl; 
    }
    return 0;
}

