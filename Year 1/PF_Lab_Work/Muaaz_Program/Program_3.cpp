#include <iostream>
using namespace std;

int findMax(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int main(){
    int num1, num2;
    cout << "Entr number: ";
    cin >> num1 >> num2;
    cout << findMax(num1, num2) << " is greater" << endl;
    return 0;
}

