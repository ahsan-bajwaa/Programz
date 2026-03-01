#include <iostream>
using namespace std;

class Class_1
{
public:
    void print()
    {
        cout << "From class 'Class_1'" << endl;
    }
};

class Class_2
{
public:
    void print()
    {
        cout << "From class 'Class_2'" << endl;
    }
};


class All_in_one : public Class_1, public Class_2
{
public:
    void usePrinter()
    {
        Class_1::print();
    }
    void useScanner()
    {
        Class_2::print();
    }
};

int main()
{
    All_in_one all_in_one;

    all_in_one.usePrinter();
    all_in_one.useScanner();
    
    // if we call device.print(); then it will give Error: Ambiguous call

    return 0;
}