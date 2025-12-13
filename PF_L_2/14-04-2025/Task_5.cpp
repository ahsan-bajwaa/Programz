//  For Public...

#include <iostream>
using namespace std;

class Person
{
protected:
    int age;

public:
    void showAge()
    {
        cout << age << endl;
    }
};

class Student : public Person
{
public:
    void setAge(int a)
    {
        age = a;
    }
};

int main()
{
    Student student;
    student.setAge(20);
    student.showAge();

    return 0;
}


-----------------------------------------------------------------------------
// For Protected..

#include <iostream>
using namespace std;

class Person
{
protected:
    int age;

public:
    void showAge()
    {
        cout << age << endl;
    }
};

class Student : protected Person
{
public:
    void setAge(int a)
    {
        age = a;
    }

    void displayAge()
    {
        showAge();
    }
};

int main()
{
    Student student;
    student.setAge(21);
    student.displayAge();

    return 0;
}

-------------------------------------------------------------------
// For the Privete...

#include <iostream>
using namespace std;

class Person
{
protected:
    int age;

public:
    void showAge()
    {
        cout << age << endl;
    }
};

class Student : private Person
{
public:
    void setAge(int a)
    {
        age = a;
    }

    void displayAge()
    {
        showAge();
    }
};

int main()
{
    Student student;
    student.setAge(22);
    student.displayAge();

    return 0;
}
