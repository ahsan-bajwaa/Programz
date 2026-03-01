#include <iostream>
using namespace std;

class Vehicle
{
public:

void showDetail()
{
    cout << "This is a vehicle." << endl;
}
};

class Car : public Vehicle
{
public:

void showCar()
{
    cout << "This is a car." << endl;
}
};

int main()
{
Car obj;

obj.showDetail();
obj.showCar();
}