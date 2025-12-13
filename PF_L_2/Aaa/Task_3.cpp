#include <iostream>
using namespace std;

//  Virtual Function.
// Ma'am wasy ya virtual funtion parha nhi ha many.
class Shape
{
public:
    virtual double area()
    {
        return 0.0;
    }
};

class Circle : public Shape
{
    double radius;
public:
    Circle(double r)
    {
        radius = r;
    }
    double area()
    {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape
{
    double length, width;
public:
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }
    double area()
    {
        return length * width;
    }
};

int main()
{
    Shape* shapes[3];

    shapes[0] = new Circle(5);        
    shapes[1] = new Rectangle(4, 6); 
    shapes[2] = new Circle(3); 

    cout << "Area of Circle 1: " << shapes[0]->area() << endl;
    cout << "Area of Rectangle: " << shapes[1]->area() << endl;
    cout << "Area of Circle 2: " << shapes[2]->area() << endl;

    return 0;
}