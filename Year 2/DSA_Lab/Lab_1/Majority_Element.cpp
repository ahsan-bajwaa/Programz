#include <iostream>
using namespace std;

// Function to find the majority element
int findMajorityElement(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) count++;
        }
        if (count > n / 2) {
            return arr[i];  // majority element found
        }
    }
    return -1;  // no majority element
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
   cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int result = findMajorityElement(arr, n);

    if (result != -1)
        cout << "Majority element is: " << result << endl;
    else
        cout << "No majority element found." << endl;

    return 0;
}
