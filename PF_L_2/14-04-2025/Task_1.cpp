#include <iostream>
using namespace std;

class Vehicle
{
public:
    void showDetails()
    {
        cout << "This is a vehicle\n";
    }
};

class Car : public Vehicle
{
public:
    void carInfo()
    {
        cout << "This is a car\n";
    }
};

int main()
{
    Car car;
    car.showDetails();
    car.carInfo();

    return 0;
}
