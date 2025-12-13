#include <iostream>
using namespace std;

class Base {
private:
    int private_variable = 1;

protected:
    int protected_variable = 2;

public:
    int public_variable = 3;

    void show_base() {
        cout << "Base: " << private_variable << ", "
             << protected_variable << ", " << public_variable << endl;
    }
};

class Derived : private Base {
public:
    void showDerived() {
        show_base();
        cout  << "Derived accessing: Public >> " << public_variable << endl;
        cout << "Derived accessing: Protected >> " << protected_variable << endl;
        // cout << private_variable; // Private member inaccessible.
    }
};

int main() {
    Derived d;
    d.showDerived();

    // d.show_base(); It is inaccessible as inherited privated. And so with all other varibles.
    return 0;
}