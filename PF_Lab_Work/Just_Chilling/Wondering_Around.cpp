#include <iostream>

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void storePrimes(int arr[], int &count, int n) {
    count = 0; // Number of primes found
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            arr[count++] = i; // Store prime number in array
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the range N: ";
    std::cin >> n;

    int primes[n]; // Array to store prime numbers
    int count = 0;

    storePrimes(primes, count, n);

    std::cout << "Prime numbers up to " << n << " are: ";
    for (int i = 0; i < count; i++) {
        std::cout << primes[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
