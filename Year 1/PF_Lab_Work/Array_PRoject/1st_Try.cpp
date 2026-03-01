#include <iostream>
using namespace std;

bool checcking_matrix(int matrix[][3]) {
	bool flag;
	int row_sum = 0, column_sum = 0, diagonal_right = 0, diagonal_left = 0;
		
		// Summing up diagonals.
		diagonal_right += matrix[0][0] + matrix[1][1] + matrix[2][2];
		diagonal_left += matrix[0][2] + matrix[1][1] + matrix[2][0];
		
		//	Summing up rows and column.
		for (int i = 0; i <3; i++) {
			for (int j = 0; j < 3; j++) {
			
				row_sum += matrix[i][j];
				column_sum += matrix[j][i];
			}
			// Checking Rows and column.
			if (row_sum != column_sum || row_sum != diagonal_right) {
				flag = false;
				break;
			}
			// Check diagonal.
			if (diagonal_right != diagonal_left) {
				flag = false;
				break;
			}
		}
			
			//	Returning result.
			return flag;
}

int main() {
	int matrix[3][3]= { {2, 7, 6},
						{9, 5, 1},
						{4, 3, 8}
					};
			
	if (checcking_matrix){
		cout << "True";
	}
	else cout << "False";
					
}
