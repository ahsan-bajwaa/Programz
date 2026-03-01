#include <iostream>
using namespace std;

void displayAscii(char ch){
	cout << "ASCII value = " << int(ch);
}

int main(){
	char ch;
	cout << "Enter a charcter: ";
	cin >> ch;
	
	displayAscii(ch);
}
