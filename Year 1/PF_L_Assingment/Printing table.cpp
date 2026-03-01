#include <iostream>
using namespace std;

int main(){
	char chess_table[10][10];
	
	for (int i = 0; i <= 9; i++) {		// 0
        for (int j = 0; j <= 9; j++) {
            chess_table[i][j] = '.';	// 0 1
        }
    }
    
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            cout << chess_table[i][j] << " ";	// 0 1
        }
        cout << endl;
    }
}