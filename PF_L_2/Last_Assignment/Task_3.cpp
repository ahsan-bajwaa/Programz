#include <iostream>
using namespace std;

class Account
{
public:
    void display_1()
    {
        cout << "From Account: Non-virtual function\n";
    }
    virtual void display_2()
    {
        cout << "From Account: Virtual function\n";
    }
    void display_3(int x) 
    {
        cout << "From Account: Overloaded function with int\n";
    }
};

class SavingsAccount : public Account
{
public:
    void display_1()
    {
        cout << "From SavingsAccount: Non-virtual function (name hiding)\n";
    }

    void display_2() override
    {
        cout << "From SavingsAccount: Overridden virtual function\n";
    }

    void display_3(double y)
    {
        cout << "From SavingsAccount: Overloaded function with double\n";
    }
};

int main()
{
    SavingsAccount savings_account;
    Account* account_pointer = &savings_account;

    cout << "Calling display_1 (non-virtual):\n";
    account_pointer->display_1();

    cout << "Calling display_2 (virtual):\n";
    account_pointer->display_2();

    cout << "Calling display_3 (overload):\n";
    account_pointer->display_3(42);
}
