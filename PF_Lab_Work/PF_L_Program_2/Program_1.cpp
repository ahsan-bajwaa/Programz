#include <iostream>
using namespace std;

int main(){
	char word;
	
	cout << "Enter Character: ";
	cin >> word;
	
	switch(word){
	case 'a':
	case 'A':
	case 'e':
	case 'E':
	case 'i':
	case 'I':
	case 'o':
	case 'O':
		cout << "\"" << word << "\" is vowel character. ";
		break;
	default:
		cout << "\"" << word << "\" is not a vowel character.";	
		break;
	}
	return 0;				
}
