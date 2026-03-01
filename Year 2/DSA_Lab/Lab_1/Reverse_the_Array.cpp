#include <iostream>
using namespace std;

int main()
{
    int size_of_array = 5;
    int array[size_of_array] = {1, 2, 3, 4, 5};
    int temp_num;
    int reverse_index = 4;

    cout << "Orignal Array:  ";
    for (int i = 0; i < size_of_array; i++)
    {
        cout << array[i] << " ";
    }

    // Here I'm calling loop for half time of the size of an array.. As vaules are getting assign form both ends.
    for (int i = 0; i < size_of_array / 2; i++)
    {
        temp_num = array[i];
        array[i] = array[size_of_array - 1 - i];
        array[size_of_array - 1 - i] = temp_num;
    }

    cout << "\nReversed Array: ";
    for (int i = 0; i < size_of_array; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}