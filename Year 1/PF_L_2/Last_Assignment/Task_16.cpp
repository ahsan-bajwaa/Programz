#include <iostream>
using namespace std;

// Struct version
struct Structure 
{
    // Default public access, no private or protected.
    int x;
    int y;

    // Constructor can be added.
    Structure(int x = 0, int y = 0) : x(x), y(y) {}

    // Member function.
    void display() {
        cout << "Structure: (" << x << ", " << y << ")" << endl;
    }

    // Destructor can also be added.
    ~Structure() {
        cout << "Struct point destroyed" << endl;
    }
};

// Class version
class Class {
    // Default private access.
    int x;
    int y;

public:
    // Constructor.
    Class(int x = 0, int y = 0) : x(x), y(y) {}

    // Member function.
    void display() {
        cout << "Class: (" << x << ", " << y << ")" << endl;
    }

    // Virtual function can be added.
    virtual void virtual_function() {
        cout << "This is from class: virtual function" << endl;
    }

    // Destructor.
    virtual ~Class() {
        cout << "Class point destroyed" << endl;
    }
};

int main() {
    // Using struct
    Structure structure(3, 4);
    structure.display();

    // Using class
    Class class_1(5, 6);
    class_1.display();
    class_1.virtual_function();

    return 0;
}