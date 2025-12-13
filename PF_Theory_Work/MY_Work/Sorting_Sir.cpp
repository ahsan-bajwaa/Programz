#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (A[j] > key && j >= 0)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
    for (int i = 0; i <= n - 1; i++)
    {
        cout << A[i] << "  ";
    }
}

#include <iostream>
using namespace std;
void selection_sort(int A[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int small = i; // let
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (A[j] < A[small])
            {
                small = j;
            }
        }
        if (small != i)
        {
            int temp;
            temp = A[i];
            A[i] = A[small];
            A[small] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << "	";
    }
}
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    selection_sort(A, n);
}

#include <iostream>
using namespace std;
int main()
{
    int A[7] = {17, 66, 25, 4, 3, 21, 1};

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6 - i; j++)
        {
            int temp;
            if (A[j] > A[j + 1])
            {
                temp = A[j + 1];
                A[j + 1] = A[j];
                A[j] = temp;
            }
        }
    }
    cout << "Sorted List is : ";
    for (int i = 0; i < 7; i++)
    {
        cout << A[i] << "  ";
    }
}