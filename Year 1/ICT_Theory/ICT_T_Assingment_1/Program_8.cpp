#include <iostream>
using namespace std;

int main(){
	char cha;
	cout << "Enter character: ";
	cin >> cha;
	
	if(cha == 'a' || cha == 'e' || cha == 'i' || cha == 'o' || cha == 'u'){
	    	cout << "It's vowel character.";
		}
	else{
		cout << "It's consonant character.";
	}	
}
