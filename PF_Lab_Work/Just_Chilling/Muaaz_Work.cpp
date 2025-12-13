#include <iostream>
using namespace std;

// 1. Find row with highest sum in 2D array
int highestSumRow(int arr[][3], int rows, int cols) {
    int maxSum = 0, rowIndex = 0;
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            rowIndex = i;
        }
    }
    return rowIndex;
}

// 2. Merge two sorted arrays
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }
    while (i < size1) merged[k++] = arr1[i++];
    while (j < size2) merged[k++] = arr2[j++];
}

// 3. Add corresponding elements of two arrays
void addArrays(int arr1[], int arr2[], int sum[], int size) {
    for (int i = 0; i < size; i++) {
        sum[i] = arr1[i] + arr2[i];
    }
}

// 4. Add even-indexed, subtract odd-indexed elements
void processArrays(int arr1[], int arr2[], int result[], int size) {
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0)
            result[i] = arr1[i] + arr2[i];
        else
            result[i] = arr1[i] - arr2[i];
    }
}

// 5. Find unique elements in an array
void findUnique(int arr[], int size, int unique[], int &uniqueSize) {
    uniqueSize = 0;
    for (int i = 0; i < size; i++) {
        bool isUnique = true;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j] && i != j) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            unique[uniqueSize++] = arr[i];
        }
    }
}

// 6. Sum of rows and columns in 2D array
void sumRowsCols(int arr[][3], int rows, int cols, int rowSum[], int colSum[]) {
    for (int i = 0; i < rows; i++) {
        rowSum[i] = 0;
        for (int j = 0; j < cols; j++) {
            rowSum[i] += arr[i][j];
        }
    }
    for (int j = 0; j < cols; j++) {
        colSum[j] = 0;
        for (int i = 0; i < rows; i++) {
            colSum[j] += arr[i][j];
        }
    }
}

// 7. Swap two numbers using pass-by-reference
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// 8. Update two numbers (sum and product)
void updateNumbers(int &a, int &b) {
    int sum = a + b;
    int product = a * b;
    a = sum;
    b = product;
}

// 9. Double each element in an array
void doubleElements(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

// 10. Sort three integers in ascending order
void sortThree(int &a, int &b, int &c) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
}

// 11. Convert character to uppercase
void toUppercase(char &ch) {
    if (ch >= 'a' && ch <= 'z') {
        ch -= 32;
    }
}

// 12. Reverse a string
void reverseString(char str[], int length) {
    int start = 0, end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// 13. Sum of array elements
int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// 14. Check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// 15. Fill array with first N prime numbers
void fillPrimeNumbers(int arr[], int N) {
    int count = 0, num = 2;
    while (count < N) {
        if (isPrime(num)) {
            arr[count++] = num;
        }
        num++;
    }
}

// 16. Remove duplicates from an array
void removeDuplicates(int arr[], int &size) {
    int temp[size], newSize = 0;
    for (int i = 0; i < size; i++) {
        bool exists = false;
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == temp[j]) {
                exists = true;
                break;
            }
        }
        if (!exists) temp[newSize++] = arr[i];
    }
    for (int i = 0; i < newSize; i++) {
        arr[i] = temp[i];
    }
    size = newSize;
}

// 17. Fill array with multiples of 4
void fillMultiplesOf4(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        arr[i] = (i + 1) * 4;
    }
}

// 18. Swap main and secondary diagonal in NxN matrix
void swapDiagonals(int arr[][3], int N) {
    for (int i = 0; i < N; i++) {
        int temp = arr[i][i];
        arr[i][i] = arr[i][N - i - 1];
        arr[i][N - i - 1] = temp;
    }
}