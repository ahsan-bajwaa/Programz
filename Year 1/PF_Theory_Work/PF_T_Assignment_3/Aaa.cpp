#include <iostream>
using namespace std;

int main(){
	for(int i = 6; i > 0; i--){
		
		for(int j = 6-i; j > 0; j--){
			cout << " ";
		}
		for(int k = i; k > 0; k--){
			cout << k;
		}
		cout << endl;
	}
}
