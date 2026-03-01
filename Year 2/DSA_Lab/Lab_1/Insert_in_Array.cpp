#include <iostream>
using namespace std;

int main()
{
    int array[10] = {2, 4, 6 ,8 , 10};

    int position, number;
    int size_of_array = 5;

    cout << "Enter the position where you want to enter a number: ";
    cin >> position;
    // here decrement mean that I'm not talking about index of position.
    position--;

    cout << "Enter the number you want to insert: ";
    cin >> number;

    // Display array.
    cout << "Fresh data:        ";
    for (int i = 0; i < size_of_array; i++)
    {
        cout << array[i] << "  ";
    }

    for (int i = size_of_array; i > position; i--)
    {
        array[i] = array[i - 1];
    }

    size_of_array++;

    // Display array.
    cout << "\nShiffted position: ";
    for (int i = 0; i < size_of_array; i++)
    {
        cout << array[i] << "  ";
    }

    // Inserting the number.
    array[position] = number;

    // Display array.
    cout << "\nUpdated array:     ";
    for (int i = 0; i < size_of_array; i++)
    {
        cout << array[i] << "  ";
    }

    return 0;
}