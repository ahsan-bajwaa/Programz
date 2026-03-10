// This is machine-dependent analysis in action
#include <time.h>
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {          // n-1 passes
        for (int j = 0; j < n-i-1; j++) {    // shrinks each pass
            if (arr[j] > arr[j+1]) {
                int temp  = arr[j];
                arr[j]    = arr[j+1];
                arr[j+1]  = temp;
            }
        }
    }
}
int main()
{
int n = 500;
int arr[500] = {6, 8, 4, 3, 1,2,3,6,5,9,5,8,8,9,98,1,10,111,15,19,17,14,1,65,65,48,74,85,33,66,25,19,25,55,44,77,88,99,32,11,22,29,37,48,46,42,41,71,74,75,65};

clock_t start = clock();
bubbleSort(arr, n);             // run the algorithm
clock_t end = clock();

double time = (end - start) / CLOCKS_PER_SEC;
cout << "Time: " << time << " seconds";
}
/*
```
**Problems with machine-dependent analysis:**
```
Same algorithm on different machines → different results

Old laptop    →  5.2 seconds
New gaming PC →  0.3 seconds
Server        →  0.1 seconds

Which result is the "real" answer? None of them!
They all change based on hardware.
```
*/
