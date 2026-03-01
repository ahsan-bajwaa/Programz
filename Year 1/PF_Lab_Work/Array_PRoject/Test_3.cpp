#include <iostream>
using namespace std;

void input_data(int matrix_1[][20], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> matrix_1[i][j];
		}
	}
}

void multiply_matrix(int matrix_1[][20], int matrix_2[][20], int multiply[][20], int N, int M, int P) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < P; j++) {
				multiply[i][j] = 0;
			for (int k = 0; k < M; k++) {
                
				multiply[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
		}
	}
}

void result(int multiply[][20], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << multiply[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	int N,M,P;
	cout << "Enter Values of N,M,P";
	cin >> N >> M >> P;
	
	int matrix_1[20][20], matrix_2[20][20], multiply[20][20];
	
	cout << "Enter data in matrix 1." << endl;
	input_data(matrix_1, N, M);
	
	cout << "Enter data in matrix 2." << endl;
	input_data(matrix_2, M, P);
	
	cout << "Multiply Matrix.";
	multiply_matrix(matrix_1, matrix_2, multiply, N, M, P);
	
	cout << "Result:" << endl;
	result(multiply, N, P);
}