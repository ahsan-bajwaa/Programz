#include <iostream>
using namespace std;

int main(){
	char alphabet;
	cout << "Enter a character of your choice : ";		//offering to enter any alphabet.
	cin >> alphabet;
	
	cout << "**************************************" << endl;
	cout << "The ASCII code of " << alphabet << " you entered is " << int(alphabet) << endl;	//using int function to convert in ASCII code
	cout << "**************************************";
}
