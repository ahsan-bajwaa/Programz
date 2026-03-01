#include <iostream>
using namespace std;

void printFactors(int num) {
    cout << "Factors of " << num << " are: ";
    
    for(int i = 1; i <= num; i++) {
        if(num % i == 0){
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int num;
    cout << "Enter number: ";
    cin >> num;
    
    printFactors(num);
    return 0;
}

