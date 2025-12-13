#include <iostream>
using namespace std;

class Device
{
public:
    void connect()
    {
        cout << "Hello for Device class\n";
    }
};

class Smartphone : public Device
{
public:
    void connect()
    {
        cout << "Hello for Smartphone class\n";
    }
};

int main()
{
    Smartphone smartphone;

    //  Part 1.
    Device* device_pointer = &smartphone;

    device_pointer->connect();

    //  Part 2.
    Smartphone smartPhone;
    smartPhone.connect();
}