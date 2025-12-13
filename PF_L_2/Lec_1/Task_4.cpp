#include <iostream>
using namespace std;

class Multiplication  
{
public:
    void answer(int a, int b)
    {
        cout << "Multiply two numbers: " << a * b << endl;
    }
    void answer(int a, int b, int c)
    {
        cout << "Multiply three number: " << a * b * c << endl;
    }
};

class Addition
{
public:
    void answer(int a, int b)
    {
        cout << "Sum two number: " << a + b << endl;
    }
    void answer(int a, int b, int c)
    {
        cout << "Sum of three numbers: " << a + b + c << endl;
    }
};

int main()
{
    Multiplication obj1;
    Addition obj2;
    
    obj1.answer(5, 4);
    obj1.answer(2, 4, 3);

    obj2.answer(4, 5); 
    obj2.answer(4, 5, 7); 

    return 0; 
}
