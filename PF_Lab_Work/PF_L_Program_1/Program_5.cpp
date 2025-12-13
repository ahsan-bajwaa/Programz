#include <iostream>
using namespace std;

int main(){
	int hour;
	cout << "Enter time in hours : ";  	//Requsting user to enter hours.
	cin >> hour;
	
	cout << "*************************************************" << endl;
	cout << "*	Total minutes in " << hour << " hour is : " << hour * 60 << "	*" << endl;	//Convert hour into minutes.
	cout << "*	Total seconds in " << hour << " hour is : " << hour  * 60 * 60 << "	*" << endl;	//Convert hour into seconds.
	cout << "*************************************************";
}
