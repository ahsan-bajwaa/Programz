#include <iostream>
using namespace std;

int main()
{
    int size_of_array = 7;
    int array[size_of_array] = {1, 2, 3, 4, 5, 6, 7};
    int k;

    cout << "Original Array: ";
    for (int i = 0; i < size_of_array; i++)
    {
        cout << array[i] << " ";
    }

    cout << "\nEnter number of positions to rotate left: ";
    cin >> k;

    int rotated_array[size_of_array];
    int index = 0;

    // Copy elements from k to end
    for (int i = k; i < size_of_array; i++)
    {
        rotated_array[index++] = array[i];
    }

    // Copy elements from start to k-1
    for (int i = 0; i < k; i++)
    {
        rotated_array[index++] = array[i];
    }

    cout << "Rotated Array:  ";
    for (int i = 0; i < size_of_array; i++)
    {
        cout << rotated_array[i] << " ";
    }

    return 0;
}
