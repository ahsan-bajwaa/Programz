#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	float b_price = 1.20, a_price = 0.50, m_price = 1.50, sum_1, sum_2, sum_3, total;
	int amount_1, amount_2, amount_3;
	
	cout << "Enter Number of Banana you want to buy: ";
	cin >> amount_1;
	cout << "Enter number of Apple you want to buy: ";
	cin >> amount_2;
	cout << "Enter number of Mango you want to buy: ";
	cin >> amount_3;
	
	sum_1 = amount_1 * b_price;
	sum_2 = amount_2 * a_price;
	sum_3 = amount_3 * m_price;
	total = sum_1 + sum_2 + sum_3;
	
	
	cout << endl;
	
	cout << fixed << setprecision(2);
	cout << setw(76) << setfill('_') << " " << endl;
	cout << setw(76) << setfill('-') << " " << endl;
	cout << setfill(' ');
	cout << setw(4) << setfill(' ') << left << "|" << "Items" << right << setw(20) << "Price" << setw(21) << "Quantity" << setw(22) << "Subtotal" << setw(3) << "|" << endl;
	cout << setw(76) << setfill('_') << " " << endl;
	cout << setfill(' ') << setw(3) << left << "|" << "Banana" << right << setw(19) << b_price << "$" << setw(21) << amount_1 << setw(21) << sum_1 << "$" << setw(3) << "|" << endl;
	cout << setw(4) << left << "|" << "Apple" << right << setw(19) << a_price << "$" << setw(21) << amount_2 << setw(21) << sum_2 << "$" << setw(3) << "|" << endl;
	cout << setw(4) << left << "|" << "Mango" << right << setw(19) << m_price << "$" << setw(21) << amount_3 << setw(21) << sum_3 << "$" << setw(3) << "|" << endl;
	
	
	cout << setw(76) << setfill('_') << " " << endl;
	cout << setw(76) << setfill('-') << " " << endl;
	
	cout << "|" << setw(8) << right << setfill(' ') << "Total" << setw(62) << total << "$" << setw(3) << "|" << endl;
	cout << setw(76) << setfill('-') << " ";
}
