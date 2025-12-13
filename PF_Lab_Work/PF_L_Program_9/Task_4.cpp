#include <iostream>
using namespace std;

int main(){
	int Array[11] = {2, 3, 3, 4, 4, 4, 5, 5, 6, 7, 7};
	int find, count = 0;
	cout << "Enter a number: ";
	cin >> find;
	
	for(int i = 0; i < 11; i++){
		if(find == Array[i]){
			count++;
		}
	}
	if(count == 0){
		cout << "Number is not present in array!";
	}
	else{
		cout << "This number '" << find << "' appears " << count << " times.";
	}
}
