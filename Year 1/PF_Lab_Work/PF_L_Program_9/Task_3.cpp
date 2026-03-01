#include <iostream>
using namespace std;

int main(){
	int Array[5] = {2, 4, 6, 8, 10};
	int find;
	cout << "Enter a number: ";
	cin >> find;
	
	for(int i = 0; i < 5; i++){
		if(find == Array[i]){
			cout << "Your number '" << find << "' is present in array!";
			return 0;
		}
	}
	cout << "Number is not founded!";
}
