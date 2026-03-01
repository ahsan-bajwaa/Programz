#include <iostream>
using namespace std;

class BankAccount
{
	int balance = 0;
public:
	int accountNumber = 12345;

	void deposit(int amount)
	{
		balance += amount;
	}
	void withdraw(int amount)
	{
		balance -= amount;
	}
	void displayInfo()
	{
		cout << "Balance: " << balance;
	}
};

int main()
{	
	BankAccount obj1;
	int amount;
	cout << "Enter account number(12345): ";
	cin >> amount;
	if (amount != obj1.accountNumber) return 0;
	cout << "Enter deposite amount: ";
	cin >> amount;
	obj1.deposit(amount);

	cout << "Enter withdraw amount: ";
	cin >> amount;
	obj1.withdraw(amount);

	obj1.displayInfo();
}