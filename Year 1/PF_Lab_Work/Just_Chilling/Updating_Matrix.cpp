#include <iostream>
using namespace std;

void swapping_diagonal(int matrix[][3]) {
	int temp_1, temp_2;
	//	For main diagonal.
	temp_1 = matrix[0][0];
	matrix[0][0] = matrix[0][2];
	matrix[0][2] = temp_1;
	//	For nakili diagonal.
	temp_2 = matrix[2][0];
	matrix[2][0] = matrix[2][2];
	matrix[2][2] = temp_2;
}

void display_matrix(int matrix[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

void special_element(int matrix[][3]) {
	
		int Aaa = 0;
		int row_sum = 0, col_sum;
	for(int i = 0; i < 3; i++) {
		
		row_sum = matrix[i][0] + matrix[i][1] + matrix[i][2];
		col_sum = matrix[0][i] + matrix[1][i] + matrix[2][i];
			
			bool row_flag = true, col_flag = true;
		for (int k = 2; k < row_sum; k++) {
			if (row_sum % k == 0) {
				row_flag = false;
			}
		}
		
		for (int k = 2; k < col_sum; k++) {
			if (col_sum % k == 0) {
				col_flag = false;
			}
		}
		Aaa++;
		//	Checking for prime number for row.
		if (row_flag) {
			cout << "Row_Sum = " << Aaa << ": " << row_sum << endl;
		}
		
		//	Checking for prime number for col.
		if (col_flag) {
			cout << "Col_Sum = " << Aaa << ": " << col_sum << endl;
		}
	}
}

int main(){
	int matrix[3][3] = {{3, 7, 9},
					    {1, 4, 6},
						{8, 9, 5}
						};
	
	//	Printing orignal table;
	cout << "Orignal Matrix:" << endl;
	display_matrix(matrix);
	
	//	Printing updated matrix.
	swapping_diagonal(matrix);
	
	//	Printing orignal table;
	cout << "Updated Matrix:" << endl;
	display_matrix(matrix);
	
	//	Searching for prime sum.
	special_element(matrix);				
	
	
}