#include <iostream>
using namespace std;

class classes
{
    public:
    int sum_0(int a, int b)
    {
        int sum = a + b;
        return sum;
    }
    int sum_1(int a, int b)
    {
        int sum = a + b;
        return sum;
    }
};

int main()
{
    classes obj;
    int a = 2, b = 3, c = 4, d = 5;
    cout << obj.sum_0(a,b) << endl;
    cout << obj.sum_1(a,b) << endl;
}