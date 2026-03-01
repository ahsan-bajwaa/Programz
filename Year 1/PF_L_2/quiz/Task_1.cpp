#include <iostream>
using namespace std;

class Calculation
{
public:
	//	For Circle.
    void area(double input_1, int input_2)
    {
		cout << "Area of Circle is: " << input_1 * input_2 * input_2 << endl;
    }
	// For rectangle.
    void area(int input_1, int input_2)
    {
		cout << "Area of Rectangle is: " << input_1 * input_2 << endl;
    }
	// For Triangle.
    void area(int input_2, double input_3)
    {
		cout << "Area of Triangle is: " << 1.0/2 * input_2 * input_3 << endl;
    }
    
};

int main()
{
    Calculation obj;
    double pi_value = 3.14;
    double hight = 6;
    

    obj.area(pi_value,9);
    obj.area(7, 8);
    obj.area(4,hight);
    
}