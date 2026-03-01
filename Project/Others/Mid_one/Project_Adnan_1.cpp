#include <iostream>
using namespace std;

int main(){
	int basic_salery, darness, house_rent, taxes, gross_salery;
	cout << "Enter your basic_salery: ";
	cin >> basic_salery;
	
	darness = 	 35 * basic_salery / 100;
	house_rent = 25 * basic_salery / 100;
	gross_salery = basic_salery + darness + house_rent;
	taxes = 	 10 * gross_salery / 100;
	gross_salery -= taxes;
	
	cout << endl;
	cout << "Basic Salery: " << basic_salery << endl;
	cout << "Darness: "      << darness << endl;
	cout << "House Rent: "   << house_rent << endl;
	cout << "Taxes: "		 << taxes << endl;
	cout << "Gross Salery: " << gross_salery << endl;
}
