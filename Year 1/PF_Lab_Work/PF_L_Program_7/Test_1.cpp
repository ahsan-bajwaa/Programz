#include <iostream>
using namespace std;

int function(int &number){
	return number = 10;
}

int main(){
	int number;

	function(number);
	number++;
	
	cout << number;
}
