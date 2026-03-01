#include <iostream>
using namespace std;

int main(){
	int rows_1, coloumn_1;
	cout << "Enter size of 1st array:\nEnter number of rows: ";
	cin >> rows_1;
	cout << "Enter number of coloumn: ";
	cin >> coloumn_1;
	
	int Aaa[rows_1][coloumn_1];
	
	cout << "Enter data of an array." << endl;
	for(int i = 0; i < rows_1; i++){
		for(int j = 0; j < coloumn_1; j++){
			cin >> Aaa[i][j];				
		}
	}
	
	for(int i = 0; i < coloumn_1; i++){
		for(int j = 0; j < rows_1; j++){
			cout << Aaa[j][i] << " ";	
		}
		cout << endl;
	}
}
