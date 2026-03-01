#include <iostream>
using namespace std;

bool isPerfect(int num){
	cout << "Perfect number between 1 to 100" << endl;
	for(int i = 2; i <= 100; i++){	
		int sum= 0;
		for(int j = 1; j < i; j++){
			if(i % j == 0){
				sum += j;
			}			
		}
			if(sum == i){
				cout << "Perfect number: " << sum << endl;
		}
	}	
}

int main(){
	int num;
	
	isPerfect(num);
}
