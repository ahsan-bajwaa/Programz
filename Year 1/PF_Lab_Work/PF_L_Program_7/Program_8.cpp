#include <iostream>
using namespace std;

	// using &x_value and &y_value so they can be changed from their address. Since any change in function stay within it.
void solveLinearSystem(int a_1, int b_1, int c_1, int a_2, int b_2, int c_2, int &x_value, int &y_value){
    int determinant = a_1 * b_2 - a_2 * b_1;

    if(determinant == 0){
        cout << "It has no solution." << endl;
    }
    
    x_value = (c_1 * b_2 - c_2 * b_1) / determinant;
    y_value = (a_1 * c_2 - a_2 * c_1) / determinant;
}

int main(){
    int a_1, a_2, b_1, b_2, c_1, c_2;
    int x_value = 0, y_value = 0, determinant;
    cout << "Enter value of a_1: ";
    cin >> a_1;
    cout << "Enter value of b_1: ";
    cin >> b_1;
    cout << "Enter value of c_1: ";
    cin >> c_1;
    cout << "Enter value of a_2: ";
    cin >> a_2;
    cout << "Enter value of b_2: ";
    cin >> b_2;
    cout << "Enter value of c_2: ";
    cin >> c_2;

    determinant = a_1 * b_2 - a_2 * b_1;

    if(determinant == 0){
        if(a_1 * c_2 == a_2 * c_1 && b_1 * c_2 == b_2 * c_1){
            cout << "It has infinite solutions.\n";
        }
		else{
            cout << "It has no solution.\n";
        }
    }
	else{
        // Calling a function.
        solveLinearSystem(a_1, b_1, c_1, a_2, b_2, c_2, x_value, y_value);
        cout << "The solution is of x and y is as: " << endl;
        cout << "x = " << x_value << endl;
		cout << "y = " << y_value << endl;
    }

}

