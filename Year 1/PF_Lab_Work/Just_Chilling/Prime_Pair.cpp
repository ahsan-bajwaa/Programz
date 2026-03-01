#include <iostream>
using namespace std;

// Function to check if a number is prime
bool prime_sequence(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to store prime numbers in an array
void prime_array(int range, int prime_numbers[], int &count) {
    count = 0; // Reset count
    for (int i = 2; i <= range; i++) {
        if (prime_sequence(i)) {
            prime_numbers[count] = i; // Store prime number in array
            count++;
        }
    }
}

// Function to print prime numbers
void printing_pairs(int prime_numbers[], int count) {
    cout << "Prime numbers up to the given range are: ";
    for (int i = 0; i < count; i++) {
        cout << prime_numbers[i] << " ";
    }
    cout << endl;
}

// Function to find and display pairs of primes whose sum is also prime
void find_and_display_pairs(int prime_numbers[], int count) {
    cout << "Pairs of prime numbers whose sum is also prime:" << endl;
    for (int i = 0; i < count; i++) {
        for (int j = i; j < count; j++) {
            int sum = prime_numbers[i] + prime_numbers[j];
            if (prime_sequence(sum)) {
                cout << "(" << prime_numbers[i] << ", " << prime_numbers[j] << ")" << endl;
            }
        }
    }
}

int main() {
    int range, count = 0;

    // Input the range
    cout << "Enter range for prime numbers: ";
    cin >> range;

    // Array to store prime numbers
    int prime_numbers[range];

    // Store prime numbers in the array
    prime_array(range, prime_numbers, count);

    // Print the prime numbers
    printing_pairs(prime_numbers, count);
    
     // Find and display pairs whose sum is also prime
    find_and_display_pairs(prime_numbers, count);

    return 0;
}