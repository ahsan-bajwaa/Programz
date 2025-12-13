#include <iostream>
#include <string>
using namespace std;

// Base class Employee
class Employee {
public:
    string name;
    double salary;
    
    Employee(string n, double s) {
        name = n;
        salary = s;
    }
};

// Derived class Manager
class Manager : public Employee {
public:
    string department;
    
    Manager(string n, double s, string d) : Employee(n, s) {
        department = d;
    }
};

// Function to print Finance department managers
void printFinanceManagers(Manager managers[], int size) {
    cout << "Managers in Finance department:" << endl;
    for (int i = 0; i < size; i++) {
        if (managers[i].department == "Finance") {
            cout << managers[i].name << endl;
        }
    }
}

int main() {
    // Create array of 5 Manager objects
    Manager managers[5] = {
        Manager("John", 50000, "Finance"),
        Manager("Mary", 60000, "HR"),
        Manager("Peter", 55000, "Finance"),
        Manager("Lisa", 52000, "IT"),
        Manager("Tom", 58000, "Finance")
    };
    
    // Call function to print Finance managers
    printFinanceManagers(managers, 5);
    
    return 0;
}