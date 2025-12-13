#include <iostream>
using namespace std;

int main(){
	int Array[5] = {5, 6, 3, 8, 7};
	int maximum_number, minimum_number;
	maximum_number = minimum_number = Array[0];
	
	for(int i = 0; i < 5; i++){
		int digit = Array[i];
		
		if(maximum_number < digit){
			maximum_number = digit;
		}
		if(minimum_number > digit){
			minimum_number = digit;
		}		
	}
	cout << "Maximum number in array is: " << maximum_number << endl;
	cout << "Minimum number in array is: " << minimum_number;
}
