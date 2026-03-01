#include <iostream>
#include <string>
using namespace std;

class Machine {
protected:
    string machineID;
    float powerConsumption; // in kW
public:
    Machine(const string& id, float power) : machineID(id), powerConsumption(power) {}
    virtual float computeUsageCost(float hours) {
        float cost = powerConsumption * hours * 20; // Rs. 20 per kWh
        cout << "Machine ID: " << machineID << endl;
        cout << "Power Consumption: " << powerConsumption << " kW" << endl;
        cout << "Usage Cost: Rs. " << cost << endl;
        return cost;
    }
    virtual ~Machine() {}
};

class Printer : protected Machine {
private:
    int pagesPerMinute;
public:
    Printer(const string& id, float power, int ppm)
        : Machine(id, power), pagesPerMinute(ppm) {}
    float computeUsageCost(float hours) override {
        float cost = powerConsumption * hours * 20;
        cout << "Printer ID: " << machineID << endl;
        cout << "Pages Per Minute: " << pagesPerMinute << endl;
        cout << "Usage Cost: Rs. " << cost << endl;
        return cost;
    }
};

class Cutter : protected Machine {
private:
    float cutSpeed; // meters per minute
public:
    Cutter(const string& id, float power, float speed)
        : Machine(id, power), cutSpeed(speed) {}
    float computeUsageCost(float hours) override {
        float cost = powerConsumption * hours * 20;
        cout << "Cutter ID: " << machineID << endl;
        cout << "Cut Speed: " << cutSpeed << " meters/minute" << endl;
        cout << "Usage Cost: Rs. " << cost << endl;
        return cost;
    }
};

int main() {
    Printer* m1 = new Printer("PR123", 0.5, 30);
    Cutter* m2 = new Cutter("CT456", 1.2, 15.5);

    cout << "--- Printer Usage ---" << endl;
    m1->computeUsageCost(5); // 5 hours

    cout << "\n--- Cutter Usage ---" << endl;
    m2->computeUsageCost(3); // 3 hours

    delete m1;
    delete m2;
    return 0;
}