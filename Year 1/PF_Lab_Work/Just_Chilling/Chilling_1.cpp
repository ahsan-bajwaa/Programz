#include <iostream>
using namespace std;

int main() {
	int number;
	
		for(;;) {
			cout << endl << "Enter number: ";
			cin >> number;
			if (number > 0) {
			if (number % 2 == 0) cout << "Even wala number";
			else if (number % 2 == 1) cout << "Odd wala number";
			}
			else cout << "Galat number.";
		}
}
		