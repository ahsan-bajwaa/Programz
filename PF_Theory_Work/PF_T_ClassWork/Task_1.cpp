#include <iostream>
using namespace std;

int main(){
	int sum = 0;
	int rows_1, coloumn_1;
	cout << "Enter size of 1st array:\nEnter number of rows: ";
	cin >> rows_1;
	cout << "Enter number of coloumn: ";
	cin >> coloumn_1;
	
	int Aaa[rows_1][coloumn_1];
	
	for(int i = 0; i < rows_1; i++){
		for(int j = 0; j < coloumn_1; j++){
			cin >> Aaa[i][j];
			sum += Aaa[i][j];
		}
	}
	
	int rows_2, coloumn_2;
	cout << "Enter size 2nd of array:\nEnter number of rows: ";
	cin >> rows_2;
	cout << "Enter number of coloumn: ";
	cin >> coloumn_2;
	
	int Aaaa[rows_2][coloumn_2];
	for(int i = 0; i < rows_2; i++){
		for(int j = 0; j < coloumn_2; j++){
			cin >> Aaaa[i][j];
			sum += Aaaa[i][j];
		}
	}
	cout << "Sum is: " << sum;
}
