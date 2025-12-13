#include <iostream>
using namespace std;

class Display 
{
public:
    void print_Value(int c)
    {
        cout << "Integer: " << c << endl;
    }
    void print_Value(float b) 
    {
        cout << "Float: " << b << endl;
    }
    void print_Value(double b) 
    {
        cout << "Double: " << b << endl;
    }
    void print_Value(string a)
    {
        cout << "String: " << a << endl;
    }
};

int main()
{
    Display obj; 
    float a = 0.1234f;

    obj.print_Value("Muhammad Ahmad");
    obj.print_Value(a); 
    obj.print_Value(789);
    obj.print_Value(3.14159); 

    return 0;
}
