#include <iostream>
using namespace std;

void displayAscii(char ch){
    cout << "ASCII value of '" << ch << "' is = " << int(ch) << endl;
}

int main(){
    char ch;
    cout << "Enter a character: ";
    cin >> ch;
    
    displayAscii(ch);
    return 0;
}

