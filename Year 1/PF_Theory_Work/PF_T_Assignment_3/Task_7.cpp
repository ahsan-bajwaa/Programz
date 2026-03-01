#include <iostream>
using namespace std;

int main(){
	int spaces = 0;
	for(int i = 1; i < 6; i++){
		
		for(int j = spaces; j > 0;j--){
			cout << " ";
		}
		int number = 1;
		for(int k = 6-i; k > 0; k--){
			
			cout << number;
			number++;
		}
		cout << endl;
		spaces++;
	}
}
