#include <iostream>
using namespace std;

int main(){
	int number;
	
	for(;;){
		cout << "Enter number: ";
		cin >> number;
		if(number%2 == 0)
			cout << "It\'s \"Even\" number." << endl;
		
		else
			cout << "It\'s \"Odd\" number." << endl;	
	}
}
