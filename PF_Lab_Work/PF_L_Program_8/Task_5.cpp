#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(string str, int start, int end){
    if(start >= end) {
        return true;
    }
    if(str[start] != str[end]){
        return false;
    }
    return is_palindrome(str, start + 1, end - 1);
}

int main(){
    string input;
    cout << "Enter a string: ";
    cin >> input;
	
    bool result = is_palindrome(input, 0, input.length() - 1);
    if(result){
        cout << "String is a palindrome." << endl;
    }
	else{
        cout << "String is not a palindrome." << endl;
    }
	
}

