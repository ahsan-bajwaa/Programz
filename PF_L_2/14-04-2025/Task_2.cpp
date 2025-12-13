#include <iostream>
using namespace std;

class Animal
{
public:
    void eat()
    {
        cout << "Animals eat food" << endl;
    }
};

class Mammal : public Animal
{
public:
    void walk()
    {
        cout << "Mammals can walk" << endl;
    }
};

class Dog : public Mammal
{
public:
    void bark()
    {
        cout << "Dogs bark" << endl;
    }
};

int main()
{
    Dog dog;
    dog.eat();
    dog.walk();
    dog.bark();

    return 0;
}
