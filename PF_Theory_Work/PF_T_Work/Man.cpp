	// Ahsan Hammad
	// su92-bscbm-f24-015

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	float banana= 1.20, apple= 0.50, mango= 1.50, sum1, sum2, sum3, total;
	int no1, no2, no3;
	
	cout << "Enter amount of Banana ";
	cin >> no1;
	cout << "Enter amount of Apple ";
	cin >> no2;
	cout << "Enter amount of Mango ";
	cin >> no3;
	
	sum1 = no1 * banana;
	sum2 = no2 * apple;
	sum3 = no3 * mango;
	total = sum1 + sum2 + sum3;
	cout << endl;
	cout << endl;
	
	cout << fixed << setprecision(2);
	cout << setw(40) << setfill('-') << " " << endl;
	cout << setfill(' ');	
	cout << setw(6) << "Items" << right << setw(11) << "Price" << setw(10) << "Quantity" << setw(11) << "Subtotal" << endl;
	cout << setw(6) << "Banana" << setw(10) << banana << "$" << setw(10) << no1 << setw(10) << no1 << "$" << endl;
	cout << setw(6) << "Apple" << setw(10) << apple << "$" << setw(10) << no2 << setw(10) << no2 << "$" << endl;
	cout << setw(6) << "Mango" << setw(10) << mango << "$" << setw(10) << no3 << setw(10) << no3 << "$" << endl;
	
	cout << setw(40) << setfill('-') << " " << endl;
	
	cout << setw(6) << setfill(' ') << "Total" << setw(31) << total << "$" << endl;
	cout << setw(40) << setfill('-') << " ";
}
