#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    int id;
    double salary;

public:
    Employee(string n, int i, double s)
    {
        name = n; id = i; salary = s;
    }

    Employee(string n, int i)
    {
        name = n; id = i; salary = 56000;
    }

    // Method to display employee details
    void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    Employee e1("Muhammad Zubair", 101, 75000.0);
    cout << "Employee 1 Details:" << endl;
    e1.display();

    Employee e2("Muhammad Ahmad", 102);
    cout << "\nEmployee 2 Details:" << endl;
    e2.display();

    return 0;
}