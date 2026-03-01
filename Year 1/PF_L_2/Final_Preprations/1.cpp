#include <iostream>
using namespace std;

class Employee
{
protected:
    string Name;
    int Salery;
    
    virtual void display()
    {
        cout << "Name: " << Name << "\nSalery: " << Salery << "\n"; 
    }
public:
    Employee(string name, int salery) : Name(name), Salery(salery) {}
};

class Manager : protected Employee
{
protected:
    int Bonus;
public:
    Manager(string name, int salery, int bonus) : Employee(name, salery), Bonus(bonus) {}

    void display()
    {
        cout << "Name: " << Name;
        cout << "\nSalery: " << Salery;
        cout << "\nBonus: " << Bonus;
        cout << "\nTotal Salery: " << Salery + Bonus << endl;
    }
};

class Engineer : protected Employee
{
private:
    string Specialization;
public:
    Engineer(string name, int salery, string specialization) : Employee(name, salery), Specialization(specialization) {}
    void display()
    {
        cout << "Specialization: " << Specialization << endl;
    }
};

int main()
{
    Manager manager("Spider-Man", 155000, 50000);
    Engineer engineer("Iron-Man", 210000, "Savier");
    Employee *employee;
}