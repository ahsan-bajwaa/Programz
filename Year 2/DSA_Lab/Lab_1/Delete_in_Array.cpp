#include <iostream>
using namespace std;

int main()
{
    int array[10] = {1, 3, 5, 7, 9};
    int size_of_array = 5;

    int position;
    
    cout << "Original array: ";
    for (int i = 0; i < size_of_array; i++)
    {
        cout << array[i] << " ";
    }

    cout << "\nEnter the position of number you want to delete: ";
    cin >> position;
    position--;

    for (int i = position; i < size_of_array - 1; i++)
    {
        array[i] = array[i + 1];
    }
    size_of_array--;

    cout << "\nArray after deletion: ";
    for (int i = 0; i < size_of_array; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}
