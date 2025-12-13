#include <iostream>
#include <string>
using namespace std;

class Transaction {
public:
    void deposit(double amount_, string account_type_) {
        cout << "Deposited $" << amount_ << " into " << account_type_ << " account." << endl;
    }

    void withdraw(double amount_, string account_type_) {
        cout << "Withdrew $" << amount_ << " from " << account_type_ << " account." << endl;
    }

    void check_balance(string account_type_) {
        cout << "Checked balance for " << account_type_ << " account." << endl;
    }
};

class Customer {
private:
    Transaction transaction_;

public:
    void perform_action(string account_type_, string action_, double amount_ = 0.0) {
        if (action_ == "deposit") {
            transaction_.deposit(amount_, account_type_);
        } else if (action_ == "withdraw") {
            transaction_.withdraw(amount_, account_type_);
        } else if (action_ == "check_balance") {
            transaction_.check_balance(account_type_);
        } else {
            cout << "Invalid action." << endl;
        }
    }
};

int main() {
    Customer customer_;

    customer_.perform_action("savings", "deposit", 100.0);
    customer_.perform_action("current", "withdraw", 50.0);
    customer_.perform_action("fixed_deposit", "check_balance");

    return 0;
}
