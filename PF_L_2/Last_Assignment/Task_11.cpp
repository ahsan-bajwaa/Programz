#include <iostream>
using namespace std;

class Demo {
private:
    int data;

public:
    Demo(int d) : data(d) 
    {}

    // Non-const function.
    void modify_data(int new_data) {
        data = new_data;
        cout << "Data modified to: " << data << endl;
    }
    // Const function.
    int get_data() const {
        return data;
    }
    // Returns a const reference.
    const int &get_const_ref() const {
        return data;
    }
};

int main() {
    // 1. Normal object(non-const), nothing new.
    Demo obj1(10);
    obj1.modify_data(20);
    cout << "Data: " << obj1.get_data() << endl;
    
    //  2. Const object
    const Demo obj2(30);
    // obj2.modify_data(40);     Now we can't modify the data as obj is constant.
    cout << "Const Data: " << obj2.get_data() << endl;

    //  3. Const return type
    const int &ref = obj1.get_const_ref();
    // ref = 100;          We can't modify const reference.
    cout << "Const Ref: " << ref << endl;

    return 0;
}