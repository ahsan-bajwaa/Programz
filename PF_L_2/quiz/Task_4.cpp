#include <iostream>
using namespace std;

class Processor
{
public:
	float process(int array[], int size)
	{
		float answer = 0;
		for (int i = 0; i < size; i++)
		{
			answer += array[i];
		}
		answer /= size;
			
		return answer;
	};
	
	double process(double ary[], int size)
	{
		double sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += ary[i];
		}
		
		return sum;
	};
	
	int process(float a, int b)
	{
		int answer;
		for (int i = b; i < 1; i--)
		{
			answer *= b;
		}
		return answer;
	};
	
	int process(int a, float b)
	{
		
		return a * b;
	};
};

int main()
{
	Processor obj;
	int array[3] = {2, 3, 4};
	double ary[3] = {2.2, 3.3, 4.4};
	int size = 3;
	cout << "1st function: " << obj.process(array[3], size) << endl;
	cout << "2nd function: " << obj.process(ary[3], size) << endl;
	cout << "3rd function: " << obj.process(3f,3) << endl;
	cout << "4th function: " << obj.process(4,5f) << endl;
	
}