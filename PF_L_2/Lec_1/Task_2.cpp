#include <iostream>
using namespace std;

class Calculator
{
public:
    void Numbers(int a, int b)
    {
        cout << "Sum of two numbers: " << a + b << endl;
    }
    void Numbers(int a, int b, int c)
    {
        cout << "Sum of three numbers: " << a + b + c << endl;
    }
    void Numbers(int a, int b, int c, int d)
    {
        cout << "Sum of four numbers: " << a + b + c + d << endl;
    }
    void Numbers(int a, int b, int c, int d, int e)
    {
        cout << "Sum of five numbers: " << a + b + c + d + e << endl;
    }
    void Numbers(int a, int b, int c, int d, int e, int f)
    {
        cout << "Sum of six numbers: " << a + b + c + d + e + f << endl;
    }
};

int main()
{
    Calculator obj;
    
    obj.Numbers(1, 2);
    obj.Numbers(1, 2, 3);
    obj.Numbers(1, 2, 3, 4);
    obj.Numbers(1, 2, 3, 4, 5);
    obj.Numbers(1, 2, 3, 4, 5, 6);
    
    return 0;
}
