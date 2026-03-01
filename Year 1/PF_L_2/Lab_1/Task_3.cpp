#include <iostream>
using namespace std;

class Product {
public:	
	string productName;
	int price;
	
	void displayInfo() {
		cout << "ProductName: " << productName << endl;
		cout << "Price: " << price << endl;
	}
};

int main(){
	
	Product obj1;
	
	obj1.productName = "Dairy_milk";
	obj1.price = 200;
	
	obj1.displayInfo();
	
}