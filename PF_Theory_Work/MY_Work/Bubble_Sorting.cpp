#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // After i passes, last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*
Array:

[5, 3, 4, 1]

Pass 1:

    Compare 5 & 3 → swap → [3, 5, 4, 1]

    Compare 5 & 4 → swap → [3, 4, 5, 1]

    Compare 5 & 1 → swap → [3, 4, 1, 5]

    👉 Largest element (5) fixed at end

Pass 2:

    Compare 3 & 4 → no swap

    Compare 4 & 1 → swap → [3, 1, 4, 5]

Pass 3:

    Compare 3 & 1 → swap → [1, 3, 4, 5]

✅ Sorted.
*/
