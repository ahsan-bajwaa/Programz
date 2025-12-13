#include <iostream>
using namespace std;

class Counter
{
private:
    static int totalCalls;

public:
    void increment()
    {
        totalCalls++;
        cout << "Incremented! Total calls: " << totalCalls << endl;
    }

    static int getTotalCalls()
    {
        return totalCalls;
    }
};

int Counter::totalCalls = 0;

int main()
{
    Counter c1, c2, c3;

    c1.increment();
    c2.increment();
    c3.increment();

    cout << "Final total calls: " << Counter::getTotalCalls() << endl;
    return 0;
}