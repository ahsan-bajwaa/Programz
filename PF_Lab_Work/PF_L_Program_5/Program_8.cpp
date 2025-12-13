#include <iostream>
using namespace std;

void printFactors(int num){
	cout << "Factor: ";
	for(int i = 1; i <= num; i++){
		if(num % i == 0){
			cout << i << " ";
		}
	}
}

int main(){
	int num;
	cout << "Enter a number: ";
	cin >> num;
	
	printFactors(num);
}
