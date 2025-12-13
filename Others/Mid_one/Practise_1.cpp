#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int price, select, region, discount;
	float discounted_price, with_taxes, payment_method;
	cout << "Enter price: ";
	cin >> price;
	cout << "Press 1 for member.\nPress 2 for non-member. \n Select: ";
	cin >> select;
	cout << "Select area!!\n1 for Urban.\n2 for Suburban.\n3 for Rural. \n Select: ";
	cin >> region;
	
	if(select == 1){
		if(region == 1){
			discount = price * 15 / 100;
		}
		else if(region == 2){
			discount = price * 10 / 100;
		}
		else if(region == 3){
			discount = price * 5 / 100;
		}
	}
	else if(select == 2){
		if(region = 1){
			discount = price * 10 / 100;
		}
		else if(region == 2){
			discount = price * 5 / 100;
		}
		else if(region == 3){
			discount = 0;
		}
	}
	discounted_price = price - discount;
	cout << fixed << setprecision(2);
	discounted_price += discounted_price * 5.0 / 100;
	cout << "1 for Cash payment.\n2 for Credit Card.\n Select: ";
	cin >> select;
	
	if(select == 1){
		discounted_price -= discounted_price * 2 / 100;
	}
	else if(select == 2){
		discounted_price += discounted_price * 1 / 100;
	}
	cout << "SubToal: " << price << endl;
	cout << "After Discount: " << discounted_price;
}
