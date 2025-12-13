#include <iostream>
using namespace std;

int main() {
    float sum = 0;
    int num1 = 1, num2 = 3;

    while(num1 <= 97){
        sum += (num1 * 1.0 / num2);
        num1 += 2;
        num2 += 2;
    }
    cout << "Sum of series is: " << sum << endl;

    return 0;
}
