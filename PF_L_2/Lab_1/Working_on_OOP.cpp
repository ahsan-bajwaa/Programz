#include <iostream>
using namespace std;

class Aaa
{
public: 
    int Bbb(int Fff);
};

int Aaa::Bbb(int Ccc)
{
    return Ccc;
};

int main()
{
    Aaa Zzz;
    cout << Zzz.Bbb(100);
}