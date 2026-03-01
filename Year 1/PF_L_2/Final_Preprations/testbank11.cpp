// #include <iostream>
// using namespace std;

// class Counter {
// private:
//     int count;
// public:
//     Counter() : count(0) {}

//     // Prefix increment
//     Counter& operator++() {
//         ++count;
//         return *this;
//     }

//     // Postfix increment
//     Counter operator++(int) {
//         Counter temp = *this;
//         count++;
//         return temp;
//     }

//     // Prefix decrement
//     Counter& operator--() {
//         --count;
//         return *this;
//     }

//     // Postfix decrement
//     Counter operator--(int) {
//         Counter temp = *this;
//         count--;
//         return temp;
//     }

//     // Friend function to overload <<
//     friend ostream& operator<<(ostream& os, const Counter& c) {
//         os << "Count: " << c.count;
//         return os;
//     }
// };

// int main() {
//     Counter c;

//     cout << c << endl; // Initial value

//     ++c;
//     cout << c << endl; // After prefix increment

//     c++;
//     cout << c << endl; // After postfix increment

//     --c;
//     cout << c << endl; // After prefix decrement

//     c--;
//     cout << c << endl; // After postfix decrement

//     return 0;
// }

#include <iostream>
using namespace std;

class Counter {
private:
    int count;
public:
    Counter() : count(0) {}

    void increment() { ++count; }
    void decrement() { --count; }

    int getCount()  { return count; }
};

int main() {
    Counter c;

    cout << "Count: " << c.getCount() << endl;

    c.increment();
    cout << "Count: " << c.getCount() << endl;

    c.increment();
    cout << "Count: " << c.getCount() << endl;

    c.decrement();
    cout << "Count: " << c.getCount() << endl;

    c.decrement();
    cout << "Count: " << c.getCount() << endl;

    return 0;
}