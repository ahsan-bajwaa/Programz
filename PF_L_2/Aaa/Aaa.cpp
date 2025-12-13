#include <iostream>
using namespace std;

class Person
{
public:
    string name;
//  Default constructor.
Person()
    {
        cout << "Person Created!" << endl;
    }

    //  Parameterized constructor.
    Person(string name)
    {
        this->name = name;
        cout << "Person created: " << name << endl;
    }

    // Non-parameterized Fucntion.
    void info()
    {
        cout << "General person info" << endl;
    }
};

class Student : public Person
{
public:
    using Person::info;
    //  Default constructor.
    Student()
    {
        cout << "Student created!" << endl;
    }

    //  Parameterized constructor.
    Student(string name, int rollno)
    {
        cout << "Student created: " << this->name << endl;
        cout << "Roll No: " << rollno << endl;
    }

    // Non-parameterized Fucntion.
    void info(int rollno)
    {
        cout << "Student Roll no: " << rollno << endl;
    }
};

class Teacher : public Person
{
public:
    using Person::info;
    //  Default constructor.
    Teacher()
    {
        cout << "Teacher created!" << endl;
    }

    //  Parameterized constructor.
    Teacher(string name, string subject)
    {
        cout << "Teacher created: :" <<  name << endl;
        cout << "Subject: " << subject << endl;
    }
     // Non-parameterized Fucntion.
     void info(string subject)
     {
         cout << "Teacher Subject: " << subject << endl;
     }
};

int main()
{
  Person obj1("ChatGPt");
  Student obj2 ("Useless_name", 456);
  
  obj2.info(456);
  
  obj2.info();

  Teacher obj3("ChatGPT Sir", "Knowledge of Milky Way.😎😏");
  obj3.info();
  obj3.info("Knowledge of Aliens👽🤖");


}