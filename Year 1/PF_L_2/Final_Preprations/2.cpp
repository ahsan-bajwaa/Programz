#include <iostream>
using namespace std;

class Device
{
protected:
    string deviceType;
public:
    Device(string DeviceType) : deviceType(DeviceType) {}
    virtual double computerPerformace() = 0;
};

class Laptop : public Device
{
private:
    int ramSize;
    double cpuSpeed;
public:
    Laptop(string DeviceType, int RamSize, double CpuSpeed) : Device(DeviceType), ramSize(RamSize), cpuSpeed(CpuSpeed) {}
    double computerPerformace() override
    {
        return ramSize * cpuSpeed * 10;
    }
    friend void deviceType(Laptop &laptop);
};

void deviceType(Laptop &laptop)
{
    cout << "Device Name: " << laptop.deviceType;
    cout << "\nRam Size: " << laptop.ramSize;
    cout << "\nCPU speed: " << laptop.cpuSpeed;
    cout << "\nComputer Performance: " << laptop.computerPerformace();
}

class Smartwatch : public Device
{
private:
    double batterLife;
public:
    Smartwatch(string DeviceType, double BatterLife) : Device(DeviceType), batterLife(BatterLife) {}
    double computerPerformace() override
    {
        return batterLife * 5;
    }
    friend void deviceType(Smartwatch &smartwatch);
};

void deviceType(Smartwatch &smartwatch)
{
    cout << "Device Name: " << smartwatch.deviceType;
    cout << "\nBattery Life: " << smartwatch.batterLife;
    cout << "\nComputer Performance: " << smartwatch.computerPerformace();
}

int main()
{
    Laptop laptop("Dell", 16, 2.4);
    Smartwatch smartwatch("HP", 20);

    deviceType(laptop);
    cout << "\n\n\n";
    deviceType(smartwatch);

    return 0;
}