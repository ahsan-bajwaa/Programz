#include <iostream>
using namespace std;

class Calculator
{
public:
    void add(int a, int b)
    {
        cout << a + b << endl;
    }
};

class AdvancedCalculator : public Calculator
{
public:
    void add(int a, int b)
    {
        cout << a + b << endl;
    }

    void add(double a, double b)
    {
        cout << a + b << endl;
    }
};

int main()
{
    AdvancedCalculator calculator;
    calculator.add(2, 4);
    calculator.add(1.546, 3.524);

    return 0;
}
