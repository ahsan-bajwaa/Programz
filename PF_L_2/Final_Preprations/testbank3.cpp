#include <iostream>
using namespace std;

class Employes
{
protected:
    string name;
    int salary;

public:
    Employes(string personname, int sal) : name(personname), salary(sal) {}
    virtual void display()
    {
        cout << name << " Salary is " << salary << endl;

    }
};

class Manager : protected Employes
{

private:
    int bonus;

public:
    Manager(string personname, int sal, int bon) : Employes(personname, sal), bonus(bon) {}
    void display() override
    {
        cout << name << " Salary is " << salary << ". He got bonus by his great work.(The bonus he got is ): " << bonus << endl;
    }
};

class Engineer : protected Employes
{
private:
    string specilization;

public:
    Engineer(string personname, int sal, string spe) : Employes(personname, sal), specilization(spe) {}
    void display() override
    {
        cout << name << " Salary is " << salary << ". He is Specilized in " << specilization << endl;
    }
};

int main()
{

    Manager *manager = new Manager("Muhammad_Zubair", 50000, 40000);
    Engineer *engineer = new Engineer("MR Sonic", 59999, "CyberSecurity_Engineer");

    manager->display();
    engineer->display();

    delete manager;
    delete engineer;
    return 0;
}
