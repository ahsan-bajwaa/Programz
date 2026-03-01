#include <iostream>
using namespace std;
int main() {
 int n, steps = 0, maxValue, evenCount = 0, oddCount = 0;
 cout << "Enter a positive integer: ";
 cin >> n;
 if (n > 0) {
 
 cout << "Collatz sequence for " << n << ": ";

 
 if (n % 2 == 0) {
 evenCount--;
 } else {
 oddCount--;
 }
 
 while (n != 1) {
 cout << n << ", ";
 if (n % 2 == 0) {
 evenCount++;
 n /= 2;
 } else {
 oddCount++;
 n = 3 * n + 1;
 }
 maxValue = max(maxValue, n);
 steps++;
 }
 oddCount++;
 cout << n << endl;
 cout << "Total steps: " << steps << endl;
 cout << "Maximum value reached: " << maxValue << endl;
 cout << "Even count: " << evenCount << endl;
 cout << "Odd count: " << oddCount << endl;
}
else{
	cout << "number negative or zero.";
}
 return 0;
}
