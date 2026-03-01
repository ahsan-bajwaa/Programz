#include <iostream>
#include <cctype>
using namespace std;

int main(){
	char cha;
	cout << "Enter character: ";
	cin >> cha;
	
	if(isupper(cha)){
		cout << "It's upper character.";
	}
	else if(islower(cha)){
		cout << "It's lower character.";
	}
}
