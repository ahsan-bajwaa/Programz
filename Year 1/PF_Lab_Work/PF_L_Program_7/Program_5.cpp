#include <iostream>
using namespace std;

void calculateDiscount(int &price, int discount = 10){
	price = price * (1- (discount * 1.00) / 100);
}

int main(){
	int price, discount;
	cout << "Enter price of a product: ";
	cin >> price;
	cout << "Enter amount of discount: ";
	cin >> discount;
	
	calculateDiscount(price, discount);
	
	cout << "Discounted price: Rs" << price;
}
