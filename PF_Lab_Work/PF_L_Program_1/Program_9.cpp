#include <iostream>
using namespace std;

int main(){
	float item_1, item_2, item_3, total, service_charge, sales_tax;
	
	cout << "Enter the price of food item 1 : ";	//Requesting user to enter billing amount.
	cin >> item_1;
	cout << "Enter the price of food item 2 : ";
	cin >> item_2;
	cout << "Enter the price of food item 3 : ";
	cin >> item_3;
	
	total = item_1 + item_2 + item_3;		//Sumning up all above entery.
	
	cout << "--------- Bill Summary ---------" << endl;
	cout << "Subtotal : 	 	 " << total << " PKR" << endl;
	cout << "Service Charge (10%) :	 " << (total * 0.1 ) << " PKR" << endl;
	cout << "Sales Tax (8%) : 	" << total * 0.08 << " PKR" << endl;
	
	service_charge = total * 0.1;
	sales_tax = total * 0.08;		//Total amout
	
	cout << "--------------------------------" << endl;
	cout << "Total Bill : " << total + service_charge + sales_tax << " PKR";
}
