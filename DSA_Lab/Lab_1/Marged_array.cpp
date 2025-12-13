#include <iostream>
using namespace std;

int main()
{
    int size_1 = 5, size_2 = 4;
    int array_1[size_1] = {1, 3, 5, 7, 9};
    int array_2[size_2] = {2, 4, 6, 8};

    int merged_size = size_1 + size_2; 
    int merged[merged_size];
    int index = 0;
    // For Array_1.
    for (int i = 0; i < size_1; i++)
    {
        merged[i] = array_1[i];
    }

    // For Array_2.
    for (int i = size_1; i < merged_size; i++)
    {   
        merged[i] = array_2[index];
        index++;
    }

    // Display arrays
    cout << "First Array:  ";
    for (int a = 0; a < size_1; a++)
        cout << array_1[a] << " ";

    cout << "\nSecond Array: ";
    for (int b = 0; b < size_2; b++)
        cout << array_2[b] << " ";

    cout << "\nMerged Array: ";
    for (int c = 0; c < merged_size; c++)
        cout << merged[c] << " ";

    return 0;
}
