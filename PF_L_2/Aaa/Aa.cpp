#include <iostream>
using namespace std;

class Student 
{
public:

    void display()
    {
        cout << "This is 1st class" << endl;
    }
};

class Stuuudeeentttt : public Student
{
public:
    // using Student::display;
    
    void display()
    {
        cout << "This is 2st class" << endl;
    }
};

int main()
{
    Stuuudeeentttt obj;

    // Student::display;
    obj.display();
}