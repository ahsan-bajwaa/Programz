#include <iostream>
using namespace std;

void sorting_number(int &number_1, int &number_2, int &number_3) {
    
	int temp;
	
    if (number_1 > number_2) {
        temp = number_1;
        number_1 = number_2;
        number_2 = temp;
    }
	
    if (number_1 > number_3) {
        temp = number_1;
        number_1 = number_3;
        number_3 = temp;
    }
	
    if (number_2 > number_3) {
        temp = number_2;
        number_2 = number_3;
        number_3 = temp;
    }
}
int main(){
	int number_1, number_2, number_3;
	number_1 = 6;
	number_2 = 8;
	number_3 = 5;
	
	//	Before Sorting..
	cout << "Before Sorting" << endl;
	cout << number_1 << endl;
	cout << number_2 << endl;
	cout << number_3 << endl;
	
	sorting_number(number_1, number_2, number_3);
	
	// After Sorting.
	cout << "After Sorting" << endl;
	cout << number_1 << endl;
	cout << number_2 << endl;
	cout << number_3 << endl;
}