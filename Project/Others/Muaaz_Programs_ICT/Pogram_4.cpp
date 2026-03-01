#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;

    if(num % 5 == 0 && num % 11 == 0){
        cout << "Divisible by 5 and 11";
    }
	else{
        cout << "Not divisible by 5 and 11";
    }
}

