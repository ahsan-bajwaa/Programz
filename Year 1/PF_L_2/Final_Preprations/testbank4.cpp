#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string model;
    int speed; // km/h
public:
    Vehicle(const string m, int s) : model(m), speed(s) {}
    virtual float travelTime(int distance) {
        float time = (float)distance / speed;
        cout << "Vehicle " << model << " will take " << time << " hours to travel " << distance << " km." << endl;
        return time;
    }
    virtual ~Vehicle() {}
};

class Truck : protected Vehicle {
private:
    float maxLoad; // tons
public:
    Truck(const string m, int s, float ml) : Vehicle(m, s), maxLoad(ml) {}
    float travelTime(int distance) override {
        float time = (float)distance / speed;
        cout << "Truck Model: " << model << ", Max Load: " << maxLoad << " tons, Travel Time: " << time << " hours." << endl;
        return time;
    }
 
};

class Motorbike : protected Vehicle {
private:
    int engineCC;
public:
    Motorbike(const string m, int s, int cc) : Vehicle(m, s), engineCC(cc) {}
    float travelTime(int distance) override {
        float time = (float)distance / speed;
        cout << "Motorbike Model: " << model << ", Engine: " << engineCC << "cc, Travel Time: " << time << " hours." << endl;
        return time;
    }
};

int main() {
    Truck t("Volvo FH", 80, 18.0f);
    Motorbike m("Yamaha R1", 120, 998);

    Vehicle* v1 = (Vehicle*)&t;
    Vehicle* v2 = (Vehicle*)&m;

    int distance = 240; // km

    v1->travelTime(distance);
    v2->travelTime(distance);

    return 0;
}