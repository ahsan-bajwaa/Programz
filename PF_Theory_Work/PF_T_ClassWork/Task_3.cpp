#include <iostream>
using namespace std;

int main(){
	int rows_1, coloumn_1;
	cout << "Enter size of 1st array:\nEnter number of rows: ";
	cin >> rows_1;
	cout << "Enter number of coloumn: ";
	cin >> coloumn_1;
	
	int rows_2, coloumn_2;
	cout << "Enter size of 2nd array:\nEnter number of rows: ";
	cin >> rows_2;
	cout << "Enter number of coloumn: ";
	cin >> coloumn_2;
	
	bool flag = false;
		
	do{
		if(coloumn_1 == coloumn_1 && rows_1 == rows_1 && 
	coloumn_2 == coloumn_2 && rows_2 == rows_2){
		
		flag = true;
		}
	}
	while(flag);
	
	int Aaa[rows_1][coloumn_1];
	for(int i = 0; i < rows_1; i++){
		for(int j = 0; j < coloumn_1; j++){
			cin >> Aaa[i][j];
		}
	}
	
	int Aaaa[rows_2][coloumn_2];
	for(int i = 0; i < rows_2; i++){
		for(int j = 0; j < coloumn_2; j++){
			cin >> Aaaa[i][j];
		}
	}

	int sum[rows_1][coloumn_1];
	for(int i = 0; i < rows_2; i++){
		for(int j = 0; j < coloumn_2; j++){
			sum[rows_1][coloumn_1] = Aaa[i][j] + Aaaa[i][j];
		}
	}
	for(int i = 0; i < rows_1; i++){
		for(int j = 0; j < coloumn_1; j++){
			cout << sum[i][j];
		}
		cout << endl;
	}
}
