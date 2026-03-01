#include <iostream>
using namespace std;

cout << "Ahsan" << endl;

int main(){
	int temp;
	cout << "Enter Temperature: ";
	cin >> temp;
	
	if(temp < 0)
		cout << "Freezing.";
	else if(temp <= 10)
		cout << "Very Cold.";
	else if(temp <= 20)
		cout << "Cold";
	else if(temp <= 30)
		cout << "Warm";
	else if(temp > 30)
		cout << "Hot";
	return 0;		
}
