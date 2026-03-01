#include <iostream>
using namespace std;

bool isPerfect(int num, int num2) {
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
}

int main() {
    for (int num = 1; num <= 100; num++) {
        if (isPerfect(num, num2)) {
            cout << num << " is a perfect number." << endl;
        }
    }
    return 0;
}

