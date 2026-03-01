#include <iostream>
using namespace std;

class Animal
{
public:
void eat()
{
    cout << "Animals eat food." << endl;
}
};

class Mammal
{
public:
void walk()
{
    cout << "Mammal can walk." << endl;
}
};

class Dog : public Animal, public Mammal
{
public:
public:
void bark()
{
    cout << "Dogs bark." << endl;
}
};

int main()
{
Dog obj;
obj.walk();
obj.eat();
obj.bark();
}