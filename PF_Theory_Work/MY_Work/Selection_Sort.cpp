#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        // find smallest in remaining array
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // swap smallest with current position
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

/*
 Step-by-Step (slow & clear)
    Initial array:
    [64, 25, 12, 22, 11]

🟢 Pass 1 (position 0)

    Smallest in entire array → 11

    Swap with index 0:

    [11, 25, 12, 22, 64]

🟢 Pass 2 (position 1)

    Remaining part:

        [25, 12, 22, 64]


        Smallest → 12

        Swap:

        [11, 12, 25, 22, 64]

🟢 Pass 3 (position 2)

    Remaining:

        [25, 22, 64]


        Smallest → 22

        Swap:

        [11, 12, 22, 25, 64]

🟢 Pass 4

    Only one element left → already sorted.

✅ Done.
*/