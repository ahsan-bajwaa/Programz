#include <iostream>
using namespace std;

void Selection_sort(int array[], int size)
{
    int small;
    for (int i = 0; i < size-1; i++)
    {
        small = i;
        for (int j = i+1; j < size;j++)
        {
            if (array[j] < array[small])
            {
                small = j;
            }
        }
        if (i != small)
        {
            int temp = array[i];
            array[i] = array[small];
            array[small] = temp;
        }
    }

    // Display..
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "  ";
    }
}

int main()
{
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    Selection_sort(array, n);
}