#include <iostream>
using namespace std;

class Shape
{
public:
   
void draw() 
{
    cout << "Draw a Shape." << endl;
}
};

class Circle: public Shape
{
public:
	
void draw() 
{
  cout << "Draw a Circle." << endl;
}
};

int main()
{
        Shape obj1;
		Circle obj2;
		
		obj1.draw();
		obj2.draw();
}