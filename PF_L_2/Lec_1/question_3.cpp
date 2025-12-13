#include <iostream>
using namespace std;

class program_1
{
   public: 
    void number(int c, int d)
    {
        cout << c + d << endl;
    }
    void number(int *a, int *b)
    {
        cout << (*a) + (*b);
    }
};

int main()

{
    program_1 obj;
    int a = 2;
    int b = 3;
    int* ptr_1 = &a;
    int* ptr_2 = &b;
    
    obj.number(a, b);
    obj.number(ptr_1, ptr_2);
}