#include <iostream>
using namespace std;

class number_1
{
public:
    int number = 10;
    void checking_number(int input) 
    {
        input += number;
    }
    void checking_number(int a, int b)
    {
        a += b;
    }
};

class number_2
{
public:
    int number = 10;
    void checking_number(int &input)
    {
        input += number;
    }
};

int main() 
{
    number_1 obj_1;
    number_2 obj_2;

    int input_1 = 5, input_2 = 3;

    obj_1.checking_number(input_1);
    cout << "Number after update: " << input_1 << endl;

    input_1 = 7, input_2 = 2;
    obj_1.checking_number(input_1, input_2);
    cout << "Number after update: " << input_1 << endl;
    
    input_2 = 8;
    obj_2.checking_number(input_2);
    cout << "Number after update: " << input_2 << endl;
}
