#include <iostream>
using namespace std;

class area
{
public:
    void calculate_area(int l)
    {
        cout << "Area of square: " << l * l << endl;
    }
    void calculate_area(int l, int b)
    {
        cout << "Area of Rectangle: " << l * b << endl;
    }
    void calculate_area(double r)
    {
        double pi = 3.14159;
        cout << "Area of circle: " << pi * r * r;
    }
};

int main()
{
    area obj;
    
    // Area of Square.
    obj.calculate_area(7);

    // Area of Rectangle.
    obj.calculate_area(4,5);

    // Area of Circle.
    obj.calculate_area(5.1f);
}