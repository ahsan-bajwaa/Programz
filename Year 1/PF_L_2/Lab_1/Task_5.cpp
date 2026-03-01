#include <iostream>
using namespace std;

class BankAccount
{
	int balance = 0;
public:
	int accountNumber_1 = 12345;
	int accountNumber_2 = 54321;

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
		cout << "Balance: " << balance << endl;
	}
};

int main()
{	
	BankAccount obj1, obj2;
	int amount;
	cout << "Enter 1st account number(12345): ";
	cin >> amount;
	if (amount != obj1.accountNumber_1) 
    {
        cout << "You entered wrong accout!";
        return 0;
    }
	cout << "Enter deposite amount: ";
	cin >> amount;
	obj1.deposit(amount);

	cout << "Enter withdraw amount: ";
	cin >> amount;
	obj1.withdraw(amount);

	obj1.displayInfo();

    //  For Second Account.
    cout << "Enter 2nd account number(54321): ";
	cin >> amount;
	if (amount != obj2.accountNumber_2) 
    {
        cout << "You entered wrong accout!";
        return 0;
    }
	cout << "Enter deposite amount: ";
	cin >> amount;
	obj2.deposit(amount);

	cout << "Enter withdraw amount: ";
	cin >> amount;
	obj2.withdraw(amount);

	obj2.displayInfo();
}