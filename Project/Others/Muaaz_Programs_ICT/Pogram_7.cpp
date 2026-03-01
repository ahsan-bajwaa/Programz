#include <iostream>
using namespace std;

int main(){
    char ch;
    cout << "Enter chracter: ";
    cin >> ch;

    if (isalpha(ch)){
        cout << "Alphabet";
    } else{
        cout << "Not Alphabet";
    }

    return 0;
}

