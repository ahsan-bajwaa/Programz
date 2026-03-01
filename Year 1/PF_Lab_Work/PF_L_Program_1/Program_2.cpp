#include <iostream>
using namespace std;

int main(){
	string name_1, name_2;
	cout << "Enter your first name : ";		//requesting to enter  first name
	cin >> name_1;
	cout << "Enter your second value : ";	//requesting to enter second name
	cin >> name_2;
	
	cout << "*****************************************" << endl;		//putting stars.
	cout << "*	Hi, Good Morning " << name_1 << " " << name_2 << "!	*" << endl; 		//displaying full name
	cout << "*****************************************";
	
	return 0;
}
