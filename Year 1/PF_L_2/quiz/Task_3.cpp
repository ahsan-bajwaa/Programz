#include <iostream>
using namespace std;

class BankAccount
{
public:
	int account_no;
	double balance;
	BankAccount()
	{
		account_no = 0;
		balance = 0.0;	// if i use wset then this .0 will appear.
		cout << "Constructor 1\nBank Account: " << account_no << "\nBalance: " << balance << endl;
	}
	BankAccount(int account)
	{
		account_no = account;
		balance = 100.0;	// Default 100.
		cout << "Constructor 2\nBank Account: " << account_no << "\nBalance: " << balance << endl;
	}
	BankAccount(int account, double bal)
	{
		if (balance <= bal)	
		{
			balance = bal;
		}
		
		else	balance = 100.0;
		cout << "Constructor 3\nBank Account: " << account_no << "\nBalance: " << balance << endl;
	}
};

int main()
{
	BankAccount con1;
	BankAccount con2(911);
	BankAccount con3(911,120.23f);
}