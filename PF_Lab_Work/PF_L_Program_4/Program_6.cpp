#include <iostream>
using namespace std;

int main() {
    int number, reversed = 0;
    cout << "Enter a number: ";
    cin >> number;

    for(int i = number; i > 0; i /= 10) {
        int last = i % 10;
    
        reversed = reversed * 10 + last;
    }
    if(number == reversed)
        cout << "It is Palindrome number!";
	else
        cout << "It is not Palindrome number!";
	
   
}


