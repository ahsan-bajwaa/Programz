#include <iostream>
using namespace std;

class Check
{
public:
    void print(int x)
    {
        cout << "Called: print(int)" << endl;
    }

    void print(const int &x)
    {
        cout << "Called: print(const int &x)" << endl;
    }
};

int main()
{
    Check check;

    //check.print(5);   // Ambiguous call.

    /*
    Answer:
        Compiler throws an error because:
            1. Both print(int) and print(const int&) can accept the literal '5'.
            2. There’s no better match — so ambiguity arises.
            3. Compiler doesn't know whether to:
                - Pass 5 directly (for print(int))
                - Or bind it to const reference (for print(const int&))
    */

    return 0;
}
