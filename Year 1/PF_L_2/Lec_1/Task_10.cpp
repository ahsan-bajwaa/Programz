#include <iostream>
using namespace std;

class diff_operations
{
public:    
    void operation(int a, int b)
    {
        cout << "Sum of two number: " << a + b << endl;
    }
    void operation(string c, string d)
    {
        cout << "Concatination of two string: " << c + d << endl;
    }
    void operation(int e[][2], int f[][2])
    {
        int z[2][2];
        for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    z[i][j] = 0;
                    for (int k = 0; k < 2; k++)
                    {
                        z[i][j] += e[i][k] * f[k][j];
                    }
                }
            }
        
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << z[i][j] << "\t";
            }
            cout << endl;
        }
            
        }
        void operation(bool g)
        {
            if (g)  cout << "True";
            else cout << "False;";
        }
    };

int main() 
{
    diff_operations oprt;
    int a[2][2] = {{1,2},{3,4}};
    int b[2][2] = {{5,6},{7,8}};

    //  Interger sum.
    oprt.operation(4,5);

    //  String catination.
    oprt.operation("Super","man");

    // Marix Multiplication.
    oprt.operation(a, b);

    //  Bool operation.
    oprt.operation(true);
}