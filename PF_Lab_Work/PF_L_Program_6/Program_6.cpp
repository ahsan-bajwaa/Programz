#include <iostream>
using namespace std;

void convertToBinary(int num){
	string reversed_order, binary_number;
		
		// Here I'm using '0' so it will consider reminder as character. because int value can't be added in string directly.
	for (int i = num; i > 0; i /= 2) {
        reversed_order += i % 2 + '0';
    }
    for (int i = reversed_order.length() - 1; i >= 0; i--) {
        binary_number += reversed_order[i];
    }
	
    cout << "Binary Number: " << binary_number << endl;
	
}

int main(){
	int num;
	cout << "Enter a number: ";
	cin >> num;
	
	convertToBinary(num);
}
