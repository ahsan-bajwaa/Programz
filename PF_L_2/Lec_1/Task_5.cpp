#include <iostream>
using namespace std;

class Operation {
public:
    void calculate(int a, int b)
    {
         cout << "Sum: " << a + b << endl;
    }
    void calculate(int a, int b, int c) 
    { 
        cout << "Product: " << a * b * c << endl; 
    }
    void calculate(float a, float b) 
    { 
        cout << "Difference: " << a - b << endl; 
    }
};

int main() {
    Operation obj;
    obj.calculate(10, 5);
    obj.calculate(2, 3, 4);
    obj.calculate(20.5f, 5.5f);
}
