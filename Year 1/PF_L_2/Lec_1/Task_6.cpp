#include <iostream>
using namespace std;

class class1
{
public:
    void solve(int a, int b)
    {
        cout << "Multiply of first two numbers: " << a * b << endl;
    }
    void solve(int a, int b, int c)
    {
        cout << "Subtract of first two numbers: " << a - b - c << endl;
    }
    void solve(int a, int b, int c, int d)
    {
        cout << "Sum of first two numbers: " << a + b + c + d << endl;
    }

};
class class2
{
public:
    class1 obj1;
    void call()
    {
        obj1.solve(10,2);
        obj1.solve(5,2.1);
        obj1.solve(7,6,2,1); 
    }
    
};

int main()
{
    class2 obj2;
    
    obj2.call();

}