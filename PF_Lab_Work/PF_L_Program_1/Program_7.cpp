#include <iostream>
using namespace std;

int main(){
	int no_pasngr, left_seat, capacity = 50;
	cout << "Enter the total number of passengers : "; //requseting user to enter input.
	cin >> no_pasngr;
	
	left_seat = capacity - (no_pasngr % capacity);

	if(left_seat == 50)	{	// If bus left with no passengers.
	cout << "-------------------------------------" << endl;
	cout << "The seats left in last bus is : 0" << endl; 
	cout << "-------------------------------------" << endl;
}
	
	else{			// If bus left with number of passengers.
	cout << "---------------------------------------------";
	cout << "The seats left in last bus is : " << left_seat;
	cout << "----------------------------------------------";
}
}
