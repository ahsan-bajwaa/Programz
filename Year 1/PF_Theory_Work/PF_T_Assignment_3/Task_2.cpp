#include <iostream>
using namespace std;

int main(){
	for(int i = 7; i >= 1; i--){
		for(int j = i; j >= 1; j--){
			cout << "*";
		}
		cout << endl;
	}
}
