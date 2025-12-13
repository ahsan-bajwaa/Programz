#include <iostream>
using namespace std;

class Person
{
protected:
    int age = 10;
public:
    void showAge()
    {
        cout << "Age: " << age << endl;
    }    
};

class Student_public : public Person
{
public:
    void accessAge()
    {
        cout << "For Public inheritance => Age: " << age << endl;
    }
};

/*
Age can't be access diretly in main function.
So we need function within class for that.
*/
class Student_private : private Person
{
public:
    void accessAge()
    {
        cout << "For Protected inheritance => Age: " << age << endl;
    }
};

class Student_protected : protected Person
{
public:
    void accessAge()
    {
        cout << "For Private inheritance => Age: " << age << endl;
    }
};

int main()
{
    Student_public student_public;
    Student_protected student_protected;
    Student_private student_private;

    student_public.showAge();
    //  For public.
    student_public.accessAge();
    //  For Protected.
    student_protected.accessAge();
    //  For Private.
    student_private.accessAge();

    return 0;
}
