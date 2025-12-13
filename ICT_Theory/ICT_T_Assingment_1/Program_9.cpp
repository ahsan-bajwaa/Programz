#include <iostream>
using namespace std;

int main(){
	char cha;
	cout << "Enter character: ";
	cin >> cha;
	
	if(isalpha(cha)){
		cout << "It's Alphabet.";
	}
	else if(isdigit(cha)){
		cout << "It's digit.";
	}
	else{
		cout << "It's symbol.";
	}
}
