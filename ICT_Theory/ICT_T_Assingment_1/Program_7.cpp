#include <iostream>
using namespace std;

int main(){
	char character;
	cout << "Enter character: ";
	cin >> character;
	
	if(isalpha(character)){
		cout << "It's character!!";
	}
	else{
		cout << "It's not character!!";
	}
}
