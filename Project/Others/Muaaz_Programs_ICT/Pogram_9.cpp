#include <iostream>
using namespace std;

int main(){
    char ch;
    cin >> ch;

    if(isalpha(ch)){
        cout << "Alphabet";
    }
	else if(isdigit(ch)){
        cout << "Digit";
    }
	else{
        cout << "Special Character";
    }
}

