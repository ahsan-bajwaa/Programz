#include <iostream>
using namespace std;

void creating_table(string chess_template[10][10]) {

	for(int i = 0; i < 8; i++) {
    	for(int j = 0; j < 8; j++) {
    		 chess_template[i][j] = "  . ";
		}
	}
}

void copy_of_table(string chess_template[10][10], string chess[10][10]) {

	for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                chess[i][j] = chess_template[i][j];
            }
        }
}

void queen_move(string chess[10][10], int row, int column){

	for(int i = 0; i < 10; i++){
            //	Horizontal Move.
            chess[row - 1][i] = "*" ;
            //	Vertival move.
            chess[i][column - 1] = "*";
			
            //	Diagonal moves.
            if(row - 1 - i >= 0 && column - 1 - i >= 0) 	// Top-left
                chess[row - 1 - i][column - 1 - i] = "*" + "w_Q";
            if(row - 1 - i >= 0 && column - 1 + i < 10) 	// Top-right
                chess[row - 1 - i][column - 1 + i] = "*" + "w_Q";
            if(row - 1 + i < 10 && column - 1 - i >= 0) 	// Bottom-left
                chess[row - 1 + i][column - 1 - i] = "*" + "w_Q";
            if(row - 1 + i < 10 && column - 1 + i < 10) 	// Bottom-right
                chess[row - 1 + i][column - 1 + i] = "*" + "w_Q";
        
		}
}

void displaying_queen_move(string chess_template[10][10]) {
	
		// Displaying chessboard.
	int numbering_numbers = 8;
	char numbering_alphabets = 'A';
    cout << endl << "__________________________Chessboard_________________________" << endl << endl;
	cout << " |   ";
    for(char c = 'A'; c <= 'H'; c++){
        cout << c << "     ";
    }
	cout << endl << "_____________________________________________________" << endl;
    for(int i = 0; i < 8; i++){
    	cout << numbering_numbers << "| ";
        for(int j = 0; j < 8; j++) {
            cout << chess_template[i][j] << "  ";
			if(j == 7){
    			cout << "|" << numbering_numbers--;
			}
		}
		if(i < 7)
			cout << endl << endl;
		
		else
			cout << endl;
   }
	cout << endl << "------------------------------------------------------" << endl;	
	cout << " |   ";
    for(char c = 'A'; c <= 'H'; c++){
        cout << c << "     ";
    }
    cout << endl << "_______________________________________________________" << endl;	
}

void checking_valid_move(bool &checking_move, int &row, int &column, int new_row, int new_column) {
       
	    // Check for row and column move.
        if(new_row == row || new_column == column){
            checking_move = true;
        }
        // Check for diagonal move.
        else if(new_row - row == new_column - column || (new_row - row == -(new_column - column))) {
            checking_move = true;
    	}
		// Verifying moves.
        if(checking_move){
            row = new_row;
            column = new_column;
        }
		else{
            cout << "Invalid move. Queen can't move there. Try again." << endl;
        }
}

int main() {
    //	Creating table.
    string chess_template[10][10];
    creating_table(chess_template);
	
	// Queen starts at position (5, 8). As in question.
    int row = 5, column = 8;
	
	//	Taking input as long as user not input '0' value.
    while(true){
    // Making a copy of an arry.
        string chess[10][10];
        copy_of_table(chess_template, chess);
	
    // Representing all possible moves of the queen with 'Q'.
        queen_move(chess, row, column);
        
    // Showing current position of Queen.
    chess[row - 1][column - 1]  = "-";
        
    // Displaying chessboard.   
	    displaying_queen_move(chess);


    
	//	Geting input from user.
        cout << "Entering position of Queen:\n";
        cout << "Enter row (0 to exit): ";
        int new_row, new_column;
        cin >> new_row;
        if(new_row == 0)
			break;
		
        cout << "Enter column (0 to exit): ";
        cin >> new_column;
        if(new_column == 0)
			break;
		
	// Checking valid move.
		bool checking_move = false;		
		
		checking_valid_move(checking_move, row, column, new_row, new_column);
    }
	
    cout << "Thanks for playing the game!";
    return 0;
}

