#include <iostream>
using namespace std;

class Person
{
private:
    int age = 0;

public:
    // Setter function.
    void setAge(int newAge)
    {
        if (newAge > 18)
        {
            age = newAge;
            cout << "Age set to " << age << endl;
        }
        else
        {
            cout << "Invalid age! Age must be greater than 18" << endl;
        }
    }

    // Getter function.
    int getAge() const
    {
        return age;
    }
};

int main() {
    Person person;
    
    // Set valid age
    person.setAge(25);  // Works

    // Get age
    cout << "Current age: " << person.getAge() << endl;
    
    // Set invalid age
    person.setAge(15);  // Shows error message
    
    // Get age
    cout << "Current age: " << person.getAge() << endl;
    
    return 0;
}