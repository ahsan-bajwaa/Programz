
 #include <iostream>
using namespace std;

class Time
{
public:
	int hours, min;
	Time()
	{
		hours = 0;
		min = 0;
		cout << "1st constructor: " << "00:00" << endl;
	}
	
	Time(int input)
	{
		hours = input;
		min = 0;
		cout << "2st constructor: " << hours << ":" << min << endl;
	}
	
	Time(int input_1, int input_2)
	{
		hours = input_1;
		min = input_2;
		cout << "3st constructor: " << hours << ":" << min << endl;
	}
};

int main()
{
	Time con1;
	Time con2(7);
	Time con3(7,04); 
}