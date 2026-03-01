#include <iostream>
using namespace std;

int main(){
	float total_interest_rate, interest_rate, principal;
	float years, total_amount, yearly_interest_rate;
	
	cout << "Enter the principal amount : ";	//Enter Principal.
	cin >> principal;
	cout << "Enter th interest rate (in%) : ";	//Interest Rate.
	cin >> interest_rate;
	cout << "Enter the loan term (in year) : ";	//Years
	cin >> years;
	
	yearly_interest_rate = principal * (interest_rate/100);		//Yearly Interest
	total_interest_rate = yearly_interest_rate * years;		//interest with number of years
	
	cout << "*********************************************************" << endl;
	cout << "*	--------- Loan Summary ---------		*" << endl;
	cout << "*	Principal :		" << principal << " PKR		*" << endl;
	cout << "*	Total Interest :	" << total_interest_rate << " PKR	 		*"<< endl;
	cout << "*********************************************************" << endl;
	
	total_amount = principal + total_interest_rate;		//Total capital.
	
	cout << "--------------------------------------------" << endl;
	cout << "	Total Amount Payable : " << total_amount << " PKR" << endl;
	cout << "--------------------------------------------";
	
	return 0;
}
