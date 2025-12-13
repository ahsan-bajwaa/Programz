#include <iostream>
using namespace std;

class Temperature
{
public:
    static int conversionCount;
    static void convertToCelsius(int Temp)
    {
        cout << (Temp - 32) * 5/9;
        conversionCount++;
    }
};
int Temperature::conversionCount = 0;

int main()
{
    Temperature temperature;
    temperature.convertToCelsius(100);

    return 0;
}