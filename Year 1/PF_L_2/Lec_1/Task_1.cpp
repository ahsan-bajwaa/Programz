#include <iostream>
using namespace std;

class Calculator 
{
public:
    void Numbers(int a, int b) 
    {
        cout << "Sum of first two numbers: " << a + b << endl;
    }
    void Numbers(int a, int b, int c)
    {
        cout << "Sum of three numbers: " << a + b + c << endl;
    }
};

int main()
{
    Calculator obj;
    
    obj.Numbers(1, 2);
    obj.Numbers(1, 2, 3); 

    return 0;
}
