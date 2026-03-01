#include <iostream>
using namespace std;

void input(int layer, int row, int col, int three_d[][10][10]) {
	three_d[layer][row][col];
	for (int i = 0; i < layer; i++) {
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++) {
				three_d[i][j][k];
			}
		}
	}
}

int main(){
	int layer, row, col;
	cout << "Enter layer, row, col:\n";
	cin >> layer, row, col;
	int three_d[10][10][10];
	
	// input entery data.
	cout << "Enter input data of matrix:\n";
	input(layer, row, col, three_d);
	
	// Find number.
	int find;
	cout << "Enter a number you want to find: ";
	cin >> find;
	
	// Finding number.
	for (int i = 0; i < layer; i++) {
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++) {
				if (three_d[i][j][k] == find) {
					cout << "Layer: " << i << ", Row: " << j << ", Column: " << k << endl;
				}
			}
		}
	}
	
}
