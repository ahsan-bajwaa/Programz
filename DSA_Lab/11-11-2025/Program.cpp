#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> myVector;

    myVector.push_back(10);
    myVector.push_back(20);

    myVector.pop_back();

    cout << myVector.size() << endl;


    cout << myVector[0] << endl;
    cout << myVector[1] << endl;

    return 0;
}