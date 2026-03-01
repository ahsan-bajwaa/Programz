#include <iostream>
using namespace std;

bool isPalindrome(int number){
    int original = number, reversed = 0, remainder;
    
	while(number > 0){
        remainder = number % 10;
        reversed = reversed * 10 + remainder;
        number /= 10;
    }
    return original == reversed;
}

int main(){
    int num;
    cout << "Enter number: ";
    cin >> num;

    if(isPalindrome(num)){
        cout << num << " is palindrome.";
    }
	else{
        cout << num << " is not palindrome.";
    }
    return 0;
}

