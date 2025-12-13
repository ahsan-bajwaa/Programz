#include <iostream>
using namespace std;

class Box
{
private:
    int lenght;
    int width;
    int height;
    
public:
    static int count;

    // Constructor.
    Box(int lenght, int widht, int height) : lenght(lenght), width(width),
    height(height)
    {
        count++;
    }
};
int Box::count = 0;

int main()
{
    Box box_1(4,5,6);
    Box box_2(7,8,9);

    cout << "Counting the number of creation: " << Box::count << endl;

    /* Answer: We use an initializer list because:
   1. It directly initializes members (more efficient than assignment).
   2. Required for `const` and reference members.
   3. Avoids default initialization followed by assignment. */

}