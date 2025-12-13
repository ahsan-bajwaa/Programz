#include <iostream>
using namespace std;

class classes
{
    public:
    int sum(int a)
    {
        return a;
    }
    int sum(int a, int b)
    {
        int sum = a + b;
        return sum;
    }
    int sum(int a, int b, int c)
    {
        int sum = a + b + c;
        return sum;
    }
    int sum(int a, int b, int c, int d)
    {
        int sum = a + b + c + d;
        return sum;
    }
};

int main()
{
    classes obj;
    int a = 2, b = 3, c = 4, d = 5;
    cout << obj.sum(a) << endl;
    cout << obj.sum(a,b) << endl;
    cout << obj.sum(a, b, c) << endl;
    cout << obj.sum(a, b, c, d) << endl;
}