#include <iostream>
using namespace std;

class Rectangle
{
public:
    void area()
    {
        cout << "area(): = " << 1 << endl;
    }
    void area(int length)
    {
        cout << "area(int): = " << length * length << endl;
    }

    void area(int length, int width)
    {
        cout << "area(int, int): = " << length * width << endl;
    }
};

int main() {
    Rectangle rectangle;

    rectangle.area();
    rectangle.area(5);
    rectangle.area(4, 6);

    // It will call function: area(int length) and consider 4.5 as 4.
    rectangle.area(4.5);

    return 0;
}