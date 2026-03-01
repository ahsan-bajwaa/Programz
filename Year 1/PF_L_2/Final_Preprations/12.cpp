#include <iostream>
using namespace std;

class FixedMatrix
{
private:
    int data[10][10];
    int row;
    int col;

public:
    // Constructor:.
    FixedMatrix() : row(10), col(10)
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                data[i][j] = 0;
    }

    FixedMatrix operator+(const FixedMatrix &object)
    {
        FixedMatrix result;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                result.data[i][j] = this->data[i][j] + object.data[i][j];
        return result;
    }

    bool operator==(const FixedMatrix &object)
    {
        if (row != object.row || col != object.col)
            return false;

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (data[i][j] != object.data[i][j])
                    return false;

        return true;
    }

    operator bool()
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (data[i][j] != 0)
                    return true;
        return false;
    }

    friend ostream &operator<<(ostream &out, const FixedMatrix &c);
};

ostream &operator<<(ostream &out, const FixedMatrix &c)
{
    for (int i = 0; i < c.row; i++)
    {
        for (int j = 0; j < c.col; j++)
        {
            cout << c.data[i][j] << " ";
        }
        cout << endl;
    }
    return cout;
}

int main()
{
    FixedMatrix m1, m2;

    // Display both
    cout << "Matrix 1:\n" << m1;
    cout << "\nMatrix 2:\n" << m2;

    // Test +
    FixedMatrix m3 = m1 + m2;
    cout << "\nMatrix 3 (m1 + m2):\n" << m3;

    // Test ==
    if (m1 == m2)
        cout << "\nMatrix 1 and Matrix 2 are equal.\n";
    else
        cout << "\nMatrix 1 and Matrix 2 are NOT equal.\n";

    // Test bool
    if (m1)
        cout << "\nMatrix 1 has non-zero elements.\n";
    else
        cout << "\nMatrix 1 is all zeros.\n";

    return 0;
}
