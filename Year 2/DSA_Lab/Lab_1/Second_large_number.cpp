#include <iostream>
using namespace std;

int main()
{
    int size_of_array = 6;
    int array[size_of_array] = {2, 8, 1, 7, 5, 6};
    int largest = array[0];
    int second_largest = 0;
    int number;

    cout << "Array elements: ";
    for (int i = 0; i < size_of_array; i++)
    {
        cout << array[i] << " ";
    }

    for (int i = 1; i < size_of_array; i++)
    {
        number = array[i];
        if (number > largest)
        {
            second_largest = largest;
            largest = number;
        }
        else if (number > second_largest && number != largest)
        {
            second_largest = number;
        }
    }

    cout << "\nSecond Largest Element: " << second_largest;

    return 0;
}
