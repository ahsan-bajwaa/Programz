#include <iostream>
using namespace std;

class A {
public:
    A()
    {
        cout << "A's constructor is called." << endl;
    }
    ~A()
    {
        cout << "A's destructor is called.\n";
    }

    int public_variable = 10;

protected:
    int protected_variable = 20;

private:
    int private_variable = 30;
};

class B : public A
{
public:
    B()
    {
        cout << "B's constructor is called." << endl;
    }
    ~B()
    {
        cout << "B's destructor is called.\n";
    }
};

class C : public B {
public:
    C()
    {
        cout << "C's constructor called." << endl;
    }
    ~C()
    {
        cout << "C's destructor is called.\n";
    }

    void accessMembers()
    {
        cout << "C accessing A's publicVar: " << public_variable << endl;    // ✅ Allowed (inherited as public in B)
        cout << "C accessing A's protectedVar: " << protected_variable << endl; // ✅ Allowed (inherited as protected in B)
        //  Private memebers are inaccessible. 
    }
    
};

int main() {
    cout << "--- Constructors ---" << endl;
    C c;
    c.accessMembers();
    return 0;
}