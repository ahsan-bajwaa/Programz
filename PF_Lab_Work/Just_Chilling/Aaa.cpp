#include <iostream>
#include <string> // Include the string library
using namespace std;

int main() {
	string input;
	cout << "Enter input: ";
	cin >> input;
	for (int i = input.length() - 1; i >= 0; i--) {
		if (input[i] == 'A' || input[i] == 'A') continue;
		cout << input[i] << " ";
	}
    return 0;
}
