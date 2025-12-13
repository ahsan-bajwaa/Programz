#include <iostream>
using namespace std;

class Ingredient {
protected:
    string name;
    float calories; 
public:
    Ingredient(string n, float cal) : name(n), calories(cal) {}
    virtual float calculateEnergy(float grams) {
        float total_calories = calories * grams / 100;
        cout << name << ": Total Calories for " << grams << "g = " << total_calories << endl;
        return total_calories;
    }
    virtual ~Ingredient() {}
};

class Spice : public Ingredient {
private:
    int spicinessLevel; 
public:
    Spice(string n, float cal, int spi) : Ingredient(n, cal), spicinessLevel(spi) {}
    float calculateEnergy(float grams) override {
        float total_calories = calories * grams / 100;
        cout << name << " (Spice): Spiciness Level " << spicinessLevel
             << ", Calories for " << grams << "g = " << total_calories << endl;
        return total_calories;
    }
};

class Vegetable : public Ingredient {
private:
    float fiberContent; 
public:
    Vegetable(string n, float cal, float fiber) : Ingredient(n, cal), fiberContent(fiber) {}
    float calculateEnergy(float grams) override {
        float total_calories = calories * grams / 100;
        cout << name << " (Vegetable): Fiber Content " << fiberContent
             << "g/100g, Calories for " << grams << "g = " << total_calories << endl;
        return total_calories;
    }
};

int main() {
    Spice* spice = new Spice("Chili", 300.0f, 8);
    Vegetable* vegetable = new Vegetable("Carrot", 41.0f, 2.8f);

    spice->calculateEnergy(50);    
    vegetable->calculateEnergy(120);

    delete spice;
    delete vegetable;
    return 0;
}