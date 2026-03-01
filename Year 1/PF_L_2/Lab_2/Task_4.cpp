#include <iostream>
using namespace std;

class Calculator
{
public:

void add(int a, int b)
{
    cout << "Sum of integers: " << a + b << endl;
}
};

class AdvancedCalculator : public Calculator
{
public:

void add(int a, int b)
{
    cout << "Sum of integers: " << a + b << endl;
}

void add(double a, double b)
{
    cout << "Sum of float numbers: " << a + b << endl;
}
};

int main()
{
    Calculator obj1;
    AdvancedCalculator obj2;

    obj1.add(5, 10);
    obj2.add(7, 15);
    obj2.add(3.5, 2.5);
}
