#include <iostream>
using namespace std;

class Counter
{
private:
    int count;

public:
    // Constructor.
    Counter() : count(0) {}

    void operator++()
    {
        ++count;
    }
    void operator++(int)
    {
        count++;
    }

    void operator--()
    {
        --count;
    }
    void operator--(int)
    {
        count--;
    }

    friend ostream& operator<<(ostream& out, const Counter& c);
};

ostream& operator<<(ostream& out, const Counter& c)
{
    cout << "Current Count: " << c.count;
    return cout;
}

int main()
{
    Counter c;

    cout << c << endl;

    ++c;
    cout << c << endl;   // Output: 1

    c++;
    cout << c << endl;   // Output: 2

    --c;
    cout << c << endl;   // Output: 1

    c--;
    cout << c << endl;   // Output: 0

    return 0;
}
