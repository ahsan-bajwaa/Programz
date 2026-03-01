#include <iostream>
using namespace std;

int main(){
	string number = "20";
	string* pointer = &number;
	
	cout << number << endl;
	cout << pointer << endl;
	cout << *pointer << endl;
	
	*pointer = "10";
	
	cout << number << endl;
	cout << pointer << endl;
	cout << *pointer << endl;
	cout << &pointer;
}
