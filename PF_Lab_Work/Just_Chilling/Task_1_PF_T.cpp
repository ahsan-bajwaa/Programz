#include <iostream>
using namespace std;

int highest_sum(int matrix[][3]) {
	int row_sum = 0, highest_sum = 0;
	int index_location;
	for (int i = 0; i < 3; i++) {
		int row_sum = 0;
		for (int j = 0; j < 3; j++) {
			row_sum += matrix[i][j];
		}
		if (highest_sum < row_sum) {
			highest_sum = row_sum;
			index_location = i;
		}
	}
	return index_location;
}

int main(){
	int matrix[3][3] = {
						{3, 50, 7},
						{5, 20, 2},
						{5, 9, 6}
						};
	int index = highest_sum(matrix);
	cout << "Highest Index: " << index << endl;
	for (int i = 0; i < 3; i++) {
		cout << matrix[index][i] << "\t";
	}
}