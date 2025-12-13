#include <iostream>
using namespace std;

int product(int a, int b){
    if(b == 0){
        return 0;
    }
    return a + product(a, b - 1);
}

int main(){
    int a, b;
    cout << "Enter two numbers (a and b): ";
    cin >> a >> b;
	
    int result = product(a, b);
    cout << "The product of " << a << " and " << b << " is: " << result << endl;
	
}

