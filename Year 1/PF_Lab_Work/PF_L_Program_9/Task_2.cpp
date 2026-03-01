#include <iostream>
using namespace std;

int main(){
	int Array[5] = {5, 4, 3, 2, 1};
	int reversed_Array[5], index = 0;
	
	cout << "Orignal form!" << endl;
	for(int j = 0; j < 5; j++){
		cout << Array[j] << " ";
	}
	
	for(int i = 4; i >= 0; i--){
		reversed_Array[index] = Array[i];
		index++;
	}
	cout << endl << "Reversed Array" << endl;
	for(int j = 0; j < 5; j++){
		cout << reversed_Array[j] << " ";
	}
}
