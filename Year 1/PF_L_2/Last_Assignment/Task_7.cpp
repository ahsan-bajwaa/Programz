#include <iostream>
using namespace std;

class Employee
{
private:
    const int id;
    string name;
public:
    Employee(int ID, string Name) : id(ID), name(Name)
    {
        cout << Name << id;
    };
};

int main()
{
    Employee employee(10, "Constant Number: ");

    /*
    Answer: 
        We use an initializer list because:
            1. It directly initializes members before constructor body runs.
            2. It is **required** for `const` and reference members.
            - `const` members must be initialized at the moment of creation.
            - You **cannot assign** to them later inside the constructor body.
    */
}