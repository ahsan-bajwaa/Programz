#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    string name;
    double salary;
    
    Employee(string n, double s)
    {
        name = n;
        salary = s;
    }
};

class Manager : public Employee
{
public:
    string department;

    Manager(string n, double s, string d) : Employee(n, s) {
        department = d;
    }
};

void printFinanceManagers(Manager managers[], int size)
{
    cout << "Managers in Finance department:" << endl;
    for (int i = 0; i < size; i++) {
        if (managers[i].department == "Finance") {
            cout << managers[i].name << endl;
        }
    }
}

int main() {
    Manager managers[5] = {
        Manager("Ali", 50000, "Finance"),
        Manager("Ahmad", 60000, "Professor"),
        Manager("Zain", 55000, "Teacher"),
        Manager("Israr", 52000, "Finance"),
        Manager("Mateen", 58000, "Cyber Expert")
    };
    
    printFinanceManagers(managers, 5);
    
    return 0;
}