#include <iostream>
using namespace std;

int main(){
    char ch;
    cout << "Enter alphabet: ";
    cin >> ch;

    if(isupper(ch)){
        cout << "Uppercase";
    }
	else if(islower(ch)){
        cout << "Lowercase";
    }
	else{
        cout << "Not an Alphabet";
    }
}

