#include <iostream>
using namespace std;

int main(){
	for(int i = 1; i < 7; i++){
		for(int j = i; j < 6; j++){
			cout << " ";
		}
		for(int k = i; k > 0; k--){
			cout << "*";
		}
		cout << endl;
	}
}
