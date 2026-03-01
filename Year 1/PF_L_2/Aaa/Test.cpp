#include <iostream>
using namespace std;

class Student_1
{
public:
    int a = 10;

    void Aaa(int a)
    {
        cout << "This is Aaa" << endl;
    }
};

class Student_2 : public Student_1
{
public:
    int b = 20;

    void Aaa(int b, int a)
    {
        cout << "This is Bbb";
    }
};

class Student_3 : public Student_2
{
public:
    using Student_1::Aaa;
    int c = 30;

    void Aaa()
    {
        cout << "This is Ccc" << endl;
    }
};

int main()
{
    Student_3 obj;
    obj.Aaa(7);
}